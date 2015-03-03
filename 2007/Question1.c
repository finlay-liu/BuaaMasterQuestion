#include <stdio.h>
#include <stdlib.h>

int main()
{
	int space_count,enter_count,tab_count;
	space_count = enter_count=tab_count=0;

	char ch,buf[1024];
	ch=getchar();
	int i=0,j;
	while(ch!='\\')	//以"\"作为输入标志
	{
		buf[i]=ch;
		ch=getchar();
		i++;
	}
	buf[i]='\0';

	int length = strlen(buf);
	for(i=0;i<length;i++)
	{
		ch = buf[i];
		if(ch == ' ')
			space_count++;
		else if(ch == '\n')
			enter_count++;
		else if(ch == '\t')
			tab_count++;
	}

	printf("%d,%d,%d",space_count,enter_count,tab_count);
	return 0;
}
