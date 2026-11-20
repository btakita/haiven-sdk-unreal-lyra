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
	/// A member's participation ended; the host closes its connection to that member.
	struct SessionMemberLeftV0
	{
		/// The session.
		std::string SessionId;

		/// The member whose participation ended.
		std::string UserId;

		/// The participation that ended.
		std::string ParticipationId;

		/// Why the participation ended.
		std::string Reason;
	};

}
