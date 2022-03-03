#include <stdio.h>
#include <iostream>

int main(int argc, char *argv[]) {
	//simply display gender-name pairs
	//note that the way they are being passed in will always result the gender and name being in the exact same index every time
	std::cout << "Child #" << argv[1] << ": ";
	std::cout << "I am a " << argv[2] << ", and my name is ";
	std::cout << argv[3] << ".\n";

	return 0;
}