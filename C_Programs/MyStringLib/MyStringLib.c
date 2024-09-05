/******************************************************************************************************************************
Author:       Yossi Kleiner
Date:         31/05/2023
Description:  Strings - Library
******************************************************************************************************************************/


#include <stdlib.h>
#include "MyStringLib.h"
#include <stdio.h>

size_t MyStrlen(char str[])
{
	int i = 1;

	while (str[i++] != '\0');
	return i;
}

int MyStrcmp(const char str1[], const char str2[])
{
	int i = 0;

	while (str1[i] != 0 || str2[i] != 0)
	{
		if (str1[i] > str2[i])
		{
			return 1;
		}
		else if (str1[i] < str2[i])
		{
			return -1;
		}
		i++;
	}
	return 0;
}

size_t MyStrlen2(char* str)
{
	size_t counter = 0;
	while (*(str++) != '\0')
	{
		counter++;
	}
	return counter - 1;
}

int MyStrcmp2(const char* str1, const char* str2)
{
	while (*str1 || *str2)
	{
		if ((*str1) > (*str2))
		{
			return 1;
		}
		else if ((*str1) < (*str2))
		{
			return -1;
		}
		str1++;
		str2++;
	}
	return 0;
}

char* strstr(const char* str, const char* substr)
{
	int i = 0;
	const char* pStr;
	while (*str)
	{
		int j = 0;
		pStr = str;
		while (*(str + j) == *(substr + j) && (*(substr + j) != 0))
		{
			j++;
		}
		if (*(substr + j) == 0)
		{
			return pStr;
		}
		str++;
	}
	return NULL;
}

char* MyStrcpy(char* destination, const char* source)
{
	char* pDst = destination;

	while (*source)
	{
		*destination++ = *source++;
	}
	*destination = 0;
	return pDst;
}

char* MyStrcat(char* destination, const char* source)
{
	char* pDst = destination;
	while (*pDst++)
		while (*source)
		{
			*pDst++ = *source++;
		}
	*pDst = 0;
	return destination;
}

char* MyStrncpy(char* destination, const char* source, size_t num)
{
	char* pDst = destination;

	while (*source && num--)
	{
		*destination++ = *source++;
	}
	if (!(*source) && num)
	{
		while (num--)
		{
			*destination++ = 0;
		}
	}
	return pDst;
}

char* MyStrncat(char* destination, const char* source, size_t num)
{

	char* pDst = destination;
	while (*pDst++)
		while (*source && num--)
		{
			*pDst++ = *source++;
		}
	*pDst = 0;
	return destination;
}
