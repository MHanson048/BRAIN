/*
 * main.c
 */

#include <stdio.h>
#include <stdlib.h>
#include "BRAIN10.h"
#include "instructions.h"
 

 FILE *brainFile;            // BRAIN program file

 int main(void)
 {
	 BRAIN10 *brain10 = malloc(sizeof(BRAIN10));
     char fileName[30];
     printf("BRAIN program file: ");
     scanf("%s", fileName);

     brainFile = fopen(fileName, "r");

     char startLine[9];
     fgets(startLine, sizeof startLine, brainFile);
     printf("%s", startLine);

     // If first line of brainFile = 'BRAIN10'
	 int lineNum = 0;
	 int cmp;
	 char instruction[6];
     printf("Reading commands into memory: ...\n");
     if (cmp = strcmp(startLine, "BRAIN10\n") == 0)
     {
	    while(fgets(instruction, sizeof instruction, brainFile) != NULL)
        {
            if (cmp = strcmp(instruction, "DATA\n") != 0)
            {
                allocateMemory(lineNum, instruction, brain10);
                lineNum++;
            }
            else
            {
                initiateBrain(brain10);
                char dataLine[50];

                // Get data string
                fgets(dataLine, sizeof dataLine, brainFile);

                // Copy data line to brain10
                int i;
                for (i = 0; i < 50; i++)
                    brain10 -> dataLine[i] = dataLine[i];
                runBrain(brain10);
                printf("%s\n", brain10 -> R);
                break;
            }
	    }
     }
     else
         printf("Wrong file format!");

     fclose(brainFile);
     return 0;
}
