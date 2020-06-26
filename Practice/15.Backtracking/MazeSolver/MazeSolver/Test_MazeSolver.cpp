#include <stdio.h>
#include "MazeSolver.h"

int main(void)
{
	char* FilePath = "MazeSample.dat";
	MazeInfo Maze;
	if(GetMaze(FilePath, &Maze) == FAIL)
		return 0;

	if(Solve(&Maze) == FAIL)
		return 0;

	int i = 0;
	int j = 0;

	for(i = 0; i < Maze.RowSize; i++)
	{
		for(j = 0; j < Maze.ColumnSize; j++)
			printf("%c", Maze.Data[i][j]);
		printf("\n");
	}

	return 0;
}