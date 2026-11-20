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
	/// A player joined the peer-to-peer session.
	struct SessionMemberJoinedV0
	{
		/// The session.
		std::string SessionId;

		/// The member.
		std::string UserId;

		/// The member's participation.
		std::string ParticipationId;
	};

}
