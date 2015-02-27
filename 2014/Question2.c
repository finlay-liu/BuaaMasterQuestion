// Author : FinlayLiu
// Time : 2015-02-26 
// Problem2 : Îå×ÓÆå
// Debug : VC6.0

#include <stdio.h>

int TestDisk(int i,int j,int index,int num);
int TestPoint(int i,int j);

int map[19][19];        // ÆåÅÌ

int main()
{
	int i,j,num;
	int index;
    i = 0;
    j = 0;

    freopen("sample2.in", "r", stdin);
    
    while(scanf("%d",&num) != EOF)
    {
        map[i][j] = num;
        j++;
        if(j == 19)
        {
            j = 0;
            i++;
        }
    }
    
    for(i = 0;i < 19;i++)
    {
        for(j = 0;j < 19;j++)
        {
            if(map[i][j] == 0)
                continue;
            
            for(index = 1; index <= 8;index++)
            {
                if(TestDisk(i,j,index,map[i][j]))
                {
                    int tmpi,tmpj;
                    
                    if(index == 1)
                    {
                        tmpi = i;
                        tmpj = j - 4;
                        printf("%d:%d,%d \n",map[i][j],tmpi + 1,tmpj + 1);
                    }
                    else if(index == 2)
                    {
                        tmpi = i - 4;
                        tmpj = j - 4;
                        printf("%d:%d,%d \n",map[i][j],tmpi + 1,tmpj + 1);
                    }
                    else if(index == 3)
                    {
                        tmpi = i - 4;
                        tmpj = j;
                        printf("%d:%d,%d \n",map[i][j],tmpi + 1,tmpj + 1);
                    }  
                    else if(index == 4)
                    {
                        tmpi = i - 4;
                        tmpj = j + 4;
                        printf("%d:%d,%d \n",map[i][j],tmpi + 1,tmpj + 1);
                    }    
                    // printf("%d,%d,%d,Ok!\n",i+1,j+1,index);
                }
            }        
        }
    }
    
    fclose(stdin);
    return 0;
}

int TestDisk(int i,int j,int index,int num)
{
    int tmpi,tmpj,tmpn;
    int step = 1;
    
    tmpi = i;
    tmpj = j;
    
    if(index == 1)
    {
        while(step < 5)
        {
            tmpj--;
            
            if(!TestPoint(tmpi,tmpj))
                return 0;
            
            if(map[tmpi][tmpj] == 0 || map[tmpi][tmpj] != num)
                return 0;
             
            step++;
        }
        return 1;
    }
    else if(index == 2) 
    {
        while(step < 5)
        {
            tmpi--;
            tmpj--;
            
            if(!TestPoint(tmpi,tmpj))
                return 0;
            
            if(map[tmpi][tmpj] == 0 || map[tmpi][tmpj] != num)
                return 0;
             
            step++;
        }
        return 1;
    }
    else if(index == 3) 
	{
        while(step < 5)
        {
            tmpi--;
            
            if(!TestPoint(tmpi,tmpj))
                return 0;
            
            if(map[tmpi][tmpj] == 0 || map[tmpi][tmpj] != num)
                return 0;
             
            step++;
        }
        return 1;
    }
    else if(index == 4) 
    {
        while(step < 5)
        {
            tmpi--;
            tmpj++;
            
            if(!TestPoint(tmpi,tmpj))
                return 0;
            
            if(map[tmpi][tmpj] == 0 || map[tmpi][tmpj] != num)
                return 0;
             
            step++;
        }
        return 1;
    }
    return 0;
}

int TestPoint(int i,int j)
{
    if(i < 0 || i > 18 || j < 0 || j > 18)
        return 0;
    else
        return 1; 
}
