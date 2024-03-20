#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
using namespace std;
const int N=1500+10;
int val[N],dp[N][2],fa[N],n;
vector<int>E[N];

void dfs(int u){
	dp[u][0]=0;
	dp[u][1]=1;
	for(int i=0;i<E[u].size();i++){
		int v=E[u][i];
		dfs(v);
		dp[u][1]+=min(dp[v][1],dp[v][0]);
		dp[u][0]+=dp[v][1];
	}
}

int main(){
	while(~scanf("%d",&n)){
		for(int i=0;i<n;i++)//编号从0开始 
			E[i].clear();
		memset(fa,-1,sizeof(fa));
		memset(dp,0,sizeof(dp));
		for(int i=0;i<n;i++){
			int a,b,m;
			scanf("%d:(%d)",&a,&m);
	        while(m--)
	        {
	        	scanf("%d",&b);
	        	E[a].push_back(b);
	        	fa[b]=a;
			}
		}
	    int rt=0;//编号从0开始
	    while(fa[rt]!=-1) rt=fa[rt];
	    dfs(rt);
	    printf("%d\n",min(dp[rt][1],dp[rt][0]));
    }
    return 0;
}
