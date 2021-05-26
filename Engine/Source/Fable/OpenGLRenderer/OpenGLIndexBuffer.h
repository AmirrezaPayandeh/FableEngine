#pragma once

#include "Core/Misc/CoreDefinitions.h"
#include "Renderer/IndexBuffer.h"

FABLE_NAMESPACE_BEGIN

class OPENGLRENDERER_API OpenGLIndexBuffer : public IndexBuffer
{
public:
	OpenGLIndexBuffer(uint32 count, uint32* indecies);
	virtual ~OpenGLIndexBuffer();

	virtual void Bind() const override;
	virtual void Unbind() const override;
	virtual uint32 GetCount() const override;
private:
	uint32 m_RendererID;
	uint32 m_Count;
};

FABLE_NAMESPACE_END