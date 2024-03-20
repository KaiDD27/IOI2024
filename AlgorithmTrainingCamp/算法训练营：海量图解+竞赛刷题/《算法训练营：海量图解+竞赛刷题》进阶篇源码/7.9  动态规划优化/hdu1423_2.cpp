#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int maxn=505;
int n,m,T,ans;
int a[maxn],b[maxn],dp[maxn][maxn];

int solve(int *a,int n,int *b,int m){
	ans=0;
	memset(dp,0,sizeof(dp));
	for(int i=1;i<=n;i++){
		int val=0;//记录决策集合S(i,j)中dp[i-1][k]的最大值
		for(int j=1;j<=m;j++){
			if(a[i]!=b[j])
				dp[i][j]=dp[i-1][j];
			else
				dp[i][j]=val+1;
			if(b[j]<a[i])//j满足条件，加入决策集合，更新最值 
				val=max(val,dp[i-1][j]);
			ans=max(dp[i][j],ans);
		}
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
            scanf("%d", &b[j]);
        printf("%d\n",solve(a,n,b,m));
        if(T) printf("\n");
    }
    return 0;
}
