#include <stdio.h>
#include <stdlib.h>
int maxsubseqsum1(int List[], int N);
int maxsubseqsum2(int List[], int N);
int maxsubseqsum3(int List[], int N);
int max3(int a, int b, int c);
int DivideAndConquer(int List[], int left, int right);
int maxsubseqsum4(int List[], int N);

int main()
{
	int a[8] = { 1,-2,3,4,-5,6,7,8 };
	int lenA = sizeof(a) / sizeof(a[0]);
	int maxsum1 = maxsubseqsum1(a, lenA);
	int maxsum2 = maxsubseqsum2(a, lenA);
	int maxsum3 = maxsubseqsum3(a, lenA);
	int maxsum4 = maxsubseqsum4(a, lenA);

	printf("maxsum1: %d\n", maxsum1);
	printf("maxsum2: %d\n", maxsum2);
	printf("maxsum3: %d\n", maxsum3);
	printf("maxsum4: %d\n", maxsum4);
	system("pause");
	return;
}

int maxsubseqsum1(int List[], int N)
{
	int i, j, k;
	int Thissum, Maxsum = 0;
	for (i = 0; i < N; i++)
	{
		for (j = i; j < N; j++)
		{
			Thissum = 0;
			for (k = i; k <= j; k++)
			{
				Thissum += List[k];
				if (Thissum > Maxsum) Maxsum = Thissum;
			}
		}
	}
	return Maxsum;
}

int maxsubseqsum2(int List[], int N)
{
	int i, j;
	int Thissum, Maxsum = 0;
	for (i = 0; i < N; i++)
	{
		Thissum = 0;
		for (j = i; j < N; j++)
		{
			Thissum += List[j];
			if (Thissum > Maxsum) Maxsum = Thissum;
		}
	}
	return Maxsum;
}

int maxsubseqsum3(int List[], int N)
{
	return DivideAndConquer(List, 0, N - 1);
}

int max3(int a, int b, int c)
{
	return a > b ? a > c ? a : c : c < b ? b : c;
}

int DivideAndConquer(int List[], int left, int right)
{
	int maxleftsum, maxrightsum;
	int leftbordersum, rightbordersum, maxleftbordersum, maxrightbordersum;
	int center, i;

	if (left == right)
	{
		if (List[left] > 0) return List[left];
		else return 0;
	}

	center = (left + right) / 2;
	maxleftsum = DivideAndConquer(List, left, center);
	maxrightsum = DivideAndConquer(List, center + 1, right);

	maxleftbordersum = 0;
	leftbordersum = 0;
	for (i = center; i >= left; i--)
	{
		leftbordersum += List[i];
		if (leftbordersum > maxleftbordersum) maxleftbordersum = leftbordersum;
	}

	maxrightbordersum = 0;
	rightbordersum = 0;
	for (i = center + 1; i <= right; i++)
	{
		rightbordersum += List[i];
		if (rightbordersum > maxrightbordersum) maxrightbordersum = rightbordersum;
	}

	return max3(maxleftsum, maxrightsum, maxleftbordersum + maxrightbordersum);
}

int maxsubseqsum4(int List[], int N)
{
	int Thissum = 0, Maxsum = 0, i;
	for (i = 0; i < N; i++)
	{
		Thissum += List[i];
		if (Thissum > Maxsum) Maxsum = Thissum;
		else if (Thissum < 0) Thissum = 0;
	}
	return Maxsum;
}