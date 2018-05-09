#include "ImageGroup.h"
#include "Image.h"


    // Adds new image into the vector
    void ImageGroup::add( Image *image ){
        arr.push_back( image );
		image->set_id( arr.size()-1 );
	
    }

	// Retrives a the image at position id from the vector Array
    Image* ImageGroup::get_image( int id ){
		return arr[id];
    }

	// Replaces image at position id with a new image
    void ImageGroup::replace ( Image* image, int id){
	arr[id] = image;
    }

	// Returns true if image is in the vector array
    bool ImageGroup::contains( Image image ){
    	for( int i=0; i<arr.size(); i++ ){
			if( *arr[i] == image ){
			    return true;
			}
		}
		return false;
    }

	// Draws images in the vector array
	void ImageGroup::draw(){
	    if( !arr.empty() ){
	        for( int i=0; i<arr.size(); i++ ){
				if( arr[i]->should_draw() )
				   	arr[i]->draw();
			    }
	    }
	}

	// Cleans the vector array
	void ImageGroup::clean(){
		for( int i=0; i<arr.size(); i++ ){
			arr[i]->clean();
			delete arr[i];
		}
	    arr.clear();
	}


