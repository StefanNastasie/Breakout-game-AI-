//============================================================================
// Name        : test.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include "Game.h"

int main()
{
	//Init game engine



	Game game;


    //Game loop

    while (game.running())
    {

    	//Update game
    	game.update();


		//Render
    	game.render();

    	//std::cout<< dt <<"\n";

    }


    return 0;
}
