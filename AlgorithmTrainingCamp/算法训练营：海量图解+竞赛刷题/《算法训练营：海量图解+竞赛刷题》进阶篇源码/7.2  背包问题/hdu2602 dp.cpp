#include<iostream>//二维数组，01背包问题 
#include<cstring>
#include<algorithm>
using namespace std;
#define M 1005
int c[M][M];//c[i][j] 表示前i个物品放入容量为j的背包获得的最大价值
int val[M],v[M];//val[i]表示第i个物品的价值，v[i]表示第i个物品的体积

int main(){
    int t,N,V;//N个物品，V表示背包的容量
    cin>>t;
    while(t--){
		cin>>N>>V;
    	for(int i=1;i<=N;i++)
    		cin>>val[i];
    	for(int i=1;i<=N;i++)
    		cin>>v[i];
    	for(int i=0;i<=N;i++)
    		c[i][0]=0;
    	for(int j=0;j<=V;j++)
    		c[0][j]=0;
	    for(int i=1;i<=N;i++)//计算c[i][j]
	        for(int j=0;j<=V;j++)//本题体积可能为0
	            if(j<v[i]) //当物品的体积大于背包的容量，则不放此物品
	                c[i][j]=c[i-1][j];
	            else    //否则比较此物品放与不放是否能使背包内的价值最大
	                c[i][j]=max(c[i-1][j],c[i-1][j-v[i]]+val[i]);
    	cout<<c[N][V]<<endl;
	}
    return 0;
}
