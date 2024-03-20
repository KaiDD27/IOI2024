#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int MAX=100+5;
int dp[MAX][MAX],p[MAX];

int solve(int n){
    for(int d=2;d<=n;d++){
        for(int i=1;i<=n-d+1;i++){
            int j=i+d-1;
            dp[i][j]=dp[i+1][j]+p[i-1]*p[i]*p[j];
            for(int k=i+1;k<j;k++)
                dp[i][j]=min(dp[i][j],dp[i][k]+dp[k+1][j]+p[i-1]*p[k]*p[j]);
        }
    }
    return dp[1][n];
}

int main(){
    int n; 
	scanf("%d",&n);
    memset(dp,0,sizeof(dp));
    for(int i=0;i<n;i++)
        scanf("%d",p+i);
    printf("%d\n",solve(n-1));//¾ØÕón-1¸ö 
    return 0;
}
