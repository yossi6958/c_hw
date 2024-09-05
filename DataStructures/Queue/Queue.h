/**************************************************************************************
    Author: Yossi Kleiner.
    Creation date:  25/07/23
    Last modified date: --
    Description: Sequence of elements (1..n), FIFO, Reuse memory (circular queue).
***************************************************************************************/

#ifndef __QUEUE_H__
#define __QUEUE_H__

typedef struct Queue Queue_t;

Queue_t* QueueCreate(size_t size);
         
void QueueDestroy(Queue_t* queue);

ADTErr EnQueue(Queue_t* queue, int item);

ADTErr DeQueue(Queue_t* queue, int* item);

int QueueIsEmpty(Queue_t* queue);

ADTErr QueueNumOfItems(Queue_t* queue, size_t* numOfItems);

void QueuePrint(Queue_t* queue);

#endif /*__QUEUE_H__*/
