#include<cstdio>
#include<algorithm>
using namespace std;
const int maxn=110000;
int cnt,n,q,tot,pl;
int Pool[maxn*50];
int head[maxn],F[maxn],dis[20][maxn],cur[maxn],id[maxn],w[maxn];//id[]Ϊ�ڵ����� 
int root,S,size[maxn],f[maxn];//f[]Ϊɾ��u����������Ĵ�С  
bool vis[maxn];
int ans;
struct edge{
	int to,next;
}edge[maxn<<1];

struct BIT{//��״���� 
	int *C,n;
	void init(int T){//��ʼ�� 
		n=T;
		C=Pool+pl;
		pl+=n+1;
		for(int i=0;i<=n;i++)
			C[i]=0;
	}
	int que(int x){//��ѯǰ׺�� 
		x++;
		int res=0;
		for(int i=x;i;i-=(i&-i))
			res+=C[i];
		return res;
	}
	void add(int x,int y){//����� 
		x++;
		for(int i=x;i<=n;i+=(i&-i))
			C[i]+=y;
	} 
}C[4*maxn][2];//������״���� 

void init(){
	tot=cnt=pl=root=0;
	for(int i=1;i<=n;i++)
		vis[i]=head[i]=0;
	f[0]=S=n;
}

void add(int u,int v){
	edge[++cnt].to=v;
	edge[cnt].next=head[u];
	head[u]=cnt;
}

void getroot(int u,int fa){//�������
    size[u]=1;
	f[u]=0;//ɾ��u����������Ĵ�С 
    for(int i=head[u];i;i=edge[i].next){
    	int v=edge[i].to;
    	if(v!=fa&&!vis[v]){
            getroot(v,u);
            size[u]+=size[v];
       		f[u]=max(f[u],size[v]);
        }
	}    
    f[u]=max(f[u],S-size[u]);//SΪ��ǰ�����ܽ���� 
    if(f[u]<f[root])
		root=u;
}

void dfs(int dep,int idx,int u,int d,int fa){
	C[idx][0].add(dis[dep][u]=d,w[u]);  //��u�ڵ��Ȩֵw[u]���뵽��1����״��״��dis[][]+1λ�ã�dis[dep-1][u]��ʾu����ǰ�����ĵľ��� 
	if(dep>1)                           //��ǰ��δ���1��˵��������һ������ 
		C[idx][1].add(dis[dep-1][u],w[u]);//��w[u]���뵽��2����״��״��dis[][]+1λ�ã�dis[dep-1][u]��ʾu����һ�����ĵľ��� 
    for(int i=head[u];i;i=edge[i].next){//u��ÿһ���ڽӵ�v 
    	int v=edge[i].to;
    	if(v!=fa&&!vis[v])
    		dfs(dep,idx,v,d+1,u); //��v������������ȱ���������+1 
    }
}

void solve(int u,int fa){//uΪ��ǰ���ģ�faΪ��һ������ 
	vis[u]=1;
	F[id[u]=++tot]=id[fa];//F[]��ʾ��һ�����ı�ţ�id[u]��ʾu�ڵ�ı��
	cur[id[u]]=cur[id[fa]]+1;//cur[]��ʾ��ǰ�ڵ��������ĵĲ�Σ�������һ�����ĵĲ��+1 
	C[tot][0].init(S+1);//��ʼ����1����״���飬0�ռ䲻�ã���˽ڵ���S+1 
	C[tot][1].init(S+1);//��ʼ����2����״����
	dfs(cur[id[u]],id[u],u,0,0);//��u��ʼ������ȱ���
	int tmp=S;
	for(int i=head[u];i;i=edge[i].next){
    	int v=edge[i].to;
    	if(vis[v]) continue;
    	root=0;
    	S=size[u]>size[v]?size[v]:tmp-size[u];
    	getroot(v,u); //����vΪ�������������� 
    	solve(root,u); //�ݹ���� 
	}
}

void query(int k,int x,int y){//��ѯ�� 
    int d=max(-1,min(C[k][0].n-1,y-dis[cur[k]][x]));//C[k][0].n-1��ʾ��ǰ�ڵ��������ĵĽڵ��� 
    ans+=C[k][0].que(d);//���һ����״������С�ڵ���d��ǰ׺�� 
    if(F[k]){//��һ�����ĵĲ�� 
    	d=max(-1,min(C[k][1].n-1,y-dis[cur[k]-1][x]));//��һ������ 
    	ans-=C[k][1].que(d);//��ȥ�ظ����ڶ�����״������С�ڵ���d��ǰ׺�� 
    	query(F[k],x,y);//����һ���������
	}
}

void update(int k,int x,int y){//����� 
    C[k][0].add(dis[cur[k]][x],y);//���µ�һ����״���飬dis[cur[k]][x]��ʾx����ǰ�����ĵľ��� 
    if(F[k]){
    	C[k][1].add(dis[cur[k]-1][x],y);//���µڶ�����״���飬dis[cur[k]-1][x]��ʾx����һ�����ĵľ��� 
    	update(F[k],x,y);//����һ����� 
	} 
}

int main(){
	int x,y;
	while(~scanf("%d%d",&n,&q)){
        init();
        char s[3];
        for(int i=1;i<=n;i++)
			scanf("%d",&w[i]);
        for(int i=1;i<n;i++){
            scanf("%d%d",&x,&y);
            add(x,y);
            add(y,x);
        }
        getroot(1,0);
        solve(root,0);
        for(int i=1;i<=q;i++){
        	scanf("%s%d%d",s,&x,&y);
	        if(s[0]=='!'){
	        	update(id[x],x,y-w[x]);
	        	w[x]=y;
			}
	        else{
	        	ans=0;
	        	query(id[x],x,y);
	        	printf("%d\n",ans);
			}
		}
    }
    return 0;
}
