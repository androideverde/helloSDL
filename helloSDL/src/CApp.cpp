#include <CApp.h>

#include <chrono>
#include <algorithm>
#include <thread>

#include <SDL_image.h>
#include <Utils.h>
#include <CCandy.h>

CApp::CApp()
	: mRunning(true)
	, mSurface(nullptr)
	, mBackground(nullptr)
	, mWindow(nullptr)
	, mRedCandy(0, 0, 150, 100)
	, mYellowCandy(400, 300, 0, 0)
	, mRotating(false)
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
			OnLoop(MS_PER_UPDATE / 1000.0f);
			lag_ms -= MS_PER_UPDATE;
		}
		OnRender();
		std::this_thread::sleep_for(std::chrono::milliseconds(10));
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
	if (!LoadResources())
	{
		return false;
	}
	return true;
}

bool CApp::LoadResources()
{
	if (!LoadBackground())
	{
		return false;
	}
	if (!mRedCandy.LoadImage("../assets/Red.png"))
	{
		return false;
	}
	if (!mYellowCandy.LoadImage("../assets/Yellow.png"))
	{
		return false;
	}
	return true;
}

bool CApp::LoadBackground()
{
	mBackground = Utils::LoadImage("../assets/BackGround.jpg");
	if (mBackground == nullptr) {
		return false;
	}
	return true;
}

void CApp::RenderCandies()
{
	SDL_Rect pos;
	pos.x = mRedCandy.getPos().x;
	pos.y = mRedCandy.getPos().y;
	SDL_BlitSurface(mRedCandy.getSurface(), nullptr, mSurface, &pos);
	pos.x = mYellowCandy.getPos().x;
	pos.y = mYellowCandy.getPos().y;
	SDL_BlitSurface(mYellowCandy.getSurface(), nullptr, mSurface, &pos);
}

void CApp::OnEvent(SDL_Event* event)
{
	CEvent::OnEvent(event);
}

void CApp::OnExit()
{
	mRunning = false;
}

void CApp::OnMouseMove(int x, int y, int delta_x, int delta_y, bool l_button, bool r_button, bool m_button)
{
	if (mRotating)
	{
		mYellowCandy.SetPos(x, y);
	}
}

void CApp::OnLButtonDown(int x, int y)
{
	mRotating ? mRotating = false : mRotating = true;
}

void CApp::OnRButtonDown(int x, int y)
{
}

void CApp::OnMButtonDown(int x, int y)
{
}

void CApp::OnLoop(float delta_time)
{
	int delta_x = mRedCandy.getVelocity()[0] * delta_time;
	int delta_y = mRedCandy.getVelocity()[1] * delta_time;
	mRedCandy.MoveBy(delta_x, delta_y);
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
