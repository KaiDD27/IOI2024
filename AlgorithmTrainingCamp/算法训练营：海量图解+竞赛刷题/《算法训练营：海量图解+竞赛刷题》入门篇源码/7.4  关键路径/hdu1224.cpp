#include<iostream>
#include<cstring>
using namespace std;
#define maxn 105
int qd[maxn];//��Ȥ�� 
int pre[maxn],dis[maxn],n,m;//ǰ������ֵ 
int map[maxn][maxn];//�ڽӾ��� 

void printpath(int i){//�����Ļ�·
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
		printpath(pre[n+1]);//���һ���ڵ㣬�ֹ����1�����Դ�pre[n+1]��ʼ 
		cout<<"1"<<endl;	
	}
	return 0;
}
