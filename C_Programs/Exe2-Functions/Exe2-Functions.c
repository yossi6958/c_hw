/******************************************************************************************************************************
Author:       Yossi Kleiner
Date:         28/03/2023 , 29/03/2023
Description:  Exe-2 Functions
******************************************************************************************************************************/
#include <stdio.h>

//Forward Declaration

void q1();
void q2();
void q3();
void q4();
void q5();
void q6();
void q7();
void q8();
void q9();
void q10();
void q11();
void q12();


void main()
{
	printf("exe-2\n");
	q11();
}

//q1

int SumOfDigits(int num)
{
	int digit, sum = 0;

	while (num != 0)
	{
		digit = num % 10;
		num /= 10;
		sum += digit;
	}
	return sum;
}

void q1()
{
	int left, right, tmp, sum, maxValue = 0, maxNumber=0;

	printf("give me a number : ");
	scanf_s("%d", &left);
	printf("give me another number : ");
	scanf_s("%d", &right);
	if (left > right)
	{
		tmp = left;
		left = right;
		right = tmp;
	}
	for (; left <= right; left++)
	{
		sum = SumOfDigits(left);
		if (sum > maxValue)
		{
			maxValue = sum;
			maxNumber = left;
		}
	}
	printf("%d", maxNumber);
}

//q2

int EvenOrOdd(int num)
{
	int digit,countEven=0;

	while (num != 0)
	{
		digit = num % 10;
		num /= 10;
		if (digit % 2 == 0)
		{
			countEven++;
		}
		else
		{
			countEven--;
		}
	}
	return countEven;
}

void q2()
{
	int num, countEven;

	printf("give me a number : ");
	scanf_s("%d", &num);
	countEven = EvenOrOdd(num);
	if (countEven > 0)
	{
		printf("even is bigger");
	}
	else if (countEven == 0)
	{
		printf("even is equal to odd");
	}
	else
	{
		printf("odd is bigger");
	}
}

//q3

unsigned long reverse(unsigned int x)
{
	int reversedNum=0;

	while (x != 0)
	{
		reversedNum *= 10;
		reversedNum += x % 10;
		x /= 10;
	}
	return reversedNum;
}

void q3()
{
	int num,reversed;

	printf("give me a number : ");
	scanf_s("%d", &num);
	reversed = reverse(num);
	printf("%d",reversed);
}

//q4

unsigned long merge(unsigned int a, unsigned int b)
{
	int mergedNum = 0;

	a = reverse(a);
	b = reverse(b);

	while (a > 0 || b > 0)
	{
		if (a > 0)
		{
			mergedNum *= 10;
			mergedNum += a % 10;
			a /= 10;
		}
		if (b > 0)
		{
			mergedNum *= 10;
			mergedNum += b % 10;
			b /= 10;
		}
	}
	return mergedNum;
}

void q4()
{
	int num1, num2,mergedNum;
	printf("give me a number : ");
	scanf_s("%d", &num1);
	printf("give me another number : ");
	scanf_s("%d", &num2);
	mergedNum = merge(num1, num2);
	printf("%d", mergedNum);
}

//q5

void q5()
{
	printf("%6d\n", 1111);
	printf("%6d\n", 11111);
	printf("%6d\n", 111111);

	printf("\n");

	printf("%-6d\n", 1111);
	printf("%-6d\n", 11111);
	printf("%-6d\n", 111111);

	printf("\n");

	printf("%8.2f\n", 3.35);
	printf("%-8.2f\n", 3.345);
	printf("%08.2f\n", 3.345);

	printf("\n");

	printf("%6d\n", 1111);
	printf("%6d\n", 11111);
	printf("%5d\n", 111111);
}

//q6

void q6()
{
	int num,leftNum,rightNum,sum;

	for (num = 1000; num <= 9900; num++)
	{
		rightNum = num % 100;
		leftNum = num / 100;
		sum = leftNum + rightNum;
		sum *= sum;
		if (sum == num)
		{
			printf("%d\n", num);
		}
	}
}

//q7

void q7()
{
	double btnArea, radius1, radius2, avg;
	const double py = 3.14;

	printf("give me the first circle radius : ");
	scanf_s("%lf", &radius1);
	printf("give me the second circle radius : ");
	scanf_s("%lf", &radius2);

	// method 1

	btnArea = (radius2 * radius2 * py) - (radius1 * radius1 * py);
	printf("%.2f\n", btnArea);

	// method 2

	avg = ((radius2 * 2 * py) + (radius1 * 2 * py)) / 2;
	btnArea = avg * (radius2 - radius1);
	printf("%.2f", btnArea);
}

// q8

void q8()
{
	double cel, fer;

	printf("give me celcius temp : ");
	scanf_s("%lf", &cel);
	fer = ((9 * cel) / 5) + 32;
	printf("%.2f\n", fer);
	printf("give me ferenheit temp : ");
	scanf_s("%lf", &fer);
	cel = ((5 * fer) / 9) - 17.8;
	printf("%.2f\n", cel);

	cel = -273;

	while (cel <= 101)
	{
		printf("%.2f\t%.2f\n", cel, (((9 * cel) / 5) + 32));
		cel += 11;
	}
}

//q9

void q9()
{
	int num, digit, count, helper;

	for (num = 100; num <= 999; num++)
	{
		count = 0;
		helper = num;
		while (helper > 0)
		{
			digit = helper % 10;
			digit *= digit * digit;
			count += digit;
			helper /= 10;
		}
		if (count == num)
		{
			printf("%d\n", num);
		}

	}
}

//q10

void q10()
{
	int num, reversedNum;

	for (num = 10000; num <= 99999; num++)
	{
		reversedNum = reverse(num);
		if ((num * 4) == reversedNum)
		{
			printf("%d\n", num);
		}
	}
}

//q11

int isValidID(long idNum)
{
	int i,vNum,v2Num,idDigit,count=0,valid;
	for (i = 1; i <= 9; i++)
	{
		vNum = (i % 2 == 0) ? 2 : 1;
		idDigit = idNum % 10;
		idNum /= 10;
		v2Num = vNum * idDigit;
		if (v2Num > 9);
		{
			v2Num = (v2Num % 10) + (v2Num / 10);
		}
		count += v2Num;
	}
	valid = (count % 10 == 0) ? 1 : 0;

	return valid;
}

void q11()
{
	int idNum, validID;

	printf("give me your id : ");
	scanf_s("%d",&idNum);
	validID = isValidID(idNum);
	if (validID)
	{
		printf("your id is okay");
	}
	else
	{
		printf("something went wrong");
	}

	
}

//q12

int counterDigitsEqual(int num1,int num2)
{
	int counter = 0;

	while(num1 != 0 && num2 != 0)
	{
	   if ((num1 % 10) == (num2 % 10))
	   {
		counter++;
	   }
	   num1 /= 10;
	   num2 /= 10;
	}
	
	return (num1 == num2) ? counter : -1;

}

void q12()
{
	int num1, num2, counterEqualDigits;
	
	printf("Give me a number : ");
	scanf_s("%d", &num1);
	printf("Give me another number : ");
	scanf_s("%d", &num2);

    counterEqualDigits = counterDigitsEqual(num1, num2);
	if (counterEqualDigits >= 0)
	{
	   printf("the number of equal digits is %d \n", counterEqualDigits);
	}
	else
	{
	   printf("the numbers are not the same length.\n");
	}
	printf("%d and %d", num1, num2);
}							  