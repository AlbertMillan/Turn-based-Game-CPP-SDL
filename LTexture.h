#ifndef LTEXTURE_H
#define LTEXTURE_H

//#include <iostream>
#include "GameManager.h"
//#include "Image.h"


class LTexture {

    public:
    // Load Texture with transparent Background
	static SDL_Texture *loadTexture( const char* filename );

	// Load Texture with Coloured Background
	static SDL_Texture *loadTexture( const char* filename, Uint8 r, Uint8 g, Uint8 b );

	// Load Font
	static SDL_Texture *loadFont( TTF_Font *font, const char* filename, SDL_Color textColor );

};

#endif
