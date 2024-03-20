#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int maxn=10010;
int head[maxn],cnt=0,total=0;//ͷ���
int fa[maxn],dep[maxn];//���ף���� 
int size[maxn],son[maxn],top[maxn];//��������������ض��ӣ������������˽��
int id[maxn],rev[maxn];//u��Ӧ��dfs���±꣬�±���ڵ�u 
int Max;
struct Edge{
	int u,v,w;
}a[maxn];

struct edge{
	int to,next;
}e[maxn<<1];
 
struct node{//���
	int l,r,Max,Min,lazy;//l,r�������Ҷ˵㣬������ֵ ,����� 
}tree[maxn<<2]; //�����洢���� 

void add(int u,int v){
	e[++cnt].to=v;
	e[cnt].next=head[u];
	head[u]=cnt;
}

void init(){
    cnt=total=0;
    memset(head,0,sizeof(head));
    memset(son,0,sizeof(son));
}

void dfs1(int u,int f){//��dep,fa,size,son
    size[u]=1;
	for(int i=head[u];i;i=e[i].next){
        int v=e[i].to;
        if(v==f)//���ڵ� 
			continue;
        dep[v]=dep[u]+1;//��� 
        fa[v]=u;
        dfs1(v,u);
        size[u]+=size[v];
        if(size[v]>size[son[u]])
        	son[u]=v;
    }
}

void dfs2(int u,int t){//��top,id
	top[u]=t;
	id[u]=++total;//u��Ӧ��dfs���±� 
	rev[total]=u;//dfs���±��Ӧ�Ľ��u 
	if(!son[u])
		return;
	dfs2(son[u],t);//�����ض���dfs 
	for(int i=head[u];i;i=e[i].next){
        int v=e[i].to;
        if(v!=fa[u]&&v!=son[u])
        	dfs2(v,v);
	}
}

void build(int i,int l,int r){//��ʼ���߶���,i��ʾ�洢�±�,����[l,r]
	tree[i].l=l;
	tree[i].r=r;
	tree[i].Max=tree[i].Min=tree[i].lazy=0;
	if(l==r) return;
	int mid=(l+r)/2;//���ֵ� 
	build(i<<1,l,mid);
	build((i<<1)|1,mid+1,r);
}

void push_up(int i){//�ϴ�
    tree[i].Max=max(tree[i<<1].Max,tree[(i<<1)|1].Max);
    tree[i].Min=min(tree[i<<1].Min,tree[(i<<1)|1].Min);
}

void push_down(int i){//�´�
    if(tree[i].l==tree[i].r) return;
    if(tree[i].lazy){//�´������Һ��ӣ����������
        tree[i<<1].Max=-tree[i<<1].Max;
        tree[i<<1].Min=-tree[i<<1].Min;
        swap(tree[i<<1].Min,tree[i<<1].Max);
        tree[(i<<1)|1].Max=-tree[(i<<1)|1].Max;
        tree[(i<<1)|1].Min=-tree[(i<<1)|1].Min;
        swap(tree[(i<<1)|1].Max,tree[(i<<1)|1].Min);
        tree[i<<1].lazy^=1;
        tree[(i<<1)|1].lazy^=1;
        tree[i].lazy=0;
    }
}

void update(int i,int k,int val){//����£��߶����ĵ�k��ֵΪval
    if(tree[i].l==k&&tree[i].r==k){
        tree[i].Max=val;
        tree[i].Min=val;
        tree[i].lazy=0;
        return;
    }
    push_down(i);
    int mid=(tree[i].l+tree[i].r)/2;
    if(k<=mid) update(i<<1,k,val);
    else update((i<<1)|1,k,val);
    push_up(i);
}

void update2(int i,int l,int r){//������£��߶���������[l,r]ȡ��
    if(tree[i].l>=l&&tree[i].r<=r){
        tree[i].Max=-tree[i].Max;
        tree[i].Min=-tree[i].Min;
        swap(tree[i].Max,tree[i].Min);
        tree[i].lazy^=1;
        return;
    }
    push_down(i);
    int mid=(tree[i].l+tree[i].r)/2;
    if(l<=mid) update2(i<<1,l,r);
    if(r>mid) update2((i<<1)|1,l,r);
    push_up(i);
}

void query(int i,int l,int r){//��ѯ�߶�����[l,r]�����ֵ
    if(tree[i].l>=l&&tree[i].r<=r){//�ҵ�������
		Max=max(Max,tree[i].Max);
		return;
	} 
    push_down(i);
    int mid=(tree[i].l+tree[i].r)/2;
    if(l<=mid) query(i<<1,l,r);
    if(r>mid) query((i<<1)|1,l,r);
    push_up(i);
}

void ask(int u,int v){//��u,v֮�����ֵ 
	while(top[u]!=top[v]){//����ͬһ�������� 
		if(dep[top[u]]<dep[top[v]])
			swap(u,v);
		query(1,id[top[u]],id[u]);//u���˽���u֮�� 
		u=fa[top[u]];
	}
	if(u==v) return; 
	if(dep[u]>dep[v])//��ͬһ�������� 
		swap(u,v); //���С�Ľ��Ϊu
	query(1,id[son[u]],id[v]);//ע����son[u] 
}

void Negate(int u,int v){//��u-v·���ϵıߵ�ֵȡ�෴�� 
	while(top[u]!=top[v]){//����ͬһ�������� 
		if(dep[top[u]]<dep[top[v]])
			swap(u,v);
		update2(1,id[top[u]],id[u]);//u���˽���u֮�� 
		u=fa[top[u]];
	}
	if(u==v) return; 
	if(dep[u]>dep[v])//��ͬһ�������� 
		swap(u,v); //���С�Ľ��Ϊu
	update2(1,id[son[u]],id[v]);//ע����son[u] 
}

int main(){
    int T,n;
    scanf("%d",&T);
    while(T--){
        init();
        scanf("%d",&n);
        for(int i=1;i<n;i++){
            scanf("%d%d%d",&a[i].u,&a[i].v,&a[i].w);
            add(a[i].u,a[i].v);
            add(a[i].v,a[i].u);
        }
        dep[1]=1;
        dfs1(1,0);
        dfs2(1,1);
        build(1,1,total);//�����߶���
        for(int i=1;i<n;i++){
            if(dep[a[i].u]>dep[a[i].v])
                swap(a[i].u,a[i].v);
            update(1,id[a[i].v],a[i].w);
        }
        char op[10];
        int u,v;
        while(scanf("%s",op)==1){
            if(op[0]=='D')break;
            scanf("%d%d",&u,&v);
            if(op[0]=='Q'){
            	Max=-0x3f3f3f3f;
				ask(u,v);//��ѯu->v·���ϱ�Ȩ�����ֵ
            	printf("%d\n",Max);
			}
            else if(op[0]=='C')
                update(1,id[a[u].v],v);//�ı��u���ߵ�ֵΪv
            else Negate(u,v);//����ȡ�� 
        }
    }
    return 0;
}
