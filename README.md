# Raylib-Quickstart
A simple cross platform template for setting up a project with the bleeding edge Raylib + Raylib-cpp code.
Works with C or C++.

Special thanks to HarenDev for both providing the quickstart base and the PA0 implementation.

## Supported Platforms
Quickstart supports the main 3 desktop platforms:
* Windows
* Linux
* MacOS 

### Windows Users
You need to have a C++ compiler toolchain installed to be able to build this project.
* Go to official RayLib site and get the Windows installer: [https://www.raylib.com/](https://www.raylib.com/)
* Run the installer. Install RayLib in `C:`
* To access the C++ compiler for this we will install `w64devkit` in `C:`. This also allows for compiling C++ in general using this tool instead of msys2. You can get it at: [https://github.com/skeeto/w64devkit/releases](https://github.com/skeeto/w64devkit/releases) 
Depending on your system, get the x64 or x86 version of the .exe file. Once it’s downloaded, run it and choose where it gets extracted, again this should be in `C:`.
Once you get the kit, you need to update your Environmental Variables and include the following path: `C:\w64devkit\bin`.

### MacOS
You need to have the raylib library installed. 

To do this you need to do the following in the Terminal:
* Have XCode installed. Install it using the command: `xcode-select --install`
* Have Homebrew installed. Install it using the command: `/bin/bash -c "$(curl -fsSL https://raw.githubusercontent.com/Homebrew/install/HEAD/install.sh)"`
* Install raylib: `brew install raylib`

# Creating Your Project
* Click the "Use This Template" button to make your own copy of this project. 
* The name of the repository you create will be the name of the project when you build it.

# VSCode Users (all platforms)

* Clone you new project repository
* Open the folder in VSCode
* Run the build task ( CTRL+SHIFT+B or F5 )
* You are good to go

## Windows Users
There are two compiler toolchains available for windows, MinGW-W64 (a free compiler using GCC), and Microsoft Visual Studio
### Using MinGW-W64
* Double click the `build-MinGW-W64.bat` file
* CD into the folder in your terminal
* run `make CXXFLAGS=-Wno-shadow -w -j4` or `mingw32-make CXXFLAGS=-Wno-shadow -w -j4`
* You are good to go

### Microsoft Visual Studio
* Run `build-VisualStudio2022.bat`
* double click the `.sln` file that is generated
* develop your game
* you are good to go

## Linux Users
* CD into the build folder
* run `./premake5 gmake2`
* CD back to the root
* run `make -j4`
* you are good to go

### Note on Linux Environments
You may get missing xorg depedency errors when trying to build the project.
You just need to obtain the relevant xorg development packages for your relevant system.

Debian systems (such as Ubuntu):
* run `apt-get install xorg-dev`
* you should be good to go

## MacOS Users
* CD into the build folder
* run `./premake5.osx gmake2`
* CD back to the root
* run `make -j4`
* you are good to go

# Output files
The built code will be in the bin dir

# Running the program
* `Run -> Start Debugging`
OR
* Go to the Debug Tab
* Press the play button

# Resources folder
The example uses a utility function from `path_utils.h` that will find the resources dir and set it as the current working directory. This means that when accessing assets in resources we do not need to reference resources. 

The resource directory will have all resources needed for the app such as images, audio, etc. 
Initially the project has:
- `images`
- `audio`
- `fonts`

Resource folders can be subdivided into more specific resources. For example, `images` could have the subfolders `images/sprites` and `images/spritesheet`.

# Main File
The file that will execute the whole program will be `src/main.cpp`. 
You can add more directories and files, but the executable will be `main.cpp`. 

Feel free to remove the `program.hpp` and `program.cpp` files as these are just an example on how to use additional files.

# Usefull links
* This project is based on this template supplied by a students: [repo](https://github.com/HarenDev/raylib-quickstart-cpp). This is made specifically for working on C++ since RayLib is mainly for working in C.
* The previous repo is based on this official template from RayLib: [repo](https://github.com/raylib-extras/raylib-quickstart). This is purely C based.
* A cheatsheet with all functions RayLib has: [cheatsheet](https://www.raylib.com/cheatsheet/cheatsheet.html)

# Building for other OpenGL targets
If you need to build for a different OpenGL version than the default (OpenGL 3.3) you can specify an OpenGL version in your premake command line. Just modify the bat file or add the following to your command line

## For OpenGL 1.1
`--graphics=opengl11`

## For OpenGL 2.1
`--graphics=opengl21`

## For OpenGL 4.3
`--graphics=opengl43`

## For OpenGLES 2.0
`--graphics=opengles2`

## For OpenGLES 3.0
`--graphics=opengles3`

# License
Copyright (c) 2020-2025 Jeffery Myers

This software is provided "as-is", without any express or implied warranty. In no event 
will the authors be held liable for any damages arising from the use of this software.

Permission is granted to anyone to use this software for any purpose, including commercial 
applications, and to alter it and redistribute it freely, subject to the following restrictions:

  1. The origin of this software must not be misrepresented; you must not claim that you 
  wrote the original software. If you use this software in a product, an acknowledgment 
  in the product documentation would be appreciated but is not required.

  2. Altered source versions must be plainly marked as such, and must not be misrepresented
  as being the original software.

  3. This notice may not be removed or altered from any source distribution.
