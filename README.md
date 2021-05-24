# Fable Engine [![License](https://img.shields.io/github/license/AmirrezaPayandeh/FableEngine?color=009000&style=flat-square)](https://github.com/AmirrezaPayandeh/FableEngine/blob/master/LICENSE)

![Fable](/Engine/Resources/Branding/Fable_Engine_Logo_Gray.png?raw=true "Fable")

Welcome to the Fable Engine source code!

Currently Fable Engine only supports ***Windows***. I'm trying to understand **[Unreal Engine](https://www.unrealengine.com)** source code and create my own game engine from scratch. Feel free to contribute and modify it as you want.

My main reference to learn how game engines are made is from **[The Cherno](https://www.youtube.com/playlist?list=PLlrATfBNZ98dC-V-N3m0Go4deliWHPFwT)** youtube playlist of how to make a game engine.

## Getting Started

Visual Studio 2019 is recommended. The steps below will take you through cloning your own fork, then compiling and running the editor yourself:

1. Install **[GitHub for Windows](https://windows.github.com/)** then **[fork and clone our repository](https://guides.github.com/activities/forking/)**. 
   To use Git from the command line, see the [Setting up Git](https://help.github.com/articles/set-up-git/) and [Fork a Repo](https://help.github.com/articles/fork-a-repo/) articles.

   If you'd prefer not to use Git, you can get the source with the 'Download ZIP' button on the right. The built-in Windows zip utility will mark the contents of zip files 
   downloaded from the Internet as unsafe to execute, so right-click the zip file and select 'Properties...' and 'Unblock' before decompressing it. Third-party zip utilities don't normally do this.

1. Install **Visual Studio (2019 recommended)**. 
   All desktop editions of Visual Studio 2019 can build Fable Engine.

1. Run **GenerateProjectFiles.bat** to create project files for the engine. It should take less than a minute to complete.

1. Load the project into Visual Studio by double-clicking on the **FableEngine.sln** file. Under the **Engine** group right click on the **FE** target and select **Build**. It may take some time to finish compiling, depending on your system specs.

1. After compiling finishes, you can load the editor from Visual Studio by pressing **F5** to debug.

### Additional target platforms
As mentioned earlier Fable Engine currently supports ***Windows***. Future versions of the engine will support multiple platforms.

## Future Roadmap
The plan for Fable is to make a simple yet powerfull engine. Obviously making such engine takes lots of efforts and as I'm not working full-time on this project this will take time. The main goal is to learn from making such engine. Here is the main roadmap for what I will implement into the engine:

- Basic Renderer Setup
- Camera System
- Entity Component System
- Material System
- Simple Editor
- Integrated 3rd Party 2D and 3D Physics Engine
- Support for Linux, Mac, Android and iOS
   - Native Rendering API Support (Vulkan, DirectX, Metal)
- Audio System
- Artificial Intelligence
