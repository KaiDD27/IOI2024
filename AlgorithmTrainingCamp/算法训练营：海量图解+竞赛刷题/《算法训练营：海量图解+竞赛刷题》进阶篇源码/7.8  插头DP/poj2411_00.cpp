#include<cstdio>//预处理669ms,不预处理1235ms
#include<cstring>
#include<algorithm>
using namespace std;
int N,M;
long long dp[12][1<<11];//长方形的上面一半为1，其它情况为0 
bool flag[1<<11];
 
void init(){//预处理 
	for(int i=0;i<(1<<M);i++){//连续0的个数必须为偶数 
		bool cnt=0;
		for(int j=0;j<M;j++)
			if(i>>j&1){
				if(cnt)
					break;
				cnt=0;
			}
			else
				cnt^=1;
		flag[i]=cnt?0:1;
	}
} 

void solve(){
	memset(dp,0,sizeof(dp));
	dp[0][0]=1; 
	for(int i=1;i<=N;i++)
		for(int j=0;j<(1<<M);j++)
			for(int k=0;k<(1<<M);k++)
	            if((j&k)==0&&flag[j|k])
	            	dp[i][j]+=dp[i-1][k];
}
	

int main(){
	while(~scanf("%d%d",&N,&M),N+M){
		init();
		solve();
		printf("%lld\n",dp[N][0]);
	}
	return 0;
}
