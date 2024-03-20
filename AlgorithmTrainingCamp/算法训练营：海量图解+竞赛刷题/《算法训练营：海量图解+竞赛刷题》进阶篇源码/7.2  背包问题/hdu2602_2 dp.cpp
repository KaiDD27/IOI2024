#include<iostream>//一维数组，01背包问题 
#include<cstring>
#include<algorithm>
using namespace std;
#define M 1005
int dp[M];//dp[j]表示放入容量为j的背包获得的最大价值
int val[M],v[M];//val[i]表示第i个物品的价值，v[i]表示第i个物品的体积

int main(){
    int t,N,V;//t个测试用例，N个物品，V表示背包的容量
    cin>>t;
    while(t--){
    	memset(dp,0,sizeof(dp));
		cin>>N>>V;
    	for(int i=1;i<=N;i++)
    		cin>>val[i];
    	for(int i=1;i<=N;i++)
    		cin>>v[i];
	    for(int i=1;i<=N;i++)//计算dp[j]
	        for(int j=V;j>=v[i];j--)//比较此物品放与不放是否能使背包内的价值最大
	            dp[j]=max(dp[j],dp[j-v[i]]+val[i]);
    	cout<<dp[V]<<endl;
	}
    return 0;
}
