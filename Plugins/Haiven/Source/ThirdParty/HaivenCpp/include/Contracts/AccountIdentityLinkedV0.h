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
	/// A Google or Apple identity linked to the account from settings.
	struct AccountIdentityLinkedV0
	{
		/// The sign-in provider of the identity: google or apple.
		std::string Provider;

		/// The email address the provider gave for the identity, which can differ from the account's.
		std::string Email;
	};

}
