#include<cstdio>//多重背包，二进制拆分hdu2844可以通过,poj1742超时，需要优化 
#include<cstring>
#include<algorithm>
using namespace std;
#define M 100005
bool dp[M];//dp[j]表示和为j的组合方式是否存在 
int v[105],c[105];//价值，数量

void multi_knapsack(int n,int W){//二进制拆分 
    for(int i=1;i<=n;i++) {
		if(c[i]*v[i]>=W){//转化完全背包 
            for(int j=v[i];j<=W;j++)
                if(dp[j-v[i]])//如果 dp[j-v[i]]是可达的，则 dp[j]也可以 
					dp[j]=1;
        }
        else{
            for(int k=1;c[i]>0;k<<=1){//二进制拆分
	            int x=min(k,c[i]);
	            for(int j=W;j>=v[i]*x;j--)//转化01背包 
	                if(dp[j-v[i]*x])//如果 dp[j-v[i]*x]是可达的，则 dp[j]也可以 
						dp[j]=1;
	            c[i]-=x;
        	} 
    	}
	}
}

int main(){
    int n,m;//n个数，手表价格m
    while(~scanf("%d%d",&n,&m),n+m){
    	for(int i=1;i<=n;i++)//价值 
    		scanf("%d",&v[i]);
    	for(int i=1;i<=n;i++)
    		scanf("%d",&c[i]);//数量
		memset(dp,0,sizeof(dp));
		dp[0]=1;//初始状态0可达 
		multi_knapsack(n,m);
		int ans=0;
		for(int i=1;i<=m;i++)//累加答案
			ans+=dp[i];
		printf("%d\n",ans);
	}
    return 0;
}
