#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <time.h>
#include <ctype.h>

#define STOP 0
#define LEFT 1
#define RIGTH 2
#define UP 3
#define DOWN 4
#define WALL 178
#define SNAKE 219
#define FRUT 149

bool isEndGame = false;

const int width = 20;
const int heigth = 20;

int x, y, fruteX, fruteY, points, direction;

void initialize() {
	time_t t;

	isEndGame = false;
	direction = STOP;
	x = width / 2;
	y = heigth / 4;
	points = 0;
	srand(time(&t));
	fruteX = rand() % width + 1;
	fruteY = rand() % heigth + 1;
}

void draw() {
	int i, j;
	system("cls");
	i = 0;
	for (j = 0; j <= width + 2; j++)
	{
		printf("%c", char(WALL));
	}
	i = 0;
	for (i = 0; i <= heigth + 1; i++) //linhas
	{
		printf("\n");
		j = 0;
		for (j = 0; j <= width + 2; j++)
		{
			if (j == 0 || j == width + 2)
			{
				printf("%c", char(WALL));
			}
			else
			{
				if (i == x and j == y)
				{
					printf("%c", char(SNAKE));
				}
				else if (i == fruteX and j == fruteY)
				{
					printf("%c", char(FRUT));
				}
				else
				{
					printf(" ");
				}

			}
		}
	}

	printf("\n");
	for (i = 0; i <= width + 2; i++)
	{
		printf("%c", char(WALL));
	}
	printf("\n Pontos: %d\n", points);
}

void input()
{
	if (_kbhit) {
		int c = tolower(_getch());
		switch (c)
		{
		case 'w':
			direction = UP;
			break;
		case 'a':
			direction = LEFT;
			break;
		case 's':
			direction = DOWN;
			break;
		case 'd':
			direction = RIGTH;
			break;
		case 'x':
			isEndGame = true;
			break;
		case 224:
			if (_kbhit()) {
				switch (_getch())
				{
				case 72:
					direction = UP;
					break;
				case 75:
					direction = LEFT;
					break;
				case 77:
					direction = RIGTH;
					break;
				case 80:
					direction = DOWN;
					break;
				}
			}
		}
	}




}

void logic() {


	switch (direction)
	{
	case UP:
		x--;
		break;
	case DOWN:
		x++;
		break;
	case LEFT:
		y--;
		break;
	case RIGTH:
		y++;
		break;
	case STOP:
		direction = rand() % 4 + 1;
		break;
	}

	if (x == 0 || x == width + 2 || y == heigth + 2 || y == 0)
	{
		isEndGame = true;
	}

	if (x == fruteX and y == fruteY)
	{
		points = points + 10;
		fruteX = rand() % width + 1;
		fruteY = rand() % heigth + 1;

	}


}

void ends() {
	system("cls");
	printf("\n\n\nFim do sua pontuação foi %d\n\n\n", points);
}
