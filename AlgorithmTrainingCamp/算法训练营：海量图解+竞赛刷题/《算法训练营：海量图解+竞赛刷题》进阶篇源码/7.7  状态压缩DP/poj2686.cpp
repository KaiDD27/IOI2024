#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const double INF=0x3f3f3f3f;
double ans;
int n,m,p,a,b;
int t[20];
int dis[50][50];
double dp[1<<10][32];//dp[s][u]表示到达当前u点（持有s的车票）的最小花费 

void solve(){
	//memset(dp,0x3f,sizeof(dp));//整型数赋值,不可以 
    for(int i=0;i<(1<<(n+1));i++)
    	fill(dp[i],dp[i]+m+1,INF);
//	for(int i=0;i<(1<<(n+1));i++)
//		for(int j=0;j<=m+1;j++)
//			dp[i][j]=INF;
    dp[(1<<n)-1][a]=0;//起点 
    ans=INF;
    for(int S=(1<<n)-1;S>=0;S--)//状态 
    {
		for(int u=1;u<=m;u++)//城市 
			for(int i=0;i<n;i++)//车票
            	if((S>>i)&1)
            		for(int v=1;v<=m;v++)//城市 
		                if(dis[u][v]>=0)
		                    dp[S&~(1<<i)][v]=min(dp[S&~(1<<i)][v],dp[S][u]+dis[u][v]/(double)t[i]);
		ans=min(ans,dp[S][b]);
	}        
}

int main()
{
    while(~scanf("%d%d%d%d%d",&n,&m,&p,&a,&b))
    {
        if(n+m+p+a+b==0) break;
        for(int i=0;i<n;i++)
			scanf("%d",&t[i]);
        memset(dis,-1,sizeof(dis));
        for(int i=0;i<p;i++)
        {
            int u,v,w;
            scanf("%d%d%d",&u,&v,&w);
            dis[u][v]=dis[v][u]=w;
        }
        solve(); 
        if(ans==INF)
            printf("Impossible\n");
        else
            printf("%.3f\n",ans);
    }
    return 0;
}
