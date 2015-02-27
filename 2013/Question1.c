// Author : FinlayLiu
// Time : 2015-02-26
// Problem1 : Ô¼·ÖÊý
// Debug : VC6.0

#include <stdio.h>

int main()
{
    int num1, num2, i;
    int yue = 0;
    freopen("sample1.in", "r", stdin);

    while(scanf("%d %d", &num1, &num2) != EOF)
    {
        for(i = num1; i >= 2; i--)
        {
            if((num1 % i == 0) && (num2 % i == 0) )
            {
                num1 /= i;
                num2 /= i;
            }
            else if(num2 % num1 == 0)
            {
                num2 /= num1;
                num1 = 1;
            }
        }

        printf("%d %d\n", num1, num2);
    }

    return 0;
}