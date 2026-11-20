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
	/// A peer-to-peer session closed; every member stops playing in it.
	struct SessionClosedV0
	{
		/// The session.
		std::string SessionId;

		/// The end reason of the host's participation that closed the session.
		std::string Reason;
	};

}
