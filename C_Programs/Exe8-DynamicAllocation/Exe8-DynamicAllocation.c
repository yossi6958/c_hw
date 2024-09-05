/******************************************************************************************************************************
Author:       Yossi Kleiner
Date:         07/06/2023
Description:  Exe-8 Dynamic allocation
******************************************************************************************************************************/

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
	printf("exe-8\n");
	q3();
	
}

// Functions

// q1

void q1()
{
	int size,*arr,i,sizeNew = 0,*newArr;

	printf("Please enter the size of the array : \n");
	scanf_s("%d", &size);
	arr = malloc(size * sizeof(int));
	if (!arr)
	{
		printf("ERROR! Out of memory!\n");
		exit(1);
	}
	
	srand((unsigned int)time(NULL));
	int randomNumber = rand() % 10;
	printf("The random number is : %d\n", randomNumber);

	for (i = 0; i < size; i++)
	{
		printf("\nPlease enter a number : \n");
		scanf_s("%d", arr+i);
		if (randomNumber == *(arr+i))
		{
			sizeNew++;
		}
	}
	newArr = malloc(sizeNew * sizeof(int));
	if (!newArr)
	{
		printf("ERROR! Out of memory!\n");
		exit(1);
	}
	for (i = 0; i < size; i++)
	{
		if (randomNumber == *(arr + i))
		{
			*(newArr) = i;
			newArr++;
		}
	}
	newArr -= sizeNew;
	printf("the new array size is : %d\n", sizeNew);
	for (i = 0; i < sizeNew; i++)
	{
		printf("%d\n", *(newArr+i));
	}
}

// q2

void MergeArray(int* arr1, int* arr2,int size1,int size2,int** mergedArr,int* mergedSize)
{
	int i = 0,j = 0;

	*(mergedSize) = size1 + size2;
	*mergedArr = malloc(*mergedSize * sizeof(int));
	if (!*mergedArr)
	{
		printf("ERROR! Out of memory!\n");
		exit(1);
	}
	for ( i = 0; i < size1; i++)
	{
		*(*mergedArr+i) = *(arr1+i);
	}
	for ( j = 0; j < size2; j++,i++)
	{
		*(*mergedArr+i) = *(arr2+j);
	}
}

void q2()
{
	int arr1[] = { 4,4,5,1 },arr2[] = { 1,2,8,4,3 }, mergedSize;
	int* mergedArr = NULL;

	MergeArray(arr1, arr2, sizeof(arr1) / sizeof(arr1[0]), sizeof(arr2) / sizeof(arr2[0]),&mergedArr,&mergedSize);
	printf("the new array size is : %d\n",mergedSize);
	for (int i = 0; i < mergedSize; i++)
	{
		printf("%d\t",mergedArr[i]);
	}

}

// q3

struct Point
{
	int x, y;
};
typedef struct Point Point_t;
struct Polygon
{
	int numOfPoints;
	Point_t** points;
};
typedef struct Polygon Polygon_t;

void q3()
{
	Point_t Point1 = { 1,2 }, Point2 = { 6,7 }, Point3 = { 10,0 };
	Polygon_t PolygonUser = {0};
	int i;

	printf("what is the size of the polygon : \n");
	scanf_s("%d", &PolygonUser.numOfPoints);

	PolygonUser.points = (Point_t**)calloc(PolygonUser.numOfPoints, sizeof(Point_t*));
	if (!PolygonUser.points)
	{
		printf("ERROR! Out of memory!\n");
		exit(1);
	}
	PolygonUser.points[0] = (Point_t*)malloc(sizeof(Point_t));
	PolygonUser.points[0] -> x = Point1.x;
	PolygonUser.points[0] -> y = Point1.y;
	PolygonUser.points[1] = (Point_t*)malloc(sizeof(Point_t));
	PolygonUser.points[1] -> x = Point2.x;
	PolygonUser.points[1] -> y = Point2.y;
	PolygonUser.points[2] = (Point_t*)malloc(sizeof(Point_t));
	PolygonUser.points[2] -> x = Point3.x;
	PolygonUser.points[2] -> y = Point3.y;
	srand((unsigned int)time(NULL));
	
	for (i = 3; i < PolygonUser.numOfPoints; i++)
	{
		PolygonUser.points[i] = (Point_t*)calloc(PolygonUser.numOfPoints, sizeof(Point_t));
		PolygonUser.points[i]->x = rand() % 15;
		PolygonUser.points[i]->y = rand() % 15;
		
	}
	for (i = 0; i < PolygonUser.numOfPoints; i++)
	{
		printf("(%d,%d)\n", PolygonUser.points[i]->x, PolygonUser.points[i]->y);
		free(PolygonUser.points[i]);
	}
	free(PolygonUser.points);
}