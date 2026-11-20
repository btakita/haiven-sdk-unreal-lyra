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
	/// One signaling message from a session member to another, relayed by the server.
	struct P2pSignalV0
	{
		/// The session both members belong to.
		std::string SessionId;

		/// The member to deliver the message to.
		std::string ToUserId;

		/// One connection attempt including an ICE restart.
		std::string AttemptId;

		/// Rises from 1 within the attempt.
		int Seq;

		/// Opaque to the server: at most 4096 bytes.
		std::string Data;
	};

}
