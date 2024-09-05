/******************************************************************************************************************************
Author:       Yossi Kleiner
Date:         31/05/2023
Description:  Strings - Library- Header
******************************************************************************************************************************/


size_t MyStrlen(char str[]);
size_t MyStrlen2(char* str);
int MyStrcmp(const char str1[], const char str2[]);
int MyStrcmp2(const char* str1, const char* str2);
char* strstr(const char* str, const char* substr);
char* MyStrcpy(char* destination, const char* source);
char* MyStrcat(char* destination, const char* source);
char* MyStrncpy(char* destination, const char* source, size_t num);
char* MyStrncat(char* destination, const char* source, size_t num);