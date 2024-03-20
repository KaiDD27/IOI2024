#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int N,M;
char map[110][20],num[70],top;
int stk[70],cur[70];
int dp[110][70][70];
 
bool check(int x){//判断该状态是否合法，横向检测相邻的1之间的距离不能小于3
	if(x&(x<<1)) return 0;
	if(x&(x<<2)) return 0;
	return 1;
}

void init(){//记录所有可能的合法状态，最多60种
	top=0;
	for(int i=0;i<(1<<M);i++)
		if(check(i)) stk[top++]=i;
}

bool fit(int x,int k){//判断状态x是否与地图第k行匹配，确保炮兵部队部署在平原上
	if(cur[k]&x) return 0;
	return 1;
}

int count(int x){//统计状态x的二进制中1的个数
	int cnt=0;
	while(x){
		cnt++;
		x&=(x-1);
	}
	return cnt;
}

int solve(){
	int ans=0;
	memset(dp,-1,sizeof(dp));
	for(int j=0;j<top;j++){//初始化第一行状态
		num[j]=count(stk[j]);
		if(fit(stk[j],1)){
			dp[1][j][0]=num[j];//第一行状态为j,上一行状态为第0个状态，即000000
			ans=max(ans,dp[1][j][0]);
		}
	}
	for(int i=2;i<=N;i++){
		for(int j=0;j<top;j++){
			if(!fit(stk[j],i)) continue;//匹配检测
            for(int k=0;k<top;k++)
            {
                if(stk[j]&stk[k]) continue;//竖向检测，与上一行不能有相邻的1 
                for(int t=0;t<top;t++)
                {
                    if(stk[j]&stk[t]) continue;//竖向检测，与上上行不能有相邻的1 
                    if(dp[i-1][k][t]==-1) continue;
                    dp[i][j][k]=max(dp[i][j][k],dp[i-1][k][t]+num[j]);
				}
				if(i==N) ans=max(ans,dp[i][j][k]);
            }
		}
	}
	return ans;
}

int main(){
	while(~scanf("%d%d",&N,&M)){
		init();
		for(int i=1;i<=N;i++)//读M行地图
			scanf("%s",map[i]+1);
		for(int i=1;i<=N;i++){//预处理地图状态 
			cur[i]=0;
			for(int j=1;j<=M;j++)
				if(map[i][j]=='H')
					cur[i]+=(1<<(j-1));
		}
		printf("%d\n",solve());
	}
	return 0;
}
