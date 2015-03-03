#include <stdio.h>

int main()
{
	double num0 = 0, num1 = 0, num2 =0;
	int n, i;

	while(scanf("%lf%d",&num0,&n) != EOF)
	{
		i = 0;
		
		num1 = num0;
		while(i < n)
		{
			num2 = num1 *(2 / 3.0) + num0 / (3 * num1 *num1);
			num1 = num2;
			i++;
		}
		printf("%0.6f\n",num2);
	}
	return 0;
}