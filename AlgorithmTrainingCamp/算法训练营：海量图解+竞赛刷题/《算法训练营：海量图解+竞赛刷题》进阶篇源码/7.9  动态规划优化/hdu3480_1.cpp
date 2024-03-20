#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int MAX=10000+10;
const int INF=0x3f3f3f3f;
int n,m,index;
int q[MAX];
int a[MAX],dp[MAX][2];//¹ö¶¯Êý×é
 
int GetY(int k1,int k2){
	return dp[k2][index^1]+a[k2+1]*a[k2+1]-(dp[k1][index^1]+a[k1+1]*a[k1+1]);
}
 
int GetX(int k1,int k2){
	return a[k2+1]-a[k1+1];
}

int GetVal(int i,int k){
	return dp[k][index^1]+(a[i]-a[k+1])*(a[i]-a[k+1]);
}

void solve(){
	int head=0,tail=0;
	index=0;
	for(int i=1;i<=n;i++)
		dp[i][index]=INF;
	for(int j=1;j<=m;j++){
		index=index^1;
		head=tail=0;
		q[tail++]=0;
		for(int i=1;i<=n;i++){
			while(head+1<tail && GetY(q[head],q[head+1])<=2*a[i]*GetX(q[head],q[head+1]))
				head++;
			dp[i][index]=GetVal(i,q[head]);
			while(head+1<tail && GetY(q[tail-1],i)*GetX(q[tail-2],q[tail-1])<=GetY(q[tail-2],q[tail-1])*GetX(q[tail-1],i))
				tail--;
			q[tail++]=i;
		}
	}
}

int main(){
	int t,num=0;
	scanf("%d",&t);
	while(t--){
		scanf("%d%d",&n,&m);
		for(int i=1;i<=n;i++)
			scanf("%d",a+i);
		sort(a+1,a+1+n);
		solve();
		printf("Case %d: %d\n",++num,dp[n][index]);
	}
	return 0;
}
