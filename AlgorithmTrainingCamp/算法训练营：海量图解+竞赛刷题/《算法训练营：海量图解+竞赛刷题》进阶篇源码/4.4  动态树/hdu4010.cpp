#include<cstring>
#include<cstdio>
#include<algorithm>
const int inf=0x3f3f3f3f;
const int N=300005;
using namespace std;
int n,m,top;
int c[N][2],fa[N],v[N],st[N],add[N],mx[N];
bool rev[N];

void update(int x){
    int l=c[x][0],r=c[x][1];
    mx[x]=max(mx[l],mx[r]);
    mx[x]=max(mx[x],v[x]);
}

void pushdown(int x){
    int l=c[x][0],r=c[x][1];
    if(rev[x]){
        rev[l]^=1;rev[r]^=1;rev[x]^=1;
        swap(c[x][0],c[x][1]);
    }
    if(add[x]){
        if(l){add[l]+=add[x];mx[l]+=add[x];v[l]+=add[x];}
        if(r){add[r]+=add[x];mx[r]+=add[x];v[r]+=add[x];}
        add[x]=0;
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

void addval(int x,int y,int val){
    split(x,y);
	add[y]+=val;mx[y]+=val;v[y]+=val;
}

int main(){
    int opt,x,y,w;
	while(~scanf("%d",&n)){
        for(int i=0;i<=n;i++)
            add[i]=rev[i]=fa[i]=c[i][0]=c[i][1]=0;
        mx[0]=-inf;
        for(int i=1;i<n;i++){
            scanf("%d%d",&x,&y);
            link(x,y);
        }
        for(int i=1;i<=n;i++) scanf("%d",&v[i]),mx[i]=v[i];
        scanf("%d",&m);
        while(m--){
            scanf("%d%d%d",&opt,&x,&y);
			switch(opt){
            case 1:
                if(findroot(x)==findroot(y)) {puts("-1");break;}
                link(x,y);break;
            case 2:
                if(findroot(x)!=findroot(y)||x==y) {puts("-1");break;}
				cut(x,y);break;
            case 3:
				w=x;x=y;scanf("%d",&y);
				if(findroot(x)!=findroot(y)) {puts("-1");break;}
                addval(x,y,w);break;
            case 4:
                if(findroot(x)!=findroot(y)) {puts("-1");break;}
                split(x,y);printf("%d\n",mx[y]);break;
            }
        }
		puts("");
    }
    return 0;
}
