#pragma once

#ifdef FB_PLATFORM_WINDOWS

extern Fable::ApplicationCore* Fable::CreateApplication();

int main(int argc, char** argv)
{
	Fable::Log::Init();
	FB_LOG(Engine, Info, "Welcome to Fable Engine!");

	auto app = Fable::CreateApplication();
	app->Run();
	delete app;
}

#endif
