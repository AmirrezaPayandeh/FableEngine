#include "FablePCH.h"
#include "OpenGLVertexBuffer.h"

#include <Glad/glad.h>

FABLE_NAMESPACE_BEGIN

OpenGLVertexBuffer::OpenGLVertexBuffer(uint32 size, float* vertecies)
{
	glCreateBuffers(1, &m_RendererID);
	glBindBuffer(GL_ARRAY_BUFFER, m_RendererID);
	glBufferData(GL_ARRAY_BUFFER, size, vertecies, GL_STATIC_DRAW);
}

OpenGLVertexBuffer::~OpenGLVertexBuffer()
{
	glDeleteBuffers(1, &m_RendererID);
}

void OpenGLVertexBuffer::Bind() const
{
	glBindBuffer(GL_ARRAY_BUFFER, m_RendererID);
}

void OpenGLVertexBuffer::Unbind() const
{
	glBindBuffer(GL_ARRAY_BUFFER, 0);
}

FABLE_NAMESPACE_END
