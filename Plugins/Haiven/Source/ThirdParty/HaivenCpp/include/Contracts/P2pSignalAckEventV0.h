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
	/// An acknowledgement delivered to the member that sent the signaling message.
	struct P2pSignalAckEventV0
	{
		/// The session both members belong to.
		std::string SessionId;

		/// The member that acknowledged as the server authenticated it.
		std::string FromUserId;

		/// The attempt of the acknowledged message.
		std::string AttemptId;

		/// The sequence number of the acknowledged message.
		int Seq;
	};

}
