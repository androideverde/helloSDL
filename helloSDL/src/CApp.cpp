#include <CApp.h>

#include <chrono>
#include <algorithm>

#include <SDL_image.h>
#include <Utils.h>
#include <CCandy.h>

CApp::CApp()
	: mRunning(true)
	, mSurface(nullptr)
	, mBackground(nullptr)
	, mWindow(nullptr)
	, mRedCandy(0, 0, 0, 0, "../assets/Red.png")
{
}

// main entry point
int CApp::OnExecute()
{
	// initialise
	if (!OnInit())
	{
		return -1;
	}
	SDL_Event event;
	
	// game loop
	auto previousTime = std::chrono::system_clock::now();
	int lag_ms = 0;
	while (mRunning)
	{
		// adjust time step
		auto currentTime = std::chrono::system_clock::now();
		int elapsed_ms = std::chrono::duration_cast<std::chrono::milliseconds>(currentTime - previousTime).count();
		previousTime = currentTime;
		elapsed_ms = std::max(200, elapsed_ms);
		lag_ms += elapsed_ms;
		
		// process inputs
		while (SDL_PollEvent(&event))
		{
			OnEvent(&event);
		}
		
		while (lag_ms >= MS_PER_UPDATE)
		{
			OnLoop(MS_PER_UPDATE / 1000);
			lag_ms -= MS_PER_UPDATE;
		}
		OnRender();
	}
	
	// destroy everything
	OnCleanup();
	
	return 0;
}

bool CApp::OnInit()
{
	if (SDL_Init(SDL_INIT_EVERYTHING) < 0)
	{
		return false;
	}
	mWindow = SDL_CreateWindow("SDL Tutorial", 0, 0, 755, 600, SDL_WINDOW_SHOWN);
	if (mWindow == nullptr)
	{
		return false;
	}
	mSurface = SDL_GetWindowSurface(mWindow);
	if (!SetBackground()) {
		return false;
	}
	return true;
}

bool CApp::SetBackground()
{
	mBackground = Utils::LoadImage("../assets/BackGround.jpg");
	if (mBackground == nullptr) {
		return false;
	}
	SDL_Rect pos;
	pos.x = 0;
	pos.y = 0;
	SDL_BlitSurface(mBackground, nullptr, mSurface, &pos);
	return true;
}

void CApp::RenderCandies()
{
	SDL_Rect pos;
	pos.x = mRedCandy.getPos().x;
	pos.y = mRedCandy.getPos().y;
	SDL_BlitSurface(mRedCandy.getSurface(), nullptr, mSurface, &pos);
}

void CApp::OnEvent(SDL_Event* event)
{
	if (event->type == SDL_QUIT)
	{
		mRunning = false;
	}
}

void CApp::OnLoop(float delta_time)
{
	mRedCandy.MoveBy(1, 1);
}

void CApp::OnRender()
{
	SDL_BlitSurface(mBackground, nullptr, mSurface, nullptr);
	RenderCandies();
	SDL_UpdateWindowSurface(mWindow);
}

void CApp::OnCleanup()
{
	SDL_FreeSurface(mSurface);
	mSurface = nullptr;
	SDL_FreeSurface(mBackground);
	mBackground = nullptr;
	SDL_DestroyWindow(mWindow);
	mWindow = nullptr;
	SDL_Quit();
}
