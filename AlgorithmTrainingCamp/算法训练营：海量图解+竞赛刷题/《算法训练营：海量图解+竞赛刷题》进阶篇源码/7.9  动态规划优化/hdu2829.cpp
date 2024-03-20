#include<cstdio>
#include<cstring>
using namespace std;
const int MAX=1000+10;
int n,m,index,head,tail;
int s[MAX],q[MAX];
int dp[MAX][2],cost[MAX],sum[MAX];//dp采用滚动数组 
 
int GetY(int k1,int k2){
	return dp[k2][index^1]-cost[k2]+sum[k2]*sum[k2]-(dp[k1][index^1]-cost[k1]+sum[k1]*sum[k1]);
}
 
int GetX(int k1,int k2){
	return sum[k2]-sum[k1];
}

int GetVal(int i,int k){
	return dp[k][index^1]+cost[i]-cost[k]-sum[i]*sum[k]+sum[k]*sum[k];
}

void solve(){
	index=0;
	for(int i=1;i<=n;i++)
		dp[i][index]=cost[i];
	for(int j=1;j<=m;j++){//分成j段,j作为第一层循环才用滚动数组
		index=index^1; 
		head=tail=0;
		q[tail++]=0;
		for(int i=1;i<=n;i++){
			while(head+1<tail && GetY(q[head],q[head+1])<=GetX(q[head],q[head+1])*sum[i])
				head++;
			dp[i][index]=GetVal(i,q[head]);
			while(head+1<tail && GetY(q[tail-1],i)*GetX(q[tail-2],q[tail-1])<=GetY(q[tail-2],q[tail-1])*GetX(q[tail-1],i))
				tail--;
			q[tail++]=i;
		}
	}
}
 
int main(){
	while(~scanf("%d%d",&n,&m),n+m){
		for(int i=1;i<=n;i++)
			scanf("%d",&s[i]);
		for(int i=1;i<=n;i++)
			sum[i]=sum[i-1]+s[i];
		memset(cost,0,sizeof(cost));
		for(int i=1;i<=n;i++)
			for(int j=i+1;j<=n;j++)
				cost[j]+=s[i]*s[j];
		for(int i=1;i<=n;i++)
			cost[i]+=cost[i-1];
		solve();
		printf("%d\n",dp[n][index]);
	}
	return 0;
}
