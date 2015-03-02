// Author : FinlayLiu
// Time : 2015-03-02
// Problem1
// Debug : VC6.0

#include <stdio.h>

int main()
{
    int n;
    int i;
    while(scanf("%d", &n) != EOF)
    {
        int begin, end;
        int found = 0;
        for(begin = 1; begin < n; begin++)
        {
            for(end = begin + 1; end < n; end++)
            {
                // 连续整数求和
                int sum = (begin + end) * (end - begin + 1) / 2;
                if(sum == n)
                {
                    // 可以分解，输出结果
                    found = 1;

                    for(i = begin;  i <= end; i++)
                    {
                        printf("%d ", i);
                    }
                    printf("\n");
                }
            }
        }
        if(found == 0)
            printf("NONE\n");
    }
    return 0;
}