#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>

int main()
{

	int size;

	printf("Please Enter size:");		//taking input from user
	scanf_s("%d", &size);

	while (size <= 3 || size % 2 == 0)		//loop for validation
	{
		printf("Invalid Input! \nEnter size again: ");
		scanf("%d", &size);
	}

	//nested loops for output
	for (int i = 0; i <= (size + 1) / 2; i++)		
	{

		for (int j = 1; j <= size - i; j++)
		{
			printf(" ");
		}

		for (int j = 1; j <= 2 * i - 1; j++)
		{
			printf("*");
		}

		printf("\n");
	}

	for (int i = ((size - 1) / 2); i >= 1; i--)
	{

		for (int j = 1; j <= size - i; j++)
		{
			printf(" ");
		}

		for (int j = 1; j <= 2 * i - 1; j++)
		{
			printf("*");
		}

		printf("\n");
	}


	return 0;
}