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
	/// A recipient's acknowledgement of one signaling message.
	struct P2pSignalAckV0
	{
		/// The session both members belong to.
		std::string SessionId;

		/// The original sender of the acknowledged message.
		std::string ToUserId;

		/// The attempt of the acknowledged message.
		std::string AttemptId;

		/// The sequence number of the acknowledged message.
		int Seq;
	};

}
