#ifndef SCREENF_H
#define SCREENF_H

//#include "Game.h"
#include "Image.h"
#include "ImageGroup.h"
#include "Rectangle.h"
#include "Player.h"
#include "Screen.h"
#include <sstream>

using namespace std;


class Screenf : public Screen {

    public:
		// Define fonts and initial positions of some images
		Screenf( bool defineLevel );
	
		~Screenf();

		// Load components of the screen
		void loadMedia( const char* soundPath );

		// Handle Keyboard events
		void eventHandler( SDL_Event event);

		// Update changes to the screen
		void update();

		// Render screen
		void render();

		// Clean screen components
		void clean();

    private:
		// Generic function to create Image objects containing text
		Image* generate_image( TTF_Font* font, const char* str, int x, int y );

		// Fills animated sprites into array
		void fill_sprites();

		// Generic function to process the turn of a player/enemies
		void player_turn();
	
		// Increases difficulty (stats) of zombies in second level.
		bool isLvlTwo;

		// STATE VARIABLES
		int selectedAction;     // Stores the player's action                                    				  ( NONE, Attack, Sp.Attack, Block)
		int selectedTarget;		// Stores the id of the enemy being attacked by a player           				  ( NONE, HALO, ZOMBIE, PESTILENT )
		int currentTurn;		// Stores the id of the player's character attacking on this turn 				  ( NONE, GOKU, WARIO, LINK )
		int currentAction;      // Separates a character's turn into phases, and processes movement accordingly   ( IDDLE, MOTION, ATTACK, BACK_MOTION )
		int frameTimer;
		int frame;

		SDL_Texture* fontSup;
		Image* gBackground;
		
		// BOTTOM MENU BOXES
		Rectangle *bRect;
		Rectangle* outRect;
		Rectangle* leftRect;
		Rectangle* rightRect;
		Rectangle* midRect;


		stringstream strManager;
	
		
		SDL_Rect sprite[60];		// Array with all animation sprites
		TTF_Font *gFont2;
		TTF_Font *gFont3;
		TTF_Font *gFont4;
};

#endif
