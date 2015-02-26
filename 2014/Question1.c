// Author : FinlayLiu
// Time : 2015-02-26 
// 题目1：数字阶乘判断
//        将数字的位按顺序阶乘相加

#include <stdio.h>

int jiecheng(int n);

int main()
{
	int num,wei[10];
	//freopen("sample.in", "r", stdin);
	// 测试文件 145 1400 等
	
	while(scanf("%d",&num) != EOF)
	{
	    int tmp = num;
		int count = 0;
		
		int index = 0;
		while(num)
		{
		    // 讲数字的位反序存储在数组中
		    wei[index] = num % 10;
		    num /= 10;
		    index++;
		}
		
		printf("%d,",tmp);
		
		int i;
		for(i = index - 1;i >= 0;i--)
		{
		    count += jiecheng(wei[i]);
		    if(i > 0)
		        printf("%d!+",wei[i]);
		    else
		        printf("%d!=%d\n",wei[i],count);
		}
		
		if(count == tmp)
		    printf("Yes\n");
		else
		    printf("No\n");
	}
	
	//fclose(stdin);
	return 0;
}

// 得到数字阶乘
int jiecheng(int n)
{
	if(n < 1)
		return 1;
	else
	{
		int i,m = 1;
		for(i = 1;i <= n;i++)
		{
			m *= i;
		}
		return m;
	}
}
