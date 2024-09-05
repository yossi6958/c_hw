/******************************************************************************************************************************
Author:       Yossi Kleiner
Date:         22/03/2023
Description:  Starting C
******************************************************************************************************************************/

#include <stdio.h>

// Forward Declaration.

void Q2();
void Q3();
void Q4();
void Q7();
void Q10();
void Q11();
void Q13();
void Q12();
void Q9();
void Q1();
void Q6();

void main()
{
	printf("Chap1: Start C\n");
	Q13();
}

#define TOTOSIZE 15
void Q1()
{
	int d = 0, i;
	char score;
	printf("please enter charcter : ");
	for (i = 1; i <= TOTOSIZE; i++)
	{
		scanf_s("%c", &score);
		if (score == 'X')
			d++;
	}
	printf("%d", d);
}

void Q2()
{
	int minNum, maxNum, sum = 0, tmp;
	printf("Give me two numbers : ");
	scanf_s("%d%d", &minNum, &maxNum);
	if (maxNum < minNum)
	{
		tmp = minNum;
		minNum = maxNum;
		maxNum = tmp;
	}
	for (; minNum <= maxNum; minNum++)
	{
		sum += minNum;
	}
	printf("the sum is %d", sum);
}

void Q3()
{
	int N, minAge = 2000, maxAge = 0, age, i, hatrogane = 0;

	printf("Give me the amount of kids ages : ");
	scanf_s("%d", &N);
	for (i = 1; i <= N; i++)
	{
		printf("give me childs age : ");
		scanf_s("%d", &age);
		if (age < minAge)
		{
			minAge = age;
		}
		if (age > maxAge)
		{
			maxAge = age;
		}
		if ((i > 1) && ((maxAge - minAge) > 3))
		{
			hatrogane = 1;
			break;
		}
	}

	if (hatrogane)
	{
		printf("the group is hatrogane ");
	}
	else
	{

		printf("the group is homogane ");
	}
}

void Q4()
{
	int threshold, numLength, i, currValue, maxValue = 0, isFound = 0;

	printf("Give me a number bigger than 1 : ");
	scanf_s("%d", &threshold);
	printf("Give me a number bigger than 1 : ");
	scanf_s("%d", &numLength);
	printf("Give me %d numbers (positive and integer) : ", numLength);
	for (i = 1; i <= numLength; i++)
	{
		scanf_s("%d", &currValue);
		if ((maxValue + currValue) > threshold)
		{
			isFound = 1;
			break;
		}
		if (maxValue < currValue)
		{
			maxValue = currValue;
		}
	}

	if (isFound)
	{
		printf("There are two numbers whose sum is bigger than %d", threshold);
	}
	else
	{
		printf("There are no two numbers whose sum is bigger than %d", threshold);
	}
}

void Q6()
{
	int counter1, counter2, vote, i;

	counter1 = counter2 = 0;
	printf("enter your vote : ");
	for (i = 1; i <= 41; i++)
	{
		scanf_s("%d", &vote);
		if (vote == 1)
		{
			counter1++;
		}
		else
		{
			counter2++;
		}
	}
	if (counter1 > counter2)
	{
		printf("contestant number 1 won");
	}
	else
	{
		printf("contestant number 2 won");
	}
}

void Q7()
{
	int input, hour, minute, second, tmp;

	printf("How many seconds have passed fro the start of the day ? ");
	scanf_s("%d", &input);
	hour = input / 3600;
	tmp = input % 3600;
	minute = tmp / 60;
	second = tmp % 60;
	printf("%d : %d : %d", hour, minute, second);
}

#define A 'c'
#define B 'b'
#define C 'd'
#define D 'a'
void Q9()
{
	char a = C, b = 'd', c = D, d = a;
	printf("%c %c %c %c", b, 'c', B, c);
}

void Q10()
{
	int a1, q, n, i;

	printf("please enter a1 : ");
	scanf_s("%d", &a1);
	printf("please enter q : ");
	scanf_s("%d", &q);
	printf("please enter n : ");
	scanf_s("%d", &n);
	for (i = 1; i <= n; i++)
	{
		printf("%d\n", a1);
		a1 *= q;
	}
}

void Q11()
{
	int sum = 0;

	for (int num = 1; num < 1000; num++)
	{
		if (num % 5 == 0 || num % 3 == 0)
			sum += num;
	}
	printf("%d\n", sum);
}

void Q12()
{
	int a, i, left, right;
	printf("give me a number between 1 and 18 : ");
	scanf_s("%d", &a);
	if ((a >= 1) && (a <= 18))
	{
		for (i = 10; i < 100; i++)
		{
			left = i / 10;
			right = i % 10;
			if ((left + right) == a)
			{
				printf("%d\n", i);
			}
		}
	}
	else
	{
		printf("c'mon follow the instructions");
	}
}

void Q13()
{
	int num1, num2;
	for (num1 = 10; num1 < 100; num1++)
	{
		for (num2 = 10; num2 < 100; num2++)
		{
			if ((num1 % 10 == num2 / 10) && (float)(num1 / 10) / (num2 % 10) == (float)num1 / num2 && num1 / num2 != 1)
			{
				printf("this is a couple : %d ,%d\n", num1, num2);
			}
		}
	}
}
