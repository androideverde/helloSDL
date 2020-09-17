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
	SDL_Window* mWindow;
	const int MS_PER_UPDATE = 16;
	bool SetBackground();
	CCandy mRedCandy;
};
