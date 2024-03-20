#include<cstdio>//不预处理1235ms,预处理669ms
#include<cstring>
#include<algorithm>
using namespace std;
int N,M;
long long dp[12][1<<11];//长方形的上面一半为1，其它情况为0 
 
bool check(int x){//检测连续0的个数为偶数 
    int cnt=0;
    for(int i=0;i<M;i++)
		if(x>>i&1){
			if(cnt&1)//奇数
				return 0;  
	        cnt=0;
		}
		else 
			cnt++;
    if(cnt&1)  
		return 0;
	return 1;     
}

void solve(){
	memset(dp,0,sizeof(dp));
	dp[0][0]=1; 
	for(int i=1;i<=N;i++)
		for(int j=0;j<(1<<M);j++)
			for(int k=0;k<(1<<M);k++)
	            if((j&k)==0&&check(j|k))
	            	dp[i][j]+=dp[i-1][k];
}
	

int main(){
	while(~scanf("%d%d",&N,&M),N+M){
		solve();
		printf("%lld\n",dp[N][0]);//注意数据类型，不要写d%!
	}
	return 0;
}
