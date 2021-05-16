#include "SandboxEditor.h"

SandboxEditor::SandboxEditor()
{
}

SandboxEditor::~SandboxEditor()
{
}

Fable::Application* Fable::CreateApplication()
{
	return new SandboxEditor();
}
