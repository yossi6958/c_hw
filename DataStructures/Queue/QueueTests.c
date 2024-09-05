/**************************************************************************************
    Author: Yossi Kleiner.
    Creation date:  25/07/23
    Last modified date: --
    Description: Sequence of elements (1..n), FIFO, Reuse memory (circular queue).
***************************************************************************************/
#include <stdio.h>
#include <stdlib.h>

#include "ADTDefs.h"
#include "Queue.h"

//Forward declaration

void tests();
void q1();
void q2();
void q3();
void q4();
void q5();
void q6();
void q7();

void main()
{
    q7();
}

// tests

void tests()
{
    Queue_t* queue = NULL;
    ADTErr  eErr;
    int item;
    int isEmpty;
    size_t numOfItems;

    /* Test-case 1: Create Queue */
    printf("Queue Unit-Test: \n-----------------\n");
    eErr = EnQueue(queue, 7);          /*End-case: Add element to null Queue */
    HandleErr(eErr, "Adding value: 7");
    eErr = QueueNumOfItems(queue, &numOfItems);
    HandleErr(eErr, "Getting the num of items\n");
    queue = QueueCreate(5);
    isEmpty = QueueIsEmpty(queue);
    printf("Is the queue empty ? (0/1): %d\n", isEmpty);

    /* Test-case 2: Add element */
    EnQueue(queue, 1);
    EnQueue(queue, 2);
    EnQueue(queue, 3); 
    eErr = EnQueue(queue, 4);
    HandleErr(eErr, "Adding value: 4");
    EnQueue(queue, 5);
    QueuePrint(queue);
    eErr = EnQueue(queue, 7);
    HandleErr(eErr, "Adding value: 7");   /*End-case: overflow*/

    /* Test-case 3: Delete element */

    DeQueue(queue, &item);
    printf("the deleted item is : %d\n", item);
    DeQueue(queue, &item);
    printf("the deleted item is : %d\n", item);
    QueuePrint(queue);

    /* Circular Queue */

    EnQueue(queue, 6);
    EnQueue(queue, 8);
    QueuePrint(queue);

    eErr = EnQueue(queue, 7);
    HandleErr(eErr, "Adding value: 7");   /*End-case: overflow*/

    /* Test-case 4: isEmpty and numOfItems */

    isEmpty = QueueIsEmpty(queue);
    printf("Is the queue empty ? (0/1): %d\n", isEmpty);
    eErr = QueueNumOfItems(queue, &numOfItems);
    HandleErr(eErr, "Getting the num of items\n");
    printf("the num of items is: %zu\n", numOfItems);

    /* Test-case 5: Queue destroy */
    QueueDestroy(queue);
    queue = NULL;
    QueueDestroy(queue);
    isEmpty = QueueIsEmpty(queue);
    printf("Is the queue empty ? (0/1): %d\n", isEmpty);
}

// q1

Queue_t* QueueDiff(Queue_t* queue)
{
    int item1,item2;
    size_t numOfItems;
    QueueNumOfItems(queue, &numOfItems);
    Queue_t* newQueue = NULL;

    newQueue = QueueCreate(numOfItems);
    if (!newQueue)
    {
        return NULL;
    }
    DeQueue(queue, &item1);
    EnQueue(queue, item1);
    for (int i = 1; i < numOfItems; i++)
    {
        DeQueue(queue, &item2);
        EnQueue(queue, item2);
        EnQueue(newQueue, (item1-item2));
        item1 = item2;
    }
    
    return newQueue;
    
    // Complexity = O(n);
}

void q1()
{
    Queue_t* queue = NULL;
    Queue_t* newQueue = NULL;

    queue = QueueCreate(5);
    if (!queue)
    {
        printf("Not initilized\n");
        return;
    }
    EnQueue(queue, 10);
    EnQueue(queue, 8);
    EnQueue(queue, 23);
    EnQueue(queue, 1);
    EnQueue(queue, 5);

    QueuePrint(queue);

    newQueue = QueueDiff(queue);

    QueuePrint(queue);
    QueuePrint(newQueue);
}

// q2

