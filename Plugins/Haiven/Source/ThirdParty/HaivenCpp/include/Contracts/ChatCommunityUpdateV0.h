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
	/// A visible update to a chat community.
	struct ChatCommunityUpdateV0
	{
		/// The chat community identifier.
		std::string CommunityId;

		/// The human-readable name of this value.
		std::string Name;

		/// The URL of the chat community icon, or null when it has no icon.
		std::string IconUrl;

		/// The URL of the chat community cover image, or null when it has no cover.
		std::string CoverUrl;
	};

}
