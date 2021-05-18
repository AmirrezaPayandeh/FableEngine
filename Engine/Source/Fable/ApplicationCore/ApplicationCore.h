#pragma once

#include "Core/CoreMinimal.h"
#include "GenericWindow/GenericWindow.h"

FABLE_NAMESPACE_BEGIN

class APPLICATIONCORE_API ApplicationCore
{
public:
	ApplicationCore();
	virtual ~ApplicationCore();

	void Run();
private:
	std::unique_ptr<GenericWindow> m_Window;
	bool m_Running = true;
};

// To be defined in CLIENT
ApplicationCore* CreateApplication();

FABLE_NAMESPACE_END
