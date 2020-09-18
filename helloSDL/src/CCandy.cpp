#include <CCandy.h>

#include <Utils.h>

CCandy::CCandy(int x, int y, int vx, int vy)
	: mPos{x, y}
	, mVelocity{vx, vy}
	, mImage(nullptr)
{
}

CCandy::~CCandy()
{
	SDL_FreeSurface(mImage);
	mImage = nullptr;
}

void CCandy::MoveBy(int delta_x, int delta_y)
{
	mPos.x += delta_x;
	mPos.y += delta_y;
	mPos.x %= 755;
	mPos.y %= 600;
}

void CCandy::SetPos(int x, int y)
{
	mPos.x = x;
	mPos.y = y;
}

bool CCandy::LoadImage(const std::string& file_path)
{
	mImage = Utils::LoadImage(file_path);
	if (mImage == nullptr)
	{
		return false;
	}
	return true;
}
