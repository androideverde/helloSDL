#pragma once

#include <SDL.h>
#include <vector>

class CCandy {
public:
	CCandy(int x, int y, int vx, int vy, const std::string& file_path);
	~CCandy();
	void MoveBy(int x, int y);
	const SDL_Point& getPos() const { return mPos; }
	std::vector<int> getVelocity() const { return mVelocity; }
	SDL_Surface* getSurface() const { return mImage; }
private:
	SDL_Point mPos;
	std::vector<int> mVelocity;
	SDL_Surface* mImage;
};
