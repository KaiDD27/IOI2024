#include<cstdio>//普通DP 超时 
#include<cstring>
using namespace std; 
const int inf=0x3f3f3f3f;
const int maxL=1000000+5;
int n,L,a,b,s,e,dp[maxL];
  
void solve(){ 
    dp[0]=0;
    for(int i=2;i<=L;i+=2){
    	if(dp[i]<=inf){//非障碍 
			int min=inf;
			for(int k=a;k<=b;k++){//求区间[i-2*b,i-2*a]的dp最小值
                int j=i-2*k;  
                if(j<0) break;
                if(min>dp[j])
					min=dp[j];
			}
			dp[i]=min+1;
		}
    }
}  
  
int main(){
	while(~scanf("%d%d",&n,&L)){   
		scanf("%d%d",&a,&b);
		memset(dp,0x3f,sizeof(dp));
		for(int i=0;i<n;i++){ 
            scanf("%d%d",&s,&e);  
            for(int j=s+1;j<e;j++)//预处理，[s,e]区间不允许被分割 
				dp[j]=inf+1;
		}
		solve(); 
		if(dp[L]>=inf) printf("-1\n");
		else printf("%d",dp[L]);
    }  
    return 0;  
}
