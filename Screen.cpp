#include "Screen.h"
#include "LTexture.h"
#include "Constants.h"

    Screen::Screen(){
		cursorPos = TOP;
    }

	Screen::~Screen(){}

    void Screen::loadMedia( TTF_Font *gFont1 ){
		Image *sCursor = NULL;
		Image *startGame = NULL;      // Start Game Text Message
		Image *loadGame = NULL;		  // Load Game Text Message
		Image *gBackground = NULL;

		//General
		SDL_Color blackColor = { 0,   0,   0 };
		SDL_Texture *fontSup = NULL;

		// Start Screen Background
		gBackground = new Image( 0, 0, w_width, w_height );
		gBackground->set_image( LTexture::loadTexture( "images/dbsl.jpg") );

		// Start Game and Load Game Text
		int w1, h1;
		fontSup = LTexture::loadFont( gFont1, "START GAME",  blackColor );
		SDL_QueryTexture(fontSup, NULL, NULL, &w1, &h1);
		startGame = new Image( w_width/2 - w1/2, w_height/100*75, w1, h1 );
	    startGame->set_image( fontSup );

		fontSup = LTexture::loadFont( gFont1, "LOAD GAME",  blackColor );
		SDL_QueryTexture(fontSup, NULL, NULL, &w1, &h1);
		loadGame = new Image( w_width/2 - w1/2, w_height/100*80, w1, h1 );
		loadGame->set_image( fontSup );

		// Cursor
		sCursor = new Image( /*w_width/2 - w1/2 - 27*/w_width*36/100, w_height/100*75, h1+3, h1 );	
		sCursor->set_image( LTexture::loadTexture( "images/cursorBlack.png" ) );
		
		// Add all created images into the vector
		set.add( gBackground );
		set.add( startGame );
		set.add( loadGame );
		set.add( sCursor );

		// Load Music
		bMusic = Mix_LoadMUS( "sound/StartGame2.wav" );
		if( bMusic == NULL ){
			cout << "Failed to load DBZ music! SDL_mixer Error: " << Mix_GetError() << endl;
			//success = false;
		}
		Mix_PlayMusic( bMusic, -1 );
    }

	// Handle Keyboard events
    void Screen::eventHandler( SDL_Event event ){
		if( event.type == SDL_KEYDOWN ){
			switch( event.key.keysym.sym )
			{
				// 'M' key
				case SDLK_m:
					// If there is no music playing
					if( Mix_PlayingMusic() == 0 )
					{
						// Play the music
						Mix_PlayMusic( bMusic, -1 );
					}
					else
					{
						// If the music is paused.
						if( Mix_PausedMusic() == 1 )
						{
							// Resume the music
							Mix_ResumeMusic();
						}
						else
						{
							// Pause Music
							Mix_PauseMusic();
						}			

					}
					break;			

				case SDLK_UP:
					// Cursor is at BOTTOM (LOAD GAME), MOVE TO TOP (START GAME)
					if( cursorPos == BOTTOM ) set.get_image(3)->set_pos( w_width*36/100, w_height/100*75 );
					cursorPos = TOP;
					break;

				case SDLK_DOWN:
					// Cursor is at TOP (START GAME), MOVE TO BOTTOM (LOAD GAME)
					if( cursorPos == TOP ) set.get_image(3)->set_pos( w_width*36/100, w_height/100*80 );
					cursorPos = BOTTOM;
					break;

				case SDLK_RETURN:
					cout << "Enter pressed!" << endl;
					if ( cursorPos == TOP ) 
					{
						// Stop music
						if( Mix_PausedMusic() == 0 )
						{
							// Pause the music
							Mix_PauseMusic();
						}
						
						clean();
						// Transition to LVL_ONE screen
						Game::currentScreen = FIGHT_SCREEN_LVL_ONE;
					}
					break;

				default:
					cout << "Useless Key typed!" << endl;
			}
		}	
    }

    void Screen::update(){

    }

    void Screen::render(){
	//cout << &set <<endl;
		set.draw();
    }

    void Screen::clean(){
		set.clean();
		Mix_FreeMusic( bMusic );
		bMusic = NULL;
    }
