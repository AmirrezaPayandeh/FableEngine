#include "FablePCH.h"
#include "VertexBuffer.h"

#include "Renderer.h"
#include "OpenGLRenderer/OpenGLVertexBuffer.h"

FABLE_NAMESPACE_BEGIN

VertexBuffer* VertexBuffer::Create(uint32 size, float* vertecies)
{
	switch (Renderer::GetAPI())
	{
		case RendererAPI::None:
		{
			FB_ASSERT(Engine, false, "RendererAPI::None is currently not supported!");
			return nullptr;
		}
		case RendererAPI::OpenGL:
		{
			return new OpenGLVertexBuffer(size, vertecies);
		}
		case RendererAPI::Vulkan:
		{
			FB_ASSERT(Engine, false, "RendererAPI::Vulkan is currently not supported!");
			return nullptr;
		}
	}
	FB_ASSERT(Engine, false, "Unknown Renderer API!");
	return nullptr;
}

FABLE_NAMESPACE_END
