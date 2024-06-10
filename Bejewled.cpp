#include <iostream>
#include <ctime>
#include <time.h>
#include <windows.h>
#include <iomanip>
#include "help.h"

using namespace std;



void FillMatrix(int r, int column, int shapes[][8])
{
	srand(time(0));
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{

			shapes[i][j] = rand() % 5 + 1;
			while ((shapes[i][j] == shapes[i - 1][j]) || (shapes[i][j] == shapes[i][j - 1]))
				shapes[i][j] = rand() % 5 + 1;

		}
	}
	//It will give numbers from 1-5 each of which represents a shape
// 1 represents yellow hollow square, 2 represents green filled square, 3 represents pink hollow square, 4 represents grey hollow ellipse
// and 5 represents purple filled ellipse
}
void FillBoard(int shapes[][8])
{
	int x, y;
	for (int i = 0; i < 8; i++)
	{
		y = i * 43.75 + 60;                             //Formula for defining starting y-coordinate of every shape
		for (int j = 0; j < 8; j++)
		{
			x = j * 50 + 265;                           //Formula for defining starting y-coordinate of every shape
			if (shapes[i][j] == 1)
				myRectangle(x, y, x + 20, y + 23.75, 220, 180, 40, 175, 255, 175);
			else if (shapes[i][j] == 2)
				myRectangle(x, y, x + 20, y + 23.75, 10, 150, 200, 10, 150, 200);
			else if (shapes[i][j] == 3)
				myRectangle(x, y, x + 20, y + 23.75, 150, 0, 200, 175, 255, 175);
			else if (shapes[i][j] == 4)
				myEllipse(x, y, x + 20, y + 23.75, 100, 100, 100, 175, 255, 175);
			else if (shapes[i][j] == 5)
				myEllipse(x, y, x + 20, y + 23.75, 100, 20, 200, 100, 20, 200);
		}
	}
}

void pointer(int whichKey, int row, int column)
{
	int x, y;
	if (whichKey == 1)                          //1 for left, 2 for up, 3 for right and 4 for down
	{
		x = (column + 1) * (48 + 1.7) + 252, y = row * (41.75 + 1.7) + 52;           //Formula for defining starting x and y-coordinates of every pointer
		myLine(x, y, x + 48, y, 175, 255, 175);
		myLine(x + 48, y, x + 48, y + 41.75, 175, 255, 175);
		myLine(x, y + 41.75, x + 48, y + 41.75, 175, 255, 175);
		myLine(x, y, x, y + 41.75, 175, 255, 175);
	}
	else if (whichKey == 2)
	{
		x = column * (48 + 1.7) + 252, y = (row + 1) * (41.75 + 1.7) + 52;
		myLine(x, y, x + 48, y, 175, 255, 175);
		myLine(x + 48, y, x + 48, y + 41.75, 175, 255, 175);
		myLine(x, y + 41.75, x + 48, y + 41.75, 175, 255, 175);
		myLine(x, y, x, y + 41.75, 175, 255, 175);
	}
	else if (whichKey == 3)
	{
		x = (column - 1) * (48 + 1.7) + 252, y = row * (41.75 + 1.7) + 52;
		myLine(x, y, x + 48, y, 175, 255, 175);
		myLine(x + 48, y, x + 48, y + 41.75, 175, 255, 175);
		myLine(x, y + 41.75, x + 48, y + 41.75, 175, 255, 175);
		myLine(x, y, x, y + 41.75, 175, 255, 175);
	}
	else if (whichKey == 4)
	{
		x = column * (48 + 1.7) + 252, y = (row - 1) * (41.75 + 1.7) + 52;
		myLine(x, y, x + 48, y, 175, 255, 175);
		myLine(x + 48, y, x + 48, y + 41.75, 175, 255, 175);
		myLine(x, y + 41.75, x + 48, y + 41.75, 175, 255, 175);
		myLine(x, y, x, y + 41.75, 175, 255, 175);
	}
	x = column * (48 + 1.7) + 252, y = row * (41.75 + 1.7) + 52;
	myLine(x, y, x + 48, y, 255, 0, 0);
	myLine(x + 48, y, x + 48, y + 41.75, 255, 0, 0);
	myLine(x, y + 41.75, x + 48, y + 41.75, 255, 0, 0);
	myLine(x, y, x, y + 41.75, 255, 0, 0);
}

void select(int row, int column)                                    //Changes the colour of pointer when shape is selected by 'ENTER'
{
	int x, y;
	x = column * (48 + 1.7) + 252, y = row * (41.75 + 1.7) + 52;
	myLine(x, y, x + 48, y, 0, 255, 0);
	myLine(x + 48, y, x + 48, y + 41.75, 0, 255, 0);
	myLine(x, y + 41.75, x + 48, y + 41.75, 0, 255, 0);
	myLine(x, y, x, y + 41.75, 0, 255, 0);
}

bool JustCheckPatternOfThree(int shapes[][8])                 //Just for checking the pattern of three in board
{
	bool pattern = false;
	for (int i = 0; i < 8; i++)
		for (int j = 0; j < 8; j++)
			if ((shapes[i][j] == shapes[i][j + 1]) && (shapes[i][j + 1] == shapes[i][j + 2]))
				pattern = true;
			else if (shapes[i][j] == shapes[i + 1][j] && shapes[i + 1][j] == shapes[i + 2][j])
				pattern = true;
	return pattern;
}

