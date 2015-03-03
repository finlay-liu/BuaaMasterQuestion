#include <stdio.h>
#include <string.h>
int main()
{
	int wlength,llength,i,j,yes,tmp;
	char word[100];
	char line[300];
	scanf("%s",&word);
	
	freopen("filein.txt","r",stdin);
	freopen("fileout.txt","w",stdout);

	while(fgets(line,300,stdin))
	{
		llength = strlen(line);

		while(line[0] == ' ' || line[0] == '\t' )
		{
			for(j = 1; j < llength; j++)
				line[j - 1] = line[j];
			llength--;
		}

		i = 0;
		wlength = strlen(word);
		tmp = -1;
		for(i = 0;i < llength;i++)
		{
			yes = 0;
			for(j = 0; j < wlength;j++)
			{
				if(i + j > llength)
					break;

				if(line[i + j] == tolower(word[j]) || line[i + j] == toupper(word[j]))
					yes++;
				else
					break;
			}

			if(yes == wlength)
			{
				i = i + wlength - 1;
				if(line[i + 1] ==' ')
					i++;
			}
			else
			{
				printf("%c",line[i]);
			}
		}
	}

	fclose(stdin);
	fclose(stdout);
	return 0;
}