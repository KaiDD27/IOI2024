#include<cstdio>//单调队列优化DP 16ms
#include<cstring>
#include<algorithm>
using namespace std;
const int inf=0x3f3f3f3f;
const int maxL=1000000+5;
int n,L,a,b,s,e,dp[maxL],queue[maxL];
  
void solve(){
    dp[0]=0;
    int st=0,ed=0;
    for(int i=2*a;i<=L;i+=2){//单调递增队列:队首是当前dp最小的
        while((st<ed)&&(dp[queue[ed-1]]>=dp[i-2*a])) ed--;
		queue[ed++]=i-2*a;
		while((st<ed)&&(queue[st]<i-2*b)) st++;//i-2*b<=j<=i-2*a
		if(dp[i]<=inf) dp[i]=dp[queue[st]]+1;
    }
}

int main(){
	while(~scanf("%d%d",&n,&L)){   
		scanf("%d%d",&a,&b);
		memset(dp,0x3f,sizeof(dp));
		for(int i=0;i<n;i++){    
            scanf("%d%d",&s,&e);  
            for(int j=s+1;j<e;j++)//预处理，(s,e)区间不允许被分割 
				dp[j]=inf+1;
		}
		solve();
		if(dp[L]>=inf) printf("-1\n");
		else printf("%d",dp[L]);
    }  
    return 0;  
}
