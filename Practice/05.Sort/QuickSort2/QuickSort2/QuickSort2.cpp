#include <stdio.h>
#include <stdlib.h>
#include <string.h>


// 리턴값이 0 보다 크면, _elem1 이 큼
// 리턴값이 0 보다 작으면, _elem2 가 큼
// 리턴값이 0 이면, 같음
int CompareScore(const void* _elem1, const void* _elem2)
{
	int* elem1 = (int*)_elem1;
	int* elem2 = (int*)_elem2;

	if(*elem1 > *elem2)
		return 1;
	else if(*elem1 < *elem2)
		return -1;
	else
		return 0;
}


int main(void)
{
	int DataSet[] = {6, 4, 2, 3, 1, 5};
	int Length = sizeof(DataSet) / sizeof(DataSet[0]);

	qsort((void*)DataSet, Length, sizeof(int), CompareScore);

	for(int i = 0; i < Length; i++)
		printf("%d ", DataSet[i]);
	printf("\n");


	return 0;
}