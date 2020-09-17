#include <CCandy.h>

#include <Utils.h>

CCandy::CCandy(int x, int y, int vx, int vy, const std::string& file_path)
	: mPos{x, y}
	, mVelocity{vx, vy}
	, mImage(Utils::LoadImage(file_path))
{
}

CCandy::~CCandy()
{
	SDL_FreeSurface(mImage);
}
