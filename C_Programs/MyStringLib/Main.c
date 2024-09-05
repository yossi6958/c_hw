/******************************************************************************************************************************
Author:       Yossi Kleiner
Date:         31/05/2023
Description:  Strings - Library - Simulation
******************************************************************************************************************************/


#include <stdlib.h>
#include "MyStringLib.h"
#include <stdio.h>

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

void q1()
{
	char myString[50];

	printf("Please enter a sentence: ");

	fgets(myString, 50, stdin);
	

	printf("the string has  %zu characters\n", MyStrlen2(myString));
	puts(myString);
}

void q2()
{
	char str1[10] = "bb", str2[10] = "bb";
		printf("%d", MyStrcmp2(str1, str2));
}

void q3()
{
	char str[50];
	char substr[50];
	char* pSubstr;

	printf("Please enter a sentence: ");

	fgets(str, 50, stdin);

	printf("Please enter another sentence: ");

	fgets(substr, 50, stdin);

	printf("%p\n", str);
	printf("%p\n", substr);

	pSubstr = strstr(str, substr);
	printf("the substr starts at the address : %p\n", pSubstr);
}

void q4()
{
	char str1[] = "yossi kleiner", str2[] = "joshua chen";
	puts(str1);
	puts(str2);
	char* des = MyStrcpy(str1, str2);
	puts(str1);
}

void q5()
{
	char str1[50] = "yossi kleiner", str2[50] = " is the best";
	printf("%s\n", str1);
	printf("%s\n", str2);
	char* des = MyStrcat(str1, str2);
	printf("%s\n", str1);

}

void q6()
{
	char str1[50] = "yossi kleiner", str2[50] = "is the4433";
	printf("%s\n", str1);
	printf("%s\n", str2);
	char* des = MyStrncpy(str1, str2,10);
	printf("%s\n", str1);
}

void q7()
{
	char str1[50] = "yossi kleiner", str2[50] = " is the4433";
	printf("%s\n", str1);
	printf("%s\n", str2);
	char* des = MyStrncat(str1, str2, 6);
	printf("%s\n", str1);
}
