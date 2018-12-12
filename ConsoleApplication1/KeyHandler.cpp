#include "stdafx.h"
#include "KeyHandler.h"
#include "Game.h"


std::map< std::string, sf::Keyboard::Key >KeyHandler::_keyMap;
std::vector<sf::Event>KeyHandler::_eventList;
KeyHandler::KeyHandler()
{
	

	_keyMap["A"] = sf::Keyboard::A;
	_keyMap["B"] = sf::Keyboard::B;
	_keyMap["C"] = sf::Keyboard::C;
	_keyMap["D"] = sf::Keyboard::D;
	_keyMap["F"] = sf::Keyboard::F;
	_keyMap["G"] = sf::Keyboard::G;
	_keyMap["H"] = sf::Keyboard::H;
	_keyMap["I"] = sf::Keyboard::I;
	_keyMap["J"] = sf::Keyboard::J;
	_keyMap["K"] = sf::Keyboard::K;
	_keyMap["L"] = sf::Keyboard::L;
	_keyMap["M"] = sf::Keyboard::M;
	_keyMap["N"] = sf::Keyboard::N;
	_keyMap["O"] = sf::Keyboard::O;
	_keyMap["P"] = sf::Keyboard::P;
	_keyMap["Q"] = sf::Keyboard::Q;
	_keyMap["R"] = sf::Keyboard::R;
	_keyMap["S"] = sf::Keyboard::S;
	_keyMap["T"] = sf::Keyboard::T;
	_keyMap["U"] = sf::Keyboard::U;
	_keyMap["V"] = sf::Keyboard::V;
	_keyMap["W"] = sf::Keyboard::W;
	_keyMap["X"] = sf::Keyboard::X;
	_keyMap["Y"] = sf::Keyboard::Y;
	_keyMap["Z"] = sf::Keyboard::Z;
	_keyMap["0"] = sf::Keyboard::Num0;
	_keyMap["1"] = sf::Keyboard::Num1;
	_keyMap["2"] = sf::Keyboard::Num2;
	_keyMap["3"] = sf::Keyboard::Num3;
	_keyMap["4"] = sf::Keyboard::Num4;
	_keyMap["5"] = sf::Keyboard::Num5;
	_keyMap["6"] = sf::Keyboard::Num6;
	_keyMap["7"] = sf::Keyboard::Num7;
	_keyMap["8"] = sf::Keyboard::Num8;
	_keyMap["9"] = sf::Keyboard::Num9;
	_keyMap["Escape"] = sf::Keyboard::Escape;
	_keyMap["LControl"] = sf::Keyboard::LControl;
	_keyMap["LShift"] = sf::Keyboard::LShift;
	_keyMap["LAlt"] = sf::Keyboard::LAlt;
	_keyMap["LSystem"] = sf::Keyboard::LSystem;
	_keyMap["RControl"] = sf::Keyboard::RControl;
	_keyMap["RShift"] = sf::Keyboard::RShift;
	_keyMap["Menu"] = sf::Keyboard::Menu;
	_keyMap["LBracket"] = sf::Keyboard::LBracket;
	_keyMap["RBracket"] = sf::Keyboard::RBracket;
	_keyMap["SemiColon"] = sf::Keyboard::SemiColon;
	_keyMap["Comma"] = sf::Keyboard::Comma;
	_keyMap["Period"] = sf::Keyboard::Period;
	_keyMap["Quote"] = sf::Keyboard::Quote;
	_keyMap["Slash"] = sf::Keyboard::Slash;
	_keyMap["BackSlash"] = sf::Keyboard::BackSlash;
	_keyMap["Tilde"] = sf::Keyboard::Tilde;
	_keyMap["Equal"] = sf::Keyboard::Equal;
	_keyMap["Dash"] = sf::Keyboard::Dash;
	_keyMap["Space"] = sf::Keyboard::Space;
	_keyMap["Return"] = sf::Keyboard::Return;
	_keyMap["BackSpace"] = sf::Keyboard::BackSpace;
	_keyMap["Tab"] = sf::Keyboard::Tab;
	_keyMap["PageUp"] = sf::Keyboard::PageUp;
	_keyMap["PageDown"] = sf::Keyboard::PageDown;
	_keyMap["End"] = sf::Keyboard::End;
	_keyMap["Home"] = sf::Keyboard::Home;
	_keyMap["Insert"] = sf::Keyboard::Insert;
	_keyMap["Delete"] = sf::Keyboard::Delete;
	_keyMap["Add"] = sf::Keyboard::Add;
	_keyMap["Subtract"] = sf::Keyboard::Subtract;
	_keyMap["Multiply"] = sf::Keyboard::Multiply;
	_keyMap["Divide"] = sf::Keyboard::Divide;
	_keyMap["Left"] = sf::Keyboard::Left;
	_keyMap["Right"] = sf::Keyboard::Right;
	_keyMap["Up"] = sf::Keyboard::Up;
	_keyMap["Down"] = sf::Keyboard::Down;
}
//liste

