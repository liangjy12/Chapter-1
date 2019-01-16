#include <stdio.h>

void main()
{
	int N, start_temp, start, end,data, data_0, data_N;
	int temp = 0, maxsum = -1,flag = 1,allnegative = 1;
	scanf_s("%d", &N);
	for (int i = 0; i < N; i++)
	{
		scanf_s("%d", &data);
		if (i == 0) data_0 = data;
		if (i == N - 1) data_N = data;
		if (flag == 1)
		{
			start_temp = data;
			flag = 0;
		}
		temp += data;
		if (temp < 0)
		{
			temp = 0;
			flag = 1;
		}
		else if (temp > maxsum)
		{
			maxsum = temp;
			start = start_temp;
			end = data;
			allnegative = 0;
		}
	}
	if (allnegative) printf("%d %d %d", 0, data_0, data_N);
	else printf("%d %d %d", maxsum,start,end);
	system("pause");
	return;
}