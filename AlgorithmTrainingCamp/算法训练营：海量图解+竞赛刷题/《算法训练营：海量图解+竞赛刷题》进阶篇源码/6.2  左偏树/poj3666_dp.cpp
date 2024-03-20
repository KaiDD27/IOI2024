#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int maxn=2010;
const int inf=0x3f3f3f3f;
int a[maxn],b[maxn];
int dp[maxn][maxn];//dp[i][j]表示前i个数变成b[j]时的最小代价

int main(){
	int n;
	while(~scanf("%d",&n)){
		for(int i=1;i<=n;++i)
			scanf("%d",&a[i]),b[i]=a[i];
		sort(b+1,b+n+1);
		memset(dp,0,sizeof(dp));
		for(int i=1;i<=n;i++){
			int tmp=dp[i-1][1];
			for(int j=1;j<=n;j++){
				tmp=min(tmp,dp[i-1][j]);
				dp[i][j]=tmp+abs(a[i]-b[j]);
			}
		}
		int ans=inf;
		for(int i=1;i<=n;i++)
			ans=min(ans,dp[n][i]);
		printf("%d\n",ans);
	}
	return 0;
}