void QueueUpdateNum(Queue_t* queue,int num,int newNum)
{
    int item;
    size_t numOfItems;
    QueueNumOfItems(queue, &numOfItems);

    for(int i = 0; i < numOfItems; i++)
    {
        DeQueue(queue, &item);
        if (item == num)
        {
            item = newNum;
        }
        EnQueue(queue, item);
    }
    // Complexity = O(n);
}

void q2()
{
    int newNum = 3;
    Queue_t* queue = NULL;

    queue = QueueCreate(5);
    if (!queue)
    {
        printf("Not initilized\n");
        return;
    }
    EnQueue(queue, 10);
    EnQueue(queue, 8);
    EnQueue(queue, 23);
    EnQueue(queue, 8);
    EnQueue(queue, 5);

    QueuePrint(queue);

    QueueUpdateNum(queue, 8, newNum);

    QueuePrint(queue);
}

// q3

void QueuePositiveFirst(Queue_t* queue)
{
    int item;
    size_t numOfItems;
    QueueNumOfItems(queue, &numOfItems);
    Queue_t* negativeQueue = NULL;

    negativeQueue = QueueCreate(numOfItems);
    if (!negativeQueue)
    {
        return;
    }
    for (int i = 0; i < numOfItems; i++)
    {
        DeQueue(queue, &item);
        if (item >= 0)
        {
            EnQueue(queue, item);;
        }
        else
        {
        EnQueue(negativeQueue, item);
        }
    }
    for (int i = 0; i < numOfItems; i++)
    {
        DeQueue(negativeQueue, &item);
        EnQueue(queue, item);
    }

    QueueDestroy(negativeQueue);

    // Complexity = O(n);
}

void q3()
{
    Queue_t* queue = NULL;

    queue = QueueCreate(5);
    if (!queue)
    {
        printf("Not initilized\n");
        return;
    }
    EnQueue(queue, 10);
    EnQueue(queue, -7);
    EnQueue(queue, 23);
    EnQueue(queue, -2);
    EnQueue(queue, 5);

    QueuePrint(queue);

    QueuePositiveFirst(queue);

    QueuePrint(queue);
}

// q4

Queue_t* QueueArrangeData(Queue_t* marksQueue)
{
    int item, counter = 0;
    size_t numOfItems;
    QueueNumOfItems(marksQueue, &numOfItems);
    Queue_t* testsQueue = NULL;

    testsQueue = QueueCreate(numOfItems);
    if (!testsQueue)
    {
        return NULL;
    }
    
    for (int i = 0; i < numOfItems; i++)
    {
        DeQueue(marksQueue, &item);
        if (item == -1)
        {
            EnQueue(testsQueue, counter);
            counter = 0;
        }
        else
        {
            EnQueue(marksQueue, item);
            counter++;
        }
    }

    return testsQueue;

    // Complexity = O(n);
}

void q4()
{
    Queue_t* queue = NULL;
    Queue_t* newQueue = NULL;

    queue = QueueCreate(20);
    if (!queue)
    {
        printf("Not initilized\n");
        return;
    }
    EnQueue(queue, 80);
    EnQueue(queue, 90);
    EnQueue(queue, 100);
    EnQueue(queue, -1);
    EnQueue(queue, 75);
    EnQueue(queue, 96);
    EnQueue(queue, -1);
    EnQueue(queue, 100);
    EnQueue(queue, 100);
    EnQueue(queue, 97);
    EnQueue(queue, 96);
    EnQueue(queue, -1);
    EnQueue(queue, -1);
    EnQueue(queue, 88);
    EnQueue(queue, 94);
    EnQueue(queue, -1);

    QueuePrint(queue);

    newQueue = QueueArrangeData(queue);

    QueuePrint(queue);
    QueuePrint(newQueue);
}

// q5

