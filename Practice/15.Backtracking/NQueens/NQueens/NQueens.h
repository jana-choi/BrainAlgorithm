#ifndef _NQUEENS_H_
#define _NQUEENS_H_

void PrintSolution(int Columns[], int NumberOfQueens);
int IsThreatened(int Columns[], int NewRow);
void FindSolutionForQueen(int Columns[], int Row, int NumberOfQueens, int* SolutionCount);

#endif	// _NQUEENS_H_