#include<cstdio>
#include<cstring>
#include<algorithm>
const int INF=0x3f3f3f3f;
using namespace std;
int n,m,ans;
int tri[12]={0,1,3,9,27,81,243,729,2187,6561,19683,59049};//三进制每位为1时对应十进制，如第3位是1，(100)3=9 
int dig[60000][11];//dig[S][j]状态S的第j位是多少
int edge[11][11],dp[60000][11];//3^10=59050
 
void init(){
	for(int i=0;i<59050;i++){//预处理状态S的第j位
       int t=i;
       for(int j=1;j<=10;++j){//将i状态转换为3进制，记录每一位
           dig[i][j]=t%3;
           t/=3;
           if(t==0) break;
       }
   }
}

void solve(){
	memset(dp,0x3f,sizeof(dp));
	for(int i=1;i<=n;i++)
		dp[tri[i]][i]=0;//初始化状态为tri[i]时，从i出发最小费用为0
	ans=INF;
	for(int S=0;S<tri[n+1];S++){
		bool visit_all=1;//标记所有的城市都遍历1次以上 
		for(int u=1;u<=n;u++){
			if(dig[S][u]==0){//u点没被访问 
				visit_all=0;
				continue;
			}
			for(int v=1;v<=n;v++){
				if(dig[S][v]==0) continue;//v点未访问，减法，状态不会超过2次 
				dp[S][u]=min(dp[S][u],dp[S-tri[u]][v]+edge[u][v]);//u从S中减去 
			}
		}
		if(visit_all){//所有的城市都遍历1次以上
			for(int u=1;u<=n;u++)
				ans=min(ans,dp[S][u]);
		}
	}
}

int main(){
	init();
	while(~scanf("%d%d",&n,&m)){
		memset(edge,0x3f,sizeof(edge));
		int a,b,c;
		while(m--){
			scanf("%d%d%d",&a,&b,&c);
 			edge[a][b]=edge[b][a]=min(edge[a][b],c);
		} 
		solve();
		if(ans==INF)
			ans=-1;
		printf("%d\n",ans);
	}
	return 0;
}
