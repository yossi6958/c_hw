/******************************************************************************************************************************
Author:       Yossi Kleiner
Date:         16/05/2023
Description:  Exe-5 Bits
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
	printf("exe-5\n");
	q5();
}

// Functions

void printCharAsBinary(char ch)
{
	int i;
	unsigned char temp;

	for (i = 0; i < 8; i++)
	{
		temp = ch << i;
		temp >>= 7;
		printf("%d", temp);
	}
}

// q1

char setBit(unsigned char ch, int index, int value)
{
	unsigned char mask = 1;
	mask <<= index;

	if (value == 1)
	{
		return(ch | mask);
	}
	else
	{
		mask = ~mask;
		return(ch & mask);
	}
}

void q1()
{
	unsigned char ch = 'a';
	int index = 5;
	int value = 0;
	int result =  setBit(ch, index, value);
	printCharAsBinary(result);
}

// q2

void IsNegative(int num)
{
	unsigned int temp = num;
	
	if (temp>>=31)
	{
		printf("the number is negative");
	}
	else
	{
		printf("the number is positive");
	}
}

void q2()
{
	int num = -4;
	IsNegative(num);
}

// q3

int IsPowerOf2(unsigned int num)
{
	return((num & (num-1))==0);
}

void q3()
{
	for (int i = 1; i < 256; i++)
	{
		if (IsPowerOf2(i))
		{
			printf("%d\n", i);
		}
    }
}

// q4

int CountOnes(int num)
{
	int mask = 1,count = 0;
	unsigned int temp = num;
	
	for (int i = 0; i < 32; i++)
	{
		if (temp >> 31 & mask)
		{
			count++;
		}
		temp <<= 1;
	}
	return count;
}

void q4()
{
	int num = -157748;
	printf("the number of ones in the number is :  %d", CountOnes(num));
}

// q5

void PrintAsHex(int num)
{
	int numBits = sizeof(int) * 8;
	int mask = 0xF;

	for (int i = numBits - 4; i >= 0; i -= 4) 
	{
		int nibble = (num >> i) & mask;
		char hexChar;

		if (nibble < 10)
		{
			hexChar = nibble + '0';
		}
		else
		{
			hexChar = nibble - 10 + 'A';
		}
		printf("%c", hexChar);
	}
	printf("\n");
}

void q5()
{
	int num = -1847;
	PrintAsHex(num);
}


