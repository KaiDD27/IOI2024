#include<cstdio>
#include<cstring>
#include<algorithm>
#define maxn 105
using namespace std;
int a[maxn][maxn],dp[maxn];
int n,m;

int main(){
    while(~scanf("%d%d",&n,&m)){
        if(n==0&&m==0) break;
        memset(dp,0,sizeof(dp));
        for(int i=1;i<=n;i++)
            for(int j=1;j<=m;j++)
				scanf("%d",&a[i][j]);
        for(int i=1;i<=n;i++)
            for(int j=m;j>=0;j--)
                for(int k=1;k<=j;k++)//用来枚举分组内的天数 
                    dp[j]=max(dp[j],dp[j-k]+a[i][k]);
        printf("%d\n",dp[m]);
    }
    return 0;
}
