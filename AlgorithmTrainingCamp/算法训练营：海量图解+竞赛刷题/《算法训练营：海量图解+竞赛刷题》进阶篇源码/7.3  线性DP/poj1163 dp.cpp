#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int maxn=105;
int dp[maxn][maxn];
int a[maxn][maxn];

int main(){
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
		for(int j=1;j<=i;j++)
            scanf("%d",&a[i][j]);
    memset(dp,0,sizeof(dp));
    dp[1][1]=a[1][1];
    for(int i=2;i<=n;i++)
        for(int j=1;j<=i;j++)
            dp[i][j]=a[i][j]+max(dp[i-1][j],dp[i-1][j-1]);
    int ans=0;
    for(int j=1;j<=n;j++)
        ans=max(dp[n][j],ans);
    printf("%d\n", ans);
    return 0;
}
