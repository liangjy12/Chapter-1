#include <stdio.h>

void printN1(int N)
{
	int i;
	for (i = 1; i <= N; i++)
	{
		printf("%d\n", i);
	}
	return;
}

void printN2(int N)
{
	if (N != 0)
	{
		printN2(N - 1);
		printf("%d\n", N);
	}
	return;
}

int main()
{
	int N;
	scanf_s("%d", &N);
	printf("N1:\n");
	printN1(N);
	printf("N2:\n");
	printN2(N);
	system("pause");
	return 0;
}