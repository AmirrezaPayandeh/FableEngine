#include "FablePCH.h"
#include "IndexBuffer.h"

#include "Renderer.h"
#include "OpenGLRenderer/OpenGLIndexBuffer.h"

FABLE_NAMESPACE_BEGIN

IndexBuffer* IndexBuffer::Create(uint32 count, uint32* indecies)
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
			return new OpenGLIndexBuffer(count, indecies);
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