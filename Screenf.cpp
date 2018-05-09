#include "Screenf.h"
#include "LTexture.h"
#include "Zombie.h"
//#include "Player.h"
#include "Constants.h"
#include "GameManager.h"


int currentTurnAnt = -1;
int selectedTargetAnt = -1;
int currentActionAnt = -1;

	// Initialize variables
    Screenf::Screenf( bool defineLevel ){
		cursorPos = TOP;
		selectedAction = NONE;
		selectedTarget = NONE;
		currentTurn = NONE;
		currentAction = IDDLE;
		gFont3 = TTF_OpenFont( "fonts/emulogic.ttf", 9 );
		gFont2 = TTF_OpenFont( "fonts/emulogic.ttf", 13 );
		gFont4 = TTF_OpenFont( "fonts/emulogic.ttf", 30 );
		fontSup = NULL;
		frame = 0;
		frameTimer = 0;
		fill_sprites();
		isLvlTwo = defineLevel;
    }

	Screenf::~Screenf(){
		
	}

    void Screenf::loadMedia( const char* soundPath ){
		//Image *gBackground = NULL;
		Image *bBackground = NULL;			// Pause background
		Image *pauseText = NULL;			// Pause text
		Image *fCursor = NULL;				// White Cursor
		Player *goku = NULL;				
		Player *wario = NULL;
		Player *link = NULL;
		Zombie *halo = NULL;
		Zombie *zombie = NULL;
		Zombie *pestilent = NULL;
		Image *bAttack = NULL;				// Attack text in player menu
		Image *bSpecialAttack = NULL;		// Sp.Attack text in player menu
		Image *bBlock = NULL;				// Block text in player menu
		Image *gokutxt = NULL;				// Goku name text in bottom menu
		Image *wariotxt = NULL;				// Wario name text in bottom menu
		Image *linktxt = NULL;				// Link name text in bottom menu
		Image *halotxt = NULL;				// Halo name text in bottom menu
		Image *zombietxt = NULL;			// Zombie name text in bottom menu
		Image *pestilenttxt = NULL;			// Pestilent name text in bottom menu
		Image *halotxt2 = NULL;				// Halo name text in player menu	
		Image *zombietxt2 = NULL;			// Zombie name text in player menu
		Image *pestilenttxt2 = NULL;		// Pestilent name text in player menu
		Image *gokuStats = NULL;	
		Image *warioStats = NULL;
		Image *linkStats = NULL;
		Image *haloStats = NULL;
		Image *zombieStats = NULL;
		Image *pestilentStats = NULL;




		//General
        SDL_Color blackColor = { 0,   0,   0 };
        //SDL_Color whiteColor = { 255, 255, 255 };

		// Define size of the characters
		SDL_Rect rect;
		rect.x = 0; rect.y = 0;
		rect.w = 32; rect.h = 32;
	

		// Load Fight background
		gBackground = new Image( 0, 0, w_width, w_height );
		gBackground->set_image( LTexture::loadTexture( "images/Background1.png" ) );

		// Load Pause blended background
		bBackground = new Image( 0, 0, w_width, w_height );
		bBackground->set_image( LTexture::loadTexture( "images/BlackBackground.jpg" ) );
		bBackground->set_blend_mode( SDL_BLENDMODE_BLEND );
		bBackground->set_alpha( 199 );
		bBackground->donot_draw();																		// Does not display it initally

		// Load Pause text
		pauseText = generate_image( gFont4, "Pause", w_width*42/100, w_height*46/100 );
		pauseText->donot_draw();																		// Does not display it initally

		// Load Cursor for the Menu
		fCursor = new Image( w_width*72/100, w_height/100*76, w_width/100*3+3, w_width/100*3+3 );
		fCursor->set_image( LTexture::loadTexture( "images/cursorWhite.png" ) );

		int haloHealth = HALO_HEALTH;
		int haloAtt = HALO_ATTACK_DAMAGE;
		int zombieHealth = ZOMBIE_HEALTH;
		int zombieAtt = ZOMBIE_ATTACK_DAMAGE;
		int pestilentHealth = PESTILENT_HEALTH;
		int pestilentAtt = PESTILENT_ATTACK_DAMAGE;

		// Increase zombies health and attack if level 2
		if( isLvlTwo ){
			haloHealth = haloHealth+100;
			haloAtt = haloAtt+5;
			zombieHealth = zombieHealth+100;
			zombieAtt = zombieAtt+5;
			pestilentHealth = pestilentHealth+100;
			pestilentAtt = pestilentAtt+5;
		}

		// Load PLAYER and ZOMBIE characters, format as follows: [rect position, nSpriteImages, sprite, character stats]
		goku = new Player( w_width*21/100, w_height*12/100, w_width*5.8/100, w_height*11.4/100, GOKU_MOTION_IMAGES, GOKU_ATTACK_IMAGES, GOKU_SWAP_RATE, sprite[GOKU_SPRITE], GOKU_HEALTH, GOKU_SPEED, GOKU_ATTACK_DAMAGE, GOKU_SPATTACK_DAMAGE, PLAYER_EXPERIENCE );
		goku->set_image( LTexture::loadTexture( "images/Test111.png", 255, 255, 255 ) );

		wario = new Player( w_width*32/100, w_height*42/100, w_width*5.8/100, w_height*11.4/100, WARIO_MOTION_IMAGES, WARIO_ATTACK_IMAGES, WARIO_SWAP_RATE, sprite[WARIO_SPRITE], WARIO_HEALTH, WARIO_SPEED, WARIO_ATTACK_DAMAGE, WARIO_SPATTACK_DAMAGE, PLAYER_EXPERIENCE );
		wario->set_image( LTexture::loadTexture( "images/Wario.png" ) );

		link = new Player( w_width*21/100, w_height*62/100, w_width*6.5/100, w_height*11.4/100, LINK_MOTION_IMAGES, LINK_ATTACK_IMAGES, LINK_SWAP_RATE, sprite[LINK_SPRITE], LINK_HEALTH, LINK_SPEED, LINK_ATTACK_DAMAGE, LINK_SPATTACK_DAMAGE, PLAYER_EXPERIENCE);
		link->set_image( LTexture::loadTexture( "images/Link.png" ) );

		halo = new Zombie( w_width*73/100, w_height*6/100, w_width*5.8/100, w_height*11.4/100, HALO_MOTION_IMAGES, HALO_ATTACK_IMAGES, HALO_SWAP_RATE, sprite[HALO_SPRITE], haloHealth, HALO_SPEED, haloAtt );
		halo->set_image( LTexture::loadTexture( "images/Zombie1.png" ) );

		zombie = new Zombie( w_width*61/100, w_height*42/100, w_width*5.8/100, w_height*11.4/100, ZOMBIE_MOTION_IMAGES, ZOMBIE_ATTACK_IMAGES, ZOMBIE_SWAP_RATE, sprite[ZOMBIE_SPRITE], zombieHealth, ZOMBIE_SPEED, zombieAtt/*800*/ );
		zombie->set_image( LTexture::loadTexture( "images/Zombie2.png" ) );

		pestilent = new Zombie( w_width*73/100, w_height*62/100, w_width*5.8/100, w_height*11.4/100, PESTILENT_MOTION_IMAGES, PESTILENT_ATTACK_IMAGES, PESTILENT_SWAP_RATE, sprite[PESTILENT_SPRITE], pestilentHealth, PESTILENT_SPEED, pestilentAtt );
		pestilent->set_image( LTexture::loadTexture( "images/Zombie3.png" ) );


		// Load Text in player Menu
		bAttack = generate_image( gFont2, "Attack", w_width*75/100, w_height/100*76.9 );
		bSpecialAttack = generate_image( gFont2, "S.Attack", w_width*75/100, w_height/100*82 );
		bBlock = generate_image( gFont2, "Block", w_width*75/100, w_height/100*87 );

		// Load Menu box at bottom of the screen
		int bigBox   = w_height*75/100;
		int medBox   = bigBox+3;
        int smallBox = bigBox+6;
		bRect = new Rectangle( 4, bigBox, w_width-8, w_height-bigBox-4);
		outRect = new Rectangle( 7, medBox, w_width-14, w_height-medBox-7);
		leftRect = new Rectangle( 10, smallBox, w_width*73/100-20, w_height-smallBox-10);
		rightRect = new Rectangle ( w_width*73/100-16, smallBox, w_width-w_width*73/100+6, w_height-smallBox-10);
		midRect = new Rectangle ( w_width*44/100, smallBox, w_width*73/100-16 - w_width*44/100, w_height-smallBox-10);

		// Load Character name Text in the bottom menu
		gokutxt = generate_image( gFont2, "Goku", w_width*3/100, w_height*76.9/100 );

		wariotxt = generate_image( gFont2, "Wario", w_width*3/100, w_height*84/100 );

		linktxt = generate_image( gFont2, "Link", w_width*3/100, w_height*91.4/100 );

		halotxt = generate_image( gFont2, "Halo", w_width*45.7/100, w_height*76.9/100 );
		halotxt2 = generate_image( gFont2, "Halo", w_width*75/100, w_height/100*76.9 );

		zombietxt = generate_image( gFont2, "Zombie", w_width*45.7/100, w_height*84/100 );
		zombietxt2 = generate_image( gFont2, "Zombie",  w_width*75/100, w_height/100*82 );

		pestilenttxt = generate_image( gFont2, "pestilent", w_width*45.7/100, w_height*91.4/100 );
		pestilenttxt2 = generate_image( gFont2, "pestilent", w_width*75/100, w_height/100*87 );

		// Load Stats into Screen
		strManager << "PS=" << goku->get_PS() << "/" << goku->get_MAX_PS() << /*"    EXP=" << goku.get_EXP() << "/" << goku.get_LvlEXP() <<*/ "    SPD=" << goku->get_SPD() << "/100    ATT=" << goku->get_ATT() /*<< "    Sp.Att=" << goku.get_SpATT()*/;
		gokuStats = generate_image( gFont3, strManager.str().c_str(), w_width*3/100, w_height*80.5/100);

		strManager.clear();
		strManager.str( string() );

		strManager << "PS=" << wario->get_PS() << "/" << wario->get_MAX_PS() << "    SPD=" << wario->get_SPD() << "/100    ATT=" << wario->get_ATT() ;
		warioStats = generate_image( gFont3, strManager.str().c_str(), w_width*3/100, w_height*87.6/100);

		strManager.clear();
		strManager.str( string() );

		strManager << "PS=" << link->get_PS() << "/" << link->get_MAX_PS() << "    SPD=" << link->get_SPD() << "/100    ATT=" << link->get_ATT() ;
		linkStats = generate_image( gFont3, strManager.str().c_str(), w_width*3/100, w_height*94.7/100);

		strManager.clear();
		strManager.str( string() );

		strManager << "PS=" << halo->get_PS() << "/" << halo->get_MAX_PS() << "    SPD=" << halo->get_SPD() << "/100";
		haloStats = generate_image( gFont3, strManager.str().c_str(), w_width*45.7/100, w_height*80.5/100);

		strManager.clear();
		strManager.str( string() );

		strManager << "PS=" << zombie->get_PS() << "/" << zombie->get_MAX_PS() << "    SPD=" << zombie->get_SPD() << "/100";
		zombieStats = generate_image( gFont3, strManager.str().c_str(), w_width*45.7/100, w_height*87.6/100);

		strManager.clear();
		strManager.str( string() );

		strManager << "PS=" << pestilent->get_PS() << "/" << pestilent->get_MAX_PS() << "    SPD=" << pestilent->get_SPD() << "/100";
		pestilentStats = generate_image( gFont3, strManager.str().c_str(), w_width*45.7/100, w_height*94.7/100);

		// Add Images into the vector.
		set.add( goku );
		set.add( wario );
		set.add( link );
		set.add( halo );
		set.add( zombie );
		set.add( pestilent );
		set.add( fCursor );
		set.add( bAttack );
		set.add( bSpecialAttack );
		set.add( bBlock );

		set.add( gokutxt );         // 10
		set.add( wariotxt );
		set.add( linktxt );
		set.add( halotxt );
		set.add( zombietxt );
		set.add( pestilenttxt );
		set.add( gokuStats );       // 16
		set.add( warioStats );
		set.add( linkStats );
		set.add( haloStats );
		set.add( zombieStats );
		set.add( pestilentStats );
		set.add( halotxt2 );		// 22
		set.add( zombietxt2 );
		set.add( pestilenttxt2 );
		// Pause Screen, but not displayed initially
		set.add( bBackground );
		set.add( pauseText );

		//cout << &goku << endl;
		
		// Set background song for the screen
		bMusic = Mix_LoadMUS( soundPath );
		if( bMusic == NULL ){
			cout << "Failed to load DBZ music! SDL_mixer Error: " << Mix_GetError() << endl;
			//success = false;
		}
    }

	// Handle keyboard events
    void Screenf::eventHandler( SDL_Event event ){
		// Keyboard pressed
		if( event.type == SDL_KEYDOWN )
		{
			switch( event.key.keysym.sym )
			{
				// 'P' pressed
				case SDLK_p:
					// If Pause screen is currently displayed
					if(  set.get_image(25)->should_draw() ){
				
						set.get_image(25)->donot_draw();		// Hide Pause Screen
						set.get_image(26)->donot_draw();		// Hide Pause Text
	
						if( Mix_PausedMusic() == 1 )
						{
							// Resume the music
						
							Mix_ResumeMusic();
						}		
					}
					else
					{
						// Draw the Pause screen and text
						set.get_image(25)->do_draw();
						set.get_image(26)->do_draw();

						if( Mix_PausedMusic() == 0 )
						{
							Mix_PauseMusic();
						}	
					}
					break;


				case SDLK_UP:
					// If not paused
					if(  !set.get_image(25)->should_draw() )
					{
						// Player is not moving
						if( currentAction == IDDLE )
						{
							// Select Action here
							if( selectedAction == NONE )
							{
								// If cursor in MID (Sp.Attack), move to TOP (Attack)
								if( cursorPos == MID ) {
									set.get_image(6)->set_pos( w_width*72/100, w_height/100*76 );
									cursorPos = TOP;
								}
								// If cursor in BOTTOM (Block), move to TOP (Sp.Attack)
								if( cursorPos == BOTTOM ) {
									set.get_image(6)->set_pos( w_width*72/100, w_height/100*82-5 );
									cursorPos = MID;
								}
							}
							else
							{
								
								// If cursor in MID (ZOMBIE), and HALO is alive, move CURSOR to TOP (HALO)
								if ( cursorPos == MID && !set.get_image(HALO)->is_dead() ){
									set.get_image(6)->set_pos( w_width*72/100, w_height/100*76  );
										cursorPos = TOP;
								}
								// If cursor in BOTTOM (PESTILENT), and ZOMBIE is alive, move CURSOR to MID (ZOMBIE)
								if ( cursorPos == BOTTOM && !set.get_image(4)->is_dead() ){
									set.get_image(6)->set_pos( w_width*72/100, w_height/100*82-5 );
						   		    cursorPos = MID;
								}
								// If cursor in BOTTOM (PESTILENT), ZOMBIE is dead, HALO is alive, move CURSOR to TOP (HALO)
								if ( cursorPos == BOTTOM && set.get_image(4)->is_dead() && !set.get_image(3)->is_dead() ){
									set.get_image(6)->set_pos( w_width*72/100, w_height/100*76  );
									cursorPos = TOP;
								}
							}
						}
					}
					break;

				case SDLK_DOWN:
					// If not paused
					if(  !set.get_image(25)->should_draw() )
					{
						// Player is not moving
						if( currentAction == IDDLE )
						{
							// Select Action here
							if( selectedAction == NONE )
							{
								// If cursor in MID (Sp.Attack), move to BOTTOM (Block)
								if( cursorPos == MID ) {
									set.get_image(6)->set_pos( w_width*72/100, w_height/100*87 - 5 );
									cursorPos = BOTTOM;
								}
								// If cursor in TOP (Attack), move to MID (Sp.Attack)
								if( cursorPos == TOP ) {
									set.get_image(6)->set_pos( w_width*72/100, w_height/100*82-5 );
									cursorPos = MID;
								}
							}
							else
							{
							// Select Target here
								// If cursor in MID (ZOMBIE), and PESTILENT is alive, move CURSOR to BOTTOM (PESTILENT)
								if ( cursorPos == MID && !set.get_image(5)->is_dead() ){
									set.get_image(6)->set_pos( w_width*72/100, w_height/100*87 - 5  );
									cursorPos = BOTTOM;
								}
								// If cursor in TOP (HALO), and ZOMBIE is alive, move CURSOR to MID (ZOMBIE)
								if ( cursorPos == TOP && !set.get_image(4)->is_dead() ){
									set.get_image(6)->set_pos( w_width*72/100, w_height/100*82-5 );
									cursorPos = MID;
								}
								// If cursor in TOP (HALO), ZOMBIE is dead, HALO is alive, move CURSOR to BOTTOM (HALO)
								if ( cursorPos == TOP && set.get_image(4)->is_dead() && !set.get_image(5)->is_dead() ){
									set.get_image(6)->set_pos( w_width*72/100, w_height/100*87 - 5  );
									cursorPos = BOTTOM;
								}
							}
						}
					}
					break;

				case SDLK_RETURN:
					cout << "Enter pressed!" << endl;
					// If not paused
					if(  !set.get_image(25)->should_draw() )
					{
						// Player is not moving
						if( currentAction == IDDLE )
						{
							// If cursor in TOP ( ATTACK or HALO ) 
							if ( cursorPos == TOP ) 
							{
								// Select action here
								if ( selectedAction == NONE ){
								
									selectedAction = IS_ATTACK;

									// HALO is dead, ZOMBIE is dead, cursor set to BOTTOM (PESTILENT)
									if ( set.get_image(3)->is_dead() && set.get_image(4)->is_dead() ){
										set.get_image(6)->set_pos( w_width*72/100, w_height/100*87 - 5  );
										cursorPos = BOTTOM;
									}
									// HALO is dead, set cursor to MID (ZOMBIE)
									else if ( set.get_image(3)->is_dead() ){
										set.get_image(6)->set_pos( w_width*72/100, w_height/100*82-5 );
										cursorPos = MID;
									}
									// cursor set to TOP (HALO)
									else{
										set.get_image(6)->set_pos( w_width*72/100, w_height/100*76  );
										cursorPos = TOP;
									}
								}
								// Select taget here
								else{
									selectedTarget = HALO;
									// Switch phase from IDDLE to MOTION
									currentAction = MOTION;
									set.get_image(6)->set_pos( w_width*72/100, w_height/100*76  );
									cursorPos = TOP;
								}
							}
							// If cursor in MID ( SP.ATTACK or ZOMBIE ) 
							else if ( cursorPos == MID ) 
							{
								// Select action here
								if ( selectedAction == NONE ){
									selectedAction = IS_SPECIALATTACK;
									
									// HALO is dead, ZOMBIE is dead, cursor set to BOTTOM (PESTILENT)
									if ( set.get_image(3)->is_dead()  && set.get_image(4)->is_dead()  ){
										set.get_image(6)->set_pos( w_width*72/100, w_height/100*87 - 5  );
										cursorPos = BOTTOM;
									}
									// HALO is dead, set cursor to MID (ZOMBIE)
									else if ( set.get_image(3)->is_dead() ){
										set.get_image(6)->set_pos( w_width*72/100, w_height/100*82-5 );
										cursorPos = MID;
									}
									// cursor set to TOP (HALO)
									else{
										set.get_image(6)->set_pos( w_width*72/100, w_height/100*76  );
										cursorPos = TOP;
									}
								}
								else{
									selectedTarget = ZOMBIE;
									// Start Motion
									currentAction = MOTION;
							 	    set.get_image(6)->set_pos( w_width*72/100, w_height/100*76  );
									cursorPos = TOP;
								}
							}
							// Cursor is BOTTOM (BLOCK or PESTILENT)
							else 
							{
								if ( selectedAction == NONE ){
									selectedAction = IS_BLOCK;
								}
								else{
									selectedTarget = PESTILENT;
									currentAction = MOTION;
									set.get_image(6)->set_pos( w_width*72/100, w_height/100*76  );
									cursorPos = TOP;
								}
							}
						}
					}
			 	    break;

				default:
					cout << "Useless Key typed!" << endl;
			}
		}
    }

    void Screenf::update(){
	  /**** EXIT CONDITION ****/
	  	// If player's characters are dead
		if( set.get_image(0)->is_dead() && set.get_image(1)->is_dead() && set.get_image(2)->is_dead() && currentTurn == NONE )
		{
			cout << "GAME OVER!" << endl;
			if( Mix_PausedMusic() == 0 ){
				// Pause Music
				Mix_PauseMusic();
				// Free Music to display next screen's music
				Mix_FreeMusic( bMusic );
				bMusic = NULL;
			}
			// Move to GAMEOVER screen
			Game::currentScreen = GAME_OVER;
		}
		// If enemy's characters are dead
		if( set.get_image(3)->is_dead() && set.get_image(4)->is_dead() && set.get_image(5)->is_dead() && currentTurn == NONE)
		{
			cout << "GAME WIN!" << endl;
			if( Mix_PausedMusic() == 0 ){
				// Pause Music
				Mix_PauseMusic();
				// Free Music to display next screen's music
				Mix_FreeMusic( bMusic );
				bMusic = NULL;
				
			}
			
			// case LVL_ONE, transition to LVL_COMPLETED screen
			if( Game::currentScreen == FIGHT_SCREEN_LVL_ONE )
				Game::currentScreen = LVL_COMPLETED;
			// case LVL_TWO, transition to CREDITS screen
			else
				Game::currentScreen = CREDITS;
		}
	  /**** END EXIT CONDITION ****/

	  /**** UPDATE IF GAME IS NOT PAUSED ***/
		if( !set.get_image(25)->should_draw() )
		{
			// Play Music when loaded for the first time
			if( Mix_PlayingMusic() == 0 )
			{
				
				Mix_PlayMusic( bMusic, -1 );
			}

			frame++;
			frameTimer++;
	
			// Decide what character is attacking next: ( when character's SPEED reaches 100 and it is ALIVE ). If tie, character players attack first.
			if( set.get_image(0)->attack_now()  &&  !set.get_image(0)->is_dead() )
				currentTurn = GOKU;	    
			else if ( set.get_image(1)->attack_now()  &&  !set.get_image(1)->is_dead() ) 
				currentTurn = WARIO;
			else if ( set.get_image(2)->attack_now()  &&  !set.get_image(2)->is_dead() ) 
				currentTurn = LINK;
			else if ( set.get_image(3)->attack_now()  &&  !set.get_image(3)->is_dead() ) 
				currentTurn = HALO;
			else if ( set.get_image(4)->attack_now()  &&  !set.get_image(4)->is_dead() ) 
				currentTurn = ZOMBIE;
			else if ( set.get_image(5)->attack_now()  &&  !set.get_image(5)->is_dead() ) 
				currentTurn = PESTILENT;
			else
				currentTurn = NONE;
			
			// Process a move when it is a character's turn
			if ( currentTurn != NONE )
			{
				// stop block at the start of that character's new turn
				if( set.get_image(currentTurn)->is_blocking() ){
					set.get_image(currentTurn)->deblock();
				}

				// case where player character, process turn inmediately
				if( currentTurn <= LINK ){
					player_turn();
				}
				// AI selects target, then process turn
				else
				{
					// Enemy starts MOTION without user input
					if( currentAction == IDDLE) 
						currentAction = MOTION;
					/** NEED TO REVISE THIS **/
					// AI attacks player that has the lowest health
					if ( set.get_image( 0 )->get_PS() <= set.get_image( 1 )->get_PS()   &&    set.get_image( 0 )->get_PS() <= set.get_image( 2 )->get_PS()  && !set.get_image(0)->is_dead() ){
			
						selectedTarget = GOKU;
					}
					else if (  ( (set.get_image( 1 )->get_PS() <= set.get_image( 0 )->get_MAX_PS()   &&    set.get_image( 1 )->get_PS() <= set.get_image( 2 )->get_PS())
							 || (set.get_image( 1 )->get_PS() <= set.get_image( 2 )->get_PS()       &&    set.get_image(0)->is_dead() )	 )							
								 &&  !set.get_image(1)->is_dead() )
						selectedTarget = WARIO;
					else if ( !set.get_image(2)->is_dead() )
						selectedTarget = LINK;

					player_turn();
				}
			}
	
			// DINAMIC UPDATE STATS while all characters IDDLE
			if ( currentTurn == NONE )
			{

				/*** SPEED RELATED UPDATES ***/
				if( !set.get_image(0)->is_dead() ){
					set.get_image(0)->update_spd();
					strManager.clear();
					strManager.str( string() );
					strManager << "PS=" << set.get_image(0)->get_PS() << "/" << set.get_image(0)->get_MAX_PS() << "    SPD=" << set.get_image(0)->get_SPD() << "/100    ATT=" << set.get_image(0)->get_ATT();
					set.replace( generate_image( gFont3, strManager.str().c_str(), w_width*3/100, w_height*80.5/100 ),   16 );
				}

			 	if( !set.get_image(1)->is_dead() ){
					set.get_image(1)->update_spd();
					strManager.clear();
					strManager.str( string() );
					strManager << "PS=" << set.get_image(1)->get_PS() << "/" << set.get_image(1)->get_MAX_PS() << "    SPD=" << set.get_image(1)->get_SPD() << "/100    ATT=" << set.get_image(1)->get_ATT() ;
					set.replace( generate_image( gFont3, strManager.str().c_str(), w_width*3/100, w_height*87.6/100),   17 );
				}

			 	if( !set.get_image(2)->is_dead() ){
					set.get_image(2)->update_spd();
					strManager.clear();
					strManager.str( string() );
					strManager << "PS=" << set.get_image(2)->get_PS() << "/" << set.get_image(2)->get_MAX_PS() << "    SPD=" << set.get_image(2)->get_SPD() << "/100    ATT=" << set.get_image(2)->get_ATT() ;
					set.replace( generate_image( gFont3, strManager.str().c_str(), w_width*3/100, w_height*94.7/100),   18 );
				}

				if( !set.get_image(3)->is_dead() ){
					set.get_image(3)->update_spd();
					strManager.clear();
					strManager.str( string() );
					strManager << "PS=" << set.get_image(3)->get_PS() << "/" << set.get_image(3)->get_MAX_PS() << "    SPD=" << set.get_image(3)->get_SPD() << "/100";
					set.replace( generate_image( gFont3, strManager.str().c_str(), w_width*45.7/100, w_height*80.5/100),   19 );
				}

				if( !set.get_image(4)->is_dead() ){
					set.get_image(4)->update_spd();
					strManager.clear();
					strManager.str( string() );
			   		strManager << "PS=" << set.get_image(4)->get_PS() << "/" << set.get_image(4)->get_MAX_PS() << "    SPD=" << set.get_image(4)->get_SPD() << "/100";
					set.replace( generate_image( gFont3, strManager.str().c_str(), w_width*45.7/100, w_height*87.6/100),   20 );
				}

				if( !set.get_image(5)->is_dead() ){
					set.get_image(5)->update_spd();
					strManager.clear();
					strManager.str( string() );
					strManager << "PS=" << set.get_image(5)->get_PS() << "/" << set.get_image(5)->get_MAX_PS() << "    SPD=" << set.get_image(5)->get_SPD() << "/100";
					set.replace( generate_image( gFont3, strManager.str().c_str(), w_width*45.7/100, w_height*94.7/100),   21 );
				}
				/*** END SPEED RELATED UPDATES ***/
			}

			// PLAYER MENU - display when it is a player's chacter turn & the character has not started motion
			if ( currentTurn != NONE && currentAction == IDDLE )
			{
				set.get_image(6)->do_draw();
				// show actions (ATTACK, SPATTACK, BLOCK) if no action selected
				if( selectedAction == NONE ){
					set.get_image(7)->do_draw();
					set.get_image(8)->do_draw();
					set.get_image(9)->do_draw();
					set.get_image(22)->donot_draw();
					set.get_image(23)->donot_draw();
					set.get_image(24)->donot_draw();
				}
				// Do not draw menu, finish turn if player blocks
				else if( selectedAction == IS_BLOCK ){
					set.get_image(7)->donot_draw();
					set.get_image(8)->donot_draw();
					set.get_image(9)->donot_draw();
					set.get_image( currentTurn )->block();
					set.get_image( currentTurn )->donot_attack();
					selectedAction = NONE;
					currentTurn = NONE;
					//set.get_image(22)->donot_draw();
					//set.get_image(23)->donot_draw();
					//set.get_image(24)->donot_draw();
				}
				// Show enemies' names if no target selected
				else if( selectedTarget == NONE ) {
					set.get_image(7)->donot_draw();
					set.get_image(8)->donot_draw();
					set.get_image(9)->donot_draw();
					set.get_image(22)->do_draw();
					set.get_image(23)->do_draw();
					set.get_image(24)->do_draw();
				}
			}
			else
			{
				set.get_image(6)->donot_draw();
				set.get_image(7)->donot_draw();
				set.get_image(8)->donot_draw();
				set.get_image(9)->donot_draw();
				set.get_image(22)->donot_draw();
				set.get_image(23)->donot_draw();
				set.get_image(24)->donot_draw();
			}
			
			// Testing Purposes.
			if ( currentTurn != currentTurnAnt || selectedTarget != selectedTargetAnt ||  currentAction != currentActionAnt ){
				currentActionAnt = currentAction;
				currentTurnAnt = currentTurn;
				selectedTargetAnt = selectedTarget;
				    printf("%4d,  %4d,  %4d,   %4d\n",frame,currentTurn,selectedTarget,currentAction);
		//	    cout << frame << " , " << currentTurn <<  " , " << selectedTarget <<  " , " << currentAction <<  endl;
			}
		}
    }

	// Render components. Background and rectangles are drawn first, followed by the component list. 
    void Screenf::render(){
		gBackground->draw();
		bRect->set_color(22, 46, 144);
		bRect->draw();
		outRect->set_color(255, 255, 255);
		outRect->draw_outline();
		leftRect->draw_outline();
		rightRect->draw_outline();
		midRect->draw_outline();
		set.draw();
    }

	// Clean all components in the screen
    void Screenf::clean(){
		set.clean();		
		gBackground->clean();
		SDL_DestroyTexture( fontSup );
		fontSup = NULL;
		Mix_FreeMusic( bMusic );
		bMusic = NULL;
		delete bRect;
		delete outRect;
		delete leftRect;
		delete rightRect;
		delete midRect;
		bRect = NULL;
		outRect = NULL;
		leftRect = NULL;
		rightRect = NULL;
		midRect = NULL;

		TTF_CloseFont( gFont2 );
		gFont2 = NULL;
		TTF_CloseFont( gFont3 );
		gFont3 = NULL;
		TTF_CloseFont( gFont4 );
		gFont4 = NULL;
    }


	// Generates images with text
    Image* Screenf::generate_image( TTF_Font *font, const char* str, int x, int y ){
		SDL_Color whiteColor = { 255, 255, 255 };
		int w, h;
		fontSup = LTexture::loadFont( font, str, whiteColor );
		SDL_QueryTexture(fontSup, NULL, NULL, &w, &h);
		Image* image = new Image( x, y, w, h );
		image->set_image( fontSup );
		return image;
    }

	// GENERIC turn proccesor function (for both player and enemy characters). One character at a a time.
    void Screenf::player_turn(){
		int startingSpritePos = 0;
		
		// ANIMATION - Reset frames to reset animation for motion
		if( currentAction == MOTION || currentAction == BACK_MOTION ){
			if (   ( frame/set.get_image( currentTurn )->get_swapFrame() )      >=      ( set.get_image( currentTurn )->get_nMotionSprites() ) ) 
				frame = 0;
		}
		// ANIMATION - Reset frames to reset animation for attack
		else if( currentAction == ATTACK ){
			if (   ( frame/set.get_image( currentTurn )->get_swapFrame() )      >=      ( set.get_image( currentTurn )->get_nAttackSprites() ) )
				frame = 0;
		}

		// ANIMATION - Get starting position in the array of the animations of a character
		switch ( currentTurn )
		{
			case GOKU:		startingSpritePos = GOKU_SPRITE;		break;
			case WARIO:		startingSpritePos = WARIO_SPRITE;		break;
			case LINK:		startingSpritePos = LINK_SPRITE;		break;
			case HALO:		startingSpritePos = HALO_SPRITE;		break;
			case ZOMBIE:	startingSpritePos = ZOMBIE_SPRITE;		break;
			default:		startingSpritePos = PESTILENT_SPRITE;	break;
		}

		switch ( currentAction )
		{
			case MOTION:
				// Check if current character has collided with target character.
				if( !set.get_image( currentTurn )->check_front_collision( set.get_image( selectedTarget )->get_x_origin(),   set.get_image( selectedTarget )->get_y_origin() ) )
				{
					// Move towards target character
					set.get_image( currentTurn )->move_forward( set.get_image( selectedTarget )->get_x_origin(),   set.get_image( selectedTarget )->get_y_origin() );
				}
				// Collision here
				else{
					// Substract current character's attack damage to the targeted character's health
					set.get_image( selectedTarget )->damaged( set.get_image( currentTurn )->get_ATT() );
					
					// Update Stats
					strManager.clear();
					strManager.str( string() );
					strManager << "PS=" << set.get_image( selectedTarget )->get_PS() << "/" << set.get_image( selectedTarget )->get_MAX_PS() << "    SPD=" << set.get_image( selectedTarget )->get_SPD() << "/100";
					set.replace( generate_image( gFont3, strManager.str().c_str(), set.get_image( selectedTarget+16 )->get_x_origin() , set.get_image( selectedTarget+16 )->get_y_origin() ),   selectedTarget+16 );
					
					// Move forward to ATTACK
					currentAction = ATTACK;
					frame = 0;
					frameTimer = 0;
				}
				// Motion animation of a given character
				set.get_image( currentTurn )->update_sprite( sprite[ (startingSpritePos+1) + ( frame/set.get_image( currentTurn )->get_swapFrame() ) ] );
				break;

			case ATTACK:
				// Attack animation of a given character
				set.get_image( currentTurn )->update_sprite( sprite[ (startingSpritePos+1+set.get_image( currentTurn )->get_nMotionSprites() ) + ( frame/set.get_image( currentTurn )->get_swapFrame() ) ] );
				
				// show for 30 frames
				if( frameTimer == 30 )
					currentAction = BACK_MOTION;
				break;

			case BACK_MOTION:
				// Back motion animation
				set.get_image( currentTurn )->update_sprite( sprite[ (startingSpritePos+1) + ( frame/set.get_image( currentTurn )->get_swapFrame() ) ] );
				
				// Check backwards collision (with original location of the rectangle/sprite)
				if( !set.get_image( currentTurn )->check_back_collision() ){
					// Move towards original position
					set.get_image( currentTurn )->move_backward();
				}
				// Collision
				else{
					// Set starting sprite, reset ACTION variables to finish turn
					set.get_image( currentTurn )->update_sprite( sprite[ startingSpritePos ] );
					currentAction = IDDLE;
					selectedAction = NONE;
					selectedTarget = NONE;
					currentTurn = NONE;
				}
				break;

			default:
				break;

		}
	}

	// Load sprites
    void Screenf::fill_sprites(){
    	sprite[GOKU_SPRITE].x = 3;
    	sprite[GOKU_SPRITE].y = 102;
    	sprite[GOKU_SPRITE].w = 33  - sprite[GOKU_SPRITE].x;
    	sprite[GOKU_SPRITE].h = 152 - sprite[GOKU_SPRITE].y;

		// GOKU MOTION
   		sprite[GOKU_SPRITE+1].x = 135;
    	sprite[GOKU_SPRITE+1].y = 112;
    	sprite[GOKU_SPRITE+1].w = 173 - sprite[GOKU_SPRITE+1].x;
    	sprite[GOKU_SPRITE+1].h = 152 - sprite[GOKU_SPRITE+1].y;

		// GOKU ATTACK
		sprite[GOKU_SPRITE+2].x = 375;
    	sprite[GOKU_SPRITE+2].y = 175;
   	 	sprite[GOKU_SPRITE+2].w = 416 - sprite[GOKU_SPRITE+2].x;
    	sprite[GOKU_SPRITE+2].h = 216 - sprite[GOKU_SPRITE+2].y;

		sprite[GOKU_SPRITE+3].x = 430;
    	sprite[GOKU_SPRITE+3].y = 173;
   	 	sprite[GOKU_SPRITE+3].w = 480 - sprite[GOKU_SPRITE+3].x;
    	sprite[GOKU_SPRITE+3].h = 216 - sprite[GOKU_SPRITE+3].y;

		sprite[GOKU_SPRITE+4].x = 493;
    	sprite[GOKU_SPRITE+4].y = 172;
   	 	sprite[GOKU_SPRITE+4].w = 540 - sprite[GOKU_SPRITE+4].x;
    	sprite[GOKU_SPRITE+4].h = 216 - sprite[GOKU_SPRITE+4].y;
		

    	// WARIO
    	sprite[WARIO_SPRITE].x = 205;
    	sprite[WARIO_SPRITE].y = 0;
   	 	sprite[WARIO_SPRITE].w = 230 - sprite[WARIO_SPRITE].x;
    	sprite[WARIO_SPRITE].h = 34  - sprite[WARIO_SPRITE].y;
    	// Wario Motion
    	sprite[WARIO_SPRITE+1].x = 202;
    	sprite[WARIO_SPRITE+1].y = 159;
    	sprite[WARIO_SPRITE+1].w = 233 - sprite[WARIO_SPRITE+1].x;
    	sprite[WARIO_SPRITE+1].h = 194 - sprite[WARIO_SPRITE+1].y;

    	sprite[WARIO_SPRITE+2].x = 242;
    	sprite[WARIO_SPRITE+2].y = 159;
    	sprite[WARIO_SPRITE+2].w = 272 - sprite[WARIO_SPRITE+2].x;
    	sprite[WARIO_SPRITE+2].h = 194 - sprite[WARIO_SPRITE+2].y;

   		sprite[WARIO_SPRITE+3].x = 281;
    	sprite[WARIO_SPRITE+3].y = 159;
    	sprite[WARIO_SPRITE+3].w = 314 - sprite[WARIO_SPRITE+3].x;
    	sprite[WARIO_SPRITE+3].h = 193 - sprite[WARIO_SPRITE+3].y;

    	sprite[WARIO_SPRITE+4].x = 323;
    	sprite[WARIO_SPRITE+4].y = 159;
    	sprite[WARIO_SPRITE+4].w = 351 - sprite[WARIO_SPRITE+4].x;
    	sprite[WARIO_SPRITE+4].h = 194 - sprite[WARIO_SPRITE+4].y;

    	sprite[WARIO_SPRITE+5].x = 204;
    	sprite[WARIO_SPRITE+5].y = 119;
    	sprite[WARIO_SPRITE+5].w = 230 - sprite[WARIO_SPRITE+5].x;
    	sprite[WARIO_SPRITE+5].h = 153 - sprite[WARIO_SPRITE+5].y;

    	sprite[WARIO_SPRITE+6].x = 243;
    	sprite[WARIO_SPRITE+6].y = 119;
    	sprite[WARIO_SPRITE+6].w = 272 - sprite[WARIO_SPRITE+6].x;
    	sprite[WARIO_SPRITE+6].h = 154 - sprite[WARIO_SPRITE+6].y;

    	sprite[WARIO_SPRITE+7].x = 282;
    	sprite[WARIO_SPRITE+7].y = 119;
    	sprite[WARIO_SPRITE+7].w = 311 - sprite[WARIO_SPRITE+7].x;
    	sprite[WARIO_SPRITE+7].h = 153 - sprite[WARIO_SPRITE+7].y;

    	sprite[WARIO_SPRITE+8].x = 324;
    	sprite[WARIO_SPRITE+8].y = 119;
    	sprite[WARIO_SPRITE+8].w = 350 - sprite[WARIO_SPRITE+8].x;
    	sprite[WARIO_SPRITE+8].h = 154 - sprite[WARIO_SPRITE+8].y;

		// WARIO ATTACK SPRITE
    	sprite[WARIO_SPRITE+9].x = 283;
    	sprite[WARIO_SPRITE+9].y = 280;
    	sprite[WARIO_SPRITE+9].w = 317 - sprite[WARIO_SPRITE+9].x;
    	sprite[WARIO_SPRITE+9].h = 312 - sprite[WARIO_SPRITE+9].y;

    	// LINK
    	sprite[LINK_SPRITE].x = 698;
    	sprite[LINK_SPRITE].y = 255;
    	sprite[LINK_SPRITE].w = 780 - sprite[LINK_SPRITE].x;
    	sprite[LINK_SPRITE].h = 341 - sprite[LINK_SPRITE].y;

		// LINK MOTION
    	sprite[LINK_SPRITE+1].x = 24;
    	sprite[LINK_SPRITE+1].y = 40;
    	sprite[LINK_SPRITE+1].w = 88  - sprite[LINK_SPRITE+1].x;
    	sprite[LINK_SPRITE+1].h = 113 - sprite[LINK_SPRITE+1].y;

    	sprite[LINK_SPRITE+2].x = 136;
    	sprite[LINK_SPRITE+2].y = 35;
    	sprite[LINK_SPRITE+2].w = 204 - sprite[LINK_SPRITE+2].x;
    	sprite[LINK_SPRITE+2].h = 114 - sprite[LINK_SPRITE+2].y;

    	sprite[LINK_SPRITE+3].x = 252;
    	sprite[LINK_SPRITE+3].y = 40;
    	sprite[LINK_SPRITE+3].w = 316 - sprite[LINK_SPRITE+3].x;
    	sprite[LINK_SPRITE+3].h = 113 - sprite[LINK_SPRITE+3].y;

		// LINK ATTACK
		sprite[LINK_SPRITE+4].x = 577;
    	sprite[LINK_SPRITE+4].y = 6;
    	sprite[LINK_SPRITE+4].w = 673 - sprite[LINK_SPRITE+4].x;
    	sprite[LINK_SPRITE+4].h = 113 - sprite[LINK_SPRITE+4].y;

    	sprite[LINK_SPRITE+5].x = 342;
    	sprite[LINK_SPRITE+5].y = 39;
    	sprite[LINK_SPRITE+5].w = 423 - sprite[LINK_SPRITE+5].x;
    	sprite[LINK_SPRITE+5].h = 113 - sprite[LINK_SPRITE+5].y;

    	sprite[LINK_SPRITE+6].x = 454;
    	sprite[LINK_SPRITE+6].y = 19;
    	sprite[LINK_SPRITE+6].w = 569 - sprite[LINK_SPRITE+6].x;
    	sprite[LINK_SPRITE+6].h = 114 - sprite[LINK_SPRITE+6].y;   // 20 

		// HALO
    	sprite[HALO_SPRITE].x = 222;
    	sprite[HALO_SPRITE].y = 270;
    	sprite[HALO_SPRITE].w = 267 - sprite[HALO_SPRITE].x;
    	sprite[HALO_SPRITE].h = 324 - sprite[HALO_SPRITE].y; 

		// HALO MOTION
    	sprite[HALO_SPRITE+1].x = 220;
    	sprite[HALO_SPRITE+1].y = 5;
    	sprite[HALO_SPRITE+1].w = 255 - sprite[HALO_SPRITE+1].x;
    	sprite[HALO_SPRITE+1].h = 59 - sprite[HALO_SPRITE+1].y;   // 20 

    	sprite[HALO_SPRITE+2].x = 222;
    	sprite[HALO_SPRITE+2].y = 69;
    	sprite[HALO_SPRITE+2].w = 255 - sprite[HALO_SPRITE+2].x;
    	sprite[HALO_SPRITE+2].h = 127 - sprite[HALO_SPRITE+2].y;  

    	sprite[HALO_SPRITE+3].x = 220;
    	sprite[HALO_SPRITE+3].y = 134;
    	sprite[HALO_SPRITE+3].w = 259 - sprite[HALO_SPRITE+3].x;
    	sprite[HALO_SPRITE+3].h = 191 - sprite[HALO_SPRITE+3].y;  

   		sprite[HALO_SPRITE+4].x = 221;
    	sprite[HALO_SPRITE+4].y = 201;
    	sprite[HALO_SPRITE+4].w = 252 - sprite[HALO_SPRITE+4].x;
    	sprite[HALO_SPRITE+4].h = 258 - sprite[HALO_SPRITE+4].y;

		// HALO ATTACK
   		sprite[HALO_SPRITE+5].x = 222;
    	sprite[HALO_SPRITE+5].y = 270;
    	sprite[HALO_SPRITE+5].w = 267 - sprite[HALO_SPRITE+5].x;
    	sprite[HALO_SPRITE+5].h = 324 - sprite[HALO_SPRITE+5].y;

   		sprite[HALO_SPRITE+6].x = 223;
    	sprite[HALO_SPRITE+6].y = 333;
    	sprite[HALO_SPRITE+6].w = 275 - sprite[HALO_SPRITE+6].x;
    	sprite[HALO_SPRITE+6].h = 387 - sprite[HALO_SPRITE+6].y;

		// ZOMBIE
     	sprite[ZOMBIE_SPRITE].x = 546;
    	sprite[ZOMBIE_SPRITE].y = 56;
    	sprite[ZOMBIE_SPRITE].w = 583 - sprite[ZOMBIE_SPRITE].x;
    	sprite[ZOMBIE_SPRITE].h = 106 - sprite[ZOMBIE_SPRITE].y;

		// ZOMBIE MOTION
    	sprite[ZOMBIE_SPRITE+1].x = 508;
    	sprite[ZOMBIE_SPRITE+1].y = 56;
    	sprite[ZOMBIE_SPRITE+1].w = 544 - sprite[ZOMBIE_SPRITE+1].x;
    	sprite[ZOMBIE_SPRITE+1].h = 106 - sprite[ZOMBIE_SPRITE+1].y;

    	sprite[ZOMBIE_SPRITE+2].x = 469;
    	sprite[ZOMBIE_SPRITE+2].y = 55;
    	sprite[ZOMBIE_SPRITE+2].w = 501 - sprite[ZOMBIE_SPRITE+2].x;
    	sprite[ZOMBIE_SPRITE+2].h = 106 - sprite[ZOMBIE_SPRITE+2].y;

    	sprite[ZOMBIE_SPRITE+3].x = 430;
    	sprite[ZOMBIE_SPRITE+3].y = 55;
    	sprite[ZOMBIE_SPRITE+3].w = 459 - sprite[ZOMBIE_SPRITE+3].x;
    	sprite[ZOMBIE_SPRITE+3].h = 106 - sprite[ZOMBIE_SPRITE+3].y;

    	sprite[ZOMBIE_SPRITE+4].x = 391;
    	sprite[ZOMBIE_SPRITE+4].y = 55;
    	sprite[ZOMBIE_SPRITE+4].w = 423 - sprite[ZOMBIE_SPRITE+4].x;
    	sprite[ZOMBIE_SPRITE+4].h = 106 - sprite[ZOMBIE_SPRITE+4].y;

    	sprite[ZOMBIE_SPRITE+5].x = 352;
    	sprite[ZOMBIE_SPRITE+5].y = 56;
    	sprite[ZOMBIE_SPRITE+5].w = 390 - sprite[ZOMBIE_SPRITE+5].x;
    	sprite[ZOMBIE_SPRITE+5].h = 106 - sprite[ZOMBIE_SPRITE+5].y;  

    	sprite[ZOMBIE_SPRITE+6].x = 305;
    	sprite[ZOMBIE_SPRITE+6].y = 57;
    	sprite[ZOMBIE_SPRITE+6].w = 341 - sprite[ZOMBIE_SPRITE+6].x;
    	sprite[ZOMBIE_SPRITE+6].h = 106 - sprite[ZOMBIE_SPRITE+6].y;

    	sprite[ZOMBIE_SPRITE+7].x = 268;
    	sprite[ZOMBIE_SPRITE+7].y = 58;
    	sprite[ZOMBIE_SPRITE+7].w = 302 - sprite[ZOMBIE_SPRITE+7].x;
    	sprite[ZOMBIE_SPRITE+7].h = 106 - sprite[ZOMBIE_SPRITE+7].y;

   		sprite[ZOMBIE_SPRITE+8].x = 232;
    	sprite[ZOMBIE_SPRITE+8].y = 57;
    	sprite[ZOMBIE_SPRITE+8].w = 260 - sprite[ZOMBIE_SPRITE+8].x;
    	sprite[ZOMBIE_SPRITE+8].h = 106 - sprite[ZOMBIE_SPRITE+8].y;

   		sprite[ZOMBIE_SPRITE+9].x = 195;
    	sprite[ZOMBIE_SPRITE+9].y = 56;
    	sprite[ZOMBIE_SPRITE+9].w = 227 - sprite[ZOMBIE_SPRITE+9].x;
    	sprite[ZOMBIE_SPRITE+9].h = 107 - sprite[ZOMBIE_SPRITE+9].y;

     	sprite[ZOMBIE_SPRITE+10].x = 220;
    	sprite[ZOMBIE_SPRITE+10].y = 5;
    	sprite[ZOMBIE_SPRITE+10].w = 255 - sprite[ZOMBIE_SPRITE+10].x;
    	sprite[ZOMBIE_SPRITE+10].h = 59  - sprite[ZOMBIE_SPRITE+10].y;

		// ZOMBIE ATTACK
     	sprite[ZOMBIE_SPRITE+11].x = 203;
    	sprite[ZOMBIE_SPRITE+11].y = 112;
    	sprite[ZOMBIE_SPRITE+11].w = 240 - sprite[ZOMBIE_SPRITE+11].x;
    	sprite[ZOMBIE_SPRITE+11].h = 162 - sprite[ZOMBIE_SPRITE+11].y;

     	sprite[ZOMBIE_SPRITE+12].x = 171;
    	sprite[ZOMBIE_SPRITE+12].y = 112;
    	sprite[ZOMBIE_SPRITE+12].w = 203 - sprite[ZOMBIE_SPRITE+12].x;
    	sprite[ZOMBIE_SPRITE+12].h = 162 - sprite[ZOMBIE_SPRITE+12].y;

     	sprite[ZOMBIE_SPRITE+13].x = 142;
    	sprite[ZOMBIE_SPRITE+13].y = 107;
    	sprite[ZOMBIE_SPRITE+13].w = 168 - sprite[ZOMBIE_SPRITE+13].x;
    	sprite[ZOMBIE_SPRITE+13].h = 162 - sprite[ZOMBIE_SPRITE+13].y;

     	sprite[ZOMBIE_SPRITE+14].x = 171;
    	sprite[ZOMBIE_SPRITE+14].y = 112;
    	sprite[ZOMBIE_SPRITE+14].w = 203 - sprite[ZOMBIE_SPRITE+14].x;
    	sprite[ZOMBIE_SPRITE+14].h = 162 - sprite[ZOMBIE_SPRITE+14].y;

     	sprite[ZOMBIE_SPRITE+15].x = 203;
    	sprite[ZOMBIE_SPRITE+15].y = 112;
    	sprite[ZOMBIE_SPRITE+15].w = 240 - sprite[ZOMBIE_SPRITE+15].x;
    	sprite[ZOMBIE_SPRITE+15].h = 162 - sprite[ZOMBIE_SPRITE+15].y;

     	sprite[ZOMBIE_SPRITE+16].x = 98;
    	sprite[ZOMBIE_SPRITE+16].y = 114;
    	sprite[ZOMBIE_SPRITE+16].w = 132 - sprite[ZOMBIE_SPRITE+16].x;
    	sprite[ZOMBIE_SPRITE+16].h = 161 - sprite[ZOMBIE_SPRITE+16].y;

     	sprite[ZOMBIE_SPRITE+17].x = 63;
    	sprite[ZOMBIE_SPRITE+17].y = 113;
    	sprite[ZOMBIE_SPRITE+17].w = 96  - sprite[ZOMBIE_SPRITE+17].x;
    	sprite[ZOMBIE_SPRITE+17].h = 162 - sprite[ZOMBIE_SPRITE+17].y;

		// PESTILENT
		sprite[PESTILENT_SPRITE].x = 595;
    	sprite[PESTILENT_SPRITE].y = 7;
    	sprite[PESTILENT_SPRITE].w = 629 - sprite[PESTILENT_SPRITE].x;
    	sprite[PESTILENT_SPRITE].h = 78  - sprite[PESTILENT_SPRITE].y;

		// PESTILENT MOTION
    	sprite[PESTILENT_SPRITE+1].x = 476;
    	sprite[PESTILENT_SPRITE+1].y = 86;
    	sprite[PESTILENT_SPRITE+1].w = 508 - sprite[PESTILENT_SPRITE+1].x;
    	sprite[PESTILENT_SPRITE+1].h = 157 - sprite[PESTILENT_SPRITE+1].y;

    	sprite[PESTILENT_SPRITE+2].x = 538;
    	sprite[PESTILENT_SPRITE+2].y = 86;
    	sprite[PESTILENT_SPRITE+2].w = 573 - sprite[PESTILENT_SPRITE+2].x;
    	sprite[PESTILENT_SPRITE+2].h = 157 - sprite[PESTILENT_SPRITE+2].y;

    	sprite[PESTILENT_SPRITE+3].x = 308;
    	sprite[PESTILENT_SPRITE+3].y = 86;
    	sprite[PESTILENT_SPRITE+3].w = 348 - sprite[PESTILENT_SPRITE+3].x;
    	sprite[PESTILENT_SPRITE+3].h = 157 - sprite[PESTILENT_SPRITE+3].y;

    	sprite[PESTILENT_SPRITE+4].x = 253;
    	sprite[PESTILENT_SPRITE+4].y = 88;
    	sprite[PESTILENT_SPRITE+4].w = 284 - sprite[PESTILENT_SPRITE+4].x;
    	sprite[PESTILENT_SPRITE+4].h = 157 - sprite[PESTILENT_SPRITE+4].y;

    	sprite[PESTILENT_SPRITE+5].x = 203;
    	sprite[PESTILENT_SPRITE+5].y = 86;
    	sprite[PESTILENT_SPRITE+5].w = 231 - sprite[PESTILENT_SPRITE+5].x;
    	sprite[PESTILENT_SPRITE+5].h = 157 - sprite[PESTILENT_SPRITE+5].y;

		// PESTILENT ATTACK
 		sprite[PESTILENT_SPRITE+6].x = 315;
    	sprite[PESTILENT_SPRITE+6].y = 246;
    	sprite[PESTILENT_SPRITE+6].w = 348 - sprite[PESTILENT_SPRITE+6].x;
    	sprite[PESTILENT_SPRITE+6].h = 316 - sprite[PESTILENT_SPRITE+6].y;

 		sprite[PESTILENT_SPRITE+7].x = 395;
    	sprite[PESTILENT_SPRITE+7].y = 245;
    	sprite[PESTILENT_SPRITE+7].w = 430 - sprite[PESTILENT_SPRITE+7].x;
    	sprite[PESTILENT_SPRITE+7].h = 316 - sprite[PESTILENT_SPRITE+7].y;

    	sprite[PESTILENT_SPRITE+8].x = 593;
    	sprite[PESTILENT_SPRITE+8].y = 245;
    	sprite[PESTILENT_SPRITE+8].w = 632 - sprite[PESTILENT_SPRITE+8].x;
    	sprite[PESTILENT_SPRITE+8].h = 316 - sprite[PESTILENT_SPRITE+8].y;

    	sprite[PESTILENT_SPRITE+9].x = 543;
    	sprite[PESTILENT_SPRITE+9].y = 243;
    	sprite[PESTILENT_SPRITE+9].w = 586 - sprite[PESTILENT_SPRITE+9].x;
    	sprite[PESTILENT_SPRITE+9].h = 316 - sprite[PESTILENT_SPRITE+9].y;

 		sprite[PESTILENT_SPRITE+10].x = 493;
    	sprite[PESTILENT_SPRITE+10].y = 241;
    	sprite[PESTILENT_SPRITE+10].w = 530 - sprite[PESTILENT_SPRITE+10].x;
    	sprite[PESTILENT_SPRITE+10].h = 316 - sprite[PESTILENT_SPRITE+10].y;

    	sprite[PESTILENT_SPRITE+11].x = 543;
    	sprite[PESTILENT_SPRITE+11].y = 243;
    	sprite[PESTILENT_SPRITE+11].w = 586 - sprite[PESTILENT_SPRITE+11].x;
    	sprite[PESTILENT_SPRITE+11].h = 316 - sprite[PESTILENT_SPRITE+11].y;

    	sprite[PESTILENT_SPRITE+12].x = 593;
    	sprite[PESTILENT_SPRITE+12].y = 245;
    	sprite[PESTILENT_SPRITE+12].w = 632 - sprite[PESTILENT_SPRITE+12].x;
    	sprite[PESTILENT_SPRITE+12].h = 316 - sprite[PESTILENT_SPRITE+12].y;

 		sprite[PESTILENT_SPRITE+13].x = 395;
    	sprite[PESTILENT_SPRITE+13].y = 245;
    	sprite[PESTILENT_SPRITE+13].w = 430 - sprite[PESTILENT_SPRITE+13].x;
    	sprite[PESTILENT_SPRITE+13].h = 316 - sprite[PESTILENT_SPRITE+13].y;
    }
