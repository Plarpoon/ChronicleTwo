#pragma once

#include "common.h"

#include "runscript.hpp"

/**
 * @file
 * Declares the external functions a monster's script can call, the table
 * that maps script function numbers to them, and the routines that give a
 * monster's interpreter its program and that table.
 */

class CActiveMonster;
class mgCMemory;

/**
 *
 * Pairs one external function a monster script can call with the number
 * the script calls it by.
 *
 */
struct RS_EXTFUNC_INFO {
    int (*func)(RS_STACKDATA *, int); /**< External function to run; null ends the list. */
    int no;                           /**< Number the script calls the function by. */
};

STATIC_ASSERT(sizeof(RS_EXTFUNC_INFO) == 0x8);

/**
 * Monster whose script is running, and on which the external functions
 * act unless they are given a monster of their own.
 */
extern CActiveMonster *nowMonster;

/**
 * Gives a monster's interpreter its program, an operand stack and call
 * stack taken from an arena, and the monster external-function table.
 *
 * @mangled SetMonsterScript__FP10CRunScriptPcP9mgCMemory
 * @address 0x1E90A0
 * @size 0x90
 */
int SetMonsterScript(CRunScript *script, char *program, mgCMemory *memory);

/**
 * Builds the monster external-function table out of the list of
 * external functions, stopping the game on a number listed twice.
 *
 * @mangled SetMonsterExtendTable__Fv
 * @address 0x1E9130
 * @size 0x130
 */
void SetMonsterExtendTable();
