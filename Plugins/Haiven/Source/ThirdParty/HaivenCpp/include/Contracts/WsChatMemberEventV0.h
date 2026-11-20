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
	/// The payload of a chat community membership change.
	struct WsChatMemberEventV0
	{
		/// The community whose membership changed.
		std::string CommunityId;

		/// The member who joined or left.
		std::string UserId;

		/// The member's display name at the time of the change.
		std::string DisplayName;
	};

}
