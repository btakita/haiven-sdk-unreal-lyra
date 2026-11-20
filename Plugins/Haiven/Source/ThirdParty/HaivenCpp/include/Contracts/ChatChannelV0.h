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
	/// A chat channel visible to a gaming client.
	struct ChatChannelV0
	{
		/// The chat community identifier.
		std::string CommunityId;

		/// The chat channel identifier.
		std::string ChannelId;

		/// The identifier of the user who created the channel.
		std::string CreatedByUserId;

		/// The human-readable name of this channel.
		std::string Name;

		/// The category used to group the channel.
		std::string Category;

		/// The display order of the channel within its category.
		int Position;
	};

}
