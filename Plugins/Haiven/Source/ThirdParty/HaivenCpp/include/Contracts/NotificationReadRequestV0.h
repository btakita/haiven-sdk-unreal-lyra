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
	/// A request to mark a notification category as read.
	struct NotificationReadRequestV0
	{
		/// The notification category used for grouping and read state.
		std::string Kind;
	};

}
