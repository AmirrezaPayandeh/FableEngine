#pragma once

#include "Core/Input/Input.h"

FABLE_NAMESPACE_BEGIN

class WindowsInput : public Input
{
protected:
	virtual bool IsKeyPressedImpl(int keycode) const override;

	virtual bool IsMouseButtonPressedImpl(int button) const override;
	virtual std::pair<float, float> GetMousePositionImpl() const override;
	virtual float GetMouseXImpl() const override;
	virtual float GetMouseYImpl() const override;
};

FABLE_NAMESPACE_END