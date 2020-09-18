#include <CEvent.h>

CEvent::CEvent()
{
}

CEvent::~CEvent()
{
}

void CEvent::OnEvent(SDL_Event *event)
{
	switch (event->type) {
		case SDL_QUIT:
			OnExit();
			break;
			
		default:
			break;
	}
}
