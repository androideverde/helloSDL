#pragma once

#include <SDL.h>
#include <SDL_image.h>
#include <string>

namespace Utils
{
	SDL_Surface* LoadImage(const std::string& file_str);
}
