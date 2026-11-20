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
	/// A server frame the client did not ask for.
	struct WsServerEventV0
	{
		/// The frame discriminator, naming what happened.
		std::string Type;

		/// The event body, whose shape is determined by the type field.
		std::optional<std::string> Payload;
	};

}
