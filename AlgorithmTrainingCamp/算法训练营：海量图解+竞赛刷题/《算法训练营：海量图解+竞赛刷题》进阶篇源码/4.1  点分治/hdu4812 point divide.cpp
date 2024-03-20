#include<cstdio>
#include<cstring>
#include<algorithm>
#pragma comment(linker,"/STACK:102400000,102400000")
#define inf 0x3f3f3f3f
#define P 1000003
#define ll long long
using namespace std;
const int maxn=100005;
ll inv[P+5],mp[P+5];//inv�洢��Ԫ,mp���˻�ӳ�䵽�ڵ� 
ll val[maxn],d[maxn],dep[maxn];//�ڵ��ֵ���ڵ㵽�����ĳ˻����˻�����
int cnt,n,k,top,head[maxn],id[maxn];//id[]Ϊ�ڵ����� 
int root,S,size[maxn],f[maxn];//f[]Ϊɾ��u����������Ĵ�С  
bool vis[maxn];
int ans1,ans2;
struct edge{
	int to,next;
}edge[maxn*2];

void add(int u,int v){
	edge[++cnt].to=v;
	edge[cnt].next=head[u];
	head[u]=cnt;
}

void get_inv(){//��1..P-1����Ԫ 
	inv[1]=1;
	for(int i=2;i<P;i++)
		inv[i]=((-P/i)*inv[P%i]%P+P)%P;
}

void getroot(int u,int fa){//��ȡ����
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

void getdep(int u,int fa){//��ȡ�˻� 
    dep[++top]=d[u];//����˻����� 
    id[top]=u;//����ڵ� 
    for(int i=head[u];i;i=edge[i].next){
    	int v=edge[i].to;
    	if(v!=fa&&!vis[v]){
    		d[v]=(d[u]*val[v])%P;//�˻�MOD P 
            getdep(v,u);
		}
    }
}

void query(int x,int id){//�����ڵ��� 
    x=inv[x]*val[root]*k%P;//����һ����Ļ� 
    int y=mp[x];//ӳ�䵽��� 
    if(y==0) return;
    if(y>id) swap(y,id);//��֤id>y 
    if(y<ans1||(y==ans1&&id<ans2))//���´�Ϊ��С��� 
        ans1=y,ans2=id;
}

void solve(int u){ //��ȡ��
    vis[u]=true;
    mp[val[u]]=u;//ֵӳ�䵽��� 
    for(int i=head[u];i;i=edge[i].next){
    	int v=edge[i].to;
		if(!vis[v]){
			top=0;//������vΪ�������� 
			d[v]=val[v]*val[u]%P;//��ǰ�ڵ�ֵΪ��ֵ 
			getdep(v,u);
            for(int j=1;j<=top;j++)//��ѯ����ٰ���Щ��ӳ�䣬�Ա���һ��������ѯ 
				query(dep[j],id[j]);//��һ��������ѯʱ��ֻ��������ӳ�䣬�ɴ˱�֤������һ�������ڲ���ѯ����Ϊ��Щ�ڵ㻹û��ӳ�� 
            for(int j=1;j<=top;j++)
                if(!mp[dep[j]]||mp[dep[j]]>id[j])//0��id[j]��ԭ����ֵӳ��С 
					mp[dep[j]]=id[j];
        }
    }
	mp[val[u]]=0;//�ղŸ�ֵ��mp[]���㣬��memset��ʱ 
	for(int i=head[u];i;i=edge[i].next){
		int v=edge[i].to;
		if(!vis[v]){
            top=0;
			d[v]=(val[u]*val[v])%P;
            getdep(v,u);
            for(int j=1;j<=top;j++)
                mp[dep[j]]=0;
        }
	}
	for(int i=head[u];i;i=edge[i].next){
		int v=edge[i].to;
        if(!vis[v]){
            root=0;
			S=size[v];
            getroot(v,0);
            solve(root);
        }
	}
}

int main(){
	int u,v;
	get_inv();//��1..P-1����Ԫ 
	while(~scanf("%d%d",&n,&k)){
        memset(vis,0,sizeof(vis));
        cnt=0;
		ans1=ans2=inf;
        memset(head,0,sizeof(head));
        for(int i=1;i<=n;i++)
			scanf("%d",&val[i]);
        for(int i=1;i<n;i++){
            scanf("%d%d",&u,&v);
            add(u,v);
            add(v,u);
        }
        root=0;S=n;f[0]=n+1;
        getroot(1,0);
        solve(root);
        if(ans1==inf)
			printf("No solution\n");
        else
			printf("%d %d\n",ans1,ans2);
    }
    return 0;
}
