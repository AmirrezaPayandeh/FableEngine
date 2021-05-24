#pragma once

#include "Core/Misc/CoreDefinitions.h"
#include "Core/CoreTypes.h"
#include <string>

FABLE_NAMESPACE_BEGIN

class RENDERER_API Shader
{
public:
	Shader(const std::string& vertexSrc, const std::string& fragmentSrc);
	~Shader();

	void Bind() const;
	void Unbind() const;
private:
	uint32 m_RendererID;
};

FABLE_NAMESPACE_END
