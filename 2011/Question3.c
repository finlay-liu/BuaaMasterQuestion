#include <stdio.h>
#include <string.h>

int main()
{
	int i, j;
	char input[100],start,end;
	scanf("%s",input);

	for(i = 0;i < strlen(input);i++)
	{
		if(input[i] == '-')
		{
			start = input[i - 1];
			end = input[i + 1];

			if( (start >= 'a' && start <= 'z' && end >= 'a' && end <= 'z')
				|| (start >= 'A' && start <= 'Z' && end >= 'A' && end <= 'Z')
				|| (start >= '0' && start <= '9' && end >= '0' && end <= '9') )
				for(j = start + 1;j < end;j++)
					printf("%c",j);
			else
				printf("-");

		}
		else
			printf("%c",input[i]);
	}

	printf("\n");
	return 0;
}