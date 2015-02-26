// Author : FinlayLiu
// Time : 2015-02-26 
// Problem2：五子棋获胜判断
//        判断五子连珠，输出序号
// Todo : 使用结构体
// Debug : Linux,gcc 

#include <stdio.h>

int TestDisk(int i,int j,int index,int num);
int TestPoint(int i,int j);

int map[19][19];        // 棋盘

int main()
{
    freopen("sample2.in", "r", stdin);
    
    int i,j,num;
    i = 0;
    j = 0;
    
    // 读取棋盘
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
            
            int index;
            for(index = 1; index <= 8;index++)
            {
                if(TestDisk(i,j,index,map[i][j]))       // 是五子连珠点
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

// 检查是否五子连珠
// i,j 珠子坐标     index 方向    num 棋子颜色
int TestDisk(int i,int j,int index,int num)
{
    int tmpi,tmpj;  // 检测珠子的位置
    int tmpn;       // 检测珠子的颜色
    int step = 1;   // 珠子连色步数
    
    tmpi = i;
    tmpj = j;
    
    if(index == 1)  // 方向←
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
    else if(index == 2) // 方向←↑
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
    else if(index == 3) // 方向↑
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
    else if(index == 4) // 方向→↑
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

// 检测坐标是否合法
int TestPoint(int i,int j)
{
    if(i < 0 || i > 18 || j < 0 || j > 18)
        return 0;
    else
        return 1; 
}
