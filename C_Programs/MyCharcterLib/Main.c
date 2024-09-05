/******************************************************************************************************************************
Author:       Yossi Kleiner
Date:         18/04/2023
Description:  Functions - Library - Simulation
******************************************************************************************************************************/

#include <stdio.h>

#include "MyCharcterLib.h"

void main()

{

	char ch = 0;

	printf("Please enter a charachter: ");

	ch = getchar();

	printf("Is '%c' a digit? %d\n", ch, IsDigit(ch));

	printf("Is '%c' a small letter? %d\n", ch, IsSmallLetter(ch));

	printf("Is '%c' a capital letter? %d\n", ch, IsCapitalLetter(ch));

	printf("Is '%c' a letter? %d\n", ch, IsAlpha(ch));

}