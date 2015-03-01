// Author : FinlayLiu
// Time : 2015-02-27 
// Problem3: �Ű梘
// Debug : VC6.0

#include <stdio.h>
#include <string.h>

int main()
{    
	int i,n;
	int works,worke,names,namee;
	char line[200];
    freopen("sample3.in", "r", stdin);
    
	scanf("%d\n",&n);

    while( fgets(line,200,stdin) )
    {
		works = worke = names = namee = -1;

		for(i = 0;i < strlen(line); i++)
		{
			if(works == -1 && line[i] != ' ')
				works = i;
			else if(worke == -1 && line[i] == ' ' && works != -1 && names == -1)
				worke = i;
			else if(names == -1 && line[i] != ' ' && line[i] != ':' && namee == -1 && worke != -1)
				names = i;
			else if(namee == -1 && (line[i] == ' ' || line[i]== '\n' ) && names != -1)
				namee = i;
		}

		for(i = works;i < worke; i++)
			printf("%c",line[i]);
		for(i = 0;i < n-worke+works+1;i++)
			printf(" ");
		printf(": ");
		for(i = names;i < namee; i++)
			printf("%c",line[i]);
		printf("\n");
    } 
    
    fclose(stdin);
    return 0;
}