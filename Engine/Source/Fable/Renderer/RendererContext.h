#pragma once

#include "Core/Misc/CoreDefinitions.h"

FABLE_NAMESPACE_BEGIN

class RENDERER_API RendererContext
{
public:
	virtual void Init() = 0;
	virtual void SwapBuffers() = 0;
};

FABLE_NAMESPACE_END
