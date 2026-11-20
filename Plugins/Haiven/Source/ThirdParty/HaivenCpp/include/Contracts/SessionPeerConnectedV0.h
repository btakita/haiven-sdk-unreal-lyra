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
	/// The host's report that the data channel to a guest is open.
	struct SessionPeerConnectedV0
	{
		/// The session the guest belongs to.
		std::string SessionId;

		/// The guest whose data channel opened.
		std::string UserId;
	};

}
