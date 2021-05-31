#pragma once

#include "Core/Misc/CoreDefinitions.h"
#include "Renderer/VertexBuffer.h"
#include "Renderer/BufferLayout.h"

FABLE_NAMESPACE_BEGIN

class OPENGLRENDERER_API OpenGLVertexBuffer : public VertexBuffer
{
public:
	OpenGLVertexBuffer(uint32 size, float* vertecies);
	virtual ~OpenGLVertexBuffer();

	virtual void Bind() const override;
	virtual void Unbind() const override;

	virtual const BufferLayout& GetLayout() const override { return m_Layout; }
	virtual void SetLayout(const BufferLayout& layout) override { m_Layout = layout; }
private:
	uint32 m_RendererID;
	BufferLayout m_Layout;
};

FABLE_NAMESPACE_END