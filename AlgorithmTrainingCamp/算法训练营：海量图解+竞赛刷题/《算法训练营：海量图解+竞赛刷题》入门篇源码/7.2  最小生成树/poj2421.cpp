#include<iostream>
#include<cstring>
using namespace std;
const int maxn=105;
const int inf=0x3f3f3f3f; 
double m[maxn][maxn],low[maxn];
bool vis[maxn];
int n;

int prim(int s){
	memset(vis,false,sizeof(vis));
	for(int i=1;i<=n;i++)
		low[i]=m[s][i];
	vis[s]=1;
	int sum=0;
	int t;
	for(int i=1;i<n;i++){//执行n-1次 
		int min=inf;
		for(int j=1;j<=n;j++){//找最小 
			if(!vis[j]&&low[j]<min){
				min=low[j];
				t=j;
			}
		}
		sum+=min;
		vis[t]=1;
		for(int j=1;j<=n;j++){//更新
			if(!vis[j]&&low[j]>m[t][j])
				low[j]=m[t][j];
		}	 
	}
	return sum;
}

int main(){
	int q,a,b;
	while(cin>>n){
		for(int i=1;i<=n;i++)
			for(int j=1;j<=n;j++)
				cin>>m[i][j];
		cin>>q;
		while(q--){
			cin>>a>>b;
			m[a][b]=m[b][a]=0;
		}
		cout<<prim(1)<<endl;
	}
	return 0;
}
