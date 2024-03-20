#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int INF=0x3f3f3f3f;
const int N=1005;
int n;
int dp[N<<1][N<<1];
int s[N<<1][N<<1];
int sum[N<<1];
int a[N<<1];
 
void init(){
    sum[0]=0;
    for(int i=1;i<=n;i++){
        scanf("%d",a+i);
        sum[i]=a[i]+sum[i-1];
        dp[i][i]=0;
        s[i][i]=i;
    }
    for(int i=1;i<n;i++){
        a[n+i]=a[i];
        sum[n+i]=a[n+i]+sum[n+i-1];
        dp[n+i][n+i]=0;
        s[n+i][n+i]=n+i;
    }
}
 
void solve(){
    for(int d=2;d<=n;d++){
        for(int i=1;i<=2*n-d;i++){
            int j=i+d-1; 
            int tmp=sum[j]-sum[i-1];
            dp[i][j]=INF;
            for(int k=s[i][j-1];k<=s[i+1][j];k++)
            	if(dp[i][k]+dp[k+1][j]+tmp<dp[i][j]){
            		dp[i][j]=dp[i][k]+dp[k+1][j]+tmp;
            		s[i][j]=k;
				}                
        }
    }
    int ans=INF;
    for(int i=1;i<=n;i++)
        ans=min(ans,dp[i][n+i-1]);
    printf("%d\n",ans);
}
 
int main(){
    while(~scanf("%d",&n)){
        init();
        solve();
    }
    return 0;
}
