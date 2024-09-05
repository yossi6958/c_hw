/******************************************************************************************************************************
Author:       Yossi Kleiner
Date:         28/03/2023 , 19/04/2023 , 02/05/2023
Description:  Exe-3 Arrays
******************************************************************************************************************************/
#include <stdio.h>
#include <math.h>
#define SIZE 4
#define N 4
#define M 5
typedef int matrix[SIZE][SIZE];

//Forward Declaration
void q0();
void q1a();
//void q1b();
void q2();
void q3();
void q4();
void q5a();
void q5b();
void q6a();
void q6b();
void q6c();
void q6d();
void q7a();
void q7b();
void q8();
void q9();
void q10();
void q11();
void q13();
void q14();


void main()
{
	printf("exe-3\n");
	q14();
}

//q0

void q0()
{
	int matrix[SIZE][SIZE] = { {1,1,1,1}, {2,4,4,2}, {3,2,1,0}, {7,6,5,4} };
	int i,sum=0;
	
	for ( i = 0; i < SIZE; i++)
	{
		sum += matrix[i][i];
	}
	 
	printf("the sum is %d", sum);

}

//q1a

void q1a()
{
	int size,i,num1,num2;
	float sum = 0, counter = 0;

	printf("Give me a size : ");
	scanf_s("%d", &size);
	printf("Give me a number : ");
	scanf_s("%d", &num1);
	for (i = 1; i < size; i++)
	{
		printf("Give me another number : ");
		scanf_s("%d", &num2);
		if (num2 < num1)
		{
			sum += num2;
			counter++;
		}
	}
	if (counter > 0)
	{
		printf("the average is : %.2f", sum / counter);
	}
	else
	{
		printf("no numbers were smaller than %d", num1);
	}
	
	
}

//q1b

void q1b()
{
	int size, i,lastNum = 0;
	int list[200];
	float sum = 0, counter = 0;

	printf("Give me a size : ");
	scanf_s("%d", &size);
	for (i = 0; i < size; i++)
	{
		printf("Give me a number : ");
		scanf_s("%d", &list[i]);
		lastNum = list[i];
	}
	
	for (i = 0; i < size; i++)
	{
		if (list[i] < lastNum)
		{
			sum += list[i];
			counter++;
		}
	}
	if (counter > 0)
	{
		printf("the average is : %.2f", sum / counter);
	}
	else
	{
		printf("no numbers were smaller than %d", lastNum);
	}
}

//q2

void digitCounter(int num)
{
	int digitCount[10] = { 0 };
	int digit, i;

	while (num != 0)
	{
		digit = num % 10;
		num /= 10;
		digitCount[digit]++;
	}
	for (i = 0; i < 10; i++)
	{
		if (digitCount[i] > 0)
		{
			printf("the number %d appears %d times.\n", i, digitCount[i]);
		}
		
	}
}

void q2()
{ 
	int num;

	printf("Give me a number : ");
	scanf_s("%d", &num);
	digitCounter(num);
	int arr[3] = { 5,num,8 };
}

//q3

unsigned int findMissing(unsigned int a[], unsigned int n)
{
	unsigned int i,currentSum = 0,sum;

	for (i = 0; i < (n-1); i++)
	{
		currentSum += a[i];
	}
	sum = n * (n + 1)/2;
	return(sum - currentSum);
}

void q3()
{
	int arr[SIZE] = { 3,2,4 };
	int missingNum;

	missingNum = findMissing(arr, SIZE);
	printf("%d", missingNum);
}

//q4

void q4()
{
	int binary[SIZE] = { 0 };
	int results[SIZE+1] = { 0 };
	int counter = 0,i,j;
	
	for ( j = 0; j < SIZE; j++)
	{
		printf("give me binary digit : ");
		scanf_s("%d", &binary[j]);
	}
	for ( i = 0; i < SIZE; i++)
	{ 
		if (binary[i] == 1)
		{ 
			counter++;
		}
		else
		{ 
			results[(counter)]++;
			counter = 0;
		}
	}
	if (counter > 0)
	{
		results[counter]++;
	}

	for ( i = 0; i <= SIZE; i++) {
		if (results[i] > 0)
		{
			printf("there were %d sequences of %d ones\n", results[i], i);
		}
	}
}

//q5

int midMax(float a, float b, float c)
{
	return ((b > a) && (b > c));
}

void q5a()
{
	float num1, num2, num3,answer;

	printf("give me 3 numbers : ");
	scanf_s("%f%f%f", &num1, &num2, &num3);
	answer =(float) midMax(num1, num2, num3);

	if (answer == 1)
	{
		printf("the second number is the biggest");
	}
	else
	{
		printf("the second number is NOT the biggest");
	}
}

