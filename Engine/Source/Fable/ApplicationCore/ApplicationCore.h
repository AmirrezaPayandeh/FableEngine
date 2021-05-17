#pragma once

#include "Core/CoreMinimal.h"

#ifndef FB_PLATFORM_WINDOWS
	#error Fable only supports windows!
#endif

FABLE_NAMESPACE_BEGIN

class FABLE_API ApplicationCore
{
public:
	ApplicationCore();
	virtual ~ApplicationCore();

	void Run();
};

// To be defined in CLIENT
ApplicationCore* CreateApplication();

FABLE_NAMESPACE_END
