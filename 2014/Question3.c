// Question3.c
// 2015-03-14
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
	int pos, len1, len2, i;
	char input[120];
	char *delim = ":", *ch1, *ch2;
	scanf("%d\n", &pos);
	while(fgets(input, 100, stdin))
	{
		ch1 = strtok(input, delim);
		ch2 = strtok(NULL, delim);
		len1 = strlen(ch1);
		len2 = strlen(ch2);

		printf("%s", ch1);
		for(i = 0;i < pos - len1 - 1;i++)
			printf(" ");
		printf(": %s", ch2);
	}
	return 0;
}