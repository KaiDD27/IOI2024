#include<bits/stdc++.h>
#define REP(i,b,e) for(int i=(b);i<=(e);i++)
using namespace std;
const int maxn=100+5;
string str[maxn];//存储字符矩阵 
int m,n,setid[maxn][maxn];//行列，连通分量号 

void dfs(int x,int y,int id){//行列和连通分量号
	if(x<0||x>=m||y<0||y>=n) return ;//出界
	if(setid[x][y]>0||str[x][y]!='@') return ;//已有连通分量号或不是'@' 
	setid[x][y]=id;
	REP(dx,-1,1)
		REP(dy,-1,1)
			if(dx!=0||dy!=0)
				dfs(x+dx,y+dy,id);//八个方向深搜 
 }
 
int main(){
 	while((cin>>m>>n)&&m&&n){
 		REP(i,0,m-1)
 			cin>>str[i];
 		memset(setid,0,sizeof(setid));
 		int cnt=0;
 		REP(i,0,m-1)
 			REP(j,0,n-1)
 				if(setid[i][j]==0&&str[i][j]=='@')
 					dfs(i,j,++cnt);
 		cout<<cnt<<endl;
	}
	return 0;
} 
