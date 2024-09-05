/**************************************************************************************
    Author: Yossi Kleiner.
    Creation date:  28/6/22
    Last modified date: --
    Description: Sequence of elements (1..n), Ditect access, Grows & Reduce on demand.
***************************************************************************************/
#include <stdlib.h>
#include <stdio.h>

#include "ADTDefs.h"
#include "DynamicVector.h"

#define REALLOC_FACTOR 2

struct Vector
{
    int* items;
    size_t  originalSize;
    size_t  blockSize;
    size_t  currSize;
    size_t  nItems;
};


Vector_t* VectorCreate(size_t size, size_t blockSize)
{
    Vector_t* vector;

    if ((size == 0))
    {
        return NULL;
    }

    vector = (Vector_t*)malloc(sizeof(Vector_t));
    if (!vector)
    {
        return NULL;
    }

    vector->items = (int*)malloc(sizeof(int) * size);
    if (!vector->items)
    {
        free(vector);
        return NULL;
    }

    vector->currSize = size;
    vector->originalSize = size;
    vector->blockSize = blockSize;
    vector->nItems = 0;

    return vector;
}

void VectorDestroy(Vector_t* vector)
{
    if (vector)
    {
        free(vector->items);
        free(vector);
    }
}

ADTErr VectorAdd(Vector_t* vector, int item)
{
    int* tmp;

    if (!vector)
    {
        return ERR_NOT_INITIALIZED;
    }

    if (vector->nItems == vector->currSize)
    {
        // Handle overflow case.
        if (vector->blockSize == 0)
        {
            return ERR_OVERFLOW;
        }
        tmp = (int*)realloc(vector->items,
            sizeof(int) * (vector->currSize + vector->blockSize));

        if (NULL == tmp)
        {
            return ERR_REALLOCATION_FAILED;
        }
        vector->items = tmp;
        vector->currSize += vector->blockSize;
    }

    *(vector->items + vector->nItems) = item;
    ++vector->nItems;

    return ERR_OK;
}

ADTErr VectorDelete(Vector_t* vector, int* item)
{
    int* tmp;

    if (!vector || !item)
    {
        return ERR_NOT_INITIALIZED;
    }

    if (vector->nItems == 0)
    {
        return ERR_UNDERFLOW;
    }

    if ((vector->currSize > vector->originalSize) &&
        (vector->nItems <= vector->currSize - (vector->blockSize * REALLOC_FACTOR)))
    {
        tmp = (int*)realloc(vector->items,
            sizeof(int) * (vector->currSize - vector->blockSize));
        if (!tmp)
        {
            return (ERR_REALLOCATION_FAILED);
        }
        vector->items = tmp;
        vector->currSize -= vector->blockSize;
    }

    *item = *(vector->items + vector->nItems - 1);
    --vector->nItems;

    return ERR_OK;
}

/* Index from 1 */

ADTErr VectorGet(Vector_t* vector, size_t index, int* item)
{
    if (!vector || !item)
    {
        return ERR_NOT_INITIALIZED;
    }

    if (index > vector->nItems || index == 0)
    {
        return (ERR_WRONG_INDEX);
    }

    *item = *(vector->items + index - 1);

    return ERR_OK;
}

/* Index from 1 */
ADTErr VectorSet(Vector_t* vector, size_t index, int item)
{
    if (!vector)
    {
        return ERR_NOT_INITIALIZED;
    }

    if (index > vector->nItems || index == 0)
    {
        return (ERR_WRONG_INDEX);
    }

    *(vector->items + index - 1) = item;

    return ERR_OK;
}

ADTErr VectorItemsNum(Vector_t* vector, size_t* numOfItems)
{
    if (!vector || !numOfItems)
    {
        return ERR_NOT_INITIALIZED;
    }

    *numOfItems = vector->nItems;

    return ERR_OK;
}


/*  Unit-Test functions  */

void VectorPrint(Vector_t* vector)
{
    int i;

    if (!vector)
    {
        printf("\n-------------------------------------------------------\n");
        printf("vector details> Vector is not initialized.\n");
        printf("-------------------------------------------------------\n");
        return;
    }

    printf("\n-------------------------------------------------------\n");
    printf("vector details> nItems : %zu, size: %zu, blockSize : %zu \n", vector->nItems, vector->currSize, vector->blockSize);
    printf("vector items>   ");
    for (i = 0; i < vector->nItems; ++i)
    {
        printf("%d ", vector->items[i]);
    }
    printf("\n-------------------------------------------------------\n");
}