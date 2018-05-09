#ifndef IMAGEGROUP_H
#define IMAGEGROUP_H


#include "GameManager.h"
#include "Image.h"
#include <vector>

using namespace std;

class ImageGroup {

    public:
    
    // Adds new image into the vector
	void add( Image *image );

	// Retrives a the image at position id from the vector Array
	Image* get_image(int id);	

	// Replaces image at position id with a new image
	void replace(Image* image, int id);

	// Returns true if image is in the vector array
	bool contains( Image image );

	// Draws images in the vector array
	void draw();

	// Cleans the vector array
	void clean();


	//int size();

    private:
	vector<Image*> arr;

};

#endif



