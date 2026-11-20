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
	/// The socket a resumed participation is now bound to.
	struct SessionResumeReplyV0
	{
		/// The resumed participation.
		std::string ParticipationId;

		/// The server-generated WebSocket connection identifier.
		std::string ConnectionId;
	};

}
