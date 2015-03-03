#include <stdio.h>

double pow(double num,int n)
{
	int i;
	double sum = 1;
	for(i = 1;i <= n;i++)
		sum *= num;

	return sum;
}
int main()
{
	int i, j;
	double input = 0,sum = 0,jie[200];

	jie[1] = 1;
	for(i = 2;i < 200;i++)
		jie[i] = i * jie[i - 1];

	scanf("%lf",&input);

	sum += 1;
	j = -1;
	for(i = 2;i < 200;i += 2)
	{
		sum += j * pow(input,i) / jie[i];
		j *= -1;
	}

	printf("%f\n",sum);
	return 0;
}