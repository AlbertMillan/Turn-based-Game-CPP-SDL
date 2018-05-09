#ifndef SCREENEND_H
#define SCREENEND_H

//#include "Game.h"
#include "ImageGroup.h"

//using namespace std;


class ScreenEnd {

    public:
    	// Initialize variables
		ScreenEnd( const char* title, const char* subtitle );
		ScreenEnd( const char* title, const char* subtitle, const char* subsubtitle );
		
		~ScreenEnd();
	
		// Load Images/Text
		void loadMedia(const char* soundPath);

		//void eventHandler( SDL_Event event);

		// Update
		void update();

		// Draw Images/Text
		void render();

		// Clean
		void clean();

    protected:
		const char* bigText;
		const char* midText;
		const char* bottomText;
		ImageGroup set;
		TTF_Font *bigFont;
		TTF_Font *smallFont;
		Mix_Music *bMusic;
		int frame;
};

#endif
