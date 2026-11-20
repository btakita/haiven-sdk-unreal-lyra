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
	/// A request to replace a chat message's content.
	struct ChatEditRequestV0
	{
		/// The chat message identifier.
		std::string MessageId;

		/// The user-authored message content.
		std::string Content;
	};

}