Queue_t* AverageQueue(Queue_t* marksQueue, Queue_t* testsQueue)
{
    int item, counter, sum = 0;
    size_t numOfItems1;
    size_t numOfItems2;
    QueueNumOfItems(testsQueue, &numOfItems1);
    QueueNumOfItems(marksQueue, &numOfItems2);
    Queue_t* averageQueue = NULL;

    averageQueue = QueueCreate(numOfItems1);
    if (!testsQueue)
    {
        return NULL;
    }
    for (int i = 0; i < numOfItems1; i++)
    {
        sum = 0;
        DeQueue(testsQueue, &counter);
        EnQueue(testsQueue, counter);
        for (int i = 0; i < counter; i++)
        {
            DeQueue(marksQueue, &item);
            EnQueue(marksQueue, item);
            sum += item;
        }
        EnQueue(averageQueue, (sum / counter));
    }
 
    return averageQueue;

    // Complexity = O(n);
}

void q5()
{
    Queue_t* marksQueue = NULL;
    Queue_t* testsQueue = NULL;
    Queue_t* averageQueue = NULL;

    marksQueue = QueueCreate(20);
    if (!marksQueue)
    {
        printf("Not initilized\n");
        return;
    }
    testsQueue = QueueCreate(5);
    if (!testsQueue)
    {
        printf("Not initilized\n");
        return;
    }
    EnQueue(marksQueue, 80);
    EnQueue(marksQueue, 90);
    EnQueue(marksQueue, 100);
    EnQueue(marksQueue, 75);
    EnQueue(marksQueue, 96);
    EnQueue(marksQueue, 100);
    EnQueue(marksQueue, 100);
    EnQueue(marksQueue, 97);
    EnQueue(marksQueue, 96);
    EnQueue(marksQueue, 88);
    EnQueue(marksQueue, 94);

    EnQueue(testsQueue, 3);
    EnQueue(testsQueue, 2);
    EnQueue(testsQueue, 4);
    EnQueue(testsQueue, 2);

    QueuePrint(marksQueue);
    QueuePrint(testsQueue);

    averageQueue = AverageQueue(marksQueue,testsQueue);

    QueuePrint(averageQueue);
    QueuePrint(marksQueue);
    QueuePrint(testsQueue);
}

// q6

int PutInPlace(Queue_t* queue, int num)
{
    int item, counter = 0;
    size_t numOfItems;
    QueueNumOfItems(queue, &numOfItems);
    Queue_t* tempQueue = NULL;

    tempQueue = QueueCreate(numOfItems);
    if (!tempQueue)
    {
        return 0;
    }

    for (int i = 0; i < numOfItems; i++)
    {
        DeQueue(queue, &item);
        if (item < num)
        {
            EnQueue(queue, item);
            counter++;
        }
        else
        {
            EnQueue(tempQueue, item);
        }
    }
    EnQueue(queue, num);
    for (int i = 0; i < (numOfItems - counter); i++)
    {
        DeQueue(tempQueue, &item);
        EnQueue(queue, item);
    }

    return counter + 1;

    // Complexity = O(n);
}

void q6()
{
    Queue_t* queue = NULL;
    int num = 9;

    queue = QueueCreate(10);
    if (!queue)
    {
        printf("Not initilized\n");
        return;
    }
    EnQueue(queue, 2);
    EnQueue(queue, 10);
    EnQueue(queue, 12);
    EnQueue(queue, 3);
    EnQueue(queue, 7);
    EnQueue(queue, 4);
    EnQueue(queue, 1);

    QueuePrint(queue);

    int index = PutInPlace(queue, num);

    QueuePrint(queue);
    printf("the index is: %d", index);
}

// q7

void MoveToFront(Queue_t* queue, int k)
{
    int item;
    size_t numOfItems;
    QueueNumOfItems(queue, &numOfItems);

    for (int i = 0; i < numOfItems - k; i++)
    {
        DeQueue(queue, &item);
        EnQueue(queue, item);
    }
    // Complexity = O(n);
}

void q7()
{
    Queue_t* queue = NULL;
    int k = 5;

    queue = QueueCreate(10);
    if (!queue)
    {
        printf("Not initilized\n");
        return;
    }
    EnQueue(queue, 7);
    EnQueue(queue, 2);
    EnQueue(queue, 5);
    EnQueue(queue, 4);
    EnQueue(queue, 6);
    EnQueue(queue, 8);
    EnQueue(queue, 10);
    EnQueue(queue, 12);

    QueuePrint(queue);

    MoveToFront(queue, k);

    QueuePrint(queue);
}