#pragma once

FABLE_NAMESPACE_BEGIN

class RENDERER_API IndexBuffer
{
public:
	virtual ~IndexBuffer() {}

	virtual void Bind() const = 0;
	virtual void Unbind() const = 0;

	virtual uint32 GetCount() const = 0;

	static IndexBuffer* Create(uint32 count, uint32* indecies);

};

FABLE_NAMESPACE_END
	