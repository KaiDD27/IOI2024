#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int maxn=100005;
int n,mx;//n���ڵ�,���ֵ 
int trie[maxn*32][2],tot;//�ֵ����洢����01λ 
int head[maxn],dx[maxn],cnt;//ͷ��㣬�Ӹ�����ǰ�ڵ����б�Ȩ��xorֵ 
struct Edge{
	int to,w,next;
}e[maxn<<1];
 
void add(int u,int v,int w){
	e[++cnt].to=v;
	e[cnt].w=w;
	e[cnt].next=head[u];
	head[u]=cnt;
}

void dfs(int u,int f){//��dx,�Ӹ�����ǰ�ڵ����б�Ȩ��xorֵ 
	for(int i=head[u];i;i=e[i].next){
        int v=e[i].to,w=e[i].w;
        if(v==f)//���ڵ� 
			continue;
        dx[v]=dx[u]^w; 
        dfs(v,u);
    }
}

void insert(int num){
	int p=1;
	for(int i=30;i>=0;i--){
		bool k=num&(1<<i);
		if(!trie[p][k])
			trie[p][k]=++tot;
		p=trie[p][k];
	}
}

int find(int num){
	int p=1,res=0;
	for(int i=30;i>=0;i--){
		bool k=num&(1<<i);
		if(trie[p][k^1]){//���෴·��
			res+=1<<i;
			p=trie[p][k^1];
		}
		else
			p=trie[p][k];
	}
	return res; 
}

void init(){
	memset(head,0,sizeof(head));
	memset(trie,0,sizeof(trie));
	cnt=0;
	tot=1;
	mx=0;
}

int main(){
	int u,v,w;
	while(~scanf("%d",&n)){
		init();
		for(int i=1;i<n;i++){//n-1����
			scanf("%d%d%d",&u,&v,&w);
			add(u+1,v+1,w);
			add(v+1,u+1,w);
		}
		dx[1]=0;
		dfs(1,0);
		insert(dx[1]);
		for(int i=2;i<=n;i++){
			mx=max(mx,find(dx[i]));
			insert(dx[i]);
		}
		printf("%d\n",mx);
	}
	return 0;
}
