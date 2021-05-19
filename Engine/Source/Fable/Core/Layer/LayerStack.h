#pragma once

#include "Layer.h"

FABLE_NAMESPACE_BEGIN

class CORE_API LayerStack
{
	using LayerVector = std::vector<Layer*>;
	using LayerVectorIterator = std::vector<Layer*>::iterator;
public:
	LayerStack();
	~LayerStack();

	void PushLayer(Layer* layer);
	void PushOverlay(Layer* overlay);
	void PopLayer(Layer* layer);
	void PopOverlay(Layer* overlay);

	LayerVectorIterator begin() { return m_Layers.begin(); }
	LayerVectorIterator end() { return m_Layers.end(); }
private:
	LayerVector m_Layers;
	LayerVectorIterator m_LayerInsert;
};

FABLE_NAMESPACE_END