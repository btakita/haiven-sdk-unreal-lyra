// Generated from the published Haiven contract schemas. Do not edit by hand.
//
// The nullability of a presence discriminant is deliberate and is NOT derived
// from `required`.

#pragma once

#include <optional>
#include <string>
#include <vector>

namespace Haiven
{
	/// The payload of a chat community update.
	struct WsChatServerEventV0
	{
		/// The community this event is about.
		std::string CommunityId;

		/// The community's display name after the update.
		std::string Name;

		/// The community's icon, or null when it has none.
		std::optional<std::string> IconUrl;
	};

}
