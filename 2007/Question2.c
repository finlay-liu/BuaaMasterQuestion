#include <stdio.h>
#include <string.h>

int main()
{
	int l1, l2, i, j, k;
	char line1[100],line2[100],out[200];
	scanf("%s",&line1);
	scanf("%s",&line2);
	
	l1 = strlen(line1);
	l2 = strlen(line2);

	i = 0;
	j = 0;
	k = 0;
	while(i < l1 || j < l2)
	{
		if(i == l1 && j < l2)
		{
			for(;j < l2;j++,k++)
			{
				out[k] = line2[j];
			}
		}
		else if(i < l1 && j == l2)
		{
			for(;i < l1;i++,k++)
			{
				out[k] = line1[i];
			}
		}

		if(line1[i] < line2[j])
		{
			out[k] = line1[i];
			i++;
			k++;
		}
		else if(line1[i] > line2[j])
		{
			out[k] = line2[j];
			j++;
			k++;
		}
		else
		{
			out[k] = line1[i];
			i++;
			j++;
			k++;
		}		
	}

	for(i = 0;i < k;i++)
		printf("%c",out[i]);
	printf("\n");
	return 0;
}