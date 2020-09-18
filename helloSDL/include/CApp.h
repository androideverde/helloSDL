#pragma once

#include <SDL.h>
#include <CCandy.h>
#include <string>

class CApp
{
public:
	CApp();
	int OnExecute();
	bool OnInit();
	void OnEvent(SDL_Event* event);
	void OnLoop(float delta_time);
	void OnRender();
	void OnCleanup();
private:
	bool mRunning;
	SDL_Surface* mSurface;
	SDL_Surface* mBackground;
	SDL_Window* mWindow;
	CCandy mRedCandy;
	const int MS_PER_UPDATE = 16;

	bool LoadBackground();
	bool LoadResources();
	void RenderCandies();
};
