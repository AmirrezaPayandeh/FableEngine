#pragma once


FABLE_NAMESPACE_BEGIN

enum class RendererAPI
{
	None = 0,
	OpenGL,
	Vulkan
};

class RENDERER_API Renderer
{
public:
	inline static RendererAPI GetAPI() { return s_RendererAPI; }
private:
	static RendererAPI s_RendererAPI;
};

FABLE_NAMESPACE_END