#include"stdafx.h"
#include "Game.h"
using namespace std;



int main()
{
	Game* game = Game::GetInstance();
	game->Start();
	game->Update();

	return 0;
}