void UpdateBoardAndDisplayScore(int shapes[8][8], int& score)                  //For updating board and displaying score 
{
	srand(time(0));                       //srand() for new values everytime
	gotoxy(0, 3);
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			if (shapes[i][j] == shapes[i][j + 1] && shapes[i][j + 1] == shapes[i][j + 2])  //checking row combination
			{
				for (int r = i; r > 0; r--)  // r represents row loop to bring the above table down after 3 same consecutive shapes found in a row like  ***
				{
					shapes[r][j] = shapes[r - 1][j];
					shapes[r][j + 1] = shapes[r - 1][j + 1];
					shapes[r][j + 2] = shapes[r - 1][j + 2];
				}

				shapes[0][j] = rand() % 5 + 1;             //filling the top with random numbers
				if (j != 0)
					while (shapes[0][j] == shapes[0][j - 1])     //the first column of the new produced row should not equal previous column
						shapes[0][j] = rand() % 5 + 1;
				shapes[0][j + 2] = rand() % 5 + 1;
				if ((j + 2) != 7)
					while (shapes[0][j + 2] == shapes[0][j + 3])    //the last column of the new produced row should not equal next column
						shapes[0][j + 2] = rand() % 5 + 1;
				shapes[0][j + 1] = rand() % 5 + 1;
				while (shapes[0][j] == shapes[0][j + 1])
					shapes[0][j + 1] = rand() % 5 + 1;

				score = score + 250;
				gotoxy(0, 3);
				cout << "SCORE: " << score;
				UpdateBoardAndDisplayScore(shapes, score);
			}
			else if (shapes[i][j] == shapes[i + 1][j] && shapes[i + 1][j] == shapes[i + 2][j])  //checking column combination
			{
				int end1 = i - 1;      //index no. before first element of combination
				int end2 = i + 2;      //last index of combination
				if (i > 2)                     //meaning there are more than 3 spaces above the first element of the combination hence 3 swaps can take place easily
				{
					for (int r = 1; r <= i; r++)
					{
						shapes[end2][j] = shapes[end1][j];
						end2--;
						end1--;
					}
					for (int r = 0; r < 3; r++)
					{
						shapes[r][j] = rand() % 5 + 1;
						if (r != 0)
							while (shapes[r][j] == shapes[r - 1][j])         //the row of the new produced column should not equal the previous row
								shapes[r][j] = rand() % 5 + 1;
					}
				}
				else                              //meaning spaces above the first element of the combination are less than three 
				{                                       //now swaps will take place depending on the index
					for (int r = 1; r <= end2 - 2; r++)
					{
						shapes[end2][j] = shapes[end1][j];
						end2--;
						end1--;
					}
					for (int r = 0; r < 3; r++)
					{
						shapes[r][j] = rand() % 5 + 1;
						if (i != 0)
							while (shapes[r][j] == shapes[r][j - 1])             //the row of the new produced column should not equal the previous row
								shapes[r][j] = rand() % 5 + 1;
					}
				}
				score = score + 250;
				gotoxy(0, 3);
				cout << "SCORE: " << score;
				UpdateBoardAndDisplayScore(shapes, score);
			}
		}
	}
}



int main()
{
	int shapes[8][8], isCursor = 0, whichCursor, score = 0;

	myRectangle(250, 50, 650, 400, 0, 0, 255, 175, 255, 175);           //FOR MAKING THE OUTER RECTANGLE OF BOARD

	pointer(0, 0, 0);

	int timer = 60, current;                          //Setting the timer for 60 seconds
	current = time(NULL);                             //This will give the current time in seconds

	FillMatrix(8, 8, shapes);
	FillBoard(shapes);

	gotoxy(0, 3);
	cout << "Score: " << score;

	int i = 0, j = 0;

	while (time(NULL) - current <= timer)            //This loop will continue running for 60 seconds
	{
		gotoxy(0, 0);
		if (current - time(NULL) + timer < 10)
			cout << "Time Left: " << 0 << current - time(NULL) + timer << endl;            //Displaying time
		else
			cout << "Time Left: " << current - time(NULL) + timer << endl;
		isCursor = isCursorKeyPressed(whichCursor);                         //Getting cursor keys
		if (isCursor)
			if (whichCursor == 1)
				j--;
			else if (whichCursor == 2)
				i--;
			else if (whichCursor == 3)
				j++;
			else if (whichCursor == 4)
				i++;
		if (i < 0)
			i = 0;
		else if (i > 7)
			i = 7;
		if (j < 0)
			j = 0;
		else if (j > 7)
			j = 7;

		if (isCursor)
			pointer(whichCursor, i, j);
		isCursor = 0;
		whichCursor = 0;
		if (isEnterKeyPressed())
		{
			select(i, j);
			while (isCursor == false)
			{
				isCursor = isCursorKeyPressed(whichCursor);

				if (whichCursor == 1)
					swap(shapes[i][j], shapes[i][j - 1]);
				else if (whichCursor == 2)
					swap(shapes[i][j], shapes[i - 1][j]);
				else if (whichCursor == 3)
					swap(shapes[i][j], shapes[i][j + 1]);
				else if (whichCursor == 4)
					swap(shapes[i][j], shapes[i + 1][j]);
			}
			if (isCursor)
			{
				if (JustCheckPatternOfThree(shapes))
				{
					UpdateBoardAndDisplayScore(shapes, score);
					myRectangle(250, 50, 650, 400, 0, 0, 255, 175, 255, 175);
					FillBoard(shapes);
				}
				else
					pointer(whichCursor, i, j);
			}
		}
	}
	system("CLS");
	cout << ">>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>GAME OVER!<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<\n";
	cout << "Your Score is " << score << "\n\n\n\n";

	return 0;
}
