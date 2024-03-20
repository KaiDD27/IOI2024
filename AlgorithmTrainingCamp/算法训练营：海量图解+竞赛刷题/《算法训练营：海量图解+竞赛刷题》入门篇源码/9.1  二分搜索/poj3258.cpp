#include<iostream>
#include<algorithm>
using namespace std;
const int maxn=50050;
int L,n,m,dis[maxn];

bool judge(int x){ //移除m个石头之后，任意间距不小于x
	int num=n-m; //减掉m个石头，放置num个石头，循环num次
    int last=0; //记录前一个已放置石头下标
    for(int i=0;i<num;i++){ //对于这些石头，要使任意间距不小于x
        int cur=last+1;
        while(cur<=n&&dis[cur]-dis[last]<x) //放在第1个与last距离>=x的位置
            cur++; //由cur累计位置 
        if(cur>n)
			return 0; //如果在这个过程中大于n了，说明放不开
        last=cur; //更新last位置
    }
    return 1;
}

int main(){
    cin>>L>>n>>m;
    if(n==m){
        cout<<L<<endl;
        return 0;
    }
    for(int i=1;i<=n;i++)
		cin>>dis[i];
    dis[0]=0;//增加开始点
	dis[n+1]=L;//增加结束点
    sort(dis,dis+n+2);
    int left=0,right=L;
    while(right-left>1){
        int mid=(right+left)/2;
        if(judge(mid))
			left=mid;//如果放得开，说明x还可以更大
        else
			right=mid;
    }
    cout<<left<<endl;
    return 0;
}
