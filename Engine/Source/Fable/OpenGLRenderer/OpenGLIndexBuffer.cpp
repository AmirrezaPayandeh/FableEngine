#include "FablePCH.h"
#include "OpenGLIndexBuffer.h"

#include <Glad/glad.h>

FABLE_NAMESPACE_BEGIN

OpenGLIndexBuffer::OpenGLIndexBuffer(uint32 count, uint32* indecies)
	: m_Count(count)
{
	glCreateBuffers(1, &m_RendererID);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_RendererID);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, count * sizeof(uint32), indecies, GL_STATIC_DRAW);
}

OpenGLIndexBuffer::~OpenGLIndexBuffer()
{
	glDeleteBuffers(1, &m_RendererID);
}

void OpenGLIndexBuffer::Bind() const
{
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_RendererID);
}

void OpenGLIndexBuffer::Unbind() const
{
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
}

uint32 OpenGLIndexBuffer::GetCount() const
{
	return m_Count;
}

FABLE_NAMESPACE_END
