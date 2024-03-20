#include<cstdio>//子树size优化,31ms,未优化234ms 
#include<cstring>
#include<algorithm>
#include<vector>
using namespace std;
const int N=200+10;
int val[N],dp[N][N];
vector<int>E[N];

int dfs(int u,int M){//返回u为根的子树的大小 
	dp[u][1]=val[u];
	int sizeu=1,sizev=0;//u、v为根的子树大小 
	for(int i=0;i<E[u].size();i++){
		int v=E[u][i];
		sizev=dfs(v,M-1);
		for(int j=M;j>=1;j--)//类似分组背包倒推 
			for(int k=1;k<=sizev&&k<j;k++)
				dp[u][j]=max(dp[u][j],dp[v][k]+dp[u][j-k]);
		sizeu+=sizev;
	}
	return sizeu;
}

int main(){
	int N,M;
	while(~scanf("%d%d",&N,&M),N+M){//N+M为0时，结束 
		for(int i=0;i<=N;i++)
			E[i].clear();
		memset(dp,0,sizeof(dp));
		M++;//增加超根后，M+1 
		val[0]=0;
		int u;
		for(int i=1;i<=N;i++){
			scanf("%d%d",&u,&val[i]);
			E[u].push_back(i);
		}
	    dfs(0,M);
	    printf("%d\n",dp[0][M]);
    }
    return 0;
}
