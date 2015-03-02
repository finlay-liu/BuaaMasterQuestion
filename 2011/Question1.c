// Author : FinlayLiu
// Time : 2015-03-02
// Problem1
// Debug : VC6.0
// 还需要优化

#include <stdio.h>
#include <stdlib.h>

int gethe(int n)
{
	int i,sum;
	sum = 0;
	if(n == 1)
		return sum;
	for(i = 1;i < n;i++ )
		if(n % i == 0)
			sum += i;

	return sum;
}

int main()
{
    int num1, num2, i, j, k,size, min, max,has;
	int out[20000][2];
    freopen("sample1.in", "r", stdin);

    while(scanf("%d %d", &num1, &num2) != EOF)
    {
		size = 0;
		memset(out,-1,20000*2*sizeof(int));
        for(i = num1;i <= num2;i++)
		{
			for(j = num1;j <= num2;j++)
			{
				if(i != j && gethe(i) == j && gethe(j) == i)
				{	
					if(i > j)
					{
						min = j;
						max = i;
					}
					else
					{
						min = i;
						max = j;
					}
					has = 0;
					for(k = 0;k <= size;k++)
					{
						if(out[k][0] == min && out[k][1] == max)
							has =1;
					}

					if(!has)
					{
						out[size][0] = min;
						out[size][1] = max;
						size++;
					}
				}
			}
		}

		if( size == 0)
			printf("NONE\n");
		else
		{
			for(i = 0;i < size;i++)
			{
				printf("%d %d\n",out[i][0],out[i][1]);
			}
		}
    }

	fclose(stdin);
    return 0;
}