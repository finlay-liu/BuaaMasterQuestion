// Author : FinlayLiu
// Time : 2015-02-27 
// Problem3：排版题
// Debug : Linux,gcc 
// Todo : 排版还有问题

#include <stdio.h>
#include <string.h>

int main()
{    
    int n;          // 冒号位置
    
    int bytes_read;
    int nbytes = 100;
    char *strs;
    
    scanf("%d\n",&n);    
    
    strs = (char *) malloc (nbytes + 1);
    
    while( getline(&strs, &nbytes, stdin) != -1)
    {
        if(*strs == '\n')       // 如果是空行
            break;
            
        char *token1=strtok(strs,":");
        char *token2=strtok(token1,":");
        
        printf("%s%d",token1,n);
        printf(" : %s\n",token2);
    } 

    return 0;
}
