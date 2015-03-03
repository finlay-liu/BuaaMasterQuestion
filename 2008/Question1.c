#include <stdio.h>

int main()
{
	int num, i, j, f1, f2;
	scanf("%d",&num);

	f1 = -1;
	for(i = 2;i < num;i++)
	{
		f2 = -1;
		for(j = 2; j< i;j++)
		{
			if(i % j == 0)
				f2 = 1;
		}
		if(f2 == -1)
		{
			f1 = 1;
			printf("%d ",i);
		}
	}
	if(f1 == -1)
		printf("-1\n");
	else
		printf("\n");

	return 0;
}