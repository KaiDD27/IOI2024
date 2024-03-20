#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;//���߼򵥴ֱ����ڵ㿪4����������4��
const int MX=4e4+5;//���鿪��С�ˣ�һֱruntime error������ 
const int MXE=4e4+5;//��������ڵ㣬�ؽ�����2N���ڵ㣬����4N 
        //T��ÿ�����ı�Ҳ��һ���ڵ㣬��4N���ڵ㣬��̬������Ҫ��� 
struct Edge{
    int v,w,nxt,pre;
}edge[MXE],E[MXE];//ԭͼ���ع�ͼ 
int Head[MX],head[MX],tail[MX],tot,rear,Max;
int sz[MX],mark[MX];//������С�������ʵ�ڵ� 
int N,n,k,cnt,root,midedge;
int ans;

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

void Delete(int u,int i){
    if(Head[u]==i)
		Head[u]=E[i].nxt;
    else
		E[E[i].pre].nxt=E[i].nxt;
    if(tail[u]==i)
		tail[u]=E[i].pre;
    else
		E[E[i].nxt].pre=E[i].pre;
}

void build(int u,int fa){//��֤ÿ����ĶȲ�����2
    int father=0;
    for(int i=head[u];~i;i=edge[i].nxt){
        int v=edge[i].v,w=edge[i].w;
        if(v==fa)continue;
        if(father==0){//��û�������ӽڵ㣬ֱ������
            ADD(u,v,w);
			ADD(v,u,w);
            father=u;
        }
		else{//�Ѿ���һ���ӽڵ㣬�򴴽�һ���½ڵ㣬��v�����½ڵ���      
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
		mark[i]=1;
    build(1,0);//�ؽ���
    get_pre();//����ÿ���ߵ�ǰ����Ϊɾ�����ı���׼�� 
}

struct node{
    int rt,midlen; //���ڵ㣬���ı�
    int ls,rs;     //�����������
}T[MX];

int q[2][MX],len[2];//��������������ÿ��ʵ�ڵ㵽���ľ��룬len[]Ϊ�����±� 

void dfs_size(int u,int fa,int dir,int flag){//��������������ӣ�������ÿ��������С
	if(mark[u])
		q[flag][len[flag]++]=dir;//��������ʵ�ڵ㵽���ľ������ 
    sz[u]=1;
    for(int i=Head[u];~i;i=E[i].nxt){
        int v=E[i].v,w=E[i].w;
        if(v==fa) continue;
        dfs_size(v,u,dir+w,flag);
        sz[u]+=sz[v];
    }
}

void dfs_midedge(int u,int code){//�����ı�
    if(max(sz[u],sz[T[root].rt]-sz[u])<Max){
        Max=max(sz[u],sz[T[root].rt]-sz[u]);
        midedge=code;
    }
    for(int i=Head[u];~i;i=E[i].nxt){
        int v=E[i].v;
        if(i!=(code^1))
			dfs_midedge(v,i);
    }
}

void solve(int ls,int rs,int midlen){//��ѯ���벻����k�Ľڵ��� 
	sort(q[0],q[0]+len[0]);
	sort(q[1],q[1]+len[1]);
	for(int i=0,j=len[1]-1;i<len[0];i++){
		while(j>=0&&q[0][i]+q[1][j]+midlen>k)
			j--;
		ans+=j+1;
	}
}

int getmide(int id,int u,int flag){//������ıߣ����� 
	Max=N;midedge=-1;
    root=id;T[id].rt=u;
    len[flag]=0;
    dfs_size(u,0,0,flag);
	dfs_midedge(u,-1);
	return midedge;
}

void DFS(int id,int midedge,int flag){//�ݹ����
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
        int t1=getmide(T[id].ls,p1,0);
        int t2=getmide(T[id].rs,p2,1);
        solve(T[id].ls,T[id].rs,T[id].midlen);
        DFS(T[id].ls,t1,0);
    	DFS(T[id].rs,t2,1);
    }
}

int main(){
	while(scanf("%d%d",&n,&k),n+k){
		init();
		int u,v,w;
		for(int i=1;i<n;i++){
		    scanf("%d%d%d",&u,&v,&w);
		    add(u,v,w);
			add(v,u,w); 
		}
		ans=0;
		if(n>1){
			rebuild();//�ؽ�
			root=1; 
		    T[root].rt=1;//T����
		    len[0]=0;//�������鳤�� 
		    cnt=1;//T���ڵ��� 
		    int t=getmide(1,1,0);//�õ����ı� 
			DFS(1,t,0);//�߷��εݹ�
		}
        printf("%d\n",ans);
	}
    return 0;
}
