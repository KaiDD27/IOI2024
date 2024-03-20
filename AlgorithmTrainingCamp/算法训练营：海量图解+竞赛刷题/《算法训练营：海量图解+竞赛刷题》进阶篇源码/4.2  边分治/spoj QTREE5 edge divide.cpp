#include<bits/stdc++.h>
using namespace std;
const int MX=2e5+5;
const int MXE=4e6+5;//����ͼ��Ҫ�����࣬����10�� 
const int inf=0x3f3f3f3f;
struct Edge{
    int v,w,nxt,pre;
}edge[MXE],E[MXE];//ԭͼ���ع�ͼ 
int Head[MX],head[MX],rear,tot,tail[MX];
int mark[MX],sz[MX];
int N,n,cnt,root,midedge,Max;
int white;//��ʼ��û�а׵�

void init(){//ԭͼ��ʼ�� 
    memset(head,-1,sizeof(head));
    tot=0;
}

void INIT(){//�ع�ͼ��ʼ��
    memset(Head,-1,sizeof(Head));
    rear=0;//�±���㿪ʼ 
}

void add(int u,int v,int w){
    edge[tot].v=v;
    edge[tot].w=w;
    edge[tot].nxt=head[u];
    head[u]=tot++;
}

void ADD(int u,int v,int w){
    E[rear].v=v;
    E[rear].w=w;
    E[rear].nxt=Head[u];
    Head[u]=rear++;
}

void Delete(int u,int i){//ɾ�����ı� 
    if(Head[u]==i)
		Head[u]=E[i].nxt;
    else
		E[E[i].pre].nxt=E[i].nxt;
    if(tail[u]==i)
		tail[u]=E[i].pre;
    else
		E[E[i].nxt].pre=E[i].pre;
}

void build(int u,int fa){ //��֤ÿ����ĶȲ�����2
    int father=0;
    for(int i=head[u];~i;i=edge[i].nxt){
        int v=edge[i].v,w=edge[i].w;
        if(v==fa)continue;
        if(father==0){//��û�������ӽڵ㣬ֱ������
            ADD(u,v,w);
			ADD(v,u,w);
            father=u;
        }
		else{ //�Ѿ���һ���ӽڵ㣬�򴴽�һ���½ڵ㣬��v�����½ڵ���     
            mark[++N]=0;//��ڵ㣬���Ϊ��ɫ 
            ADD(N,father,0);
			ADD(father,N,0);
            father=N;
            ADD(v,father,w);
			ADD(father,v,w); 
        }
		build(v,u);
    }
}

void get_pre(){//��ÿ���ߵ�ǰ����Ϊɾ�����ı���׼�� 
    memset(tail,-1,sizeof(tail));
    for(int i=1;i<=N;i++){//nxt����һ���ߵı�ţ�pre����һ���ߵı��
        for(int j=Head[i];~j;j=E[j].nxt){
            E[j].pre=tail[i];
            tail[i]=j;
        }
    }
}

void rebuild(){//�ؽ���
    INIT();//�ؽ�����ʼ�� 
    N=n;
    for(int i=1;i<=N;i++)
		mark[i]=0;//��Ǻ�ɫ 
    build(1,0);//�ؽ���
    get_pre();//����ÿ���ߵ�ǰ����Ϊɾ�����ı���׼�� 
    init();//��ԭͼ�ÿգ�Ϊ������������׼��
}
 
struct point{
    int u, dis;
    point() {}
    point(int _u, int _dis){
        u=_u;dis=_dis;
    }
    bool operator<(const point& _A)const{
        return dis>_A.dis;//�����С�������ȶ��� 
    }
};

struct node{
    int rt,midlen; //���ڵ㣬���ı�
    int ls,rs;     //�����������
    priority_queue<point>q;//����������ÿ���׽ڵ㵽���ľ��� 
}T[2*MX];
 
void dfs_size(int u,int fa,int dir){//��������������ӣ�������ÿ��������С
    add(u,root,dir);//���������� 
    //����ǰ׵㣬��ѹ����ڵ�root�����ȶ��У�distΪu�����ľ���
    if(mark[u])//�׵� 
		T[root].q.push(point(u,dir));
    sz[u]=1;
    for(int i=Head[u];~i;i=E[i].nxt){
        int v=E[i].v,w=E[i].w;
        if(v==fa) continue;
        dfs_size(v,u,dir+w);
        sz[u]+=sz[v];
    }
}

void dfs_midedge(int u, int code){//�����ı�
    if(max(sz[u],sz[T[root].rt]-sz[u])<Max){
        Max=max(sz[u],sz[T[root].rt]-sz[u]);
        midedge=code;
    }
    for(int i=Head[u];~i;i=E[i].nxt){
        int v=E[i].v;
        if(i!=(code^1))//����� 
			dfs_midedge(v,i);
    }
}

void PushUP(int id){//����
    while(!T[id].q.empty()&&!mark[T[id].q.top().u])
		T[id].q.pop();//�����ڵ�
}

void DFS(int id, int u){//�ݹ����
    root=id; Max=N; midedge=-1;
    T[id].rt=u;
    dfs_size(u,0,0);
    dfs_midedge(u,-1);
    if(~midedge){
        //���ıߵ�����2��
        int p1=E[midedge].v;
        int p2=E[midedge^1].v;
        //���ı߳���
        T[id].midlen=E[midedge].w;
        //��������
        T[id].ls=++cnt;
        T[id].rs=++cnt;
        //ɾ�����ı�
        Delete(p1,midedge^1);
        Delete(p2,midedge);
        DFS(T[id].ls,p1);
        DFS(T[id].rs,p2);
    }
}

void update(int u){//u�ڵ��ɫ 
    mark[u]^=1;//��ɫ
    if(mark[u])
    	white++;
    else
    	white--;
    for(int i=head[u];~i;i=edge[i].nxt){//����ͼ���ڽӵ� 
        int v=edge[i].v,w=edge[i].w;
        if(mark[u])	
			T[v].q.push(point(u,w));
        PushUP(v);//����
    }
}

int query(int u){//��ѯ��u����İ׵�ľ���
	int mn=inf,temp=0;
	for(int i=head[u];~i;i=edge[i].nxt){//����ͼ���ڽӵ� 
        int id=edge[i].v,w=edge[i].w;
        int ls=T[id].ls, rs=T[id].rs; //lsΪ����ӣ�rsΪ�Ҷ���
		if(!T[ls].q.empty()) //�������ı�
			mn=min(mn,T[ls].q.top().dis+temp+T[id].midlen);
        if(!T[rs].q.empty()) //�������ı�
        	mn=min(mn,T[rs].q.top().dis+temp+T[id].midlen);
		temp=w;
    }
    return mn;
}

int main(){
	scanf("%d",&n);
    init();
    int u,v;
    for(int i=1;i<n;i++){
        scanf("%d%d",&u,&v);
        add(u,v,1);add(v,u,1);//�ޱ�Ȩ,��Ϊ1 
    }
    rebuild();//�ؽ���  
    DFS(cnt=1,1);//�߷��εݹ�
    int opt,m; 
	white=0;//��ʼ��û�а׵�
    scanf("%d",&m);
    while(m--){
        scanf("%d%d",&opt,&u);
        if(opt==1){
			if(!white)
            	printf("-1\n");
            else if(mark[u]) //uΪ��ɫ 
            	printf("0\n");
			else
				printf("%d\n",query(u));
        }
		else
			update(u);
    }
    return 0;
}
