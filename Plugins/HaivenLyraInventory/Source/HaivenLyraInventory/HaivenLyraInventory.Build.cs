// Unlike HaivenLyraDemo, this module depends on LyraGame (for the inventory
// manager), so it builds only inside a Lyra project, the way Lyra's own game
// feature plugins do.

using UnrealBuildTool;

public class HaivenLyraInventory : ModuleRules
{
	public HaivenLyraInventory(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;
		CppStandard = CppStandardVersion.Cpp20;
		// The inline C++ SDK headers use exceptions even in Shipping targets.
		bEnableExceptions = true;

		PublicDependencyModuleNames.AddRange(new string[]
		{
			"Core",
			"CoreUObject",
			"Engine",
			"DeveloperSettings",
		});

		PrivateDependencyModuleNames.AddRange(new string[]
		{
			"CommonUser",
			"GameplayMessageRuntime",
			"GameplayTags",
			"HaivenLyraDemo",
			"LyraGame",
		});
	}
}
