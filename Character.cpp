#include "Character.h"

Character::Character( int x, int y, int w, int h, int nMotionSprites, int nAttackSprites, int sFrame, SDL_Rect sprite, int health, int speed, int attack ) : Image( x, y,  w, h ){

		attackNow = false;
		swapFrame = sFrame;
		this->nMotionSprites = nMotionSprites;
		this->nAttackSprites = nAttackSprites;
		x_origin = x;
		y_origin = y;

		// Static sprite
		src = sprite;
		
		// Stats variables
		ps = health;
		maxPs = ps;
		spd = speed;
		currentSpd = 0;
		att = attack;
		isBlocking = false;
    }

    Character::~Character(){}

    void Character::draw() {
	//cout << "Drawing Character!" << endl;
		SDL_RenderCopy( Game::gRenderer, texture, &src, &rect );
    }

    void Character::update_sprite( SDL_Rect imageRect ){
		src = imageRect;
    }

    void Character::damaged ( int damage ){
		if( isBlocking )
			ps = ps - damage/2;
		else
			ps = ps- damage;
		if( ps < 0 ) ps = 0;
    }

    void Character::block ( ){
		isBlocking = true;
    }

    void Character::deblock ( ){
		isBlocking = false;
    }

    void Character::update_spd(){
		currentSpd += spd;
		if( currentSpd >= MAX_SPD ){
			currentSpd = currentSpd % MAX_SPD;
			attackNow = true;
		}
    }

    void Character::donot_attack(){
		attackNow = false;
    }

    bool Character::attack_now(){
		return attackNow;
    }


    bool Character::is_blocking(){
		return isBlocking;
    }

    bool Character::is_dead(){
		return ps == 0;
    }

	int Character::get_nMotionSprites(){
		return nMotionSprites;
	}

	int Character::get_nAttackSprites(){
		return nAttackSprites;
	}

	int Character::get_swapFrame(){
		return swapFrame;
	}

    int Character::get_PS(){
		return ps;
    }

    int Character::get_MAX_PS(){
		return maxPs;
    }

    int Character::get_SPD(){
		return currentSpd;
    }

    int Character::get_ATT(){
		return att;
    }


