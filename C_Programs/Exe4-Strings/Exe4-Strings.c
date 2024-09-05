/******************************************************************************************************************************
Author:       Yossi Kleiner
Date:         10/05/2023,16/05/2023
Description:  Exe-4 Strings
******************************************************************************************************************************/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

//Forward Declaration
void q1();
void q2();
void q3();
void q4();
void q5();
void q6();
void q7();
void q8();

void main()
{
	printf("exe-4\n");
	q5();
}

// Functions

// q1

void q1()
{
	char str[20];
	size_t length;

	printf("Enter a string : ");
	fgets(str, 20, stdin);
	length = strlen(str);
	printf("%c", str[length - 2]);
}

// q2

int checkStr(char str[])
{
	size_t length;

	length = strlen(str);
	if (str[0] == str[length - 2])
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

void q2()
{
	char str[20];

	for (int i = 0; i < 4; i++)
	{
		printf("\nEnter a string : ");
		fgets(str, 20, stdin);
		if (checkStr(str))
		{
			printf("\t\t\t\t\t\t");
			puts(str);
		}
	}
}

// q3

void q3()
{
	char st[100] = {"hey"};
	int count = 0,i=0;

	printf("Enter a string : ");
	fgets(st, 100, stdin);
	while (st[i] != 0)
	{
		if (st[i] == 'Y' && st[i + 1] == ' ')
		{
			count++;
		}
		i++;
	}
	printf("the amount of words ending with a Y is : %d ", count);
}

// Q4

void q4()
{
	char strBig[100] = { 'h' };
	char strSmall[100] = { 'h' };
	char temp[100] = { 'h' };

	printf("Enter a string : ");
	fgets(strBig, 100, stdin);
	printf("Enter another string : ");
	fgets(strSmall, 100, stdin);
	if (strlen(strBig) < strlen(strSmall))
	{
		strcpy(temp, strBig);
		strcpy(strBig, strSmall);
		strcpy(strSmall, temp);
	}
	if ((strlen(strBig)-1) >= ((strlen(strSmall)-1) * 2))
	{
		puts(strBig);
	}
	else
	{
		puts(strSmall);
	}

}

// q5

void q5()
{
	char firstName[20];
	char lastName[20];

	printf("Enter your firstName : ");
	fgets(firstName, 20, stdin);
	printf("Enter your lastName : ");
	fgets(lastName, 20, stdin);


	if ((strlen(lastName)-1) > 12)
	{
		printf("Error: The last name you inserted is too long.\n");
		return;
	}
	printf("Your full name is %zd characters long.\n", strlen(firstName) + strlen(lastName)-2);
}

// q6

void reverse(char str[])
{
   int i,tmp;
   size_t lastIndex;

	lastIndex = strlen(str)-1;
	for ( i = 0 ;i< lastIndex;i++,lastIndex--)
	{
		tmp = str[i];
		str[i] = str[lastIndex];
		str[lastIndex] = tmp;
	}
	
}

void q6()
{
	char str[] = "mosh";
	reverse(str);
	printf("%s", str);
}

// q7

int countOccurences(const char s1[], const char s2[])
{	
	unsigned count = 0;
	int i = 0;
	size_t s1Length = strlen(s1);
	size_t s2Length = strlen(s2);
	size_t iterationsCounter = s1Length - s2Length;

	if (s2Length == 0)
	{
		return 0;
	}

	while (i <= iterationsCounter)
	{
		int j = 0;

		while (s2[j] != '\0' && s1[i+j] == s2[j] )
		{
			j++;
		}
		if (s2[j] == '\0')
		{
			count++;
		}
		i++;
	}
	return count;
}

void q7()
{
	char str1[80] = "abaaba";
	char str2[50] = "aba";
	int result = countOccurences(str1, str2);
	printf("%d", result);
}

// q8

int sumInString(const char str[])
{
	int sum = 0,i=0;
	int currentNumber = 0;

	while (str[i] != '\0') {
		if (isdigit(str[i])) {
			currentNumber = currentNumber * 10 + (str[i] - '0');
		}
		else {
			sum += currentNumber;
			currentNumber = 0;
		}
		i++;
	}

	sum += currentNumber;

	return sum;
}

void q8() {
	const char str[30] = "605cw580d12";
	int sum = sumInString(str);
	printf("%d\n", sum);
}

