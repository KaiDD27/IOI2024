#include<iostream>
#include<algorithm>
#include<cmath>//ʹ��log����

using namespace std;
const int maxn=40005;
int n,m,k,F[maxn][20];//n����㣬m����ѯ��F(i,j)��ʾi������2^j���Ľ�� 
int head[maxn],dist[maxn],d[maxn],cnt;//ͷ��㣬���룬������� 
struct Edge
{
	int to,c,next;
 }e[maxn<<1];
 
void add(int u,int v,int w)
{
	e[++cnt].to=v;
	e[cnt].c=w;
	e[cnt].next=head[u];
	head[u]=cnt;
}

void dfs(int u)//����ȡ����롢��ʼ��F[v][0]
{
    for(int i=head[u];i;i=e[i].next)
	{
        int v=e[i].to;
        if(v==F[u][0])
			continue;
        d[v]=d[u]+1;//��� 
        dist[v]=dist[u]+e[i].c;//���� 
        F[v][0]=u; //F[v][0]��v�ĸ��ڵ�
        dfs(v);
    }
}

void ST_create()//����ST�� 
{
	for(int j=1;j<=k;j++)
		for(int i=1;i<=n;i++)//i����2^(j-1)������F[i][j-1],����2^(j-1)��
			F[i][j]=F[F[i][j-1]][j-1];
}

int LCA_st_query(int x,int y)//������x,y������������� 
{
	if(d[x]>d[y])//��֤x�����С�ڵ���y 
		swap(x,y);
	for(int i=k;i>=0;i--)//y�����ߵ���xͬһ��� 
		if(d[F[y][i]]>=d[x])
			y=F[y][i];
	if(x==y)
		return x;
	for(int i=k;i>=0;i--)//x,yһ��������
		if(F[x][i]!=F[y][i])
			x=F[x][i],y=F[y][i];
	return F[x][0];//����x�ĸ��� 
}

int main()
{
	int x,y,T,lca;
	cin>>T;
	while(T--)
	{
		cin>>n>>m;
		k=log2(n);//log(n)/log(2);
		for(int i=1;i<=n;i++)//��ʼ�� 
			head[i]=d[i]=dist[i]=0;
		cnt=0;
		for(int i=1;i<n;i++)//����һ������n-1��
		{
			int x,y,z;
			cin>>x>>y>>z;
			add(x,y,z);
			add(y,x,z);
		}
		d[1]=1;
		dfs(1);
		ST_create();//����ST��
		for(int i=1;i<=m;i++)
		{
			cin>>x>>y;
			lca=LCA_st_query(x,y);
			cout<<dist[x]+dist[y]-2*dist[lca]<<endl;//���x y�ľ��� 
		}	
	}
	return 0;
}
