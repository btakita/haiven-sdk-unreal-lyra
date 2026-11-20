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
	/// A signaling message delivered to its recipient, with the sender the server authenticated.
	struct P2pSignalReceivedV0
	{
		/// The session both members belong to.
		std::string SessionId;

		/// The sender as the server authenticated it.
		std::string FromUserId;

		/// The sender's connection attempt.
		std::string AttemptId;

		/// The sender's sequence number within the attempt.
		int Seq;

		/// The sender's opaque signaling data.
		std::string Data;
	};

}
