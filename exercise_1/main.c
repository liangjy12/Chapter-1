#include <stdio.h>

int main()
{
	int N, maxsum = 0, temp = 0, data;
	scanf_s("%d", &N);
	for (int i = 0; i < N; i++)
	{
		scanf_s("%d", &data);
		temp += data;
		if (temp > maxsum) maxsum = temp;
		else if (temp < 0) temp = 0;
	}
	printf("%d", maxsum);
	return 0;
}