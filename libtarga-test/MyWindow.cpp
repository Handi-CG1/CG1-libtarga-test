#include "MyWindow.h"
#include <iostream>
#include <Fl/fl_draw.H>
#include "libtarga/libtarga.h"

MyWindow::MyWindow(int width, int height, const char* title) :
	Fl_Window(width, height, title)
{
	image = NULL;
}

MyWindow::~MyWindow()
{
	delete image;
}

void MyWindow::draw()
{
	//setup image
	static bool firstTime = true;
	if (firstTime)
	{
		image = TargaImage::readImage("flower.tga");
		if (image == NULL)
			std::cerr << "Failed to load image." << std::endl;
		else
			size(image->width(), image->height());
		firstTime = false;
	}
	if (image != NULL)
		fl_draw_image(image->pixels(), 0, 0, image->width(), image->height(), 4);
}