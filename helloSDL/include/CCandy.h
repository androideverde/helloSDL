#pragma once

#include <SDL.h>
#include <vector>

class CCandy {
public:
	CCandy(int x, int y, int vx, int vy, float angle, const std::string& imagePath);
	~CCandy();
	void MoveBy(int delta_x, int delta_y);
	void SetPos(int x, int y);
	const SDL_Rect& getRect() const { return mRect; }
	std::vector<int> getVelocity() const { return mVelocity; }
	const std::string& getImagePath() const { return mImagePath; }
	SDL_Texture* getImageTex() const { return mImageTex; }
	const float GetAngle() const { return mAngle; }
	void SetAngle(const float angle);
	void Rotate(const float angle);
	bool LoadTexture(SDL_Renderer* renderer);
private:
	SDL_Rect mRect;
	std::vector<int> mVelocity;
	const std::string& mImagePath;
	SDL_Texture* mImageTex;
	float mAngle;
};
