#ifndef RECTANGLE_H
#define RECTANGLE_H

#include <SDL2/SDL.h>
#include "GameManager.h"
//#include "Image.h"
using namespace std;

class Rectangle {

    public:
    	// Initialize Rectangle
		Rectangle( int x, int y, int w, int h );	

		// Set rectangle Color
		void set_color( Uint8 r, Uint8 g, Uint8 b );

		// Draw Image
	 	void draw();

		// Draw Outline
		void draw_outline();

		// Get x axis
		int get_x();

		// Get y axis
		int get_y();

		// Get width
		int get_w();
	
		// Get height
		int get_h();

		//void clean();

    private:
		SDL_Rect rect;
};

#endif
