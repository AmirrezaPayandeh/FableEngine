#include "FablePCH.h"
#include "ApplicationCore.h"

FABLE_NAMESPACE_BEGIN

ApplicationCore::ApplicationCore()
{
	m_Window = std::unique_ptr<GenericWindow>(GenericWindow::Create());
}

ApplicationCore::~ApplicationCore()
{
}

void ApplicationCore::Run()
{
	while (m_Running)
	{
		m_Window->OnUpdate();
	}
}

FABLE_NAMESPACE_END
