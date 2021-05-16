#pragma once

#include "Core/CoreTypes.h"

namespace LogLevel
{
	enum Type : uint8
	{
		/** Not used */
		NoLogging = 0,

		/** Always prints a fatal error to console (and log file) and crashes. */
		Fatal,

		/** Prints an error to console (and log file). */
		Error,

		/** Prints a warning to console (and log file). */
		Warn,

		/** Prints a message to console (and log file) */
		Info,

		/** Prints a message to console (and log file) */
		Trace,

		// Log masks and special Enum values

		All,
		NumLevel,
		LevelMask = 0xf // not actually a level, used to mask big numbers
	};
};
