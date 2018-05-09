#ifndef CHARACTER_H
#define CHARACTER_H

#include "Image.h"

class Character : public Image {

    public:
		Character( int x, int y, int w, int h, int nMotionSprites, int nAttackSprites, int sFrame, SDL_Rect sprite, int health, int speed, int attack );

		~Character();

		void draw();

		// Changes the Rectangle of the from where the sprite is extracted from the spriteSheet
		void update_sprite( SDL_Rect imageRect );

		// Reduces the health of current character by the attack damage of opponent
		void damaged ( int damage );

		// Does not attack
		void donot_attack();

		// Blocks incoming attacks. Reduces 50% damage until this character's next turn
		void block();

		// Stops blocking attacks
		void deblock();

		// Updates character spd. When it reachs 100, sets attackNow to true, initiates turn of the character
		void update_spd();

		// Checks wether Character should attack now
		bool attack_now();

		// Checks if character is currently blocking damage
		bool is_blocking();

		// Checks if the character is dead
		bool is_dead();

		/*** GETTERS ***/
		// ANIMATION - Sprites used for motion animation
		int get_nMotionSprites();

		// ANIMATION - Sprites used for attack animation
		int get_nAttackSprites();

		// ANIMATION - Frames required to swap animation sprites
		int get_swapFrame();

		int get_PS();

		int get_MAX_PS();

		int get_SPD();

		int get_ATT();

		/*** END GETTERS */
		//void clean();

    protected:
		SDL_Rect src;
		int x_origin;
		int y_origin;
		int swapFrame;
		int nMotionSprites;
		int nAttackSprites;
		bool isBlocking;
		bool attackNow;
		
	
		static const int RECT_SPEED = 5;
		static const int MAX_SPD = 100;
		int ps, maxPs, spd, currentSpd, att;
};

#endif
