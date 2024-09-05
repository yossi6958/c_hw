/******************************************************************************************************************************
Author:       Yossi Kleiner
Date:         18/04/2023
Description:  Functions - Library
******************************************************************************************************************************/

int IsSmallLetter(char ch)
{
	return(ch >= 'a' && ch <= 'z');
}

int IsCapitalLetter(char ch) 
{
	return(ch >= 'A' && ch <= 'Z');
}

int IsAlpha(char ch) 
{
	return(IsSmallLetter(ch) || IsCapitalLetter(ch));
}

int IsDigit(char ch)
{
	return(ch >= '0' && ch <= '9');
}
