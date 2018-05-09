#ifndef PLAYER_H
#define PLAYER_H

#include "Character.h"

class Player : public Character {

    public:
		// Initializes variables
		Player( int x, int y, int w, int h, int nMotionSprites, int nAttackSprites, int sFrame, SDL_Rect sprite, int health, int speed, int attack, int spAttack, int experience );

		~Player();
	
		// Moves the character forward towards the coordinates of the enemy
		void move_forward( int x, int y);

		// Moves character backward to original position
	 	void move_backward();

		// Check if character has collided with enemy
		bool check_front_collision( int x, int y );

		// Check if character is at the original position
		bool check_back_collision();

		int get_EXP();

		int get_LvlExp();

		//void clean();

    private:
		int exp, lvlExp, lvl, spAtt;
};

#endif
