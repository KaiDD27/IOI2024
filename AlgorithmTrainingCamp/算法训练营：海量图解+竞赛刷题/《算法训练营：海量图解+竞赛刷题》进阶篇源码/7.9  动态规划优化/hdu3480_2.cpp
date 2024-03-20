#include<cstdio>
#include<algorithm>
using namespace std;
const int MAX=10000+10;
const int INF=0x3f3f3f3f;
int n,m;
int a[MAX];
int s[MAX][MAX],dp[MAX][MAX];

void solve(){
    for(int i=1;i<=n;i++){
        dp[i][1]=(a[i]-a[1])*(a[i]-a[1]);
        s[i][1]=1;
    }
    for(int j=2;j<=m;j++){
        dp[j][j]=0;
        s[n+1][j]=n;
        for(int i=n;i>j;i--){//逆序求解，因为要先得到s[i][j-1]~s[i+1][j]
            dp[i][j]=INF;
            for(int k=s[i][j-1];k<=s[i+1][j];k++){
                if(dp[i][j]>dp[k][j-1]+(a[i]-a[k+1])*(a[i]-a[k+1])){
                    dp[i][j]=dp[k][j-1]+(a[i]-a[k+1])*(a[i]-a[k+1]);
                    s[i][j]=k;
                }
            }
        }
    }
}

int main(){
	int t,num=0;
	scanf("%d",&t);
	while(t--){
		scanf("%d%d",&n,&m);
		for(int i=1;i<=n;i++)
			scanf("%d",a+i);
		sort(a+1,a+1+n);
		solve();
		printf("Case %d: %d\n",++num,dp[n][m]);
	}
	return 0;
}
