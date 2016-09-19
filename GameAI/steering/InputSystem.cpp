#include "InputSystem.h"
#include "Game.h"

InputSystem::InputSystem()
{
	mpEventQueue = NULL;
	mEscape = true;
	mF = true;
	mS = true;
	mLMouseClick = true;
}


InputSystem::~InputSystem()
{
	cleanup();
}


void InputSystem::init()
{
	

	if (!al_install_keyboard()) ///setup the keyboard
	{
		al_show_native_message_box(NULL, "Error!", "Failed to install keyboard.", 0, 0, ALLEGRO_MESSAGEBOX_ERROR);
		std::terminate();
	}

	if (!al_install_mouse()) ///setup the mouse
	{
		al_show_native_message_box(NULL, "Error!", "Failed to install mouse.", 0, 0, ALLEGRO_MESSAGEBOX_ERROR);
		std::terminate();
	}

	mpEventQueue = al_create_event_queue();
	if (mpEventQueue == NULL)
	{
		std::cout << "This could be a problem... Allegro couldn't initialize the image addon.\n";
		std::terminate();
	}

	al_register_event_source(mpEventQueue, al_get_display_event_source(gpGame->getGraphicsSystem()->getDisplay()));
	al_register_event_source(mpEventQueue, al_get_keyboard_event_source());
	al_register_event_source(mpEventQueue, al_get_mouse_event_source());
	std::cout << ALLEGRO_KEY_A;

}


void InputSystem::update()
{
	while (al_get_next_event(mpEventQueue, &mEvent))
	{
		mCurrentType = mEvent.type;
		if (mEvent.type == ALLEGRO_EVENT_KEY_DOWN || mEvent.type == ALLEGRO_EVENT_MOUSE_BUTTON_DOWN)
		{
			if (mEvent.keyboard.keycode == ESCAPE)
			{
				gpEventSystem->fireEvent(QUIT_GAME);
			}
			else if (mEvent.mouse.button == RIGHT_CLICK)
			{
				Vector2D temp(mEvent.mouse.x, mEvent.mouse.y);
				gpEventSystem->fireEvent(MousePosEvent(DELETE_UNIT, temp));
			}
			else if (mEvent.mouse.button == LEFT_CLICK)
			{
				Vector2D temp(mEvent.mouse.x, mEvent.mouse.y);
				gpEventSystem->fireEvent(MousePosEvent(ADD_UNIT, temp));
			}
			else if (mEvent.keyboard.keycode == SPACE)
			{
				gpEventSystem->fireEvent(FREEZE_ANIMATION);
			}
		}

		/*
		if( al_key_down( &keyState, ALLEGRO_KEY_ESCAPE ) )
		{
			mShouldExit = true;
		}
		*/
	}
}


void InputSystem::cleanup()
{
	al_uninstall_keyboard();
	al_uninstall_mouse();
	al_destroy_event_queue(mpEventQueue);
	//delete mEventQueue;
	mpEventQueue = NULL;
}