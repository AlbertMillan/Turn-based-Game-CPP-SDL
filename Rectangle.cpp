#include "Rectangle.h"

    Rectangle::Rectangle( int x, int y, int w, int h ) {
		rect.x = x;
		rect.y = y;
		rect.w = w;
		rect.h = h;
    }


    void Rectangle::set_color( Uint8 r, Uint8 g, Uint8 b ){
		SDL_SetRenderDrawColor( Game::gRenderer, r, g, b, 255);
    }

    void Rectangle::draw(){
        SDL_RenderFillRect( Game::gRenderer, &rect );
    }

    void Rectangle::draw_outline(){
		SDL_RenderDrawRect( Game::gRenderer, &rect );
    }

    int Rectangle::get_x(){
		return rect.x;
    }

    int Rectangle::get_y(){
		return rect.y;
    }

    int Rectangle::get_w(){
		return rect.w;
    }

    int Rectangle::get_h(){
		return rect.h;
    }
