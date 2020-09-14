#include <CApp.h>

#include <chrono>

CApp::CApp()
	: mRunning(true)
	, mSurface(nullptr)
	, mWindow(nullptr)
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
	double lag = 0.0;
	while (mRunning)
	{
		// adjust time step
		auto currentTime = std::chrono::system_clock::now();
		std::chrono::duration<double> elapsedTime = currentTime - previousTime;
		previousTime = currentTime;
		lag += elapsedTime.count() * 1000; // in milliseconds
		
		// process inputs
		while (SDL_PollEvent(&event))
		{
			OnEvent(&event);
		}
		
		while (lag >= MS_PER_UPDATE)
		{
			OnLoop();
			lag -= MS_PER_UPDATE;
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
	mWindow = SDL_CreateWindow("SDL Tutorial", 0, 0, 640, 480, SDL_WINDOW_SHOWN);
	if (mWindow == nullptr)
	{
		return false;
	}
	mSurface = SDL_GetWindowSurface(mWindow);
	SDL_FillRect(mSurface, nullptr, SDL_MapRGB(mSurface->format, 0xFF, 0xFF, 0xFF));
	return true;
}

void CApp::OnEvent(SDL_Event* event)
{
	if (event->type == SDL_QUIT)
	{
		mRunning = false;
	}
}

void CApp::OnLoop()
{
}

void CApp::OnRender()
{
	SDL_UpdateWindowSurface(mWindow);
}

void CApp::OnCleanup()
{
	SDL_DestroyWindow(mWindow);
	mWindow = nullptr;
	SDL_Quit();
}
