#include <stdio.h>

int main()
{
	int n, i, j, k, flag, out;
	int map[500][500];
	//freopen("sample.txt", "r", stdin);
	scanf("%d", &n);
	memset(map, -1, 500 * 500);
	out = 0;
	for(i = 0;i < n;i++)
		for(j = 0;j < n;j++)
			scanf("%d", &map[i][j]);

	for(i = 0;i < n;i++)
	{
		for(j = 0;j < n;j++)
		{
			if(i == 0 || i == n - 1 || j == 0 || j == n - 1)
				continue;

			if(map[i][j] == 1)
				continue;

			flag = 0;
			for(k = j - 1; k >= 0; k--)
			{
				if(map[i][k] == 1)
				{
					flag++;
					break;
				}
			}

			for(k = j + 1; k < n; k++)
			{
				if(map[i][k] == 1)
				{
					flag++;
					break;
				}
			}

			for(k = i - 1; k >= 0; k--)
			{
				if(map[k][j] == 1)
				{
					flag++;
					break;
				}
			}

			for(k = i + 1; k < n; k++)
			{
				if(map[k][j] == 1)
				{
					flag++;
					break;
				}
			}

			if(flag == 4)
				out++;
		}
	}
	printf("%d\n", out);
	//fclose(stdin);
    return 0;
}