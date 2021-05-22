#pragma once

#ifdef FB_ENABLE_ASSERTS
#define FB_ASSERT(CategoryName, x, ...) \
			{ \
				if (!(x)) \
				{ \
					FB_LOG(CategoryName, Error, "Assertion Failed: {0}", __VA_ARGS__); \
					DEBUGBREAK(); \
				} \
			}
#else
#define FB_ASSERT(x, ...)
#endif
