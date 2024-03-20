#include<cstdio>
#include<cstring>
using namespace std;
#define mod 100000000
int m,n,top=0;
int state[600];
int dp[20][600];//dp[i][j]表示第i行，第j种编号时，前i行的可行方案数 
int cur[20];

bool check(int x){//判断编号x的二进制数是否有相邻的1，有则返回0
   if(x&x<<1) return 0;
   return 1;
}

bool fit(int x,int k){//判断编号x的种植情况是否与土地的肥沃匹配 
   if(x&cur[k]) return 0;
   return 1;
}

void init(){//记录所有没有相邻1的编号 
   top=0;
   for(int i=0;i<1<<n;i++)//n个格子，2^n种情况 
       if(check(i)) state[++top]=i;
}

void solve(){
	for(int j=1;j<=top;j++)//处理第一行 
		if(fit(state[j],1))
			dp[1][j]=1;
	for(int i=2;i<=m;i++)
		for(int j=1;j<=top;j++){//state[j]是i行的状态
			if(!fit(state[j],i)) continue;
            for(int k=1;k<=top;k++){//state[k]是i-1行的状态 
				if(!fit(state[k],i-1)) continue;
				if(state[j]&state[k]) continue;//上下行有冲突 
                dp[i][j]=(dp[i][j]+dp[i-1][k])%mod;
            }
		}
} 

int main(){
    while(~scanf("%d%d",&m,&n)){
		init();
		memset(dp,0,sizeof(dp));
		for(int i=1;i<=m;i++){
			cur[i]=0;
			int num;
			for(int j=1;j<=n;j++){
				scanf("%d",&num);
				if(num==0) cur[i]+=(1<<(n-j));//0的记录为1
			}
		}
		solve();
		int ans=0;
		for(int j=1;j<=top;j++)//累加最后一行 
			ans=(ans+dp[m][j])%mod;
		printf("%d\n",ans);
	}
	return 0;
}
