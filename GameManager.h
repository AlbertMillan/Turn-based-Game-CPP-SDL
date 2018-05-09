#ifndef GAME_H
#define GAME_H

#include <iostream>
#include <SDL2/SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>
#include <SDL_mixer.h>

using namespace std;


class Game {

    public:
		Game();

		~Game();
	
		// Initialize the game Window, texture Renderer, and SDL Libraries
		bool init( const char* title, int xpos, int ypos, Uint32 flag );

		// Loads images, sound, of all screens
		bool loadMedia();

		// Sets currentScreen to be the starting screen.
		void set_initial_variables();

		// Processes keyboard events every frame.
		void eventHandler();

		// Updates the currentScreen every frame.
		void update();

		// Draws the current screen
		void render();

		void clean();

		// Check if Game is finished
		bool isFinished();
	
		// Game rendered, used in multiple classes
		static SDL_Renderer *gRenderer;

		// Defines the screen for eventHandler, 
		static int currentScreen;

    private:
	bool hasFinished;
	SDL_Window *gWindow;
	//SDL_Renderer *gRenderer;
	TTF_Font *gFont1;
	
	
	//TTF_Font *gFont2;
	//TTF_Font *gFont3;
	//Image *gBackground;
	//int currentScreen;
	//int cursorPos;
};

#endif
