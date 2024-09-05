/**************************************************************************************
    Author: Yossi Kleiner.
    Creation date:  25/07/23
    Last modified date: --
    Description: Sequence of elements (1..n), FIFO, Reuse memory (circular queue).
***************************************************************************************/
#ifndef __ADTDEFS_H__
#define __ADTDEFS_H__

typedef enum
{
    /* General ADT Errors */
    ERR_OK = 0,
    ERR_GENERAL,
    ERR_NOT_INITIALIZED,
    ERR_ALLOCATION_FAILED,
    ERR_REALLOCATION_FAILED,
    ERR_UNDERFLOW,
    ERR_OVERFLOW,
    ERR_WRONG_INDEX,

    /* Vector Errors */

    /* Stack  Errors */
    ERR_BLABLABLA = 25,


    /* LinkedList  Errors */


    /* Bit Vector*/


} ADTErr;

// Functions header definition:
void HandleErr(ADTErr errNum, char* msg);

#endif /*__ADTDEFS_H__*/

