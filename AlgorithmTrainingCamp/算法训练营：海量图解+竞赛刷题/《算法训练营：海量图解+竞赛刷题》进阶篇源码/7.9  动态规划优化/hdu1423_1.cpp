#include<cstdio>
#include<cstring>
#define max(a,b) ((a)>(b)?(a):(b))
#define min(a,b) ((a)<(b)?(a):(b))
using namespace std;
const int maxn=505;
int n,m,T,ans;
int a[maxn],b[maxn],dp[maxn][maxn];

int solve(int *a,int n,int *b,int m){
	ans=0;
	memset(dp,0,sizeof(dp));
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
            if(a[i]!=b[j])
				dp[i][j]=dp[i-1][j];
            else{
                int mn=0;
                for(int k=1;k<j;k++)
                    if(b[k]<a[i])
                    	mn=max(mn,dp[i-1][k]);
                dp[i][j]=mn+1;
                ans=max(dp[i][j],ans);
            }
    return ans;
}

int main(){
    scanf("%d", &T);
    while(T--){
        scanf("%d",&n);
        for(int i=1;i<=n;i++)
            scanf("%d",&a[i]);
        scanf("%d",&m);
        for(int j=1;j<=m;j++)
            scanf("%d",&b[j]);
        printf("%d\n",solve(a,n,b,m));
        if(T) printf("\n");
    }
    return 0;
}
