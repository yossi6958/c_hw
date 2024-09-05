/**************************************************************************************
    Author: Yossi Kleiner.
    Creation date:  28/6/22
    Last modified date: --
    Description: Sequence of elements (1..n), Ditect access, Grows & Reduce on demand.
***************************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include "ADTDefs.h"
#include "DynamicVector.h"

int main()
{
    Vector_t* vec = NULL;
    Vector_t* tmpVec = NULL;
    ADTErr  eErr;

    /* Test-case 1: Create Vector */
    printf("Vector Unit-Test: \n-----------------\n");
    eErr = VectorAdd(vec, 7);          /*End-case: Add element to null vector */
    HandleErr(eErr, "Adding value: 7");
    vec = VectorCreate(4, 2);


    /* Test-case 2: Add element */
    eErr = VectorAdd(vec, 7);
    eErr = VectorAdd(vec, 8);
    eErr = VectorAdd(vec, 70);
    eErr = VectorAdd(vec, 3);
    VectorPrint(vec);
    VectorAdd(vec, 3);
    VectorAdd(vec, 3);
    VectorAdd(vec, 3);
    VectorAdd(vec, 3);
    VectorAdd(vec, 10);
    eErr = VectorAdd(vec, 11);           /*Feature: Grows on demand. */
    VectorPrint(vec);

    /* Test-case 3: Delete element */

    int item;
    eErr = VectorDelete(vec, &item);
    printf("the deleted item is : %d\n", item);
    VectorDelete(vec, &item);
    printf("the deleted item is : %d\n", item);
    VectorPrint(vec);
    VectorDelete(vec, &item);
    printf("the deleted item is : %d\n", item);
    VectorPrint(vec);
    VectorDelete(vec, &item);
    printf("the deleted item is : %d\n", item);
    VectorPrint(vec);
    VectorDelete(vec, &item);
    printf("the deleted item is : %d\n", item);
    VectorPrint(vec);
    VectorDelete(vec, &item);
    printf("the deleted item is : %d\n", item);
    VectorPrint(vec);


    VectorDelete(vec, &item);
    VectorDelete(vec, &item);
    VectorDelete(vec, &item);


    /*....*/
    /* Test-case 4: Set element    */
    /*....*/
    /* Test-case 5: Get element    */
    /*....*/

    /* Test-case 6: Vector destroy */
    VectorDestroy(vec);
    vec = NULL;
    VectorPrint(vec);
    return 0;
}