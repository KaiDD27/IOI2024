#include<bits/stdc++.h>
using namespace std;
const int maxn=2e5+5;
const int maxe=4e6+5;
struct Edge
{
    int v,w,nxt,pre;
}edge[maxe],E[maxe];//ԭͼ���ع�ͼ 
int Head[maxn],head[maxn],rear,tot,tail[maxn];
int mark[maxn],sz[maxn];
int N,n,cnt,root,midedge,Max;
void init()//ԭͼ��ʼ�� 
{
    memset(head,-1,sizeof(head));
    tot=0;
}
void INIT()//�ع�ͼ��ʼ��
{
    memset(Head,-1,sizeof(Head));
    rear=0;//�±���㿪ʼ 
}
void add(int u,int v,int w)
{
    edge[tot].v=v;
    edge[tot].w=w;
    edge[tot].nxt=head[u];
    head[u]=tot++;
}
void ADD(int u,int v,int w)
{
    E[rear].v=v;
    E[rear].w=w;
    E[rear].nxt=Head[u];
    Head[u]=rear++;
}
void Delete(int u,int i)//ɾ��u����i�ű� 
{
    if(Head[u]==i)
		Head[u]=E[i].nxt;
    else
		E[E[i].pre].nxt=E[i].nxt;//�����ñ� 
    if(tail[u]==i)//ָ��u�������һ���ߣ��൱��βָ�� 
		tail[u]=E[i].pre;
    else
		E[E[i].nxt].pre=E[i].pre;//˫�������޸�ǰ�� 
}
//��֤ÿ����ĶȲ�����2
void build(int u,int fa) 
{
    int father=0;
    for (int i=head[u];~i;i=edge[i].nxt)
	{
        int v=edge[i].v,w=edge[i].w;
        if(v==fa)continue;
        if(father==0)//��û�������ӽڵ㣬ֱ������
		{
            ADD(u,v,w);
			ADD(v,u,w);
            father=u;
        }
		else//�Ѿ���һ���ӽڵ㣬�򴴽�һ���½ڵ㣬��v�����½ڵ���
		{        
            mark[++N]=0;
            ADD(N,father,0);
			ADD(father,N,0);
            father=N;
            ADD(v,father,w);
			ADD(father,v,w);
        }
        build(v,u);
    }
}
//nxt����һ���ߵı�ţ�pre����һ���ߵı��
void get_pre()//�õ�ÿ���ߵ�ǰ��
{
    memset(tail,-1,sizeof(tail));
    for(int i=1;i<=N;i++)
	{
        for(int j=Head[i];~j;j=E[j].nxt)
		{
            E[j].pre=tail[i];
            tail[i]=j;//ָ��u�������һ���ߣ��൱��βָ��
        }
    }
}

void rebuild()//�ع�ͼ
{
    INIT();//�ع�ͼ��ʼ�� 
    N=n;
    for(int i=1;i<=N;i++)
		mark[i]=1;
    build(1,0);
    get_pre();//�õ�ÿ���ߵ�ǰ�� 
    init();//ԭͼ��ʼ�� 
}
 
struct point
{
    int u,dis;
    point() {}
    point(int _u,int _dis) {
        u=_u;dis=_dis;
    }
    bool operator<(const point& _A)const {
        return dis<_A.dis;//���ȶ��е����ȼ� 
    }
};

struct node {
    int rt,midlen,ans; //���ڵ㣬���ıߵ�Ȩֵ����(�����)
    int ls,rs;         //�����������
    priority_queue<point>q;
}T[2*maxn];//ע�⣺��Ϊmaxe�ᳬʱ
 
bool vis[maxn];
void dfs1(int u)//�����ؽ������ 
{
    vis[u]=1;
    for(int i=Head[u];~i;i=E[i].nxt)
	{
        int v=E[i].v,w=E[i].w;
        if(vis[v]) continue;
        cout<<u<<"\t"<<v<<"\t"<<w<<endl;
        dfs1(v);
    }
}

void dfs2(int u)//���Ծ�������� 
{
    vis[u]=1;
    for(int i=head[u];~i;i=edge[i].nxt)
	{
        int v=edge[i].v,w=edge[i].w;
        cout<<u<<"\t"<<v<<"\t"<<w<<endl;
        if(vis[v]) continue;
        dfs2(v);
    }
} 

void dfs_size(int u,int fa,int dis)//���ÿ��������С
{
    add(u,root,dis);//���ÿ���㵽root�ľ��뵽������ 
    if(mark[u])//����ǰ׵㣬��ѹ����ڵ�root�Ķ��У�disΪu����root�ľ���
		T[root].q.push(point(u,dis));//�����б���׵㼰�䵽root�ľ��� 
    sz[u]=1;
    for(int i=Head[u];~i;i=E[i].nxt)
	{
        int v=E[i].v,w=E[i].w;
        if(v==fa) continue;
        dfs_size(v,u,dis+w);
        sz[u]+=sz[v];
    }
}

