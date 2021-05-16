#pragma once

#include "Core.h"

FABLE_NAMESPACE_BEGIN

class FABLE_API Application
{
public:
	Application();
	virtual ~Application();

	void Run();
};

// To be defined in CLIENT
Application* CreateApplication();

FABLE_NAMESPACE_END
