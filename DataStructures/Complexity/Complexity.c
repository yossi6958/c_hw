/******************************************************************************************************************************
Author:       Yossi Kleiner
Date:         27/06/2023
Description:  complexity
******************************************************************************************************************************/

#define SIZE 5

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

//Forward Declaration

void q1();
void q2();
void q3();

void main()
{
	printf("complexity\n");
	q3();
}

// Functions

// q1

void q1()
{
	int arr[SIZE] = { 0 }, i,j,mostFrequent = 0,counter = 0,maxCounter = 0;

	printf("pls enter %d numbers :", SIZE);
	for (i = 0; i < SIZE; i++)
	{
		scanf_s("%d", &arr[i]);
	}
	for (i = 0; i < SIZE; i++)
	{
		for (j = 0; j < SIZE; j++)
		{
			if (arr[i] == arr[j])
			{
				counter++;
			}
		}
		if (counter > maxCounter)
		{
			maxCounter = counter;
			mostFrequent = arr[i];
		}
		counter = 0;
	}
	printf("the most frequent number is %d", mostFrequent);
}

// q2


void q2()
{
	int arr[SIZE] = {0}, i;
	int lookupTable[101] = { 0 };

	printf("pls enter %d numbers :", SIZE);
	for (i = 0; i < SIZE; i++)
	{
		scanf_s("%d", &arr[i]);
		lookupTable[arr[i]]++;
	}
	int mostFrequent = 0;
	for (i = 1; i < 101; i++)
	{
		if (lookupTable[i] > lookupTable[mostFrequent])
		{
			mostFrequent = i;
		}
	}
	printf("the most frequent number is %d", mostFrequent);
}

void q3()
{
    int a = 5;
    int*  ptr;
	ptr = &a;
	*ptr = 10;
	printf("%d\n", a);
}