#pragma once

#include <SDL.h>

class CEvent
{
public:
	CEvent();
	virtual ~CEvent();
	virtual void OnEvent(SDL_Event* event);
	virtual void OnExit() = 0;
};