void countPicks(int heights[], int size) {
	int i, count = 0;
	float data;
	for (i = 1; i < SIZE-1; i++) {
		data =(float) midMax((float) heights[i-1], (float) heights[i],(float) heights[i + 1]);
		if (data == 1) {
			count++;
		}
	}
	printf("the picks is : %d", count);
}

void q5b()
{
	int arr[] = { 206,350,300,167,406,310 };
	countPicks(arr, SIZE);
}

//q6

float arithmeticMean(int arr[], int n)
{
	int sum = 0, i;

	for (i = 0; i < n; i++)
	{
		sum += arr[i];
	}
	return (float)sum / n;
}

void q6a()
{
	int arr[4] = { 1,6,3,4 };
	float res;
	int n = 4;

	res = arithmeticMean(arr, n);
	printf("the average is : %.2f  \n", res);
}

double geometricMean(int arr[], int n)
{
	float sum = 1;
	double res;

	for (int i = 0; i < n; i++)
	{
		sum *= arr[i];
	}
	res = pow((float)sum, (float)1 / n);
	return res;

}

void q6b()
{
	int arr[4] = { 1,2,9,9 };
	double res;
	int n = 4;

	res = geometricMean(arr, n);
	printf("the average is : %.2f  \n", res);
}

float harmonicMean(int arr[], int n)
{
	float sum = 0, res;

	for (int i = 0; i < n; i++)
	{
		sum += (float)1 / arr[i];
	}
	res = (float)n / sum;
	return res;
}

void q6c()
{
	int arr[4] = { 1,2,9,8 };
	float res;
	int n = 4;

	res = harmonicMean(arr, n);
	printf("the average is : %.2f  \n", res);
}

void q6d()
{
	int arr[4] = { 8,1,2,4 };
	int n = 4;

	if (arithmeticMean(arr, n) >= geometricMean(arr, n) && geometricMean(arr, n) >= harmonicMean(arr, n))
	{
		printf("means inequality is true because %f <= %f <= %f", harmonicMean(arr, n), geometricMean(arr, n), arithmeticMean(arr, n));
	}
	else
	{
		printf("\n mean inequality is false");
	}

}

//q7

void reverse(int arr[], int size)
{
	int i, temp;

	for (i = 0; i < size / 2; i++)
	{
		temp = arr[i];
		arr[i] = arr[size - 1 - i];
		arr[size - 1 - i] = temp;
	}
}

void q7a()
{
	int arr[5] = { 1,2,1,9,3 };
	int n = 5;

	reverse(arr, n);
	for (int i = 0; i < n; i++)
	{
		printf("%d", arr[i]);
	}
}

void flip(int a[], int m, int n)
{
	int i, j, temp;
	for (i = 0; i < m; i++)
	{
		temp = a[i - i];
		for (j = 0; j < m + n; j++)
		{
			a[j] = a[j + 1];
		}

		a[m + n - 1] = temp;
	}
}

void q7b()
{
	int arr[9] = { 1,2,3,4,5,6,7,8,9 };
	int m = 3, n = 6;

	flip(arr, m, n);
	for (int i = 0; i < m + n; i++)
	{
		printf("%d\t", arr[i]);
	}
}

//q8

void q8()
{
	int i, j, sum;

	matrix matrixBox = { {2, 1, 5, 9}, { 1,3,0,1 }, { 3,2,1,0 }, { 7,6,9,4 } };
	matrix newMatrix = { 0 };

	for (i = 0; i < SIZE; i++) {
		for (j = 0; j < SIZE; j++)
		{
			sum = 0;
			sum += matrixBox[i][j];
			if (i - 1 >= 0 && j - 1 >= 0) {
				sum += matrixBox[i - 1][j - 1];
			}
			if (i - 1 >= 0) {
				sum += matrixBox[i - 1][j];
			}
			if (i - 1 >= 0 && j + 1 < SIZE) {
				sum += matrixBox[i - 1][j + 1];
			}
			if (j - 1 >= 0) {
				sum += matrixBox[i][j - 1];
			}
			if (j + 1 < SIZE) {
				sum += matrixBox[i][j + 1];
			}
			if (i + 1 < SIZE && j - 1 >= 0) {
				sum += matrixBox[i + 1][j - 1];
			}
			if (i + 1 < SIZE) {
				sum += matrixBox[i + 1][j];
			}
			if (i + 1 < SIZE && j + 1 < SIZE) {
				sum += matrixBox[i + 1][j + 1];
			}
			newMatrix[i][j] = sum;
		}
	}
	printf("The original matrix is:\n");
	for (i = 0; i < SIZE; i++) {
		for (j = 0; j < SIZE; j++) {
			printf("%d\t", matrixBox[i][j]);
		}
		printf("\n");
	}
	printf("\nThe new matrix is:\n");
	for (i = 0; i < SIZE; i++) {
		for (j = 0; j < SIZE; j++) {
			printf("%d\t", newMatrix[i][j]);
		}
		printf("\n");
	}
}

