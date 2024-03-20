#include<iostream>
#include<cstring>
using namespace std;
#define maxn 105
int qd[maxn];//有趣点 
int pre[maxn],dis[maxn],n,m;//前驱，和值 
int map[maxn][maxn];//邻接矩阵 

void printpath(int i){//输出最长的回路
	if(i==-1)
		return;
	printpath(pre[i]);
	cout<<i<<"->";
}

int main(){
	int T,u,v,cas=0;
	cin>>T;
	while(T--){
		memset(pre,-1,sizeof(pre));
		memset(dis,0,sizeof(dis));
		memset(map,0,sizeof(map));
		cin>>n;
		for(int i=1;i<=n;i++)
			cin>>qd[i];
		qd[n+1]=0;
		cin>>m;
		for(int i=1;i<=m;i++){
			cin>>u>>v;
			map[u][v]=1;
		}
		for(int j=1;j<=n+1;j++)
			for(int i=1;i<j;i++)
				if(map[i][j]&&dis[j]<dis[i]+qd[j]){
					dis[j]=dis[i]+qd[j];
					pre[j]=i;
				}
		if(cas)
			cout<<endl;
		cout<<"CASE "<<++cas<<"#"<<endl;
		cout<<"points : "<<dis[n+1]<<endl;
		cout<<"circuit : ";
		printpath(pre[n+1]);//最后一个节点，手工输出1，所以从pre[n+1]开始 
		cout<<"1"<<endl;	
	}
	return 0;
}
