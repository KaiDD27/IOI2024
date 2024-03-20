//求走过所有点并回到原点的最短路,可以走一个点多次.
//因为可以走一个点多次，所以，可以先求出每两个点之间的最短路，然后用经典的旅行商问题的状态压缩DP做法。
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
#define M 15
#define INF 0x3f3f3f3f
int n;
int g[M][M];
int dp[1<<11][M];

void Init(){
    memset(dp,-1,sizeof(dp));
    memset(g,0x3f,sizeof(g));
}

void floyd(){
    for(int k=0;k<n;k++)
        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++)
                g[i][j]=min(g[i][j],g[i][k]+g[k][j]);
}

int Tsp(int S,int u){//计算dp[S][u],记忆化递归 
	if(dp[S][u]>=0)
    	return dp[S][u];
	if(S==(1<<n)-1&&u==0)//递归结束条件
		return dp[S][u]=0;
    int ans=INF;
	for(int v=0;v<n;v++)
		if(!(S>>v&1)&&g[u][v]!=INF)
			ans=min(ans,Tsp(S|1<<v,v)+g[u][v]);
    return dp[S][u]=ans;
}

int main(){
    while(~scanf("%d",&n),n){
        n++;
		Init();
        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++)
                scanf("%d",&g[i][j]);
        floyd();
        printf("%d\n",Tsp(0,0));
    }
    return 0;
}
