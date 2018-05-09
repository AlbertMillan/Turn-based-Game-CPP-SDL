// 20027140 scyam1 Albert Millan Truyols
#include <iostream>
#include <SDL2/SDL.h>
#include "GameManager.h"
using namespace std;

Game *game = NULL;

int main()
{
	// Create new game class.
    game = new Game();
	
	// Initialize SDL libraries.
    if ( game->init( "Redania", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SDL_WINDOW_SHOWN ) )
    {
		// Load screens, and images.
		if ( game->loadMedia() ) 
		{

			game->set_initial_variables();

			// Game loop, executed every frame
			while ( !game->isFinished() )
	   	    {
				game->eventHandler();
				game->update();
		   		game->render();
			}
		}
    }

    game->clean();
	delete game;

    return 0;
}
