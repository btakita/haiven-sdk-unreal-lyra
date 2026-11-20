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
	/// A chat community its owner deleted; the last event it sends before its subscribers are dropped.
	struct ChatCommunityDeletedV0
	{
		/// The chat community identifier.
		std::string CommunityId;
	};

}
