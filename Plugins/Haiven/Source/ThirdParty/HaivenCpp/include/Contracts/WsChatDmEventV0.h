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
	struct WsChatDmEventV0Friend
	{
		/// The other member's user identifier.
		std::string Id;

		/// When the other member left the direct message, or null while they are still in it.
		std::optional<std::string> LeftAt;
	};

	/// The payload of a direct-message membership event.
	struct WsChatDmEventV0
	{
		/// The direct-message channel this event is about.
		std::string ChannelId;

		/// The other member of the direct message.
		WsChatDmEventV0Friend Friend;
	};

}
