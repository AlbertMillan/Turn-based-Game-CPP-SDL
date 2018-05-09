#include "Image.h"

//using namespace std;


    Image::Image( int x, int y, int w, int h){
		rect.w = w;
		rect.h = h;

		rect.x = x;
		rect.y = y;
		texture = NULL;
		is_draw = true;
    }
 
    Image::~Image(){

    }

    void Image::set_id( int num ){
		id = num;
    }

    void Image::set_pos( int x, int y ){
		rect.x = x;
		rect.y = y;
    }

	
    void Image::set_image( SDL_Texture *image ){
		texture = image;
    }

	void Image::set_blend_mode( SDL_BlendMode blend ){
		// Set blending function
		SDL_SetTextureBlendMode( texture, blend );
	}

	void Image::set_alpha( Uint8 alpha ){
		// Modulate texture alpha
		SDL_SetTextureAlphaMod( texture, alpha );
	}


    void Image::draw(){
		SDL_RenderCopy( Game::gRenderer, texture, NULL, &rect );
    }

    /*** ImageGroup Methods ***/
    SDL_Texture* Image::get_texture() {
		return texture;
    }

    bool Image::operator == ( Image &other ) {
		return ( texture == other.get_texture() );
    }
    /*** End ImageGroup Methods ***/


    void Image::clean(){
		SDL_DestroyTexture( texture );
		texture = NULL;
		//rect = NULL;
    }


    void Image::do_draw(){
	is_draw = true;
    }

    void Image::donot_draw(){
	is_draw = false;
    }

    bool Image::should_draw(){
	return is_draw;
    }

    int Image::get_x_origin(){
	return rect.x;
    }

    int Image::get_y_origin(){
	return rect.y;
    }

    bool Image::check_front_collision( int x, int y ){
		cout << "Hello1" << endl;
    }

    bool Image::check_back_collision(){
		cout << "Hello2" << endl;
    }


    bool Image::is_dead(){
		cout << "Hello3" << endl;
    }

    bool Image::attack_now(){
		cout << "Hello4" << endl;
    }

    bool Image::is_blocking(){
		cout << "Hello4" << endl;
    }

    void Image::donot_attack(){
		is_draw = false;
    }

    void Image::block(){
		cout << "Hello5" << endl;
    }

    void Image::deblock(){
		cout << "Hello6" << endl;
    }

    void Image::damaged( int damage ){
		cout << "Hello5" << endl;
    }

    void Image::move_forward( int x, int y ){
		cout << "Hello6" << endl;
    }

    void Image::move_backward(){
		cout << "Hello7" << endl;
    }

    void Image::update_spd(){
		cout << "Hello8" << endl;
    }

    void Image::update_sprite(SDL_Rect rect){
		cout << "Hello9" << endl;
    }

    int Image::get_nMotionSprites(){
		cout << "Hello10" << endl;
    }

    int Image::get_nAttackSprites(){
		cout << "Hello10" << endl;
    }

    int Image::get_swapFrame(){
		cout << "Hello11" << endl;
    }


    int Image::get_PS(){
		cout << "Hello" << endl;
    }

    int Image::get_MAX_PS(){
		cout << "Hello" << endl;
    }

    int Image::get_SPD(){
		cout << "Hello" << endl;
    }

    int Image::get_ATT(){
		cout << "Hello" << endl;
    }





