#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
const int M=10005;
const int INF=0x3f3f3f;
int dp[M];//dp[j]表示放入重量为j的存钱罐面值之和最小值 
int val[M],w[M];//val[i]表示第i种硬币的面值，w[i]表示第i种硬币的重量 

int main(){
    int t,E,F,W,N;//t个测试用例，E、F表示没装硬币和装了硬币之后的重量,W重量差值，硬币种类 
    cin>>t;
    while(t--){
		cin>>E>>F;
		W=F-E;
		cin>>N;
    	for(int i=0;i<N;i++)
    		cin>>val[i]>>w[i];
    	memset(dp,0x3f,sizeof(dp));
    	dp[0]=0;
	    for(int i=0;i<N;i++)//计算dp[j]
	        for(int j=w[i];j<=W;j++)//比较此硬币放与不放是否能使得存钱罐内面值之和最小
	        	dp[j]=min(dp[j],dp[j-w[i]]+val[i]);
    	if(dp[W]<INF)
			cout<<"The minimum amount of money in the piggy-bank is "<<dp[W]<<"."<<endl;
		else
			cout<<"This is impossible."<<endl;
	}
    return 0;
}
