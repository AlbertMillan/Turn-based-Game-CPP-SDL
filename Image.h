#ifndef IMAGE_H
#define IMAGE_H

//#include <iostream>
#include "GameManager.h"

class Image {

    public:
    	// Initialize Image, define its position
		Image( int x, int y, int w, int h );

		~Image();
		
		/*** SETTERS ***/
		// Set unique id for the image ( used when added by ImageGroup )
		void set_id( int num );

		// Set/change x_origin and y_origin position for the image.
		void set_pos( int x, int y );

		// Set texture of the image
		void set_image( SDL_Texture *image );

		// Set blending mode for the given texture
		void set_blend_mode( SDL_BlendMode blend );

		// Modify transparency of the image
		void set_alpha( Uint8 alpha );
		
		// Set the image to be drawn on the screen
		void do_draw();

		// Set the image to not be drawn on the screen
		void donot_draw();
		
		/*** END SETTERS ***/
		
		/*** GETTERS ***/
		
		// Get whether the image should be drawn
		bool should_draw();
		
		// Get texture
		SDL_Texture *get_texture();

		// Get x_origin
		int get_x_origin();
		
		// Get y_origin
		int get_y_origin();
		
		/*** END GETTERS ***/
		
		// Draw Image
		virtual void draw();
		
		// Define operator to compare current image with the one passed as a parameter
		bool operator == ( Image &other );

		// Clear
		void clean();

		/*** VIRTUAL FUNCTIONS - Called by child classes ***/
		
		virtual void update_sprite(SDL_Rect rect);

		virtual void donot_attack();

		virtual void block();

		virtual void deblock();

		virtual bool check_front_collision( int x, int y );

		virtual bool check_back_collision();

		virtual bool is_dead();

		virtual bool is_blocking();

		virtual bool attack_now();

		virtual void damaged( int damage );

		virtual void move_forward( int x, int y );
	
		virtual void move_backward();

		virtual void update_spd();

		virtual int get_nMotionSprites();

		virtual int get_nAttackSprites();

		virtual int get_swapFrame();

		virtual int get_PS();

		virtual int get_MAX_PS();

		virtual int get_SPD();

		virtual int get_ATT();

    protected:
		SDL_Rect rect;
		SDL_Texture *texture;
		int id;
		bool is_draw;				// Draws image if true.
};

#endif
