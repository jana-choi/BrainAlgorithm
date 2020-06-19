#pragma warning(disable : 4996)

#include <stdio.h>
#include <string.h>
#include "KarpRabin.h"

#define MAX_BUFFER 512

int main(void)
{
	char* FilePath;
	FILE* fp;

	char Text[MAX_BUFFER];
	char* Pattern;
	int PatternSize = 0;
	int Line = 0;

	FilePath = "../../kjv.txt";
	Pattern = "Righteousness";

	PatternSize = strlen(Pattern);

	fp = fopen(FilePath, "r");
	if(fp == NULL)
	{
		printf("Cannot open file:%s\n", FilePath);
		return 1;
	}

	while(fgets(Text, MAX_BUFFER, fp) != NULL)
	{
		Line++;
		int Position = KarpRabin(Text, strlen(Text), 0, Pattern, PatternSize);
		if(Position >= 0)
			printf("[line: %d, column: %d] %s", Line, Position+1, Text);
	}

	fclose(fp);

	return 0;
}