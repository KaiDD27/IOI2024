#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int M=200+10;
int n,k,cnt;
//dp[u][j][0]表示以u为根的树经过j步没有回到点u得到的最值
//dp[u][j][1]表示以u为根的树经过j步回到点u得到的最值 
int dp[M][M][2],val[M],head[M];
 
struct edge{
	int v,next;
}e[M<<1];
 
void init(){
	memset(head,-1,sizeof(head));
	memset(dp,0,sizeof(dp));
	cnt=0;
}
 
void add(int u,int v){
	e[cnt].v=v;
	e[cnt].next=head[u];
	head[u]=cnt++;
}
 
void dfs(int u,int fa){
	for(int i=0;i<=k;i++)
		dp[u][i][0]=dp[u][i][1]=val[u];
	for(int i=head[u];~i;i=e[i].next){
		int v=e[i].v;
		if(v==fa) continue;
		dfs(v,u);
		for(int j=k;j>=1;j--){//树形背包 
			for(int t=1;t<=j;t++){
				dp[u][j][0]=max(dp[u][j][0],dp[u][j-t][1]+dp[v][t-1][0]);
				if(t>=2) dp[u][j][0]=max(dp[u][j][0],dp[u][j-t][0]+dp[v][t-2][1]);
				if(t>=2) dp[u][j][1]=max(dp[u][j][1],dp[u][j-t][1]+dp[v][t-2][1]);
			}
		}
	}
}
 
int main(){
	int u,v;
	while(~scanf("%d%d",&n,&k)){
		init();
		for(int i=1;i<=n;++i)
			scanf("%d",&val[i]);
		for(int i=1;i<n;++i){
			scanf("%d%d",&u,&v);
			add(u,v);
			add(v,u);
		}
		dfs(1,-1);
		printf("%d\n",max(dp[1][k][0],dp[1][k][1]));
	}
	return 0;
}
