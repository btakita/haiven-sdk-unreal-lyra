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
	/// The host changed the session's state, visibility or metadata.
	struct SessionUpdatedV0
	{
		/// The session.
		std::string SessionId;

		/// Whether the session takes joins: open does and locked does not.
		std::string State;

		/// Who may find and join the session.
		std::string Visibility;

		/// The most members the session holds.
		int MaxMembers;

		/// The six-character code of a private session: null otherwise.
		std::optional<std::string> JoinCode;

		/// The game's own key and value pairs.
		std::string Metadata;
	};

}
