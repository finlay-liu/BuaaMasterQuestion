#include <stdio.h>
#include <stdlib.h>

int cmp(const void *a , const void *b)
{
    return *(int *)a - *(int *)b;
}

int main()
{
	int n = 0, i, j, length;
	int* array1;
	int* array2;
	
	scanf("%d",&n);
	array1 =(int*)malloc(sizeof(int)*n);
	array2 =(int*)malloc(sizeof(int)*n);

	for(i = 0;i < n;i++)
	{
		scanf("%d",&array1[i]);
		array2[i] = array1[i];
	}

	qsort(array1,n,sizeof(int),cmp);

	length = n;
	for(i = 1;i <= length;i++)
	{
		if(array1[i] == array1[i - 1])
		{
			for(j = i;j <= length; j++)
			{
				array1[j - 1] = array1[j];
			}
			length--;
		}
	}

	for(i = 0; i < n;i++)
	{
		for(j = 0;j < length;j++)
		{
			if(array1[j] == array2[i])
			{
				printf("%d ",j+1);
				break;
			}
		}
	}
	printf("\n");

	free(array1);
	free(array2);
	return 0;
}