#include<iostream>
#include<cstring>
using namespace std;
int m[30][30],dis[30];
bool vis[30];
int n;

int prim(int s){
	for(int i=0;i<n;i++)
		dis[i]=m[s][i];
	memset(vis,false,sizeof(vis));
	vis[s]=1;
	int sum=0;
	int t;
	for(int i=1;i<n;i++){
		int min=0x3f3f3f3f;
		for(int j=0;j<n;j++){//找最小 
			if(!vis[j]&&dis[j]<min){
				min=dis[j];
				t=j;
			}
		}
		sum+=min;
		vis[t]=1;
		for(int j=0;j<n;j++){//更新
			if(!vis[j]&&dis[j]>m[t][j])
				dis[j]=m[t][j];
		}	 
	}
	return sum;
}

int main(){
	while(cin>>n&&n){
		int num,w;
		char c;
		memset(m,0x3f,sizeof(m));
		for(int i=1;i<n;i++){
			cin>>c>>num;
			int u=c-'A';
			while(num--){
				cin>>c>>w;
				int v=c-'A';
				if(w<m[u][v])
					m[u][v]=m[v][u]=w;
			}
		 }
		 cout<<prim(0)<<endl;
	}
	return 0;
}
