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
	/// The payload of a chat channel event.
	struct WsChatChannelEventV0
	{
		/// The community the channel belongs to.
		std::string CommunityId;

		/// The channel this event is about.
		std::string ChannelId;

		/// The user who created the channel.
		std::string CreatedByUserId;

		/// The channel name, or null when it has none.
		std::optional<std::string> Name;

		/// The category the channel is grouped under, or null when it is ungrouped.
		std::optional<std::string> Category;

		/// The channel's sort position within its category, or null when unordered.
		std::optional<int> Position;
	};

}
