#include <CCandy.h>

#include <Utils.h>

CCandy::CCandy(int x, int y, int vx, int vy, float angle, const std::string& imagePath)
	: mRect{x, y, 0, 0}
	, mVelocity{vx, vy}
	, mImagePath(imagePath)
	, mImageTex(nullptr)
	, mAngle(angle)
{
}

CCandy::~CCandy()
{
	SDL_DestroyTexture(mImageTex);
	mImageTex = nullptr;
}

bool CCandy::LoadTexture(SDL_Renderer* renderer)
{
	mImageTex = Utils::LoadImage(mImagePath, renderer);
	if (mImageTex == nullptr)
	{
		return false;
	}
	SDL_QueryTexture(mImageTex, nullptr, nullptr, &mRect.w, &mRect.h);
	return true;
}

void CCandy::MoveBy(int delta_x, int delta_y)
{
	mRect.x += delta_x;
	mRect.y += delta_y;
	mRect.x %= 755;
	mRect.y %= 600;
}

void CCandy::SetPos(int x, int y)
{
	mRect.x = x;
	mRect.y = y;
}

void CCandy::SetAngle(const float angle)
{
	mAngle = angle;
}

void CCandy::Rotate(const float angle)
{
	mAngle += angle;
}