//q9

void q9()
{
	matrix matrixA = { {2, 1, 1, 1}, { 1,1,1,1 }, { 3,2,1,0 }, { 7,6,5,4 } };
	matrix matrixB = { {1,1,7,1}, {1,1,6,2}, {1,1,5,0}, {1,1,4,4} };
	int i, j,r, count = 0;

	for (i = 0; i < SIZE; i++)
	{
		for (j = 0; j < SIZE; j++)
		{
			for ( r = 0; r < SIZE; r++)
			{
				if (matrixA[i][r] == matrixB[r][j])
				{
					count++;
				}
				else
				{
					break;
				}
			}
			if (count == SIZE)
			{
				printf("row number %d in matrixA is equal to colom number %d in matrixB\n", i + 1, j + 1);
			}
			count = 0;
		}
		
	}
}

//q10

void q10()
{
	int matrixBox[N][M] = { {2, 5, 1, 1,6}, {1,1,0,1,9}, {3,2,1,0,6}, {1,6,5,4,4} };
	int newMatrix[M][N] = { 0 };
	int i, j;

	for (i = 0; i < N; i++)
	{
		for (j = 0; j < M; j++)
		{
			printf("\t%d\t", matrixBox[i][j]);
		}
		printf("\n");
	}
	printf("\n");
	for (i = 0; i < N; i++)
	{
		for (j = 0; j < M; j++)
		{
			newMatrix[j][N - 1 - i] = matrixBox[i][j];
		}
	}

	for (i = 0; i < M; i++)
	{
		for (j = 0; j < N; j++)
		{
			printf("\t%d\t", newMatrix[i][j]);
		}
		printf("\n");
	}
}

//q11

void q11()
{
	matrix matrixBox = { {2, 5, 1, 1}, { 1,1,0,1 }, { 3,2,1,0 }, { 1,6,5,4 } };
	int i, j, temp,minCol = 0;

	for (i = 0; i < SIZE; i++)
	{
		for (j = 0; j < SIZE; j++)
		{
			printf("%d\t", matrixBox[i][j]);
		}
		printf("\n");
	}
	printf("\n");

	for (i = 0; i < SIZE; i++)
	{
		minCol = 0;
		for (j = 1; j < SIZE; j++)
		{
			if (matrixBox[i][j] < matrixBox[i][minCol])
			{
				minCol = j;
			}
			temp = matrixBox[i][i];
			matrixBox[i][i] = matrixBox[i][minCol];
			matrixBox[i][minCol] = temp;
		}
	}
	for (i = 0; i < SIZE; i++)
	{
		for (j = 0; j < SIZE; j++) 
		{
			printf("%d\t", matrixBox[i][j]);
		}
		printf("\n");
	}
}

//q13

int countRactangles(int picture[N][M])
{
	int i, j, counter = 0;
	for (i = 1; i < N; i++)
	{
		for (j = 1; j < M; j++)
		{
			if (picture[i][j] == 0 && picture[i - 1][j] != 0 && picture[i][j - 1])
			{
				counter++;
			}
		}
	}
	return counter;
}

void q13()
{
	int matrixBox[N][M] =
	{
		{1,1,1,1,1},
		{1,0,0,0,1},
		{1,0,0,0,1},
		{1,1,1,1,1}
	};
	int i, j, counter;
	for (i = 0; i < N; i++)
	{
		for (j = 0; j < M; j++)
		{
			printf("\t%d\t", matrixBox[i][j]);
		}
		printf("\n");
	}
	counter = countRactangles((matrixBox));
	printf("the number of ractangles is : %d", counter);
}

//q14

int removeZeros(int arr[], int n)
{
	int i,count = 0;

	for (i = 0; i < n; i++)
	{
		if (arr[i] != 0)
		{
			arr[count] = arr[i];
			count++;
		}
	}
	return  count;
}

void q14()
{
	int arr[4] = { 1,0,3,0 };
	int res,i,n=4;

	res = removeZeros(arr, n);
	printf("the length of the array is : %d\n", res);
	printf("the new array is :\t");
	for (i = 0; i < res; i++)
	{
		printf("%d\t", arr[i]);
	}
}


