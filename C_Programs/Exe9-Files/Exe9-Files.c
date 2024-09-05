/******************************************************************************************************************************
Author:       Yossi Kleiner
Date:         14/06/2023
Description:  Exe-9 Files.
******************************************************************************************************************************/

#define _CRT_SECURE_NO_WARNINGS
#define SIZE 20
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <time.h>

//Forward Declaration

void q1();
void q2();
void q3();

void main()
{
	printf("exe-9\n");
	q1();

}

// Functions

// q1

struct Person

{

	char name[SIZE];

	long id;

	float age;

} typedef person_t;
void q1()
{
	
	FILE* f;

	person_t* personsSource, * personsDest;

	int sizeSource, sizeDest, i;

	printf("How many persons? ");

	scanf("%d", &sizeSource);

	// allocating the persons array

	personsSource = (person_t*)calloc(sizeSource , sizeof(person_t));

	if (!personsSource)
	{
		printf("error\n");
		exit(1);
	}

	// reading persons.

	for (i = 0; i < sizeSource; i++)

	{

		printf("Enter name: ");
		scanf("%s",personsSource[i].name);
		printf("Enter id :");
		scanf("%ld",&personsSource[i].id);
		printf("Enter age : ");
		scanf("%f",&personsSource[i].age);

	}
	f = fopen("persons.bin", "wb");

	// writing the size to the file

	fwrite(&sizeSource, sizeof(int), 1, f);

	// writing all persons to the file

	fwrite(personsSource, sizeof(person_t), sizeSource, f);

	fclose(f);

	// don’t forget to free the array!!

	free(personsSource);

	f = fopen("persons.bin", "rb");

	// reading the size from the file

	fread(&sizeDest, sizeof(int), 1, f);

	// allocating the new array

	personsDest = (person_t*)calloc(sizeDest , sizeof(person_t));

	if (!personsDest)
	{
		exit(1);
	}

	// reading all persons from the file

	fread(personsDest, sizeof(person_t), sizeDest, f);

	fclose(f);

	printf("There are %d persons in the file:\n", sizeDest);

	for (i = 0; i < sizeDest; i++)

		printf("Person #%d: Name=%s\t Id=%ld\t Age=%f\n", i + 1,

			personsDest[i].name, personsDest[i].id, personsDest[i].age);

	// don’t forget to free the array!!

	free(personsDest);

}