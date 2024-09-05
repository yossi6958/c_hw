/******************************************************************************************************************************
Author:       Yossi Kleiner
Date:         24/05/2023
Description:  Exe-6 Pointers
******************************************************************************************************************************/

#include <stdio.h>
#include <stdlib.h>

//Forward Declaration

void q1();
void q2();
void q3();
void q4();
void q5();

void main()
{
	printf("exe-6\n");
	q4();
}

// Functions

// q1

void func(int** ptr)
{
	**ptr = 90;
}

void q1()
{
	int x = 30;

	int* pX = &x;

	func(&pX);

	printf("%d\n", *pX);

}

// q2

void Foo(int* ptr1, int* ptr2)
{
	if (*ptr1 > *ptr2)
		*ptr1 = *ptr2;
}

void q2()
{
	int a = 8, b[] = { 1,2,3 };

	int *p1, *p2;

	p1 = &a;

	p2 = b;

	printf("%d\t %d\n", *p1 + *p2, *p2 - b[1]);

	Foo(&a, b);

	printf("%d\n", a);
}

// q3

void noRemainder(int arr[],int size,int num1,int num2,int* counter1,int* counter2)
{
	int i;

	*counter1 = *counter2 = 0;

	for (i = 0; i < size; i++)
	{

		if ((arr[i] % num1) == 0)
		{
			*counter1 = *counter1 + 1;
		}
		if ((arr[i] % num2) == 0)
		{
			(*counter2)++;
		}
		
	}
}

void q3()
{
	int arr[] = {48,63,8,4};
	int size = 4, num1 = 8, num2 = 9,counter1 = 0,counter2 = 0;

	noRemainder(arr, size, num1, num2, &counter1, &counter2);
	printf("the amount of numbers in the array that divide with %d without reminder is : %d\n", num1, counter1);
	printf("the amount of numbers in the array that divide with %d without reminder is : %d", num2, counter2);
}

// q4

int* GetAddressOfMaxElem(int arr[], int size)
{
	int i = 0, max = 0;

	for (i = 1; i < size; i++)
	{
		if (arr[i] > arr[max])
		{
			max = i;
		}
	}
	return &arr[max];
}

void q4()
{
	int arr[] = { 13,5,2,7,8 },i = 0,size = sizeof(arr) / sizeof(arr[0]);

	for (i = 0; i < size; i++)
	{
		printf("the address of the %d element is : %p\n", i, &arr[i]);
	}
	printf("the address of the max number in the array is : %p", GetAddressOfMaxElem(arr, size));
}