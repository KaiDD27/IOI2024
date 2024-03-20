#include<cstdio>
#include<cstring>
using namespace std;
const int maxn=100005;
int dp[maxn];//dp[i]表示从1开始到第i个元素的最大和值 

int main(){
	int t,n,cas=0;
	scanf("%d",&t);
	while(t--){
		scanf("%d",&n);
		for(int i=1;i<=n;i++)
			scanf("%d",&dp[i]);//省略原数组，直接用dp[] 
		int l=1,r=1;//记录区间
		int start=1;//记录起点
		int MAX=dp[1];
		for(int i=2;i<=n;i++){
            if(dp[i-1]>=0)//dp[i-1]大于等于0，则累加，否则重新开始 
                dp[i]=dp[i-1]+dp[i];
            else
				start=i;//重新开始
            if(dp[i]>MAX){//更新最值
            	MAX=dp[i];
				l=start;
         	    r=i;
            }
		}
		if(cas)
			printf("\n");
		printf("Case %d:\n",++cas);
		printf("%d %d %d\n",MAX,l,r);
	}
	return 0;
}
