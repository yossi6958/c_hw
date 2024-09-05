/**************************************************************************************
	Author: Yossi Kleiner.
	Creation date:  05/07/23
	Last modified date: --
	Description: Stack - Sequence of elements (1..n), Grows & Reduce on demand,LIFO.
***************************************************************************************/

#include <stdio.h>
#include <stdlib.h>

#include "ADTDefs.h"
#include "DynamicVector.h"
#include "Stack.h"

struct Stack
{
	Vector_t* Vector;
}typedef Stack_t;

Stack_t* StackCreate(size_t size, size_t blockSize)
{
	Stack_t* stack = (Stack_t*)malloc(sizeof(Stack_t));
	if (!stack)
	{
		return NULL;
	}
	stack->Vector = VectorCreate(size, blockSize);
	if (!stack->Vector)
	{
		free(stack);
		return NULL;
	}
	return stack;
}

void StackDestroy(Stack_t* stack)
{
	if(stack)
	{
		VectorDestroy(stack->Vector);
		free(stack);
	}
}

ADTErr StackPush(Stack_t* stack, int item)
{
	if (!stack)
	{
		return ERR_NOT_INITIALIZED;
	}
	ADTErr eErr = VectorAdd(stack->Vector, item);
	return eErr;
}

ADTErr StackPop(Stack_t* stack, int* item)
{
	if (!stack||!item)
	{
		return ERR_NOT_INITIALIZED;
	}
	ADTErr eErr = VectorDelete(stack->Vector, item);
	return eErr;
}

ADTErr StackTop(Stack_t* stack, int* item)
{
	if (!stack || !item)
	{
		return ERR_NOT_INITIALIZED;
	}
	size_t lastIndex = 0;
	ADTErr eErr1 = VectorItemsNum(stack->Vector, &lastIndex);
	if (eErr1)
	{
		return eErr1;
	}
	ADTErr eErr = VectorGet(stack->Vector, lastIndex, item);
	return eErr;
}

int   IsStackEmpty(Stack_t* stack)
{
	size_t numOfItems = 0;
	VectorItemsNum(stack->Vector, &numOfItems);
	return !numOfItems;
}

void StackPrint(Stack_t* stack)
{
	if (stack)
	{
		VectorPrint(stack->Vector);
	}
}