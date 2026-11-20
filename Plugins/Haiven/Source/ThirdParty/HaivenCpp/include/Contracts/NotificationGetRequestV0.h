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
	/// A notification lookup request.
	struct NotificationGetRequestV0
	{
		/// The stable identifier of this value.
		std::string Id;
	};

}
