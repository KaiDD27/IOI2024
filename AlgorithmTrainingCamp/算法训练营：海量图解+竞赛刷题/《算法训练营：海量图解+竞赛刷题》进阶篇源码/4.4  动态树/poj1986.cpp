#include<cstring>
#include<cstdio>
#include<algorithm>
const int N=100005;
using namespace std;
int n,m,q,top;
int c[N][2],fa[N],v[N],dis[N],st[N];
bool rev[N];

void update(int x){
	dis[x]=dis[c[x][0]]+dis[c[x][1]]+v[x];
}

void pushdown(int x){
    int l=c[x][0],r=c[x][1];
    if(rev[x]){
        rev[l]^=1;rev[r]^=1;rev[x]^=1;
        swap(c[x][0],c[x][1]);
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

void init(){
    memset(c,0,sizeof(c));
	memset(fa,0,sizeof(fa));
    memset(rev,0,sizeof(rev));
    memset(dis,0,sizeof(dis));
}

int main(){
    int x,y,w;
    char ch;
	while(~scanf("%d%d",&n,&m)){
        init();
        for(int i=1;i<=m;i++){
            scanf("%d%d%d %c",&x,&y,&w,&ch);
            v[n+i]=w;
            link(x,n+i);
            link(n+i,y);
        }
        scanf("%d",&q);
        while(q--){
            scanf("%d%d",&x,&y);
            if(x==y) {printf("0\n");continue;}
            split(x,y);
			printf("%d\n",dis[y]);
        }
    }
    return 0;
}
