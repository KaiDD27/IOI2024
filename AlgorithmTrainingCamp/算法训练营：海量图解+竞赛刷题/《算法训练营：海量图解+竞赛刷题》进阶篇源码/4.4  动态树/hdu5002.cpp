#include<cstdio>
#include<algorithm>
const int inf=0x3f3f3f3f;
const int N=100005;
using namespace std;
int n,m,top;
int c[N][2],fa[N],v[N],st[N];
int mx1[N],mx2[N],c1[N],c2[N],size[N];//最大值、次大值，两者的重复次数，子树大小 
int ta[N],tc[N];//增加懒标记，修改懒标记 
bool rev[N];//反转懒标记

void cnt(int x,int val,int c){//统计x的子树中最大、次大值和重复次数，当前节点值为val,其重复次数为c 
	if(val>mx1[x]) mx2[x]=mx1[x],mx1[x]=val,c2[x]=c1[x],c1[x]=c;
	else if(val==mx1[x]) c1[x]+=c;
	else if(val>mx2[x]) mx2[x]=val,c2[x]=c;
	else if(val==mx2[x]) c2[x]+=c;
}

void change(int y,int val){//y为根的子树上所有节点改为val 
	mx1[y]=val;v[y]=val;c1[y]=size[y];
	mx2[y]=-inf;c2[y]=0;
    tc[y]=val;
	if(ta[y]) ta[y]=0;
}

void addval(int y,int val){//y为根的子树上所有节点加val 
	ta[y]+=val;mx1[y]+=val;v[y]+=val;
	if(mx2[y]!=inf) mx2[y]+=val;
}

void update(int x){
	int l=c[x][0],r=c[x][1];
	mx1[x]=mx2[x]=-inf;c1[x]=c2[x]=0;
    cnt(x,v[x],1);
	if(l) cnt(x,mx1[l],c1[l]),cnt(x,mx2[l],c2[l]);
	if(r) cnt(x,mx1[r],c1[r]),cnt(x,mx2[r],c2[r]);
	size[x]=size[l]+size[r]+1;
}

void pushdown(int x){
	int l=c[x][0],r=c[x][1];
	if(rev[x]){//反转 
		rev[x]^=1;rev[l]^=1;rev[r]^=1;
		swap(c[x][0],c[x][1]);//交换两者的值，不要写l,r 
	}
	if(tc[x]!=-inf){//修改 
		if(l) change(l,tc[x]);
		if(r) change(r,tc[x]);
		tc[x]=-inf;
	}
	if(ta[x]){//增加 
		if(l) addval(l,ta[x]);
		if(r) addval(r,ta[x]);
        ta[x]=0;
	}
}

bool isroot(int x){
	return c[fa[x]][0]!=x&&c[fa[x]][1]!=x;
}

void rotate(int x){
    int y=fa[x],z=fa[y];
    int k=c[y][0]==x;
    if(!isroot(y)) c[z][c[z][1]==y]=x;
    fa[x]=z;fa[y]=x;fa[c[x][k]]=y;
    c[y][!k]=c[x][k];c[x][k]=y;
    update(y);update(x);
}

void splay(int x){
    top=0;st[++top]=x;
    for(int i=x;!isroot(i);i=fa[i])
        st[++top]=fa[i];
    while(top) pushdown(st[top--]);
    while(!isroot(x)){
        int y=fa[x],z=fa[y];
        if(!isroot(y))
            (c[y][0]==x^c[z][0]==y)?rotate(x):rotate(y);
        rotate(x);
    }
}

void access(int x){
    for(int t=0;x;t=x,x=fa[x])
        splay(x),c[x][1]=t,update(x);
}

void makeroot(int x){
    access(x);splay(x);rev[x]^=1;
}

void link(int x,int y){
    makeroot(x);fa[x]=y;
}

void split(int x,int y){
    makeroot(x);access(y);splay(y);
}

void cut(int x,int y){
    split(x,y);
	c[y][0]=fa[c[y][0]]=0;update(y);
}

int findroot(int x){
    access(x);splay(x);
    while(c[x][0]) x=c[x][0];
    return x;
}

void query(int x,int y){
	if(c1[y]==size[y]) puts("ALL SAME");
	else printf("%d %d\n",mx2[y],c2[y]);
}

int main(){
	int T,cas=0;
	int opt,x,y,a,b,d;
	scanf("%d",&T);
	while(T--){
		printf("Case #%d:\n",++cas);
		scanf("%d%d",&n,&m);
		for(int i=1;i<=n;i++)
			scanf("%d",&v[i]);
		for(int i=1;i<=n;i++){
			mx1[i]=v[i],c1[i]=1;
			mx2[i]=-inf,c2[i]=0;
			size[i]=1;
		}
		for(int i=1;i<=n;i++){
			fa[i]=c[i][0]=c[i][1]=0;
			ta[i]=rev[i]=0;tc[i]=-inf;
		}
		for(int i=1;i<n;i++){
			scanf("%d%d",&x,&y);
			link(x,y);
		}
	    while(m--){
		    scanf("%d",&opt);
			if(opt==1){
				scanf("%d%d%d%d",&x,&y,&a,&b);
				cut(x,y);link(a,b);
			}
			else if(opt==2){
				scanf("%d%d%d",&a,&b,&x);
				split(a,b);
				change(b,x);
			}
			else if(opt==3){
				scanf("%d%d%d",&a,&b,&d);
				split(a,b);
				addval(b,d);
			}
			else{
				scanf("%d%d",&a,&b);
				split(a,b);
				query(a,b);
			}
		}
	}
	return 0;
}
