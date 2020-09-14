#pragma once

#include <SDL.h>

class CApp
{
public:
	CApp();
	int OnExecute();
	bool OnInit();
	void OnEvent(SDL_Event* event);
	void OnLoop();
	void OnRender();
	void OnCleanup();
private:
	bool mRunning;
	SDL_Surface* mSurface;
	SDL_Window* mWindow;
	const int MS_PER_UPDATE = 16;
};
