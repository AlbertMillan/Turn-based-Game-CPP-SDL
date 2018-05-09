#ifndef SCREEN_H
#define SCREEN_H

//#include "Game.h"
#include "ImageGroup.h"

//using namespace std;


class Screen {

    public:
    	// Initialize Screen
		Screen();
	
		~Screen();

		// Loads Images/Media 
		void loadMedia(TTF_Font *gFont1);

		// Handles keyboard input
		void eventHandler( SDL_Event event);

		// Updates 
		void update();

		// Renders media
		void render();

		// Clears components
		void clean();

    protected:
		ImageGroup set;
		int cursorPos;
		Mix_Music *bMusic;
};

#endif
