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
	/// The payload a client sends on a chat.edit frame, replacing the text of a message it authored.
	struct WsChatEditRequestV0
	{
		/// The message to edit.
		std::string MessageId;

		/// The replacement message text.
		std::string Content;
	};

}
