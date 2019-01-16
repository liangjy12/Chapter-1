#include <stdio.h>
#include <stdlib.h>

#define MAXSIZE 10
#define NotFound 0
typedef int ElementType;

typedef int Position;
typedef struct LNode *List;
struct LNode {
	ElementType Data[MAXSIZE];
	Position Last; /* �������Ա������һ��Ԫ�ص�λ�� */
};

List ReadInput(); /* ����ʵ�֣�ϸ�ڲ���Ԫ�ش��±�1��ʼ�洢 */
Position BinarySearch(List L, ElementType X);

int main()
{
	List L;
	ElementType X;
	Position P;

	L = ReadInput();
	scanf_s("%d", &X);
	P = BinarySearch(L, X);
	printf("%d\n", P);

	return 0;
}

Position BinarySearch(List L, ElementType X)
{
	if (L == NULL) return NotFound;
	int start = 1, end = L->Last, mid;
	while (start <= end)
	{
		mid = (start + end) / 2;
		if (L->Data[mid] == X)	return	mid;
		else if (L->Data[mid] > X)	end = mid - 1;
		else start = mid + 1;
	}
	return NotFound;
}

List ReadInput()
{
	int temp,maxsize;
	int i=1,j;
	List L = (List)malloc(sizeof(List));
	L->Data[0] = NULL;
	while (scanf_s("%d", &temp)!=EOF)
	{
		L->Data[i] = temp;
		L->Last = i;
		i++;
		if (getchar() == '\n') break;
	}
	return L;
}