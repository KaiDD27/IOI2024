#include<iostream>//完全背包 
#include<cstring>
using namespace std;
#define maxn 10005
#define M 105
int dp[maxn];//dp[j]表示当前已放入容量为j的背包获得的最大价值
int w[M],v[M];//w[i]表示第i个物品的重量，v[i]表示第i个物品的价值
int n,W;//n表示n个物品，W表示背包的容量

void comp_knapsack(int n,int W){//完全背包
    for(int i=1;i<=n;i++)
		for(int j=w[i];j<=W;j++)//正序循环（正推）
			dp[j]=max(dp[j],dp[j-w[i]]+v[i]);
}

int main(){
    cout<<"请输入物品的个数 n:";
    cin>>n;
    cout<<"请输入背包的容量W:";
    cin>>W;
    cout<<"请依次输入每个物品的重量w和价值v,用空格分开:";
    for(int i=1;i<=n;i++)
        cin>>w[i]>>v[i];
    for(int j=1;j<=W;j++)//初始化第0行为0
        dp[j]=0;
    comp_knapsack(n,W);
    cout<<"装入背包的最大价值为:"<<dp[W]<<endl;
    //测试dp[]数组结果
    for(int j=1;j<=W;j++)
        cout<<dp[j]<<"  ";
    cout<<endl;
    return 0;
}