void dfs_midedge(int u, int code)//�����ı�
{
    if(max(sz[u],sz[T[root].rt]-sz[u])<Max)
	{
        Max=max(sz[u],sz[T[root].rt]-sz[u]);//sz[T[root].rt]Ϊ������������� 
        midedge=code;
    }
    for(int i=Head[u];~i;i=E[i].nxt)
	{
        int v=E[i].v;
        if(i!=(code^1))
			dfs_midedge(v,i);
    }
}

void PushUP(int id)//����id��ans 
{
    T[id].ans=-1;//��ʼΪ-1 
    while(!T[id].q.empty()&&mark[T[id].q.top().u]==0)//�����ڵ�
		T[id].q.pop();
    int ls=T[id].ls, rs=T[id].rs; //lsΪ����ӣ�rsΪ�Ҷ���
    if(ls==0&&rs==0)//��û�����Ҷ���
	{ 
        if(mark[T[id].rt])//��Ϊ�׽�� 
			T[id].ans=0;
    }
	else
	{
        if(T[ls].ans>T[id].ans)//�������ӵĽ�����ڸ� 
			T[id].ans=T[ls].ans;
        if(T[rs].ans>T[id].ans)//����Ҷ��ӵĽ�����ڸ�
			T[id].ans=T[rs].ans;
        if(!T[ls].q.empty()&&!T[rs].q.empty())//�������ıߵ�
            T[id].ans=max(T[id].ans,T[ls].q.top().dis+T[rs].q.top().dis+T[id].midlen);
	}
}
void DFS(int id, int u)
{
    root=id; Max=N; midedge=-1;
    T[id].rt=u;
    dfs_size(u,0,0);//���ÿ��������С
//    memset(vis,false,sizeof(vis));
//    cout<<"test:"<<endl;
//    for(int i=1;i<=N;i++)
//		dfs2(i);//ԭ���޸ģ�����������

//	cout<<"T["<<root<<"].q:"<<endl;
//	while(!T[root].q.empty())//���������ȶ��в���
//	{
//		cout<<T[root].q.top().u<<"\t"<<T[root].q.top().dis<<endl;
//		T[root].q.pop();
//	}
//	cout<<endl;
    dfs_midedge(u,-1);//�����ı�
    if(~midedge)
	{
        //���ıߵ�����2��
        int p1=E[midedge].v;//p1:v midedge: u->v 
        int p2=E[midedge^1].v;//p2:u
        cout<<"���ıߣ�"<<endl;
		cout<<p2<<"����"<<p1<<endl; 
        //���ı߳���
        T[id].midlen=E[midedge].w;
        //��������
        T[id].ls=++cnt;
        T[id].rs=++cnt;
        //ɾ�����ı�
        Delete(p1,midedge^1);//ɾ��p1����i�ű� 
        Delete(p2,midedge);
        DFS(T[id].ls,p1);
        DFS(T[id].rs,p2);
    }
    PushUP(id);//����rt��ans 
}
void update(int u)//�ı�u����ɫ 
{
    mark[u]^=1;//��ɫȡ�� 
    for(int i=head[u];~i;i=edge[i].nxt)
	{
        int v=edge[i].v,w=edge[i].w;
        if(mark[u]==1) //uΪ�׽�����v������ 
			T[v].q.push(point(u,w)); 
        PushUP(v);//����v
    }
}

int main()
{
/*�����ؽ������ 
6
1 6 8
1 5 2
1 4 1
1 3 5
1 2 2
*/

/*�������ı߷ֽ� 
7
1 4 2
1 3 1
1 2 3
2 6 2
2 5 2
3 7 1
*/
	scanf("%d",&n);
    init();//ԭ����ʼ�� 
    int u,v,w;
    for(int i=1;i<n;i++)
	{
        scanf("%d%d%d",&u,&v,&w);
        add(u,v,w);
		add(v,u,w);
    }
    rebuild();//�ؽ��� 
    //memset(vis,false,sizeof(vis));
    //dfs1(1);//�����ؽ������ 
	DFS(cnt=1,1);//����
	cout<<T[1].ans<<endl;
	cout<<T[2].ans<<endl;
	cout<<T[3].ans<<endl;
//    char op[2]; 
//	int m,x;
//    scanf("%d", &m);
//    while(m--)
//	{
//        scanf("%s",op);
//        if(op[0]=='A')//���������Զ�������׵���� 
//		{
//            if(T[1].ans==-1)
//				printf("They have disappeared.\n");
//            else
//				printf("%d\n",T[1].ans);
//        }else
//		{
//            scanf("%d",&x);
//            update(x);//�ı�x����ɫ
//        }
//    }
    return 0;
}
