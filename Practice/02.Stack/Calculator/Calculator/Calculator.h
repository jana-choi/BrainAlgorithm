#ifndef _CALCULATOR_H_
#define _CALCULATOR_H_

#include <stdlib.h>
#include "LinkedListStack.h"

typedef enum
{
	LEFT_PARENTHESIS	= '(',
	RIGHT_PARENTHESIS	= ')',
	PLUS				= '+',
	MINUS				= '-',
	MULTIPLY			= '*',
	DIVIDE				= '/',
	SPACE				= ' ',
	OPERAND
} SYMBOL;


int IsNumber(char Cipher);
unsigned int GetNextToken(char* Expression, char* Token, int* TYPE);
int IsPrior(char OperatorInStack, char OperatorInToken);
void GetPostfix(char* InfixExpression, char* PostfixExpression);
double Calculate(char* PostfixExpression);

#endif	// !_CALCULATOR_H_