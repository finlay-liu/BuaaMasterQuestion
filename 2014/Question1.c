// Author : FinlayLiu
// Time : 2015-02-26
// Problem1 : Êý×Ö¼ì²â
// Debug : VC6.0

#include <stdio.h>

int jiecheng(int n);

int main()
{
    int num, wei[10];
    int tmp;
    int count = 0;
    int index = 0;
	int i;

    scanf("%d", &num);
	tmp = num;
    while(num)
    {
        wei[index] = num % 10;
        num /= 10;
        index++;
    }
    printf("%d,", tmp);

    for(i = index - 1; i >= 0; i--)
    {
        count += jiecheng(wei[i]);
        if(i > 0)
            printf("%d!+", wei[i]);
        else
            printf("%d!=%d\n", wei[i], count);
    }

    if(count == tmp)
        printf("Yes\n");
    else
        printf("No\n");

    //fclose(stdin);
	system("pause");
    return 0;
}

int jiecheng(int n)
{
    if(n < 1)
        return 1;
    else
    {
        int i, m = 1;
        for(i = 1; i <= n; i++)
        {
            m *= i;
        }
        return m;
    }
}
