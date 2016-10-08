#include "InputSystem.h"
#include "Game.h"

InputSystem::InputSystem()
{
	mpEventQueue = NULL;

}


InputSystem::~InputSystem()
{
	cleanup();
}


void InputSystem::init(bool isMouseVisible)
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

	if (isMouseVisible)
	{
		if (!al_hide_mouse_cursor(GRAPHICS_SYSTEM->getDisplay()))
		{
			printf("Mouse cursor not able to be hidden!\n");
			std::terminate();
		}
	}

	al_register_event_source(mpEventQueue, al_get_display_event_source(GRAPHICS_SYSTEM->getDisplay()));
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
			}/*
			else if (mEvent.keyboard.keycode == A)
			{
				gpEventSystem->fireEvent(ADD_DINAMIC_ARRIVE);

			}*/
			else if (mEvent.keyboard.keycode == S)
			{
				gpEventSystem->fireEvent(ADD_WANDER_AND_SEEK);
			}
			else if (mEvent.keyboard.keycode == F)
			{
				gpEventSystem->fireEvent(ADD_WANDER_AND_FLEE);
			}
			else if (mEvent.keyboard.keycode == D)
			{
				gpEventSystem->fireEvent(DELETE_UNIT);
			}
			else if (mEvent.keyboard.keycode == I)
			{
				gpEventSystem->fireEvent(DEBUG);
			}
			else if (mEvent.keyboard.keycode == PLUS)
			{
				gpEventSystem->fireEvent(INCREASE_SELECTED_VALUE);
			}
			else if (mEvent.keyboard.keycode == MINUS)
			{
				gpEventSystem->fireEvent(REDUCE_SELECTED_VAULUE);
			}
			else if (mEvent.keyboard.keycode == V)
			{
				gpEventSystem->fireEvent(SELECT_ENEMY_VELOCITY);
			}
			else if (mEvent.keyboard.keycode == R)
			{
				gpEventSystem->fireEvent(SELECT_REACTION_RAD);
			}
			else if (mEvent.keyboard.keycode == A)
			{
				gpEventSystem->fireEvent(SELECT_ANGULAR_VELOCITY);
			}	

		}
		
		ALLEGRO_MOUSE_STATE mouseState;
		al_get_mouse_state(&mouseState);

		if (al_mouse_button_down(&mouseState, 1))//left mouse click
		{
			Vector2D pos(mouseState.x, mouseState.y);
			
			//new MousePosEvent(MOVE_PLAYER, pos)
			

			MousePosEvent pMessage(MOVE_PLAYER, pos);
			gpEventSystem->fireEvent(pMessage);
			//GameMessage* pMessage = new PlayerMoveToMessage(pos);
			//MESSAGE_MANAGER->addMessage(pMessage, 0);
		}


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