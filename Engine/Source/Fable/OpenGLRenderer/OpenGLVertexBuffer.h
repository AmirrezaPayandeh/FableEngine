#pragma once

#include "Core/Misc/CoreDefinitions.h"
#include "Renderer/VertexBuffer.h"

FABLE_NAMESPACE_BEGIN

class OPENGLRENDERER_API OpenGLVertexBuffer : public VertexBuffer
{
public:
	OpenGLVertexBuffer(uint32 size, float* vertecies);
	virtual ~OpenGLVertexBuffer();

	virtual void Bind() const override;
	virtual void Unbind() const override;
private:
	uint32 m_RendererID;
};

FABLE_NAMESPACE_END