/*
 * BRAIN10.h
 */

/* prevents multiple definitions in header files */
#ifndef _BRAIN
#define _BRAIN

/* BRAIN10 Virtual Machine */
typedef struct
{
    char storage[100][4];   /* Storage 0 - 99 */
    char R[4];              /* General purpose register */
    char SP[4];             /* Stack pointer */
    char dataLine[50];      /* data buffer */
    int C;          /* Toggle boolean */
    int IC;         /* Instruction counter */
    int SPindx;         /* Temp variable for stack arithmetic */
} BRAIN10;

/* Initialize instruction counter and toggle boolean */
void initiateBrain();

/* Occupy storage words with BRAIN file operations
 input:
  - storage word number 0-99 [x1x2]
  - pointer to BRAIN10 struct */
void allocateMemory(int wordNum, char instruction[], BRAIN10 *brain10);

void runBrain(BRAIN10 *brain10);

void executeInstruction(char instruction[], BRAIN10 *brain10);

void printMemory(BRAIN10 *brain10);

#endif
