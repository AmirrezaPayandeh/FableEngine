#pragma once

FABLE_NAMESPACE_BEGIN

class RENDERER_API VertexBuffer
{
public:
	virtual ~VertexBuffer() {}

	virtual void Bind() const = 0;
	virtual void Unbind() const = 0;

	static VertexBuffer* Create(uint32 size, float* vertecies);
};

FABLE_NAMESPACE_END
