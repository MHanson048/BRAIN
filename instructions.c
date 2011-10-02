/*
 * instructions.c
 */

#include <stdio.h>
#include <stdlib.h>
#include "BRAIN10.h"

// LR
void loadRegister(BRAIN10 *brain10, int wordIndex)
{
    int i;
    for (i = 0; i < 4; i++)
        brain10 -> R[i] = brain10 -> storage[wordIndex][i];
}

// LL
void loadRegLow(BRAIN10 *brain10, int wordIndex)
{
    int i;
    for (i = 2; i < 4; i++)
        brain10 -> R[i] = brain10 -> storage[wordIndex][i];
}

// LH
void loadRegHigh(BRAIN10 *brain10, int wordIndex)
{
    int i;
    for (i = 0; i < 2; i++)
        brain10 -> R[i] = brain10 -> storage[wordIndex][i];
}

// SR
void loadMemory(BRAIN10 *brain10, int wordIndex)
{
    int i;
    for (i = 0; i < 4; i++)
        brain10 -> storage[wordIndex][i] = brain10 -> R[i];
}

// SP
void loadSPfromReg(BRAIN10 *brain10)
{
    int i;
    for (i = 0; i < 4; i++)
        brain10 -> SP[i] = brain10 -> R[i];
}

// PS
void loadRfromSP(BRAIN10 *brain10)
{
    int i;
    for (i = 0; i < 4; i++)
        brain10 -> R[i] = brain10 -> SP[i];
}

// PH
void push(BRAIN10 *brain10)
{
    int i;
    brain10 -> SPindx++;
    for (i = 0; i < 4; i++)
        brain10 -> SP[i] = brain10 -> R[i];
}

// PP
void pop(BRAIN10 *brain10)
{
    int i;
    for (i = 0; i < 4; i++)
        brain10 -> R[i] = brain10 -> SP[i];
    brain10 -> SPindx--;
}

// CE
void compareEqual(BRAIN10 *brain10, int wordIndex)
{
    int i, mem;
    int reg = atoi(brain10 -> R);
    char operand[4];
    for (i = 0; i < 4; i++)
        operand[i] = brain10 -> storage[wordIndex][i];
    mem = atoi(operand);
    if (reg == mem)
        brain10 -> C = 1;
    else
        brain10 -> C = 0;
}

// CL
void compareLess(BRAIN10 *brain10, int wordIndex)
{
    int i, mem;
    int reg = atoi(brain10 -> R);
    char operand[4];
    for (i = 0; i < 4; i++)
        operand[i] = brain10 -> storage[wordIndex][i];
    mem = atoi(operand);
    if (reg < mem)
        brain10 -> C = 1;
    else
        brain10 -> C = 0;
}

// BT
void branchConditional(BRAIN10 *brain10, int wordIndex)
{
    if (brain10 -> C == 1)
        brain10 -> IC = wordIndex;
}

// BU
void branchUnconditional(BRAIN10 *brain10, int wordIndex)
{
    brain10 -> IC = wordIndex;
}

// GD
void getData(BRAIN10 *brain10, int wordIndex)
{
    int i, j, index, wIndex;
    index = 0;
    wIndex = wordIndex;
    for (i = 0; i < 40; i += 4)
    {
        for (j = 0; j < 4; j++)
        {
            brain10 -> storage[wIndex][j] = brain10 -> dataLine[index];
            printf("storage[%d][%d]: %c\n", wIndex, j, brain10 -> dataLine[index]);
            index++;
        }
        index++;
        wIndex++;
    }
}

// PD
void printData(BRAIN10 *brain10, int wordIndex)
{
    int i, j;
    for (i = 0; i < 10; i++)
    {
        for (j = 0; j < 4; j++)
            printf("%c", brain10 -> storage[wordIndex + i][j]);
    }
}

// AD
void addition(BRAIN10 *brain10, int wordIndex)
{
	int i, reg, mem, result;
	reg = atoi(brain10 -> R);
	char word[4];
	for (i = 0; i < 4; i++)
		word[i] = brain10 -> storage[wordIndex][i];
	mem = atoi(word);
	result = reg + mem;
	if (result <= 9999)
	{
		char temp[4];
        snprintf(temp, 4, "%d", result);
		for (i = 0; i < 4; i++)
			brain10 -> R[i] = temp[i];
	}
	else
		printf("Result exceeds 9999! IDKWTF2DU!.");
}

