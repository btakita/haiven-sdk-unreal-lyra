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
	/// The payload of a chat typing event.
	struct WsChatTypingEventV0
	{
		/// The channel the typing state applies to.
		std::string ChannelId;

		/// The user whose typing state changed.
		std::string UserId;

		/// Whether the user is currently typing.
		bool IsTyping;
	};

}
