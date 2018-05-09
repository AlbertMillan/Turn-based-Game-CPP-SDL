#ifndef CONSTANTS_H
#define CONSTANTS_H

#define w_width  900
#define w_height 700

// SCREEN CONSTANTS
const int MAIN_MENU = 0;
const int FIGHT_SCREEN_LVL_ONE = 1;
const int LVL_COMPLETED = 2;
const int FIGHT_SCREEN_LVL_TWO = 3;
const int GAME_OVER = 4;
const int CREDITS = 5;

// CURSOR POSITION CONSTANTS
const int TOP = 1;
const int MID = 2;
const int BOTTOM = 3;

// CURSOR ACTION CONSTANTS
const int NONE = -1;
const int IS_ATTACK = 1;
const int IS_SPECIALATTACK = 2;
const int IS_BLOCK = 3;

// CURSOR TARGET CONSTANT
const int GOKU = 0;
const int WARIO = 1;
const int LINK = 2;
const int HALO = 3;
const int ZOMBIE = 4;
const int PESTILENT = 5;

// CHARACTER CONSTANTS
const int IDDLE = 0;
const int MOTION = 1;
const int ATTACK = 2;
const int BACK_MOTION = 3;
const int SP_ATTACK = 4;
const int BLOCK = 5;

// SPRITE CONSTANTS
const int TOTAL_SPRITES = 60;
const int GOKU_SPRITE = 0;
const int WARIO_SPRITE = 4;
const int LINK_SPRITE = 14;
const int HALO_SPRITE = 21;
const int ZOMBIE_SPRITE = 28;
const int PESTILENT_SPRITE = 45;

const int GOKU_MOTION_IMAGES = 1;
const int GOKU_ATTACK_IMAGES = 3;
const int WARIO_MOTION_IMAGES = 8;
const int WARIO_ATTACK_IMAGES = 1;
const int LINK_MOTION_IMAGES = 3;
const int LINK_ATTACK_IMAGES = 3;
const int HALO_MOTION_IMAGES = 4;
const int HALO_ATTACK_IMAGES = 2;
const int ZOMBIE_MOTION_IMAGES = 10;
const int ZOMBIE_ATTACK_IMAGES = 7;
const int PESTILENT_MOTION_IMAGES = 5;
const int PESTILENT_ATTACK_IMAGES = 8;

const int GOKU_SWAP_RATE = 5;
const int WARIO_SWAP_RATE = 3;
const int LINK_SWAP_RATE = 6;
const int HALO_SWAP_RATE = 4;
const int ZOMBIE_SWAP_RATE = 4;
const int PESTILENT_SWAP_RATE = 4;

// CHARACTER STATS
const int PLAYER_EXPERIENCE    = 200;

const int GOKU_HEALTH 		   = 484;
const int GOKU_SPEED           = 11;
const int GOKU_ATTACK_DAMAGE   = 65; // 65
const int GOKU_SPATTACK_DAMAGE = 124;

const int WARIO_HEALTH 		    = 618;
const int WARIO_SPEED           = 9;
const int WARIO_ATTACK_DAMAGE   = 59; //59
const int WARIO_SPATTACK_DAMAGE = 85;

const int LINK_HEALTH 		   = 726;
const int LINK_SPEED           = 6;
const int LINK_ATTACK_DAMAGE   = 52;
const int LINK_SPATTACK_DAMAGE = LINK_ATTACK_DAMAGE*2;

const int HALO_HEALTH 		   = 524;
const int HALO_SPEED           = 10;
const int HALO_ATTACK_DAMAGE   = 72;
const int HALO_SPATTACK_DAMAGE = 85;

const int ZOMBIE_HEALTH 	     = 785;
const int ZOMBIE_SPEED           = 5;
const int ZOMBIE_ATTACK_DAMAGE   = 56;
const int ZOMBIE_SPATTACK_DAMAGE = 85;

const int PESTILENT_HEALTH 	     	= 600;
const int PESTILENT_SPEED           = 7;
const int PESTILENT_ATTACK_DAMAGE   = 64;
const int PESTILENT_SPATTACK_DAMAGE = 85;



// TEXTURE POSITION CONSTANTS
//const int START_GAME_TEXT = 

//TTF_Font* gFont3 = NULL;

#endif
