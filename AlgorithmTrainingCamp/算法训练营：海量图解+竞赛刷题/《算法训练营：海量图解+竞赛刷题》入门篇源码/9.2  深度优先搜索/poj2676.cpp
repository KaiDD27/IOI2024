#include<iostream>
#include<cstring>
using namespace std;
int map[10][10];
bool row[10][10];//row[i][x]标记在第i行中数字x是否已出现 
bool col[10][10];//col[j][y]标记在第j列中数字y是否已出现
bool grid[10][10];//grid[k][z]标记在第k个3*3子格中数字z是否已出现

bool dfs(int i,int j){
	if(i==10)
		return 1;
	bool flag=0;
	if(map[i][j]){
		if(j==9)
			flag=dfs(i+1,1);
		else
			flag=dfs(i,j+1);
		return flag?1:0;
	}
	else{
		int k=3*((i-1)/3)+(j-1)/3+1;
		for(int x=1;x<=9;x++){//枚举数字1~9填空
			if(!row[i][x]&&!col[j][x]&&!grid[k][x]){
				map[i][j]=x;
				row[i][x]=1;
				col[j][x]=1;
				grid[k][x]=1;
				if(j==9)
					flag=dfs(i+1,1);
				else
					flag=dfs(i,j+1);
				if(!flag){ //回溯，继续枚举
					map[i][j]=0;
					row[i][x]=0;
					col[j][x]=0;
					grid[k][x]=0;
				}
				else
					return 1;
			}
		} 
	}
	return 0;
}

void init(){
	memset(row,false,sizeof(row));
	memset(col,false,sizeof(col));
	memset(grid,false,sizeof(grid));
	char ch;
	for(int i=1;i<=9;i++)
		for(int j=1;j<=9;j++){
			cin>>ch;
			map[i][j]=ch-'0';
			if(map[i][j]){
				int k=3*((i-1)/3)+(j-1)/3+1;
				row[i][map[i][j]]=1;
				col[j][map[i][j]]=1;
				grid[k][map[i][j]]=1;
			}
		}
}

int main(){
	int T;
	cin>>T;
	while(T--){
		init();
		dfs(1,1);
		for(int i=1;i<=9;i++){
			for(int j=1;j<=9;j++)
				cout<<map[i][j];
			cout<<endl;
		}
	}
	return 0;
}
