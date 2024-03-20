#include<cstring>
#include<cstdio>
#include<algorithm>
const int inf=0x3f3f3f3f;
const int N=40005;
using namespace std;
int n,top;
int c[N][2],fa[N],v[N],mx[N],mn[N],st[N];
bool rev[N],reg[N];

void update(int x){
	int l=c[x][0],r=c[x][1];
	mx[x]=max(mx[l],mx[r]);
	mn[x]=min(mn[l],mn[r]);
	if(v[x]!=-inf&&v[x]!=inf){
		mx[x]=max(mx[x],v[x]);
		mn[x]=min(mn[x],v[x]);
	}
}

void phr(int x){//先修改+打懒标
	reg[x]^=1,
	v[x]=-v[x];
    mx[x]=-mx[x];
	mn[x]=-mn[x];
	swap(mx[x],mn[x]);
}

void pushdown(int x){
    int l=c[x][0],r=c[x][1];
    if(rev[x]){
        rev[l]^=1;rev[r]^=1;rev[x]^=1;
        swap(c[x][0],c[x][1]);
    }
    if(reg[x]){
        if(l) phr(l);
		if(r) phr(r);
		reg[x]^=1;
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

void change(int x,int w){
	splay(x);
	v[x]=w;
}

void query(int x,int y){
	split(x,y);
	printf("%d\n",mx[y]);
}

void neg(int x,int y){
	split(x,y);
	phr(y);
}

void init(){
    memset(c,0,sizeof(c));
	memset(fa,0,sizeof(fa));
    memset(rev,0,sizeof(rev));
    memset(reg,0,sizeof(reg));
    memset(v,0,sizeof(v));
}

int main(){
    int T,x,y,w;
    char opt[10];
    scanf("%d",&T);
	while(T--){
        init();
		scanf("%d",&n);
        mx[0]=-inf,mn[0]=inf;
		for(int i=1;i<n;i++){
            scanf("%d%d%d",&x,&y,&w);
            v[i]=-inf;
			v[n+i]=w;
            link(x,n+i);
            link(n+i,y);
        }
        v[n]=-inf;
        while(~scanf("%s",&opt)){
            if(opt[0]=='D') break;
            scanf("%d%d",&x,&y);
            if(opt[0]=='C') change(n+x,y);
            else if(opt[0]=='Q') query(x,y);
            else if(opt[0]=='N') neg(x,y);
        }
    }
    return 0;
}
