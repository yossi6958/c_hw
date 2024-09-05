/**************************************************************************************
    Author: Yossi Kleiner.
    Creation date:  25/07/23
    Last modified date: --
    Description: Sequence of elements (1..n), FIFO, Reuse memory (circular queue).
***************************************************************************************/
#include <stdio.h>

#include "ADTDefs.h"

const char* ErrDescription[] =
{
    /* General ADT Errors - Description */
    "OK",
    "General Error",
    "Initialization error",
    "Allocation error",
    "ReAllocation error",
    "Underflow error",
    "Overflow error",
    "Wrong index",
};

void HandleErr(ADTErr errNum, char* msg)
{
    if (errNum)
    {
        printf("ErrNum=%d, ErrDescription=%s, msg=%s\n",
            errNum, ErrDescription[errNum], msg);
    }

}