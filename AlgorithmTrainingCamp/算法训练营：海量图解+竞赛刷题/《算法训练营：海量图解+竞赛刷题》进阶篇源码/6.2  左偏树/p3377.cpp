#include<cstdio>
#include<algorithm>
using namespace std;
const int maxn=100010;
int v[maxn],l[maxn],r[maxn],d[maxn],fa[maxn];
bool del[maxn];//标记删除 

int merge(int x,int y){
    if(!x) return y;
    if(!y) return x;
    if(v[x]>v[y]||(v[x]==v[y]&&x>y)) swap(x,y);//小顶堆 
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
    int n,m,opt,x,y;
    d[0]=-1;
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++){
        scanf("%d",&v[i]);
        l[i]=r[i]=d[i]=del[i]=0;
        fa[i]=i;
    }
    while(m--){
        scanf("%d",&opt);
        if(opt==1){
			scanf("%d%d",&x,&y);
			if(del[x]||del[y]) continue;
			int fx=find(x),fy=find(y);
			if(fx==fy) continue;
			merge(fx,fy);
		}else{
			scanf("%d",&x);
			if(del[x]){
				printf("-1\n");
			}else{
				int fx=find(x);
				printf("%d\n",v[fx]);
				del[fx]=1;//标记删除 
				fa[fx]=pop(fx);//坑点，被删除节点的父亲改为新根，并查集中被删节点可能有子节点	
			}
		}
    }
    return 0;
}
