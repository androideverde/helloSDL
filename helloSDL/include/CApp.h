#pragma once

#include <SDL.h>
#include <CCandy.h>
#include <CEvent.h>
#include <string>

class CApp : public CEvent
{
public:
	CApp();
	int OnExecute();
	bool OnInit();
	void OnEvent(SDL_Event* event);
	void OnExit();
	void OnLButtonDown(int x, int y);
	void OnRButtonDown(int x, int y);
	void OnMButtonDown(int x, int y);
	void OnMouseMove(int x, int y, int delta_x, int delta_y, bool l_button, bool r_button, bool m_button);
	void OnLoop(float delta_time);
	void OnRender();
	void OnCleanup();
private:
	bool mRunning;
	SDL_Surface* mSurface;
	SDL_Surface* mBackground;
	SDL_Window* mWindow;
	CCandy mRedCandy;
	CCandy mYellowCandy;
	const int MS_PER_UPDATE = 16;
	bool mRotating;

	bool LoadBackground();
	bool LoadResources();
	void RenderCandies();
};
