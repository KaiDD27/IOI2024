#include<cstdio>
#include<algorithm>
#define MAXN 300005
#define lc c[x][0]
#define rc c[x][1]
using namespace std;
int n,m,a[MAXN];

struct Link_Cut_Tree{
	int top,c[MAXN][2],fa[MAXN],v[MAXN],st[MAXN],rev[MAXN];
	void update(int x){v[x]=v[lc]^v[rc]^a[x];}//更新当前节点的值（路径上点值XOR） 
	void pushdown(int x){//下传懒惰标记 
		if(rev[x]){
			rev[lc]^=1;rev[rc]^=1;rev[x]^=1;
			swap(lc,rc);
		}
	}
	bool isroot(int x){return c[fa[x]][0]!=x&&c[fa[x]][1]!=x;}//判断是否是所在Splay的根节点  
	void rotate(int x){//旋转，将x变成y的父节点 
		int y=fa[x],z=fa[y],k;
		k=x==c[y][0];
		if(!isroot(y)) c[z][c[z][1]==y]=x;//如果y不是根节点，那么将z的儿子y变成x
		fa[x]=z;fa[y]=x;fa[c[x][k]]=y;
		c[y][!k]=c[x][k];c[x][k]=y;
		update(y);update(x);
	}
	void splay(int x){
		st[top=1]=x;
		for(int i=x;!isroot(i);i=fa[i]) st[++top]=fa[i];//一定要从上往下 
		while(top) pushdown(st[top--]);
		while(!isroot(x)){//将x旋到根 
			int y=fa[x],z=fa[y];
			if(!isroot(y)) (c[y][0]==x)^(c[z][0]==y)?rotate(x):rotate(y);
			rotate(x);
		}
	}
	void access(int x){//连接一条x到根的重链
		for(int y=0;x;x=fa[y=x])
			splay(x),rc=y,update(x);
	}
	void makeroot(int x){//换根，将x变成原树的根 
		access(x);splay(x);rev[x]^=1;
	}
	int findroot(int x){//找x的根节点 
		access(x);splay(x);
		while(lc) x=lc;
		return x;
	}
	void split(int x,int y){//拉出一条x到y的路径为一个Splay 
		makeroot(x);access(y);splay(y);
	}
	void cut(int x,int y){//删除一条x到y的边 
		split(x,y);
		if(c[y][0]!=x||c[x][1]) return;//坑点，此时x是y的左儿子，且x没有右儿子，如果有说明x--y中间有节点 
		c[y][0]=fa[c[y][0]]=0;update(y);
	}
	void link(int x,int y){//连一条x到y的轻边 
		makeroot(x);fa[x]=y;
	}
}LCT;

int main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++) scanf("%d",&a[i]),LCT.v[i]=a[i];
	while(m--){
		int opt,x,y;
		scanf("%d%d%d",&opt,&x,&y);
		if(opt==0){
			LCT.split(x,y);
			printf("%d\n",LCT.v[y]);
		}else
		if(opt==1){
			if(LCT.findroot(x)!=LCT.findroot(y))//不连通 
				LCT.link(x,y);
		}else
		if(opt==2){
			if(LCT.findroot(x)==LCT.findroot(y))//连通 
				LCT.cut(x,y);
		}else
		if(opt==3){
			LCT.splay(x);a[x]=y;
		}
	}
	return 0;
}
