#include<cstdio>
#include<cstring>
using namespace std;
const int maxn=80010;
int fa[maxn],head[maxn],qhead[maxn],dis[maxn];
bool vis[maxn];
int id,iq;
struct Node{//ͼ�еı�E�Ͳ�ѯQE��ͳһ�ṹ��
    int to;
    int next;
    int lca;//ͼ��lca��ʾu��v�ı�Ȩ����ѯ��lca�����ѯu��v����̾��� 
}E[maxn],QE[maxn];
 
int find(int x){
    if(x!=fa[x])
        fa[x]=find(fa[x]);
    return fa[x];
}
 
void LCA(int u){
    fa[u]=u;
    vis[u]=true;
    for(int i=head[u];i!=-1;i=E[i].next){
        int v=E[i].to;
		if(!vis[v]){
            dis[v]=dis[u]+E[i].lca;
            LCA(v);
            fa[v]=u;
        }
    }
    for(int i=qhead[u];i!=-1;i=QE[i].next){
        int v=QE[i].to;
		if(vis[v]){
            QE[i].lca=dis[u]+dis[v]-2*dis[find(v)];
            QE[i^1].lca=QE[i].lca;
        }
    }
}

void add1(int u,int v,int w){
	E[id].to=v;
    E[id].lca=w;
    E[id].next=head[u];
    head[u]=id++;
}

void add2(int u,int v){
	QE[iq].to=v;
    QE[iq].next=qhead[u];
    qhead[u]=iq++;
}

void init(){
    memset(fa,0,sizeof(fa));
    memset(head,-1,sizeof(head));
    memset(qhead,-1,sizeof(qhead));
    memset(vis,false,sizeof(vis));
    memset(E,0,sizeof(E));
    memset(QE,0,sizeof(QE));
    memset(dis,0,sizeof(dis));
    id=iq=0;
}

int main(){
    int N,M,K,u,v,w;
    char s;
    while(~scanf("%d%d",&N,&M)){
        init();
		for(int i=0;i<M;i++){   //%*c������һ���ַ�������������������ֵ���κα�����
            scanf("%d%d%d %c",&u,&v,&w,&s);//%cǰ��Ŀո��������οհ׷�
            add1(u,v,w);
            add1(v,u,w);
        }
        scanf("%d",&K);
        for(int i=0;i<K;i++){
            scanf("%d%d",&u,&v);
        	add2(u,v);//��ѯҲ����ʽǰ���Ǵ洢
        	add2(v,u);
        }
        LCA(1);
        for(int i=0;i<iq;i+=2)
            printf("%d\n",QE[i].lca);
    }
    return 0;
}
