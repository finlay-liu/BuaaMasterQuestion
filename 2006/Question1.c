#include <stdio.h>
#include <stdlib.h>

int cmp(const void *a , const void *b)
{
	return *(int *)a - *(int *)b;
}

int set_same(int a[],int len1,int b[],int len2)
{
	int i;
	qsort(a, len1, sizeof(int), cmp);
	qsort(b, len2, sizeof(int), cmp);
	
	if(len1 != len2)
		return 0;
	else 
	{
		for(i = 0;i < len1;i++)
			if(a[i] != b[i])
				return 0;
	}
	
	return 1;
}

int main()
{
	int n1,n2,i;
	int *array1;
	int *array2;
	
	scanf("%d",&n1);
	array1 = (int *)malloc(n1 * sizeof(int));
	for(i = 0;i < n1;i++)
		scanf("%d",&array1[i]);
	
	scanf("%d",&n2);
	array2 = (int *)malloc(n2 * sizeof(int));
	for(i = 0;i < n2;i++)
		scanf("%d",&array2[i]);
	
	if(set_same(array1,n1,array2,n2))
		printf("SAME\n");
	else
		printf("NO\n");
	
	free(array1);
	free(array2);
	return 0;
}