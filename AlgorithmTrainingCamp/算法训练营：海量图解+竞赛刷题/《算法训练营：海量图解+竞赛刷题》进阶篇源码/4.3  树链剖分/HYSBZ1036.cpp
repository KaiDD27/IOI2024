#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int maxn=30005;
int n,m;//n����㣬m����ѯ
int head[maxn],cnt=0,total=0;//ͷ���
int fa[maxn],dep[maxn];//���ף���� 
int size[maxn],son[maxn],top[maxn];//��������������ض��ӣ������������˽��
int w[maxn];//Ȩֵ
int id[maxn],rev[maxn];//u��Ӧ��dfs���±꣬�±���ڵ�u 
int Max,Sum;
struct edge{
	int to,next;
}e[maxn<<1];
 
struct node{//���
	int l,r,mx,sum;//l,r��ʾ�������Ҷ˵㣬mx��ʾ����[l,r]����ֵ 
}tree[maxn*4]; //�����洢���� 

int readin(){//ע�⣺����c++����ᳬʱ 
	char c;
	int sign=1;
	while((c=getchar())<'0'||c>'9')
		if(c=='-')
			sign=-1;
	int res=c-'0';
	while((c=getchar())>='0'&&c<='9')
		res=res*10+c-'0';
	return res*sign;
}

void add(int u,int v){
	e[++cnt].to=v;
	e[cnt].next=head[u];
	head[u]=cnt;
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

void dfs2(int u,int t){//��top,id,rev
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

void build(int k,int l,int r){//�����߶���,k��ʾ�洢�±�,����[l,r]
	tree[k].l=l;
	tree[k].r=r;
	if(l==r){
		tree[k].mx=tree[k].sum=w[rev[l]];
		return;
	}
	int mid,lc,rc;
	mid=(l+r)/2;//���ֵ� 
	lc=k*2;  //���Ӵ洢�±� 
	rc=k*2+1;//�Һ��Ӵ洢�±� 
	build(lc,l,mid);
	build(rc,mid+1,r);
	tree[k].mx=max(tree[lc].mx,tree[rc].mx);//�������ֵ�������Һ�����ֵ�����ֵ 		
	tree[k].sum=tree[lc].sum+tree[rc].sum;//���ĺ�ֵ��������������ֵ 
}

void query(int k,int l,int r){//������[l..r]����ֵ����ֵ 
	if(tree[k].l>=l&&tree[k].r<=r){//�ҵ�������
		Max=max(Max,tree[k].mx);
		Sum+=tree[k].sum;
		return;
	} 
	int mid,lc,rc;
	mid=(tree[k].l+tree[k].r)/2;//���ֵ� 
	lc=k*2;  //���Ӵ洢�±� 
	rc=k*2+1;//�Һ��Ӵ洢�±�
	if(l<=mid)
		query(lc,l,r);//����������ѯ 
	if(r>mid)
		query(rc,l,r);//����������ѯ
}

void ask(int u,int v){//��u,v֮�����ֵ���ֵ 
	while(top[u]!=top[v]){//����ͬһ��������
		if(dep[top[u]]<dep[top[v]])
			swap(u,v);
		query(1,id[top[u]],id[u]);//u���˽���u֮�� 
		u=fa[top[u]];
	}
	if(dep[u]>dep[v])//��ͬһ�������� 
		swap(u,v); //���С�Ľ��Ϊu
	query(1,id[u],id[v]);
}

void update(int k,int i,int val){//u��Ӧ���±�i������ֵ�޸ĸ���Ϊval
	if(tree[k].l==tree[k].r&&tree[k].l==i){//�ҵ�i
		tree[k].mx=tree[k].sum=val;
		return;
	}
	int mid,lc,rc;
	mid=(tree[k].l+tree[k].r)/2;//���ֵ� 
	lc=k*2;  //���Ӵ洢�±� 
	rc=k*2+1;//�Һ��Ӵ洢�±�
	if(i<=mid)
		update(lc,i,val);//���������޸ĸ��� 
	else
		update(rc,i,val);//���������޸ĸ���
	tree[k].mx=max(tree[lc].mx,tree[rc].mx);//����ʱ�޸ĸ�����ֵ
	tree[k].sum=tree[lc].sum+tree[rc].sum;//����ʱ�޸ĸ��º�ֵ
}

int main(){
	int x,y;
	char str[10];
	n=readin();
	for(int i=1;i<n;i++){
		x=readin();
		y=readin();
		add(x,y);
		add(y,x);
	}
	for(int i=1;i<=n;i++)
		cin>>w[i];
	dep[1]=1;
	dfs1(1,0);
	dfs2(1,1);
	build(1,1,total);//�����߶���
	m=readin();
	for(int i=1;i<=m;i++){
		scanf("%s",str);
		x=readin();
		y=readin();
		if(str[0]=='C')
			update(1,id[x],y);
		else{
			Sum=0;
			Max=-0x3f3f3f3f;
			ask(x,y);
			if(str[1]=='M')
				printf("%d\n",Max);
			else
				printf("%d\n",Sum);	
		}	
	}
	return 0;
}
