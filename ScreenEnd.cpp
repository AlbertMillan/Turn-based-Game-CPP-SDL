#include "ScreenEnd.h"
#include "LTexture.h"
#include "Constants.h"

	// Constructor for Level 1 completed screen
    ScreenEnd::ScreenEnd(const char* title, const char* subtitle ){
		bigFont   = TTF_OpenFont( "fonts/emulogic.ttf", 38 );
		smallFont = TTF_OpenFont( "fonts/emulogic.ttf", 22 );
		bigText    = title;
		midText    = NULL;
		bottomText = subtitle;
		frame = 0;
    }

	// Game win/loose constructor
    ScreenEnd::ScreenEnd(const char* title, const char* subtitle, const char* subsubtitle ){
		bigFont   = TTF_OpenFont( "fonts/emulogic.ttf", 38 );
		smallFont = TTF_OpenFont( "fonts/emulogic.ttf", 22 );
		bigText    = title;
		midText    = subtitle;
		bottomText = subsubtitle;
		frame = 0;
    }

	ScreenEnd::~ScreenEnd(){}

	// Load Media, soundPath is the path of the sound file stored
    void ScreenEnd::loadMedia( const char* soundPath ){
		Image *congratsMessage1 = NULL;
		Image *congratsMessage2 = NULL;
		Image *credits = NULL;
		Image *background = NULL;
		
		int word_w, word_h;
		
		SDL_Color whiteColor = { 255, 255, 255 };
		SDL_Texture *fontSup = NULL;

		// Black Screen
		background = new Image( 0, 0, w_width, w_height );
		background->set_image( LTexture::loadTexture( "images/BlackBackground.jpg") );
		set.add( background );

		// Text Images
		fontSup = LTexture::loadFont( bigFont, bigText,  whiteColor );
		SDL_QueryTexture(fontSup, NULL, NULL, &word_w, &word_h);
		congratsMessage1 = new Image( w_width/2 - word_w/2, w_height/100*30, word_w, word_h );
		congratsMessage1->set_image( fontSup );
		set.add( congratsMessage1 );

		if ( midText != NULL ){
			fontSup = LTexture::loadFont( smallFont, midText,  whiteColor );
			SDL_QueryTexture(fontSup, NULL, NULL, &word_w, &word_h);
			congratsMessage2 = new Image( w_width/2 - word_w/2, w_height/100*42, word_w, word_h );
			congratsMessage2->set_image( fontSup );
			set.add( congratsMessage2 );
		}

		if ( bottomText != NULL ){
			fontSup = LTexture::loadFont( smallFont, bottomText,  whiteColor );
			SDL_QueryTexture(fontSup, NULL, NULL, &word_w, &word_h);
			credits = new Image( w_width/2 - word_w/2, w_height/100*50, word_w, word_h );
			credits->set_image( fontSup );
			set.add( credits );
		}

		// Load Music
		bMusic = Mix_LoadMUS( soundPath );
		if( bMusic == NULL ){
			cout << "Failed to load DBZ music! SDL_mixer Error: " << Mix_GetError() << endl;
			//success = false;
		}
    }

	// Update
    void ScreenEnd::update(){
		// Play Music when this screen is loaded for the first time
		if( Mix_PlayingMusic() == 0 )
		{	
			Mix_PlayMusic( bMusic, -1 );
		}
    }

	// Draw set containing all Image Components
    void ScreenEnd::render(){
		set.draw();
    }

    void ScreenEnd::clean(){
		bigText = NULL;
		midText = NULL;
		bottomText = NULL;
		set.clean();
		Mix_FreeMusic( bMusic );
		bMusic = NULL;

		TTF_CloseFont( bigFont );
		bigFont = NULL;

		TTF_CloseFont( smallFont );
		smallFont = NULL;

    }
