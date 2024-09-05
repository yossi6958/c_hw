/**************************************************************************************
    Author: Yossi Kleiner.
    Creation date:  28/6/23
    Last modified date: 12/07/23
    Description: Sequence of elements (1..n), Grows & Reduce on demand, stack practice.
***************************************************************************************/
#include <stdio.h>
#include <stdlib.h>

#include "ADTDefs.h"
#include "Stack.h"


// Forward declaration

int tests();
void q2();
void q3();
void q4();
void q5();
void q6();

void main()
{
    q6();
}


// stack tests

int tests()
{
    Stack_t* stack = NULL;
    ADTErr  eErr;

    /* Test-case 1: Create Stack */
    printf("Stack Unit-Test: \n-----------------\n");
    eErr = StackPush(stack, 7);          /*End-case: Add element to null stack */
    HandleErr(eErr, "Adding value: 7");
    stack = StackCreate(4, 2);
    int i = IsStackEmpty(stack);
    if (i)
    {
        printf("the stack is not empty\n");
    }
    else
    {
        printf("the stack is empty\n");
    }

    /* Test-case 2: Add element */
    eErr = StackPush(stack, 7);
    eErr = StackPush(stack, 70);
    eErr = StackPush(stack, 3);
    eErr = StackPush(stack, 67);
    StackPrint(stack);
    eErr = StackPush(stack, 35);
    eErr = StackPush(stack, 30);
    eErr = StackPush(stack, 31);
    eErr = StackPush(stack, 32);
    eErr = StackPush(stack, 3);
    eErr = StackPush(stack, 1);           /*Feature: Grows on demand. */
    StackPrint(stack);

    /* Test-case 3: Delete element */

    int item;
    eErr = StackPop(stack, &item);
    printf("the deleted item is : %d\n", item);
    StackPop(stack, &item);
    printf("the deleted item is : %d\n", item);
    StackPrint(stack);
    StackPop(stack, &item);;
    printf("the deleted item is : %d\n", item);
    StackPrint(stack);
    StackPop(stack, &item);
    printf("the deleted item is : %d\n", item);
    StackPrint(stack);
    StackPop(stack, &item);
    printf("the deleted item is : %d\n", item);
    StackPrint(stack);
    StackPop(stack, &item);
    printf("the deleted item is : %d\n", item);
    StackPrint(stack);

    /* Test-case 4: Get element    */

    StackTop(stack, &item);
    StackPrint(stack);

    printf("the top item is : %d\n", item);

    i = IsStackEmpty(stack);
    if (i)
    {
        printf("the stack is not empty\n");
    }
    else
    {
        printf("the stack is empty\n");
    }

    /* Test-case 5: Vector destroy */
    StackDestroy(stack);
    stack = NULL;
    StackPrint(stack);

    return 0;
}

// stack Q

// q2
Stack_t* StackReverse(Stack_t* stack)
{
    if (!stack)
    {
        return NULL;
    }
    Stack_t* newStack = NULL;
    Stack_t* tmpStack = NULL;
    int tmpItem = 0;

    newStack = StackCreate(5, 3);
    if (!newStack)
    {
        return NULL;
    }
    tmpStack = StackCreate(5, 3);
    if (!tmpStack)
    {
        return NULL;
    }
    while(!IsStackEmpty(stack))
    {
        StackPop(stack, &tmpItem);
        StackPush(newStack, tmpItem);
        StackPush(tmpStack, tmpItem);
    }
    while (!IsStackEmpty(tmpStack))
    {
        StackPop(tmpStack, &tmpItem);
        StackPush(stack, tmpItem);
    }
    StackDestroy(tmpStack);
    return newStack;
}

void q2()
{
    int item;
    ADTErr eErr;
    Stack_t* stack = NULL;
    Stack_t* newStack = NULL;
    stack = StackCreate(10, 10);

    // many items

    eErr = StackPush(stack, 1);
    eErr = StackPush(stack, 2);
    eErr = StackPush(stack, 3);
    eErr = StackPush(stack, 4);
    printf("Original Stack: \n");
    StackPrint(stack);
    newStack = StackReverse(stack);
    printf("New Stack: \n");
    StackPrint(newStack);

    // only one item
    
    StackPop(stack, &item);
    StackPop(stack, &item);
    StackPop(stack, &item);

    printf("Original Stack: \n");
    StackPrint(stack);
    newStack = StackReverse(stack);
    printf("New Stack: \n");
    StackPrint(newStack);
}

// q3

Stack_t* StackMaxToTop(Stack_t* stack)
{
    if (!stack)
    {
        return NULL;
    }
    Stack_t* newStack = NULL;
    Stack_t* tmpStack = NULL;
    int tmpItem = 0,maxNum = 0;

    newStack = StackCreate(5, 3);
    if (!newStack)
    {
        return NULL;
    }
    tmpStack = StackCreate(5, 3);
    if (!tmpStack)
    {
        return NULL;
    }     

    StackTop(stack, &maxNum);

    while (!IsStackEmpty(stack))
    {
        StackPop(stack, &tmpItem);
        if (tmpItem > maxNum)

        {
            maxNum = tmpItem;
        }
        StackPush(tmpStack, tmpItem);
    }
    while (!IsStackEmpty(tmpStack))
    {
        StackPop(tmpStack, &tmpItem);
        if (tmpItem != maxNum)
        {
            StackPush(newStack, tmpItem);
        }
        StackPush(stack, tmpItem);
    }
    StackPush(newStack, maxNum);
    StackDestroy(tmpStack);
    return newStack;
}

