// Author : FinlayLiu
// Time : 2015-03-02
// Problem1
// Debug : VC6.0

#include <stdio.h>
#include <stdlib.h>

//计算x约数的和
int yinzisum(int x)
{
    int i = 1, sum = 0;
    if(x == 1) return 0;
    while(i < x)
    {
        if(x % i == 0)
            sum = sum + i;
        i++;
    }
    return sum;
}

int main()
{
    int flag = 0, i, j, min, max;
    int *array;
    scanf("%d%d", &min, &max);
    array = (int *)malloc(sizeof(int) * (max - min + 1));
    for(i = 0; i < max - min + 1; i++)	// 先计算出来
        array[i] = yinzisum(min + i);

    for(i = 0; i < max - min + 1; i++)
        for(j = i + 1; j < max - min + 1; j++)
            if(array[i] == j + min && array[j] == i + min)
            {
                printf("%d %d\n", i + min, j + min);
                flag = 1;
            }
    if(flag == 0)
        printf("NONE\n");
    return 1;
}
