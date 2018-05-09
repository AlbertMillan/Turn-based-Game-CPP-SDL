#include "Zombie.h"

    Zombie::Zombie( int x, int y, int w, int h, int nMotionSprites, int nAttackSprites, int sFrame, SDL_Rect sprite, int health, int speed, int attack ) : Character ( x, y, w, h, sFrame, nMotionSprites, nAttackSprites, sprite, health, speed, attack ) {

    }

    Zombie::~Zombie(){}

	// Moves the enemy character forward towards the coordinates of the player's character
    void Zombie::move_forward( int x, int y){
    	// case enemy character y_pos equals player character y_pos
		if ( rect.y == y ){
			rect.x -= RECT_SPEED;
		}
		// Upwards Diagonal Movement towards player
		else if ( rect.y > y ) {
			rect.x -= RECT_SPEED;
			rect.y -= 2*RECT_SPEED;
			if( rect.y < y )rect.y = y;
		}
		// Downwards Diagonal Movement towards player
		else {
			rect.x -= RECT_SPEED;
			rect.y += 2*RECT_SPEED;
			if( rect.y > y ) rect.y = y;
		}
    }

	// Moves character backward to original position
    void Zombie::move_backward(){
    	// case enemy character y_pos equals player character y_pos
		if ( rect.y == y_origin ){
	   	    rect.x += RECT_SPEED;
		}
		// Upwards Diagonal Movement towards original position
		else if ( rect.y > y_origin ) {
			rect.x += RECT_SPEED;
			rect.y -= 2*RECT_SPEED;
			if( rect.y < y_origin )rect.y = y_origin;
		}
		// Downwards Diagonal Movement towards original position
		else {
			rect.x += RECT_SPEED;
			rect.y += 2*RECT_SPEED;
			if( rect.y > y_origin )rect.y = y_origin;
		}
    }

	// Check if character has collided with enemy
    bool Zombie::check_front_collision( int x, int y ){
    	// Compare enemy character's top-left corner with player's top-right corner
		if( rect.x <= (x+rect.w)   &&   rect.y == y)
			return true;
		return false;
    }

	// Check if character is at the original position
    bool Zombie::check_back_collision(){
		if( rect.x >= x_origin && rect.y == y_origin ){
		   attackNow = false;	 
	 	   return true;
		}
		return false;
    }



