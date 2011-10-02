/*
 * instructions.h
 */

#ifndef _INSTRUCTIONS
#define _INSTRUCTIONS

/*
 * Operator: LR
 * Operand: x1x2
 * Interpretation: R := [a]
 */
void loadRegister(BRAIN10 *brain10, int wordIndex);

/*
 * Operator: LL
 * Operand: x1x2
 * Interpretation: R := zz[a,3][a,4]
 */
void loadRegLow(BRAIN10 *brain10, int wordIndex);


/*
 * Operator: LH
 * Operand: x1x2
 * Interpretation: R := [a,1][a,2]zz
 */
void loadRegHigh(BRAIN10 *brain10, int wordIndex);


/*
 * Operator: SR
 * Operand: x1x2
 * Interpretation: [a] := R
 */
void loadMemory(BRAIN10 *brain10, int wordIndex);


/*
 * Operator: SP
 * Operand: x1x2 (dummy)
 * Interpretation: SP := R
 */
void loadSPfromReg(BRAIN10 *brain10);

/*
 * Operator: PS
 * Operand: x1x2 (dummy)
 * Interpretation: R := SP
 */
void loadRfromSP(BRAIN10 *brain10);


/*
 * Operator: PH
 * Operand: x1x2 (dummy)
 * Interpretation: SP++; [SP] := R
 */
void push(BRAIN10 *brain10);


/*
 * Operator: PP
 * Operand: x1x2 (dummy)
 * Interpretation R := [SP]; SP--
 */
void pop(BRAIN10 *brain10);

/*
 * Operator: CE
 * Operand: x1x2
 * Interpretation: If R = [a] then C:= 'T' else C := 'F'
 */
void compareEqual(BRAIN10 *brain10, int wordIndex);

/*
 * Operator: CL
 * Operand: x1x2
 * Interpretation: If R < [a] then C := 'T' else C := 'F'
 */
void compareLess(BRAIN10 *brain10, int wordIndex);

/*
 * Operator: BT
 * Operand: x1x2
 * Interpretation: If  C = 'T' then IC := a
 */
void branchConditional(BRAIN10 *brain10, int wordIndex);

/*
 * Operator: BU
 * Operand: x1x2
 * Interpretation: IC := a
 */
void branchUnconditioanl(BRAIN10 *brain10, int wordIndex);

/*
 * Operator: GD
 * Operand: x1x2
 * Interpretation: Read( [a+i], i = 0,...,9 )
 */
void getData(BRAIN10 *brain10, int wordIndex);

/* 
 * Operator: PD
 * Operand: x1x2
 * Interpretation: Print( [a+i], i = 0,...,9 )
 */
void printData(BRAIN10 *brain10, int wordIndex);

/*
 * Operator: AD
 * Operand: x1x2
 * Interpretation: R := R + [a]
 */
void additional(BRAIN10 *brain10, int wordIndex);

/*
 * Operator: SU
 * Operand: x1x2
 * Interpretation: R := R - [a], R >= [a]
 */
void subtraction(BRAIN10 *brain10, int wordIndex);

/*
 * Operator: MU
 * Operand: x1x2
 * Interpretation: R := R * [a]
 */
void multiplication(BRAIN10 *brain, int wordIndex);

/*
 * Operator: DI
 * Operand: x1x2
 * Interpretation: R := R / [a], [a] > 0
 */
void division(BRAIN10 *brain10, int wordIndex);

/*
 * Operator: AS
 * Operand: x1x2 (dummy)
 * Interpretation: Temp := [SP]; SP--; [SP] := [SP] + Temp
 */
void stackAdd(BRAIN10 *brain10);

/*
 * Operator: SS
 * Operand: x1x2 (dummy)
 * Interpretation: Temp := [SP]; SP--; [SP] := [SP] - Temp
 */
void stackSub(BRAIN10 *brain10);

/*
 * Operator: MS
 * Operand: x1x2 (dummy)
 * Interpretation: Temp := [SP]; SP--; [SP] := [SP] * Temp
 */
void stackMul(BRAIN10 *brain10);

/*
 * Operator: DS
 * Operand: x1x2 (dummy)
 * Interpretation: Temp := [SP]; SP--; [SP] := [SP] / Temp
 */
void stackDiv(BRAIN10 *brain10);

#endif