// SU
void subtraction(BRAIN10 *brain10, int wordIndex)
{
	int i, reg, mem, result;
	reg = atoi(brain10 -> R);
	char word[4];
	for (i = 0; i < 4; i++)
		word[i] = brain10 -> storage[wordIndex][i];
	mem = atoi(word);
	result = reg - mem;
	if (result >= 0)
	{
		char temp[4];
		snprintf(temp, 4, "%d", result);
		for (i = 0; i < 4; i++)
			brain10 -> R[i] = temp[i];
	}
	else
		printf("Result is less than 0! IDKWTF2DU!");
}

// MU
void multiplication(BRAIN10 *brain10, int wordIndex)
{
	int i, reg, mem, result;
	reg = atoi(brain10 -> R);
	char word[4];
	for (i = 0; i < 4; i++)
		word[i] = brain10 -> storage[wordIndex][i];
	mem = atoi(word);
	result = reg * mem;
	if (result <= 9999)
	{
		char temp[4];
	    snprintf(temp, 4, "%d", result);
		for (i = 0; i < 4; i++)
			brain10 -> R[i] = temp[i];
	}
	else
		printf("Result is larger than 9999! IDKWTF2DU!");
}

// DI
void division(BRAIN10 *brain10, int wordIndex)
{
    int i, reg, mem, result;
    reg = atoi(brain10 -> R);
    char word[4];
    for (i = 0; i < 4; i++)
        word[i] = brain10 -> storage[wordIndex][i];
    mem = atoi(word);
    result = reg / mem;
    if (result >= 0)
    {
        char temp[4];
        snprintf(temp, 4, "%d", result);
        for (i = 0; i < 4; i++)
            brain10 -> R[i] = temp[i];
    }
    else
        printf("Result is less than 0! IDKWTF2DU!");
}

// AS
void stackAdd(BRAIN10 *brain10)
{
    int i, s1, s2, result;
    s1 = atoi(brain10 -> SP);
    brain10 -> SPindx--;
    for (i = 0; i < 4; i++)
        brain10 -> SP[i] = brain10 -> storage[brain10 -> SPindx][i];
    s2 = atoi(brain10 -> SP);
    result = s2 + s1;
    char temp[4];
    snprintf(temp, 4, "%d", result);
    for (i = 0; i < 4; i++)
        brain10 -> SP[i] = temp[i];
}

// SS
void stackSub(BRAIN10 *brain10)
{
    int i, s1, s2, result;
    s1 = atoi(brain10 -> SP);
    brain10 -> SPindx--;
    for (i = 0; i < 4; i++)
        brain10 -> SP[i] = brain10 -> storage[brain10 -> SPindx][i];
    s2 = atoi(brain10 -> SP);
    result = s2 - s1;
    char temp[4];
    snprintf(temp, 4, "%d", result);
    for (i = 0; i < 4; i++)
        brain10 -> SP[i] = temp[i];
}

// MS
void stackMul(BRAIN10 *brain10)
{
    int i, s1, s2, result;
    s1 = atoi(brain10 -> SP);
    brain10 -> SPindx--;
    for (i = 0; i < 4; i++)
        brain10 -> SP[i] = brain10 -> storage[brain10 -> SPindx][i];
    s2 = atoi(brain10 -> SP);
    result = s2 * s1;
    char temp[4];
    snprintf(temp, 4, "%d", result);
    for (i = 0; i < 4; i++)
        brain10 -> SP[i] = temp[i];
}

// DS
void stackDiv(BRAIN10 *brain10)
{
    int i, s1, s2, result;
    s1 = atoi(brain10 -> SP);
    brain10 -> SPindx--;
    for (i = 0; i < 4; i++)
        brain10 -> SP[i] = brain10 -> storage[brain10 -> SPindx][i];
    s2 = atoi(brain10 -> SP);
    result = s2 / s1;
    char temp[4];
    snprintf(temp, 4, "%d", result);
    for (i = 0; i < 4; i++)
        brain10 -> SP[i] = temp[i];
}
