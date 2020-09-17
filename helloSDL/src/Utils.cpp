#include <Utils.h>

SDL_Surface* Utils::LoadImage(const std::string& file_str)
{
	const char* file = file_str.c_str();
	SDL_Surface* temp = IMG_Load(file);
	if (temp == nullptr)
	{
		printf( "Unable to load image %s! SDL Error: %s\n", file, SDL_GetError() );
		return nullptr;
	}
	return temp;
}
