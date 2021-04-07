#include "snake.h"
int main() {

	initialize();
	while (!isEndGame)
	{
		draw();
		input();
		logic();
	}
	ends();

	return 0;
}