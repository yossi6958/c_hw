/******************************************************************************************************************************
Author:       Yossi Kleiner
Date:         31/05/2023
Description:  Exe-6 Pointers
******************************************************************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

//Forward Declaration

void q1();
void q2();
void q3();
void q4();
void q5();

void main()
{
	printf("exe-7\n");
	q3();
}

// Functions

// q1

struct Time
{
	int hour, minute,second;
};
typedef struct Time MyTime_t;

MyTime_t DiffTime(MyTime_t t1, MyTime_t t2)
{
	int sec = (t2.hour * 3600 + t2.minute * 60 + t2.second) - (t1.hour * 3600 + t1.minute * 60 + t1.second);
	MyTime_t resT = { sec / 3600,(sec % 3600) / 60,sec % 60 };
	return resT;
}
void q1()
{
	MyTime_t t1={19,45,20}, t2={20,50,11}, restT;
	restT = DiffTime(t1, t2);
	printf("the new time is : %d:%d:%d", restT.hour, restT.minute, restT.second);
}

// q2

struct Student
{
	char name[20];
	int avg, id;
};

typedef struct Student Student_t;

int BestStudent(Student_t std[],int size)
{
	int i = 0;
	Student_t bestStudent = std[0];
	for (i = 1; i < size; ++i)
	{
		if (std[i].avg > bestStudent.avg)
		{
			bestStudent = std[i];
		}
	}
	return bestStudent.id;
}

void q2()
{
	Student_t std[] = { {"yossi",86,32503},{"avi",45,55488},{"maxim",83,34324},{"deni",71,4343} };
	int size = sizeof(std) / sizeof(std[0]);
	printf("the best student id is : %d", BestStudent(std, size));
}

// q3

struct Point
{
	int x;
	int y;
};
typedef struct Point Point_t;

struct Square
{
	Point_t up_l;
	Point_t down_r;
};
typedef struct Square Square_t;

int IsPointInside(const Square_t Square,const Point_t Point)
{
	return(((Point.x >= Square.up_l.x) && (Point.x <= Square.down_r.x)) 
		&& ((Point.y <= Square.up_l.y) && (Point.y >= Square.down_r.y)));
}

void q3()
{
	Square_t Square = { {4,8},{10,4} };
	Point_t Point = { 5,10 };
	printf("%d", IsPointInside(Square, Point));

}

// q4

//struct Appear
//{
//	char ch;
//	int count;
//};
//typedef struct Appear Appear_t;
//
//int ManyChar(Appear_t arr[],char str[])
//{
//	int i = 0;
//
//	while (str[i++] != 0)
//	{
//		if(isalpha(str[i]))
//	}
//}