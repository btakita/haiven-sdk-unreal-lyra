#include "Misc/AutomationTest.h"

#if WITH_DEV_AUTOMATION_TESTS

#include "CommonSessionSubsystem.h"
#include "GameFramework/PlayerState.h"
#include "GameModes/LyraUserFacingExperienceDefinition.h"
#include "HaivenLyraGameplay.h"
#include "UObject/Package.h"

IMPLEMENT_SIMPLE_AUTOMATION_TEST(
	FHaivenLyraGameplaySelectionTest,
	"Haiven.LyraDemo.GameplaySelection",
	EAutomationTestFlags::EditorContext | EAutomationTestFlags::EngineFilter)

bool FHaivenLyraGameplaySelectionTest::RunTest(const FString& Parameters)
{
	TestFalse(TEXT("a shooter map is already gameplay"),
		HaivenLyraGameplay::IsGameplayEntryMap(TEXT("L_ShooterGym")));
	TestTrue(TEXT("the PIE front end can start gameplay"),
		HaivenLyraGameplay::IsGameplayEntryMap(TEXT("UEDPIE_0_L_LyraFrontEnd")));
	TestTrue(TEXT("the editor startup overview can start gameplay"),
		HaivenLyraGameplay::IsGameplayEntryMap(TEXT("L_DefaultEditorOverview")));
	TestTrue(TEXT("the PIE editor startup overview can start gameplay"),
		HaivenLyraGameplay::IsGameplayEntryMap(
			TEXT("/Game/System/DefaultEditorMap/UEDPIE_0_L_DefaultEditorOverview")));

	const FPrimaryAssetId MapId(FPrimaryAssetType(TEXT("Map")), TEXT("L_ShooterGym"));
	const FPrimaryAssetId ExperienceId(
		FPrimaryAssetType(TEXT("LyraExperienceDefinition")), TEXT("B_ShooterGame_Elimination"));

	ULyraUserFacingExperienceDefinition* FrontEnd = NewObject<ULyraUserFacingExperienceDefinition>(
		GetTransientPackage(), TEXT("B_LyraFrontEnd_Experience"));
	FrontEnd->bIsDefaultExperience = true;
	FrontEnd->MapID = MapId;
	FrontEnd->ExperienceID = ExperienceId;

	ULyraUserFacingExperienceDefinition* Overview = NewObject<ULyraUserFacingExperienceDefinition>(
		GetTransientPackage(), TEXT("DA_ExamplePlaylist"));
	Overview->bShowInFrontEnd = true;
	Overview->MapID = FPrimaryAssetId(MapId.PrimaryAssetType, TEXT("L_DefaultEditorOverview"));
	Overview->ExperienceID = FPrimaryAssetId(ExperienceId.PrimaryAssetType, TEXT("B_LyraDefaultExperience"));

	ULyraUserFacingExperienceDefinition* Shown = NewObject<ULyraUserFacingExperienceDefinition>(
		GetTransientPackage(), TEXT("B_ShownExperience"));
	Shown->bShowInFrontEnd = true;
	Shown->MapID = MapId;
	Shown->ExperienceID = ExperienceId;

	ULyraUserFacingExperienceDefinition* DefaultExperience = NewObject<ULyraUserFacingExperienceDefinition>(
		GetTransientPackage(), TEXT("B_DefaultExperience"));
	DefaultExperience->bIsDefaultExperience = true;
	DefaultExperience->bShowInFrontEnd = false;
	DefaultExperience->MapID = MapId;
	DefaultExperience->ExperienceID = ExperienceId;
	DefaultExperience->ExtraArgs.Add(TEXT("Keep"), TEXT("1"));

	TArray<UObject*> Loaded = {FrontEnd, Overview, Shown, DefaultExperience};
	TestEqual(TEXT("PLAY prefers the default experience over the front end and a shown tile"),
		HaivenLyraGameplay::SelectGameplayExperience(Loaded),
		static_cast<const ULyraUserFacingExperienceDefinition*>(DefaultExperience));

	Loaded = {FrontEnd, Overview, Shown};
	TestEqual(TEXT("without a default, PLAY skips the overview and uses the first gameplay tile"),
		HaivenLyraGameplay::SelectGameplayExperience(Loaded),
		static_cast<const ULyraUserFacingExperienceDefinition*>(Shown));

	Loaded = {FrontEnd, Overview};
	TestNull(TEXT("neither entry map is a match"), HaivenLyraGameplay::SelectGameplayExperience(Loaded));

	UCommonSession_HostSessionRequest* Request = HaivenLyraGameplay::MakeOfflineHostRequest(*DefaultExperience, *DefaultExperience);
	if (!TestNotNull(TEXT("offline host request"), Request)) return false;
	TestEqual(TEXT("PLAY does not open an Epic lobby"), Request->OnlineMode, ECommonSessionOnlineMode::Offline);
	TestFalse(TEXT("an offline match does not create a lobby"), Request->bUseLobbies);
	TestFalse(TEXT("an offline match does not publish presence"), Request->bUsePresence);
	TestEqual(TEXT("the request keeps the experience map"), Request->MapID, MapId);
	TestEqual(TEXT("the URL carries the gameplay experience"),
		Request->ExtraArgs.FindRef(TEXT("Experience")), ExperienceId.PrimaryAssetName.ToString());
	TestEqual(TEXT("experience extra arguments are kept"), Request->ExtraArgs.FindRef(TEXT("Keep")), FString(TEXT("1")));
	return true;
}

IMPLEMENT_SIMPLE_AUTOMATION_TEST(
	FHaivenLyraMatchRewardTest,
	"Haiven.LyraDemo.MatchReward",
	EAutomationTestFlags::EditorContext | EAutomationTestFlags::EngineFilter)

bool FHaivenLyraMatchRewardTest::RunTest(const FString& Parameters)
{
	APlayerState* Local = NewObject<APlayerState>(GetTransientPackage(), TEXT("HaivenLocalPlayerState"));
	APlayerState* Bot = NewObject<APlayerState>(GetTransientPackage(), TEXT("HaivenBotPlayerState"));
	TestTrue(TEXT("eliminating a bot earns the match reward"),
		HaivenLyraGameplay::IsRewardingElimination(Local, Local, Bot));
	TestFalse(TEXT("being eliminated earns nothing"), HaivenLyraGameplay::IsRewardingElimination(Local, Bot, Local));
	TestFalse(TEXT("another player's elimination earns nothing"),
		HaivenLyraGameplay::IsRewardingElimination(Local, Bot, Bot));
	TestFalse(TEXT("eliminating yourself earns nothing"), HaivenLyraGameplay::IsRewardingElimination(Local, Local, Local));
	TestFalse(TEXT("an unknown instigator earns nothing"), HaivenLyraGameplay::IsRewardingElimination(Local, nullptr, Bot));
	TestFalse(TEXT("no local player state earns nothing"), HaivenLyraGameplay::IsRewardingElimination(nullptr, nullptr, Bot));
	return true;
}

#endif
