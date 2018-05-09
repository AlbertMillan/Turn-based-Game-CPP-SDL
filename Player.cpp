#include "Player.h"

Player::Player( int x, int y, int w, int h, int nMotionSprites, int nAttackSprites, int sFrame, SDL_Rect sprite, int health, int speed, int attack, int spAttack, int experience ) : Character ( x, y, w, h, nMotionSprites, nAttackSprites, sFrame, sprite, health, speed, attack ) {

	lvl = 0;
	exp = 0;
	lvlExp = experience;
	spAtt = spAttack;
    }

    Player::~Player(){}
	
	// Moves the character forward towards the coordinates of the enemy
    void Player::move_forward( int x, int y){
    	// case character y_pos equals enemy y_pos
		if ( rect.y == y ){
			rect.x += RECT_SPEED;
		}
		// Upwards Diagonal Movement towards enemy
		else if ( rect.y > y ) {
			rect.x += RECT_SPEED;
			rect.y -= 2*RECT_SPEED;
			if( rect.y < y )rect.y = y;
		}
		// Downwards Diagonal Movement towards enemy
		else {
			rect.x += RECT_SPEED;
			rect.y += 2*RECT_SPEED;
			if( rect.y > y )rect.y = y;
		}
    }

	// Moves character backward to original position
    void Player::move_backward(){
		// case character y_pos equals original y_pos
		if ( rect.y == y_origin ){
	   	    rect.x -= RECT_SPEED;
		}
		// Upwards Diagonal Movement towards enemy
		else if ( rect.y > y_origin ) {
			rect.x -= RECT_SPEED;
			rect.y -= 2*RECT_SPEED;
			if( rect.y < y_origin )rect.y = y_origin;
		}
		// Downwards Diagonal Movement towards enemy
		else {
			rect.x -= RECT_SPEED;
			rect.y += 2*RECT_SPEED;
			if( rect.y > y_origin )rect.y = y_origin;
		}
    }

	// Check if character has collided with enemy
    bool Player::check_front_collision( int x, int y ){
    	// Compare character's top-right corner with enemy's top-left corner
		if( (rect.x+rect.w) >= x && rect.y == y)
			return true;
		return false;
    }

	// Check if character is at the original position
    bool Player::check_back_collision(){
		// Compare character's top-left corner with original position's top-left corner
		if( rect.x <= x_origin && rect.y == y_origin ){
			//cout << "HELLO" << endl;
			attackNow = false;
			return true;
		}
		return false;
    }


    int Player::get_EXP(){
	return exp;
    }

    int Player::get_LvlExp(){
	return lvlExp;
    }

