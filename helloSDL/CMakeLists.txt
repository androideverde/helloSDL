cmake_minimum_required(VERSION 3.10)
set(CMAKE_CXX_STANDARD 14)

# set the project name
project(helloSDL)

# add the executable
add_executable(helloSDL)

# add SDL library dependency
include_directories(/Library/Frameworks/SDL2.framework/Headers)
target_link_libraries(helloSDL /Library/Frameworks/SDL2.framework/SDL2)

# add the sources
file(GLOB project_files "src/*.cpp" "include/*.h")
target_sources(helloSDL PRIVATE ${project_files})

# add the includes
include_directories(include)
