// Author : FinlayLiu
// Time : 2015-03-02
// Problem2
// Debug : VC6.0

#include <stdio.h>
#include <stdlib.h>

int main(){
	int N;	//矩阵维数
	int island[100][100];	//输入岛数据的方阵
	int data[100][4];
	int area = 0;

	freopen("simple2.in", "r", stdin);
	while(scanf("%d",&N) != EOF){
		int i,j;
		//初始化
		memset(data,-1,100*4*sizeof(int));
		//读入数据
		for(i=0;i<N;i++){
			for(j=0;j<N;j++){
				scanf("%d",&island[i][j]);
			}
		}

		for(i=0;i<N;i++){
			for(j=0;j<N;j++){

				if(island[i][j] == 1){	//小岛边界

					if(data[i][0] == -1){
						data[i][0] = j;
					}
					if(data[j][2] == -1){
						data[j][2] = i;
					}
					data[i][1] = j;
					data[j][3] = i;
				}
			}
		}

		for(i=0;i<N;i++){
			for(j=0;j<N;j++){
				if(island[i][j] == 0){	//小岛边界
					if(i > data[j][2] && i < data[j][3] && j > data[i][0] && j < data[i][1]){
						area++;
						//printf("i=%d,j=%d\n",i,j); for debug
					}
				}
			}
		}
		printf("%d\n",area);
	}
	return 0;
}
