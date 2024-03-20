#include<cstdio> 
#include<cstring>
#include<vector>
#include<algorithm>
using namespace std;
const int maxn=10000+5;
int n;
vector<int> E[maxn];
int dp[maxn][3];

void dfs(int u,int fa){
    dp[u][0]=1; //加上自身为服务器
    dp[u][1]=0;
    dp[u][2]=maxn;
    int k=E[u].size();
    if(k==1&&fa!=0)  return; //树的叶子节点
    for(int i=0;i<k;i++){
        int v=E[u][i];
        if(v==fa) continue;
        dfs(v,u);
        dp[u][0]+=min(dp[v][0],dp[v][1]);
        dp[u][1]+=dp[v][2];
    }
    for(int i=0;i<k;i++){
        int v=E[u][i];
        if(v==fa)  continue;
        dp[u][2]=min(dp[u][2],dp[u][1]-dp[v][2]+dp[v][0]);
    }
}

int main(){
    int u,v;
    while(~scanf("%d",&n)){
        for(int i=1;i<=n;i++)
            E[i].clear();
        for(int i=1;i<n;i++){
            scanf("%d%d",&u,&v);
            E[u].push_back(v);
            E[v].push_back(u);
        }
        dfs(1,0);
		printf("%d\n",min(dp[1][0],dp[1][2]));    
        scanf("%d",&u);
        if(u==-1)  break;
    }
    return 0;
}
