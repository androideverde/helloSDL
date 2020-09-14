# helloSDL
Hello world with SDL C++ library

## Requisites
This program depends on having SDL2 libraries installed in `/Library/Frameworks`. You can get SDL from here: http://www.libsdl.org/download-2.0.php

## Generating the project
In order to build this on a Mac using XCode, you'll need to run the `./helloSDL/generate_project.sh` script. After running it you'll find an XCode project file generated in `./helloSDL/build/helloSDL.xcodeproj`. Double-click on it to load the project into XCode.

## Building from the Command Line
Once the project is generated, you can build it without using XCode UI with the following command in a terminal from directory `./helloSDL`:
```
  xcodebuild -project build/helloSDL.xcodeproj -target helloSDL -configuration Debug
```

## How to run the game
- From within XCode: Load the XCode project and launch the build
- From the Command Line: Launch the executable in `./helloSDL/build/Debug/helloSDL` built by XCode
