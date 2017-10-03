#pragma once

#ifndef __InputHandler__
#define __InputHandler__

#include "SDL.h"
#include <vector>
#include "Vector2D.h"

class InputHandler
{
	InputHandler() {}
	~InputHandler(){}

	static InputHandler* s_pInstance;

	std::vector<SDL_Joystick*> m_joysticks;

	//a vector of pairs(one for each stick)
	std::vector<std::pair<Vector2D*, Vector2D*>> m_joystickValues;

	//a vector of vector(for each joystick and all of its buttons)
	std::vector<std::vector<bool>> m_buttonStates;

	//variable to account the sensitivity of the controller
	const int m_joystickDeadZone = 10000;

	bool m_bJoysticksInitialised;

public:

	static InputHandler* Instance()
	{
		if (s_pInstance == 0)
		{
			s_pInstance = new InputHandler();
		}
		return s_pInstance;
	}

	void initialiseJoysticks();

	bool joysticksInitialised();

	//Function to check if a specific button was pressed on a specific joystick
	bool getButtonState(int joy, int buttonNumber);

	//joy = Joystick identifier, stick = 1(left) and 2(right)
	int xvalue(int joy, int stick);
	int yvalue(int joy, int stick);

	void update();
	void clean();
};

typedef InputHandler TheInputHandler;

#endif //defined(__InputHandler__)