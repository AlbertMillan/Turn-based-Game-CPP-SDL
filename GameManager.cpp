//#include <iostream>

#include "GameManager.h"
#include "LTexture.h"
#include "ImageGroup.h"
#include "Image.h"
#include "Screen.h"
#include "Screenf.h"
#include "ScreenEnd.h"
#include "Constants.h"

using namespace std;

Screen  *startScreen;
Screenf *fightScreen;
Screenf *lastFightScreen;
ScreenEnd *winScreen;
ScreenEnd *gameOverScreen;
ScreenEnd *levelCompleteScreen;

SDL_Renderer* Game::gRenderer = NULL;
int Game::currentScreen = MAIN_MENU;

    Game::Game(){

    }

    Game::~Game(){}

    bool Game::init( const char* title, int xpos, int ypos, Uint32 flag ){

		bool success = true;

		// Initialize SDL libraries: image & audio
		if( SDL_Init( SDL_INIT_VIDEO | SDL_INIT_AUDIO ) < 0 )
		{
		    cout << "SDL could not initialize! SDL_Error:" << SDL_GetError() << endl;
		    success = false;
		}
	   	else
		{
			// Create window Screen
			gWindow = SDL_CreateWindow( "Redania", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, w_width, w_height, SDL_WINDOW_SHOWN );

			if( gWindow == NULL ){
			    cout <<  "Window could not be created! SDL_Error: " << SDL_GetError() << endl;
			    success = false;
			}
			else{
				// Create texture renderer
			  	gRenderer = SDL_CreateRenderer( gWindow, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC );
	
				if( gRenderer == NULL ){
			        cout <<  "Renderer could not be created! SDL_Error: " << SDL_GetError() << endl;
			        success = false;
				}
			    else{
					// Set default RenderColor to white
			        SDL_SetRenderDrawColor( gRenderer, 0xFF, 0xFF, 0xFF, 0xFF );
			    }
			}
		}

		// Initialize Fonts
		if( TTF_Init() == -1 ) { 
			cout << "SDL_ttf could not initialize! SDL_ttf Error:" << TTF_GetError() << endl;
			success = false;
		}
		else
		{
			// Set a font style
			gFont1 = TTF_OpenFont( "fonts/emulogic.ttf", 20 );
			//gFont2 = TTF_OpenFont( "fonts/emulogic.ttf", 13 );
			//gFont3 = TTF_OpenFont( "fonts/emulogic.ttf", 9 );
			if( gFont1 == NULL ){
				cout << "Failed to load font! SDL_ttf Error:" << TTF_GetError() << endl;
		        	success = false;
			}
    	}

		// Initialize SDL_Mixer (Audio)
		if( Mix_OpenAudio( 44100, MIX_DEFAULT_FORMAT, 2, 2048 ) < 0 ) { 

			cout << "SDL_mixer could not initialize! SDL_mixer Error: " << Mix_GetError() << endl;
			success = false; 

		}

		// Game has not finished
		hasFinished = false;

    	return success;
    }

	// Loads images, sound, of all screens
    bool Game::loadMedia( ){

		bool success = true;
	
		// Initial Screen
		startScreen         = new Screen();

		// Level 1 Fight Screen
		fightScreen         = new Screenf(false);

		// Level 2 Fight Screen
		lastFightScreen     = new Screenf(true);

		// Game Won message
		winScreen           = new ScreenEnd( "CONGRATULATIONS!", "GAME COMPLETED", "DIRECTOR & DEVELOPER:  ALBERT MILLAN" );

		// Game Lost message
		gameOverScreen      = new ScreenEnd( "GAME OVER!", "PRESS ANY BUTTON TO QUIT", "DIRECTOR & DEVELOPER:  ALBERT MILLAN" );

		// Level complete screen
		levelCompleteScreen = new ScreenEnd( "Level Completed!", "Press any button to continue" );

		// Load media on each screen
		startScreen->loadMedia(gFont1);
		fightScreen->loadMedia("sound/Fight1.wav");
		lastFightScreen->loadMedia("sound/Fight2.wav");
		levelCompleteScreen->loadMedia("");
		winScreen->loadMedia("sound/Credits.wav");
		gameOverScreen->loadMedia("sound/GameOver.wav");
		return success;
    }

    void Game::set_initial_variables(){
		currentScreen = MAIN_MENU;
		//cursorPos = TOP;
    }


	// Processes keyboard events every frame.
    void Game::eventHandler()
    {
		SDL_Event event;
		SDL_PollEvent( &event );

		if( event.type == SDL_QUIT ){	
			hasFinished = true;
		}

		// The current screen defines the events that can take place.
		switch( currentScreen )
		{
			case MAIN_MENU:
				startScreen->eventHandler( event );
				break;

			case FIGHT_SCREEN_LVL_ONE:
				fightScreen->eventHandler( event );
				break;

			case LVL_COMPLETED:
				if( event.type == SDL_KEYDOWN ){
					currentScreen = FIGHT_SCREEN_LVL_TWO;
				}
				break;

			case FIGHT_SCREEN_LVL_TWO:
				lastFightScreen->eventHandler( event );
				break;

			case GAME_OVER:
				if( event.type == SDL_KEYDOWN ){
					hasFinished = true;
				}
				break;

			case CREDITS:
				if( event.type == SDL_KEYDOWN ){
					hasFinished = true;
				}
				break;

			default:
				break;
		}		
	
    }	

	// Updates the currentScreen every frame. The current screen defines the events that can take place.
    void Game::update()
    {
		switch( currentScreen )
		{
			case MAIN_MENU:
				startScreen->update();
				break;

			case FIGHT_SCREEN_LVL_ONE:
				fightScreen->update();
				break;

			case LVL_COMPLETED:
				levelCompleteScreen->update();
				break;

			case FIGHT_SCREEN_LVL_TWO:
				lastFightScreen->update();
				break;

			case GAME_OVER:
				gameOverScreen->update();
				break;

			case CREDITS:
				winScreen->update();
				break;

			default:
				break;
		}
    }


    void Game::render()
    {
		// Clears images loaded in the previous frame
		SDL_RenderClear( gRenderer );

		// Draws the current screen
		switch ( currentScreen )
		{
			case MAIN_MENU:
				startScreen->render();
				break;
	
			case FIGHT_SCREEN_LVL_ONE:
				fightScreen->render();
				break;

			case LVL_COMPLETED:
				levelCompleteScreen->render();
				break;

			case FIGHT_SCREEN_LVL_TWO:
				lastFightScreen->render();
				break;

			case GAME_OVER:
				gameOverScreen->render();
    			break;

			case CREDITS:
				winScreen->render();
				break;

			default:
				break;

		}
		SDL_RenderPresent( gRenderer );
    }


    void Game::clean()
    {
		// Delete the objects stored in the screens
		startScreen->clean();
		fightScreen->clean();
		lastFightScreen->clean();
		gameOverScreen->clean();
		winScreen->clean();
		levelCompleteScreen->clean();

		// Delete the screen objects
		delete( startScreen );
		delete( fightScreen );
		delete( lastFightScreen );
		delete( winScreen );
		delete( gameOverScreen );
		delete( levelCompleteScreen );
		startScreen = NULL;
		fightScreen = NULL;
		lastFightScreen = NULL;
		winScreen = NULL;
		gameOverScreen = NULL;
		levelCompleteScreen = NULL;

		// Delete SDL libraries content
		TTF_CloseFont( gFont1 );
		gFont1 = NULL;
			
		SDL_DestroyRenderer( gRenderer );
		gRenderer = NULL;
		SDL_DestroyWindow( gWindow );
		gWindow = NULL;

		Mix_Quit();
		TTF_Quit();
		IMG_Quit();
		SDL_Quit(); // quit SDL
		cout << "Game Cleaned!" << endl;
    }

    bool Game::isFinished()
    {
		return hasFinished;
    }