void q3()
{
    int item;
    ADTErr eErr;
    Stack_t* stack = NULL;
    Stack_t* newStack = NULL;
    stack = StackCreate(10, 10);

    // many items

    eErr = StackPush(stack, 4);
    eErr = StackPush(stack, 5);
    eErr = StackPush(stack, 3);
    eErr = StackPush(stack, 1);
    printf("Original Stack: \n");
    StackPrint(stack);
    newStack = StackMaxToTop(stack);
    printf("New Stack: \n");
    StackPrint(newStack);

    // only one item

    StackPop(stack, &item);
    StackPop(stack, &item);
    StackPop(stack, &item);

    printf("Original Stack: \n");
    StackPrint(stack);
    newStack = StackMaxToTop(stack);
    printf("New Stack: \n");
    StackPrint(newStack);
}

// q4

Stack_t* StackAllMaxToTop(Stack_t* stack)
{

    if (!stack)
    {
        return NULL;
    }
    Stack_t* newStack = NULL;
    Stack_t* tmpStack = NULL;
    int tmpItem = 0, maxNum = 0,maxCounter = 0;

    newStack = StackCreate(5, 3);
    if (!newStack)
    {
        return NULL;
    }
    tmpStack = StackCreate(5, 3);
    if (!tmpStack)
    {
        return NULL;
    }

    while (!IsStackEmpty(stack))
    {
        StackPop(stack, &tmpItem);
        if (tmpItem > maxNum)

        {
            maxNum = tmpItem;
        }
        StackPush(tmpStack, tmpItem);
    }
    while (!IsStackEmpty(tmpStack))
    {
        StackPop(tmpStack, &tmpItem);
        if (tmpItem != maxNum)
        {
            StackPush(newStack, tmpItem);
        }
        else
        {
            maxCounter++;
        }
        StackPush(stack, tmpItem);
    }
    for (int i = 0; i < maxCounter; i++)
    {
        StackPush(newStack, maxNum);
    }
    StackDestroy(tmpStack);
    return newStack;
}

void q4()
{
    int item;
    ADTErr eErr;
    Stack_t* stack = NULL;
    Stack_t* newStack = NULL;
    stack = StackCreate(10, 10);

    // many items

    eErr = StackPush(stack, 5);
    eErr = StackPush(stack, 5);
    eErr = StackPush(stack, 3);
    eErr = StackPush(stack, 5);
    eErr = StackPush(stack, 3);
    eErr = StackPush(stack, 1);
    printf("Original Stack: \n");
    StackPrint(stack);
    newStack = StackAllMaxToTop(stack);
    printf("New Stack: \n");
    StackPrint(newStack);

    // only one item

    StackPop(stack, &item);
    StackPop(stack, &item);
    StackPop(stack, &item);
    StackPop(stack, &item);
    StackPop(stack, &item);

    printf("Original Stack: \n");
    StackPrint(stack);
    newStack = StackAllMaxToTop(stack);
    printf("New Stack: \n");
    StackPrint(newStack);
}

int CheckParentheses(char* expression)
{
    if (!expression)
    {
        return -1;
    }

    Stack_t* stack;
    int i = 0, item = 0;

    stack = StackCreate(5, 5);
    if (!stack)
    {
        return -1;
    }

    for (i = 0; expression[i]; i++)
    {

        if (expression[i] == '(' || expression[i] == '{' || expression[i] == '[')
        {
            StackPush(stack, expression[i]);
        }
        else if (expression[i] == '}' || expression[i] == ']' || expression[i] == ')')
        {
            StackTop(stack, &item);

            if (IsStackEmpty(stack))
            {
                StackDestroy(stack);
                return 0;
            }
            if ((expression[i] - item) == 2 || (expression[i] - item) == 1)
            {
                StackPop(stack, &item);
            }
            else
            {
                StackDestroy(stack);
                return 0;
            }
        }
    }
    
    if (IsStackEmpty(stack))
    {
        StackDestroy(stack);
        return 1;
    }
    else
    {
        StackDestroy(stack);
        return 0;
    }
}

void q5()
{
    char str[] = "a{A*(2+C)\[3+v]}";

    if (CheckParentheses(str))
    {
        printf("The sentence is correct");
    }
    else
    {
        printf("The sentence is invalid");
    }
}

// q5

float CalcPostfixExpression(char* expression)
{
    if (!expression)
    {
        return -1;
    }
    Stack_t* stack = NULL;
    int item1 = 0,item2 = 0;

    stack = StackCreate(8, 1);
    if (!stack)
    {
        return -1;
    }
    for (int i = 0; expression[i]; i++)
    {
        if (expression[i] >= '0' && expression[i] <= '9')
        {
            int value = (expression[i] - '0');
            StackPush(stack, value);
        }
        else
        {
            if (IsStackEmpty(stack))
            {
                printf("No numbers in stack\n");
                StackDestroy(stack);
                return -1;
            }
            StackPop(stack, &item2); //23 + 35 * +
            StackPop(stack, &item1);

            switch (expression[i])
            {
            case '/':
                printf("Do not suppurt divide operator!!\n");
                StackDestroy(stack);
                return -1;
            case '*':
                StackPush(stack, item1 * item2);
                break;
            case '+':
                StackPush(stack, item1 + item2);
                break;
            case '-':
                StackPush(stack, item1 - item2);
                break;
            }
        }
    }
    StackPop(stack, &item1);
    StackDestroy(stack);

    return (float)item1;
}

void q6()
{
    char expression[] = "23+35*+";
    float res = 0;

    res = CalcPostfixExpression(expression);

    printf("The result is: %.2f\n", res);
}


