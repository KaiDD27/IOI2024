#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
const int maxn=100010;
int v[maxn],l[maxn],r[maxn],d[maxn],fa[maxn];

int merge(int x,int y){
    if(!x) return y;
    if(!y) return x;
    if(v[x]<v[y]) swap(x,y);
    r[x]=merge(r[x],y);
    fa[r[x]]=x;
    if(d[l[x]]<d[r[x]]) swap(l[x],r[x]);
    d[x]=d[r[x]]+1;
    return x;
}

int pop(int x){
    fa[l[x]]=l[x];fa[r[x]]=r[x];
    return merge(l[x],r[x]);
}

int find(int x){
    return fa[x]==x?x:fa[x]=find(fa[x]);
}

int main(){
    int n,m,x,y;
    d[0]=-1;
    while(~scanf("%d",&n)){
        for(int i=1;i<=n;i++){
            scanf("%d",&v[i]);
            l[i]=r[i]=d[i]=0;
            fa[i]=i;
        }
		scanf("%d",&m);
        while(m--){
            scanf("%d%d",&x,&y);
            int fx=find(x),fy=find(y);
            if(fx==fy){printf("-1\n");continue;}
            int rt=pop(fx);//É¾³ý×î´óÖµ
            v[fx]/=2;l[fx]=r[fx]=d[fx]=0;
            fx=merge(rt,fx);
            rt=pop(fy);
            v[fy]/=2;l[fy]=r[fy]=d[fy]=0;
            fy=merge(rt,fy);
			rt=merge(fx,fy);
            printf("%d\n",v[rt]);      
        }
    }
    return 0;
}
