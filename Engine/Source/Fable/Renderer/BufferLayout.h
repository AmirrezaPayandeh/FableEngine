#pragma once


FABLE_NAMESPACE_BEGIN

enum class ShaderDataType : uint8
{
	None = 0,
	Float, Float2, Float3, Float4,
	Mat3, Mat4,
	Int, Int2, Int3, Int4,
	Bool
};

static uint32 ShaderDataTypeSize(ShaderDataType type)
{
	switch (type)
	{
		case ShaderDataType::Float:     return 4;
		case ShaderDataType::Float2:    return 4 * 2;
		case ShaderDataType::Float3:    return 4 * 3;
		case ShaderDataType::Float4:    return 4 * 4;
		case ShaderDataType::Mat3:      return 4 * 3 * 3;
		case ShaderDataType::Mat4:      return 4 * 4 * 4;
		case ShaderDataType::Int:       return 4;
		case ShaderDataType::Int2:      return 4 * 2;
		case ShaderDataType::Int3:      return 4 * 3;
		case ShaderDataType::Int4:      return 4 * 4;
		case ShaderDataType::Bool:      return 1;
	}

	FB_ASSERT(Engine, false, "Unkown Shader Data Type!");
	return 0;
}

struct BufferElement
{
	std::string Name;
	ShaderDataType Type;
	uint32 Offset;
	uint32 Size;
	bool Normalized;

	BufferElement() {}

	BufferElement(ShaderDataType type, const std::string& name, bool normalized = false)
		: Name(name), Type(type), Size(ShaderDataTypeSize(type)), Offset(0), Normalized(normalized)
	{
	}

	uint32 GetComponentCount() const
	{
		switch (Type)
		{
			case ShaderDataType::Float:     return 1;
			case ShaderDataType::Float2:    return 2;
			case ShaderDataType::Float3:    return 3;
			case ShaderDataType::Float4:    return 4;
			case ShaderDataType::Mat3:      return 3 * 3;
			case ShaderDataType::Mat4:      return 4 * 4;
			case ShaderDataType::Int:       return 1;
			case ShaderDataType::Int2:      return 2;
			case ShaderDataType::Int3:      return 3;
			case ShaderDataType::Int4:      return 4;
			case ShaderDataType::Bool:      return 1;
		}

		FB_ASSERT(Engine, false, "Unkown Shader Data Type!");
		return 0;
	}
};

class RENDERER_API BufferLayout
{
	using BufferElementVectorIterator = std::vector<BufferElement>::iterator;
	using BufferElementConstVectorIterator = std::vector<BufferElement>::const_iterator;
public:
	BufferLayout() {}

	BufferLayout(const std::initializer_list<BufferElement>& elements)
		: m_Elements(elements)
	{
		CalculateOffsetsAndStride();
	}

	inline const std::vector<BufferElement>& GetElememts() const { return m_Elements; }
	inline uint32 GetStride() const { return m_Stride; }

	BufferElementVectorIterator begin() { return m_Elements.begin(); }
	BufferElementVectorIterator end() { return m_Elements.end(); }
	BufferElementConstVectorIterator begin() const { return m_Elements.begin(); }
	BufferElementConstVectorIterator end() const { return m_Elements.end(); }
private:
	void CalculateOffsetsAndStride()
	{
		uint32 offset = 0;
		m_Stride = 0;
		for (auto& element : m_Elements)
		{
			element.Offset = offset;
			offset += element.Size;
			m_Stride += element.Size;
		}
	}
private:
	std::vector<BufferElement> m_Elements;
	uint32 m_Stride = 0;
};

FABLE_NAMESPACE_END
