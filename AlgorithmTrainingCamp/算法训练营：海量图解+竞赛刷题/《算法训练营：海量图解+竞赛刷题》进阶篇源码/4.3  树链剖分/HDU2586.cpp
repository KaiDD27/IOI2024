#include<iostream>
#include<algorithm>
using namespace std;
const int maxn=40005;
int n,m;//n����㣬m����ѯ
int head[maxn],dist[maxn],cnt;//ͷ��㣬����
int fa[maxn],dep[maxn];//���ף���� 
int size[maxn],son[maxn],top[maxn];//��������������ض��ӣ������������˽�� 
struct Edge{
	int to,c,next;
}e[maxn<<1];
 
void add(int u,int v,int w){
	e[++cnt].to=v;
	e[cnt].c=w;
	e[cnt].next=head[u];
	head[u]=cnt;
}

void dfs1(int u,int f){//��dep,fa,size,son,dist
    size[u]=1;
	for(int i=head[u];i;i=e[i].next){
        int v=e[i].to;
        if(v==f)//���ڵ� 
			continue;
        dep[v]=dep[u]+1;//��� 
        fa[v]=u;
        dist[v]=dist[u]+e[i].c;//���� 
        dfs1(v,u);
        size[u]+=size[v];
        if(size[v]>size[son[u]])
        	son[u]=v;
    }
}

void dfs2(int u){//��top
	if(u==son[fa[u]])
		top[u]=top[fa[u]];
	else
		top[u]=u;
	for(int i=head[u];i;i=e[i].next){
        int v=e[i].to;
        if(v!=fa[u])
        	dfs2(v);
	}
}

int LCA(int u,int v){//������u,v������������� 
	while(top[u]!=top[v]){//����ͬһ��������
		if(dep[top[u]]>dep[top[v]])
			u=fa[top[u]];
		else
			v=fa[top[v]];
	}
	return dep[u]>dep[v]?v:u;//�������С�Ľ�� 
}

int main(){
	int x,y,T,lca;
	cin>>T;
	while(T--){
		cin>>n>>m;
		for(int i=1;i<=n;i++)//��ʼ�� 
			head[i]=dep[i]=dist[i]=son[i]=0;
		cnt=0;
		for(int i=1;i<n;i++){//����һ������n-1��
			int x,y,z;
			cin>>x>>y>>z;
			add(x,y,z);
			add(y,x,z);
		}
		dep[1]=1;
		dfs1(1,0);
		dfs2(1);
		for(int i=1;i<=m;i++){
			cin>>x>>y;
			lca=LCA(x,y);
			cout<<dist[x]+dist[y]-2*dist[lca]<<endl;//���x y�ľ��� 
		}	
	}
	return 0;
}
