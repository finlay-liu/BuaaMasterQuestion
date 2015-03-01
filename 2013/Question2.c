// Author : FinlayLiu
// Time : 2015-03-01
// Problem2: 八皇后
// Debug : VC6.0

#include<stdio.h>
#include<math.h>

int x[100];
int place(int k) //考察皇后k放置在x[k]列是否发生冲突
{
    int i;
    for(i = 1; i < k; i++)
        if(x[k] == x[i] || abs(k - i) == abs(x[k] - x[i]))
            return 0;
    return 1;
}

void queue(int n)
{
    int i, k;
    for(i = 1; i <= n; i++)
        x[i] = 0;
    k = 1;
    while(k >= 1)
    {
        x[k] = x[k] + 1; //在下一列放置第k个皇后
        while(x[k] <= n && !place(k))
            x[k] = x[k] + 1; //搜索下一列
        if(x[k] <= n && k == n) //得到一个输出
        {
            for(i = 1; i <= n; i++)
                printf("%d ", x[i]);
            printf("\n");
            //return;//若return则只求出其中一种解，若不return则可以继续回溯，求出全部的可能的解
        }
        else if(x[k] <= n && k < n)
            k = k + 1; //放置下一个皇后
        else
        {
            x[k] = 0; //重置x[k],回溯
            k = k - 1;
        }
    }
}

void main()
{
    int n;
    printf("输入皇后个数n:\n");
    scanf("%d", &n);
    queue(n);
}