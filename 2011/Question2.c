#include <stdio.h>

int main()
{
	int A[20][20], B[20][20];
	int aa, ab, ba, bb, m, n, i, j;

	freopen("sample2.in","r",stdin);

	// Input A
	scanf("%d %d\n",&aa,&ab);
	for(i = 0;i < aa;i++)
		for(j = 0;j < ab;j++)
			scanf("%d",&A[i][j]);

	// Input B
	scanf("%d %d\n",&ba,&bb);
	for(i = 0; i < ba;i++)
		for(j = 0; j < bb;j++)
			scanf("%d",&B[i][j]);

	// Input index m n
	scanf("%d %d\n",&m,&n);

	for(i = 0; i < ba; i++)
	{
		for(j = 0; j < bb; j++)
		{
			if((i + m - 1) < aa && (j + n - 1) < ab )
				A[i + m - 1][j + n - 1] = B[i][j];
		}
	}
	
	for(i = 0; i < aa;i++)
	{
		for(j = 0; j < ab;j++)
			printf("%d ",A[i][j]);

		printf("\n");
	}

	fclose(stdin);
	return 0;
}