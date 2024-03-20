#include<iostream>//01背包一维数组优化
#include<cstring>
using namespace std;
#define maxn 10005
#define M 105
int dp[maxn];//dp[j]表示当前已放入容量为j的背包获得的最大价值
int w[M],v[M];//w[i]表示第i个物品的重量，v[i]表示第i个物品的价值
int x[M];  //x[i]表示第i个物品是否放入背包
int n,W;//n表示n个物品，W表示背包的容量

void opt1(int n,int W){
    for(int i=1;i<=n;i++)
        for(int j=W;j>0;j--)
			if(j>=w[i])//当物品的重量大于背包的容量，比较此物品放与不放是否能使得背包内的价值最大
				dp[j]=max(dp[j],dp[j-w[i]]+v[i]);
}

void opt2(int n,int W){
	for(int i=1;i<=n;i++)
		for(int j=W;j>=w[i];j--)//逆向循环（倒推）
			dp[j]=max(dp[j],dp[j-w[i]]+v[i]);
}

void opt3(int n,int W){
	int sum[n];//sum[i]表示从1...i的物品重量之和
	sum[0]=0;
	for(int i=1;i<=n;i++)
		sum[i]=sum[i-1]+w[i];
	for(int i=1;i<=n;i++){
        int bound=max(w[i],W-(sum[n]-sum[i-1]));//w[i]和剩余容量取最大值,sum[n]-sum[i-1]表示从i...n的物品重量之和
        for(int j=W;j>=bound;j--)
            //当物品的重量大于背包的容量，比较此物品放与不放是否能使得背包内的价值最大
           dp[j]=max(dp[j],dp[j-w[i]]+v[i]);
	}
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
    opt1(n,W);
    //opt2(n,W);
    //opt3(n,W);
    cout<<"装入背包的最大价值为:"<<dp[W]<<endl;

    //测试dp[]数组结果
    for(int j=1;j<=W;j++)
        cout<<dp[j]<<"  ";
    cout<<endl;
    return 0;
}

