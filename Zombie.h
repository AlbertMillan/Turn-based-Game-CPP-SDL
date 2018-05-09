#ifndef ZOMBIE_H
#define ZOMBIE_H

#include "Character.h"

class Zombie : public Character {

    public:
    // Initializes variables
	Zombie( int x, int y, int w, int h, int nMotionSprites, int nAttackSprites, int sFrame, SDL_Rect sprite, int health, int speed, int attack );

	~Zombie();
	
	// Moves the enemy character forward towards the coordinates of the player's character
	void move_forward( int x, int y);

	// Moves enemy character backward to original position
 	void move_backward();

	// Check if enemy character has collided with player character
	bool check_front_collision( int x, int y );

	// Check if enemy character is at the original position
	bool check_back_collision();

	//void clean();

    private:

};

#endif
