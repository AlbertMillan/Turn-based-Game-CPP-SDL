#include "LTexture.h"

    // Load Texture with transparent Background
    SDL_Texture* LTexture::loadTexture( const char* filename ){

		//The final optimized image
        SDL_Texture* newTexture = NULL;

    	//Load image at specified path
   		SDL_Surface* loadedSurface = IMG_Load( filename );
    	if( loadedSurface == NULL )
    	{
	    	cout <<  "Error loading image! SDL Error: " << SDL_GetError() << endl;
    	}
     	else
    	{
	   	   	newTexture = SDL_CreateTextureFromSurface( Game::gRenderer, loadedSurface );
			if( newTexture == NULL )
			{
				printf( "Unable to create texture from %s! SDL Error: %s\n", filename, SDL_GetError() );
			}

			//Get rid of old loaded surface
			SDL_FreeSurface( loadedSurface );
        }

        return newTexture;
    }

	// Load Texture with Coloured Background
    SDL_Texture* LTexture::loadTexture( const char* filename, Uint8 r, Uint8 g, Uint8 b ){
		//The final optimized image
        SDL_Texture* newTexture = NULL;

    	//Load image at specified path
   	 	SDL_Surface* loadedSurface = IMG_Load( filename );
    	if( loadedSurface == NULL )
    	{
	    	cout <<  "Error loading image! SDL Error: " << SDL_GetError() << endl;
    	}
     	else
    	{
    		// Eliminate Image colour transparency
			SDL_SetColorKey( loadedSurface, SDL_TRUE, SDL_MapRGB( loadedSurface->format, r, g, b ) );    

	   	    newTexture = SDL_CreateTextureFromSurface( Game::gRenderer, loadedSurface );
			if( newTexture == NULL )
			{
				printf( "Unable to create texture from %s! SDL Error: %s\n", filename, SDL_GetError() );
			}

			//Get rid of old loaded surface
			SDL_FreeSurface( loadedSurface );
        }

        return newTexture;
    }

	// Load Font
    SDL_Texture* LTexture::loadFont( TTF_Font *font, const char* filename, SDL_Color textColor ){
	
		SDL_Texture* newTexture = NULL;

    
    	SDL_Surface* textSurface = TTF_RenderText_Solid( font, filename, textColor );
    	if( textSurface == NULL )
   		{
	    	cout <<  "Error loading font! SDL_ttf Error: " << TTF_GetError() << endl;
    	}
    	else
    	{
			newTexture = SDL_CreateTextureFromSurface( Game::gRenderer, textSurface );
			if( newTexture == NULL )
			{
		   		printf( "Unable to create texture from rendered text! SDL Error: %s\n", SDL_GetError() );
			}

			//Get rid of old loaded surface
			SDL_FreeSurface( textSurface );
    	}

   	return newTexture;

    }




