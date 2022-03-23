#include <FL/FL.h>
#include "MyWindow.h"

int main(int argc, char** args)
{
	MyWindow myWindow(400, 400, "CG Tutorial");
	myWindow.show();
	Fl::run();

	return 0;
}