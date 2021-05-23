#include "FablePCH.h"
#include "Layer/LayerStack.h"

FABLE_NAMESPACE_BEGIN

LayerStack::LayerStack()
{
}

LayerStack::~LayerStack()
{
	for (Layer* layer : m_Layers)
	{
		if (layer)
			delete layer;
	}
}

void LayerStack::PushLayer(Layer* layer)
{
	m_Layers.emplace(m_Layers.begin() + m_LayerInsertIndex, layer);
	m_LayerInsertIndex++;
	layer->OnAttach();
}

void LayerStack::PushOverlay(Layer* overlay)
{
	m_Layers.emplace_back(overlay);
	overlay->OnAttach();
}

void LayerStack::PopLayer(Layer* layer)
{
	auto it = std::find(m_Layers.begin(), m_Layers.end(), layer);
	if (it != m_Layers.end())
	{
		m_Layers.erase(it);
		m_LayerInsertIndex--;
		layer->OnDetach();
	}
}

void LayerStack::PopOverlay(Layer* overlay)
{
	auto it = std::find(m_Layers.begin(), m_Layers.end(), overlay);
	if (it != m_Layers.end())
		m_Layers.erase(it);
	overlay->OnDetach();
}

FABLE_NAMESPACE_END