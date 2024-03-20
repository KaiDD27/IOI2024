#include<iostream>
#include<algorithm>
#include<cmath>//ʹ��log����
using namespace std;
const int maxn=40005;
int n,m,tot,F[maxn<<1][20];//F(i,j)��ʾ����[i��i+2^j-1]����ֵ�����䳤��Ϊ2^j
int head[maxn],dist[maxn],pos[maxn],seq[maxn<<1],dep[maxn<<1],cnt;//ͷ���
bool vis[maxn];
struct Edge{
	int to,c,next;
}e[maxn<<1];
 
void add(int u,int v,int w){
	e[++cnt].to=v;
	e[cnt].c=w;
	e[cnt].next=head[u];
	head[u]=cnt;
}

void dfs(int u,int d){//dfs��
	vis[u]=true;
	pos[u]=++tot;//u�״γ��ֵ��±� 
	seq[tot]=u;//dfs��������
	dep[tot]=d;//���
	for(int i=head[u];i;i=e[i].next){
		int v=e[i].to,w=e[i].c;
		if(vis[v])
			continue;
		dist[v]=dist[u]+w;
		dfs(v,d+1);
		seq[++tot]=u;//dfs��������
		dep[tot]=d;//���
	}
}

void ST_create(){
	for(int i=1;i<=tot;i++)//��ʼ�� 
		F[i][0]=i;//��¼�±꣬������С��� 
	int k=log2(tot);
	for(int j=1;j<=k;j++)
		for(int i=1;i<=tot-(1<<j)+1;i++)//tot-2^j+1
			if(dep[F[i][j-1]]<dep[F[i+(1<<(j-1))][j-1]])
				F[i][j]=F[i][j-1];
			else
				F[i][j]=F[i+(1<<(j-1))][j-1];
}

int RMQ_query(int l,int r){//������[l..r]����ֵ
	int k=log2(r-l+1);
	if(dep[F[l][k]]<dep[F[r-(1<<k)+1][k]])
		return 	F[l][k];
	else
		return 	F[r-(1<<k)+1][k];//���������С�Ľ���±� 
}

int LCA(int x,int y){//��x��y�������������
	int l=pos[x],r=pos[y];//��ȡ��һ�γ��ֵ��±�
	if(l>r)
		swap(l,r);
	return seq[RMQ_query(l,r)];//���ؽ�� 
} 

void print(){
	for(int i=1;i<=tot;i++)
		cout<<seq[i]<<" ";
	cout<<endl;
}
/*
1
9 8
1 3 2
1 2 3
2 5 1
2 4 6
4 6 2
5 7 5
6 9 7
6 8 8
��� 1 2 4 6 8 6 9 6 4 2 5 7 5 2 1 3 1
6 5
��� 9
*/
int main(){
	int x,y,T,lca;
	cin>>T;
	while(T--){
		cin>>n>>m;
		for(int i=1;i<=n;i++)//��ʼ�� 
			head[i]=vis[i]=dist[i]=0;
		cnt=0,tot=0;
		for(int i=1;i<n;i++){//����һ������n-1��
			int x,y,z;
			cin>>x>>y>>z;
			add(x,y,z);
			add(y,x,z);
		}
		dfs(1,1);
		print();
		ST_create();//����ST��
		for(int i=1;i<=m;i++){
			cin>>x>>y;
			lca=LCA(x,y);
			cout<<dist[x]+dist[y]-2*dist[lca]<<endl;//���x y�ľ��� 
		}	
	}
	return 0;
}
