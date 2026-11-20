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
	struct PresenceV0Status
	{
		/// The emoji associated with the user's status.
		std::string Emoji;

		/// The text associated with the user's status.
		std::string Text;

		/// The time at which this value expires.
		std::string ExpiresAt;
	};

	struct PresenceV0Availability
	{
		/// The current state represented by this value.
		std::string State;

		/// The time at which this value expires.
		std::string ExpiresAt;
	};

	/// A user's current availability and status.
	struct PresenceV0
	{
		/// The user identifier.
		std::string UserId;

		/// The user's current availability state.
		PresenceV0Availability Availability;

		/// The user's current custom status.
		PresenceV0Status Status;
	};

}
