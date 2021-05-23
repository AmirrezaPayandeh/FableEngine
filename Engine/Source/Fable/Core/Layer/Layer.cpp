#include "FablePCH.h"
#include "Layer.h"

FABLE_NAMESPACE_BEGIN

Layer::Layer(const std::string& name)
	: m_DebugName(name)
{
}

Layer::~Layer()
{
}

void Layer::OnAttach()
{
}

void Layer::OnDetach()
{
}

void Layer::OnUpdate()
{
}

void Layer::OnImGuiRender()
{
}

void Layer::OnEvent(Event& event)
{
}

FABLE_NAMESPACE_END