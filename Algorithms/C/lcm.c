//LCM(Least common multiple

#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>

int main()
{

	int num1;
	int num2;
	int lcm;
	int factor = 1;

	printf("Enter First Number: ");
	scanf("%d", &num1);

	while (num1 <= 0)
	{
		printf("Invalid number\nEnter First Number again: ");
		scanf("%d", &num1);
	}
	
	printf("Enter Second Number: ");
	scanf("%d", &num2);

	while (num2 <= 0)
	{
		printf("Invalid number\nEnter Second Number again: ");
		scanf("%d", &num2);

	}


	for (int i = 1; i <= num2; i++)
	{
		if (num1 % i == 0 && num2 % i == 0)
		{
			factor = i;
			printf("%d\n", factor);
		}
	}
	lcm = (num1 * num2) / factor;
	printf("LCM of %d and %d is %d \n",num1 , num2, lcm);


	return 0;
}

