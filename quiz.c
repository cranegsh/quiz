#include "stdio.h"
#include "stdlib.h"

int scissors(int, int, int*);
int scissors_count(int, int);
int min(int, int);
int max(int, int);

int main(int argc, char *argv[])
{
	int total, i;
	unsigned int N, M;
	int (*rect)[2], *ptr;
	int array[2];

	printf("This program was called with \"%s\".\n", argv[0]);

	if (argc > 1)
	{
		N = atoi(argv[1]);
		M = atoi(argv[2]);
		for(i = 1; i <= 2; i++)
		{
			printf("argv[%d] = %s\n", i, argv[i]);
		}
	}
	else
	{
		printf("The command had no other arguments.\n");
		N = 15; M = 53;	
	}

	total = scissors_count(N, M);
	ptr = (int*)malloc(total * sizeof(array)); 
	if (ptr == NULL)
	{
		printf("\nmalloc error!\n");
		return 0;
	}

	total = scissors(N, M, ptr);
	rect = ptr;

	for(i=0; i<total; i++)
	{
		printf("{%d, %d} /", rect[i][0], rect[i][1]);
	}
	printf("%d\n\n", total);

	free(ptr);
	return 0;
}

int scissors(int width, int length, int* ptr)
{
	int (*boxes)[2];
	static count = 0;
	int value, diff, temp;
	int i;

	value = min(width, length);
	boxes = ptr;

	if(value == 0)
	{
		printf("\nProgram end!\n\n");
		return count;
	}
	else
	{
		diff = max(width, length);
		temp = diff/value;
		diff = diff - temp * value;

		printf("\nOriginal N & M: %3d, %3d", width, length);
		printf("\nNew N & M & X:  %3d, %3d, %3d\n", value, diff, temp);
		for(i=0; i<temp; i++)
		{
			boxes[count+i][0] = value;
			boxes[count+i][1] = value;
			
			printf("{%d, %d} /", boxes[count+i][0], boxes[count+i][1]);
		}
		count = count + temp;
		printf("%3d\n", count);

		scissors(value, diff, ptr);
		return count;
	}

}

int scissors_count(int width, int length)
{
	static count = 0;
	int value, diff, temp;
	int i;

	value = min(width, length);

	if(value == 0)
	{
		printf("\nProgram end!\n\n");
		return count;
	}
	else
	{
		diff = max(width, length);
		temp = diff/value;
		diff = diff - temp * value;

		printf("\nOriginal N & M: %3d, %3d", width, length);
		printf("\nNew N & M & X:  %3d, %3d, %3d\n", value, diff, temp);
		count = count + temp;
		printf("%3d\n", count);

		scissors_count(value, diff);
		return count;
	}
}

int min(int number1, int number2)
{
	if(number1 < number2)
	{
		return number1;
	}
	else
	{
		return number2;
	}
} 

int max(int number1, int number2)
{
	if(number1 > number2)
	{
		return number1;
	}
	else
	{
		return number2;
	}
} 
