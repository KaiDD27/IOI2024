#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int N=21;
int dp[2][1<<N],n,v;

void solve(){
	memset(dp,0,sizeof(dp));
    int pre=0,now=1;
    dp[pre][0]=0;
    int ans=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
        	scanf("%d",&v);
            for(int S=0;S<(1<<n);S++){//轮廓线状态 
            	int newS=S&(~(1<<j));
				dp[now][newS]=max(dp[now][newS],dp[pre][S]);
                if((S&(1<<j))==0&&(j==0||(S&(1<<(j-1)))==0))//上面和左均为0，可以取数 
                    dp[now][S|(1<<j)]=max(dp[now][S|(1<<j)],dp[pre][S]+v);
            }
            swap(pre,now);
        }
    }
    for(int S=0;S<(1<<n);S++)
        ans=max(ans,dp[pre][S]);
    printf("%d\n",ans);
}

int main(){
    while(~scanf("%d",&n)){
        solve();
    }
    return 0;
}
