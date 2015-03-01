// Author : FinlayLiu
// Time : 2015-02-27
// Problem3 : 科学计数法
// Debug : VC6.0
#include <stdio.h>

int main()
{
	int i;
	double min = 0.00000000001;
	double num;
	freopen("sample3.in", "r", stdin);

	while(scanf("%lf\n",&num) != EOF)
	{
		i = 0;
		while(num - (int)num > min)
		{
			num *= 10;
			i++;
		}
		printf("%lf\n",num);
	}

	fclose(stdin);
	return 0;
}
