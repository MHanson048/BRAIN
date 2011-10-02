/*
 * BRAIN10.c
 */

#include <stdio.h>
#include "BRAIN10.h"
#include "instructions.h"

void initiateBrain(BRAIN10 *brain10)
{
	brain10 -> C = 0;
	brain10 -> IC = 0;
    brain10 -> SPindx = 89;     // Start stack at word 90
}

void allocateMemory(int wordNum, char instruction[4], BRAIN10 *brain10)
{
    int i;
    for (i = 0; i < 4; i++) {
    	brain10 -> storage[wordNum][i] = instruction[i];
        printf("[%d][%d] = %c\n", wordNum, i, brain10 -> storage[wordNum][i]);
    }
}

void runBrain(BRAIN10 *brain10)
{
    int i, j;
    j = 0;
    char instruction[4];
    while (j < 3)
    {
        for (i = 0; i < 4; i++)
            instruction[i] = brain10 -> storage[brain10 -> IC][i];
        printf("Executing command: %s\n", instruction);
        executeInstruction(instruction, brain10);
        brain10 -> IC++;
        j++;
    }
}

void executeInstruction(char instruction[4], BRAIN10 *brain10)
{
    // Separate operator and operand into separate strings
    char operator[2], operand[2];
    operator[0] = instruction[0];
    operator[1] = instruction[1];
    operand[0] = instruction[2];
    operand[1] = instruction[3];

    // If operator starts with 'L'
    if (operator[0] == 'L')
    {   
        // Load register
        if (operator[1] == 'R')
            loadRegister(brain10, atoi(operand));
        // Load register low
        else if (operator[1] == 'L')
            loadRegLow(brain10, atoi(operand));
        // Load register high
        else
            loadRegHigh(brain10, atoi(operand));
    }
    
    // If operator starts with 'S'
    else if (operator[0] == 'S')
    {
        // Load into Memory
        if (operator[1] == 'R')
            loadMemory(brain10, atoi(operand));
        // Load stack pointer from register
        else if (operator[1] == 'P')
            loadSPfromReg(brain10);
        // Subtraction
        else if (operator[1] == 'U')
            subtraction(brain10, atoi(operand));
        // Stack subtraction
        else
            stackSub(brain10);
    }

    // If operator starts with 'P'
    else if (operator[0] == 'P')
    {
        // Load register from stack pointer
        if (operator[1] == 'S')
            loadRfromSP(brain10);
        // Push
        else if (operator[1] == 'H')
            push(brain10);
        // Pop
        else if (operator[1] == 'P')
            pop(brain10);
        // Print data
        else
            printData(brain10, atoi(operand));
    }

    // If operator starts with 'C'
    else if (operator[0] == 'C')
    {
        // Compare equals
        if (operator[1] == 'E')
            compareEqual(brain10, atoi(operand));
        // Compare less than
        else
            compareLess(brain10, atoi(operand));
    }

    // If operator starts with 'B'
    else if (operator[0] == 'B')
    {
        // Branch conditional
        if (operator[1] == 'T')
            branchConditional(brain10, atoi(operand));
        // Branch unconditional
        else
            branchUnconditional(brain10, atoi(operand));
    }

    // If operator starts with 'A'
    else if (operator[0] == 'A')
    {
        // Addition
        if (operator[1] == 'D')
            addition(brain10, atoi(operand));
        // Stack addition
        else
            stackAdd(brain10);
    }

    // If operator starts with 'M'
    else if (operator[0] == 'M')
    {
        // Multiplication
        if (operator[1] == 'U')
            multiplication(brain10, atoi(operand));
        // Stack multiplication    
        else
            stackMul(brain10);
    }

    // If operator starts with 'D'
    else if (operator[0] ==  'D')
    {
        // Division
        if (operator[1] == 'I')
            division(brain10, atoi(operand));
        // Stack Division
        else
            stackDiv(brain10);
    }

    // Get Data
    else
        getData(brain10, atoi(operand));
}

void printMemory(BRAIN10 *brain10)
{
    int i, j;
}
