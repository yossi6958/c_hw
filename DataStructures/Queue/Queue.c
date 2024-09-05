/**************************************************************************************
    Author: Yossi Kleiner.
    Creation date:  25/07/23
    Last modified date: --
    Description: Sequence of elements (1..n), FIFO, Reuse memory (circular queue).
***************************************************************************************/

#include <stdlib.h>
#include <stdio.h>

#include "ADTDefs.h"
#include "Queue.h"


struct Queue
{
    int* arr;
    size_t  size;
    size_t  nItems;
    size_t  head;
    size_t  tail;
};

Queue_t* QueueCreate(size_t size)
{
    Queue_t* queue;

    if ((size == 0))
    {
        return NULL;
    }

    queue = (Queue_t*)malloc(sizeof(Queue_t));
    if (!queue)
    {
        return NULL;
    }

    queue->arr = (int*)malloc(sizeof(int) * size);
    if (!queue->arr)
    {
        free(queue);
        return NULL;
    }

    queue->size = size;
    queue->nItems = 0;
    queue->head = 0;
    queue->tail = 0;

    return queue;
}

void QueueDestroy(Queue_t* queue)
{
    if (queue)
    {
        free(queue->arr);
        free(queue);
    }
}

ADTErr EnQueue(Queue_t* queue, int item)
{
    if (!queue)
    {
        return ERR_NOT_INITIALIZED;
    }

    if (queue->nItems == queue->size)
    {
        return ERR_OVERFLOW;
    }

    *(queue->arr + queue->tail) = item;
    ++queue->nItems;
    queue->tail = ++queue->tail % queue->size;

    return ERR_OK;
}

ADTErr DeQueue(Queue_t* queue, int* item)
{
    if (!queue || !item)
    {
        return ERR_NOT_INITIALIZED;
    }

    if (queue->nItems == 0)
    {
        return ERR_UNDERFLOW;
    }

    *item = *(queue->arr + queue->head);
    --queue->nItems;
    queue->head = ++queue->head % queue->size;

    return ERR_OK;
}

int QueueIsEmpty(Queue_t* queue)
{
    if (!queue)
    {
        return -1;
    }
    return !(queue->nItems);
}

ADTErr QueueNumOfItems(Queue_t* queue, size_t* numOfItems)
{
    if (!queue)
    {
        return ERR_NOT_INITIALIZED;
    }
    *numOfItems = queue->nItems;
    return  ERR_OK;
}

void QueuePrint(Queue_t* queue)
{
    int i;
    size_t index;

    if (!queue)
    {
        printf("\n-------------------------------------------------------\n");
        printf("queue details> queue is not initialized.\n");
        printf("-------------------------------------------------------\n");
        return;
    }

    printf("\n-------------------------------------------------------\n");
    printf("queue details> nItems : %zu, size: %zu, head: %zu, tail: %zu\n", queue->nItems, queue->size,queue->head,queue->tail);
    printf("queue items>   ");
    for (i = 0,index = queue->head; i < queue->nItems; ++i,++index)
    {
        if (index == queue->size)
        {
            index = 0;
        }
        printf("%d ", queue->arr[index]);
    }
    printf("\n-------------------------------------------------------\n");
}

