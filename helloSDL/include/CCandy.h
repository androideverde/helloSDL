#pragma once

#include <SDL.h>
#include <vector>

class CCandy {
public:
	CCandy(int x, int y, int vx, int vy);
	~CCandy();
	void MoveBy(int delta_x, int delta_y);
	void SetPos(int x, int y);
	const SDL_Point& getPos() const { return mPos; }
	std::vector<int> getVelocity() const { return mVelocity; }
	SDL_Surface* getSurface() const { return mImage; }
	bool LoadImage(const std::string& file_path);
private:
	SDL_Point mPos;
	std::vector<int> mVelocity;
	SDL_Surface* mImage;
};