KeyHandler::~KeyHandler()
{
}



sf::Keyboard::Key KeyHandler::GetKey(std::string key)
{
	return _keyMap.at(key);
}

bool KeyHandler::KeyPressed(std::string key)
{
	return sf::Keyboard::isKeyPressed(_keyMap.at(key));
}

void KeyHandler::AddEvent(sf::Event event)
{
	_eventList.push_back(event);
}

bool KeyHandler::KeyDown(std::string key)
{
	for (int i = 0; i < _eventList.size(); i++)
	{	
		if (_eventList[i].type == sf::Event::KeyPressed && KeyPressed(key))
		{
			//std::cout << _eventList[i].KeyPressed << " -Key" << std::endl;
			if (_eventList[i].key.code == _keyMap.at(key))
			{
				return true;
			}
		}
	}
	return false;
	
}

bool KeyHandler::KeyUp(std::string key)
{
	for (int i = 0; i < _eventList.size(); i++)
	{
		if (_eventList[i].type== sf::Event::KeyReleased && !KeyPressed(key))
		{
			if (_eventList[i].key.code == _keyMap.at(key))
			{
			
			_eventList.erase(_eventList.begin() + i);
			return true;
			}
			
		}
		
	}
	return false;


}
//bool KeyHandler::KeyDown(std::string key)
//{
//	std::cout << "Getting here" << std::endl;
//	if (_event->key.code == _keyMap.at(key))
//	{
//		_eventList.push_back(_event->key.code);
//	}
//
//	return false;
////}
//bool KeyHandler::KeyDown(std::string key)
//{
//	_window = Game::GetInstance()->GetWindow();
//	while (_window->pollEvent(*_event))
//	{
//		if (_event->type == sf::Event::Closed)
//			_window->close();
//		if (_event->type == sf::Event::KeyPressed)
//		{
//			if (_event->key.code == _keyMap.at(key))
//			{
//				return true;
//			}
//		}
//	}
//	return false;
//}
//bool KeyHandler::KeyUp(std::string key)
//{
//	//if (_event != nullptr) delete _event;
//	//_event = new sf::Event;
//	//while (_window->pollEvent(*_event))
//	//{
//	//	for (int i = 0; i < _eventList.size(); i++)
//	//	{
//	//		if (_event->type == sf::Event::KeyReleased)
//	//		{
//	//			std::cout << "Getting here" << std::endl;
//	//			if (_event->key.code == _keyMap.at(key))
//	//			{
//	//				return true;
//	//				//_eventList.push_back(event.type);
//	//			}
//	//			else return false;
//	//		}
//	//	}
//	//}
//	return false;
//
//}

void KeyHandler::EventLoop()
{
	/*_window = Game::GetInstance()->GetWindow();
	if (_event != nullptr) delete _event;
	_event = new sf::Event;
	while (_window->pollEvent(*_event))
	{
		if (_event->type == sf::Event::Closed)
			_window->close();
		if (_event->type == _eventList[5])
		{
			if (KeyDown("S"))
				std::cout << "S is pressed" << std::endl;

			if (KeyDown("W"))
				std::cout << "W is pressed" << std::endl;
		}
	}*/
}

void KeyHandler::SetEvent(sf::Event* event)
{
	_event = event;
}




