#pragma once

#include "BufferLayout.h"

FABLE_NAMESPACE_BEGIN

class RENDERER_API VertexBuffer
{
public:
	virtual ~VertexBuffer() {}

	virtual void Bind() const = 0;
	virtual void Unbind() const = 0;

	virtual const BufferLayout& GetLayout() const = 0;
	virtual void SetLayout(const BufferLayout& layout) = 0;

	static VertexBuffer* Create(uint32 size, float* vertecies);
};

FABLE_NAMESPACE_END
