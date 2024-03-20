#include<bits/stdc++.h>
using namespace std;
const int maxn=100000+5;
int maxx[maxn],head[maxn];
int n,m,x,y,cnt;

struct Edge{
	int to,next;
}e[maxn];

void add(int u,int v){//���һ����u--v 
 	e[cnt].to=v;
	e[cnt].next=head[u];
	head[u]=cnt++;
} 

void dfs(int u,int v){
	if(maxx[v])
		return;
	maxx[v]=u;
	for(int i=head[v];~i;i=e[i].next){
		int v1=e[i].to;
		dfs(u,v1);
	}
}

int main(){
	cin>>n>>m;
	memset(head,-1,sizeof(head));
	memset(maxx,0,sizeof(maxx));
	for(int i=1;i<=m;i++){
		cin>>x>>y;
		add(y,x);//��ӷ���� 
	}
	for(int i=n;i;i--)//������ȱ��� 
		dfs(i,i);
	for(int i=1;i<=n;i++){
		if(i!=1)
			cout<<" ";
		cout<<maxx[i];
	}
	return 0;
}
