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
	/// A link of a Google or Apple identity started from settings that was refused or abandoned.
	struct AccountIdentityLinkFailedV0
	{
		/// The sign-in provider of the identity: google or apple.
		std::string Provider;

		/// The error code the link was refused with, such as identity_already_linked.
		std::string Code;
	};

}
