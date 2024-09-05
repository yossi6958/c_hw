/**************************************************************************************
    Author: Yossi Kleiner.
    Creation date:  04/07/22
    Last modified date: --
    Description: Stack - LIFO, Grows & Reduce on demand
***************************************************************************************/
#ifndef __STACK_H__
#define __STACK_H__

// Forward declaration:

typedef struct Stack Stack_t;

/* size      - The initial allocation size.
   blockSize - The extention block size.    */
Stack_t* StackCreate(size_t size, size_t blockSize);

void     StackDestroy(Stack_t* stack);

/* Add item to end. */
ADTErr   StackPush(Stack_t* stack, int  item);

/* Delete item from the end. */
ADTErr   StackPop(Stack_t* stack, int*  item);

/* The Index range in the following functions is : 1..numOfItems */
ADTErr   StackTop(Stack_t* stack, int* item);

int   IsStackEmpty(Stack_t* stack);


/*  Unit-Test functions  */
#ifdef DEBUG

void StackPrint(Stack_t* stack);

#endif // DEBUG

#endif /*__VECTOR_H__*/