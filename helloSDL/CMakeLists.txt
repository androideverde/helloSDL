cmake_minimum_required(VERSION 3.10)
set(CMAKE_CXX_STANDARD 14)

# set the project name
project(helloSDL)

# add the executable
add_executable(helloSDL)

# add SDL library dependency
include_directories(/Library/Frameworks/SDL2.framework/Headers)
target_link_libraries(helloSDL /Library/Frameworks/SDL2.framework/SDL2)

# add SDL_image library dependency
include_directories(/Library/Frameworks/SDL2_image.framework/Headers)
target_link_libraries(helloSDL /Library/Frameworks/SDL2_image.framework/SDL2_image)

# add the sources
file(GLOB project_files "src/*.cpp" "include/*.h")
target_sources(helloSDL PRIVATE ${project_files})

# add the includes
include_directories(include)

# ensure ./assets is copied to the build directory
set (source "${CMAKE_SOURCE_DIR}/assets")
set (destination "${CMAKE_CURRENT_BINARY_DIR}/assets")
add_custom_command(
 TARGET helloSDL POST_BUILD
 COMMAND ${CMAKE_COMMAND} -E create_symlink ${source} ${destination}
 DEPENDS ${destination}
 COMMENT "symbolic link resources folder from ${source} => ${destination}"
)
