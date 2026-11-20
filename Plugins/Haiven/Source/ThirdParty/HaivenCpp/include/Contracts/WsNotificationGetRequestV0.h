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
	/// The payload a client sends on a notifications.get frame, selecting one notification.
	struct WsNotificationGetRequestV0
	{
		/// The notification to fetch.
		std::string Id;
	};

}
