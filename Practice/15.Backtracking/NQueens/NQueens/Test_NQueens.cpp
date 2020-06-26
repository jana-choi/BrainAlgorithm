#include <stdio.h>
#include <stdlib.h>
#include "NQueens.h"

int main(void)
{
	int NumberOfQueens = 8;	//*
	int* Columns = (int*)calloc(NumberOfQueens, sizeof(int));

	int i = 0;
	int SolutionCount = 0;

	for(i = 0; i < NumberOfQueens; i++)
	{
		Columns[0] = i;
		FindSolutionForQueen(Columns, 0, NumberOfQueens, &SolutionCount);
	}

	free(Columns);

	return 0;
}