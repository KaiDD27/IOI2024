#include<cstdio>
#include<algorithm>
#include<queue>
using namespace std;
const int maxn=100010;
int v[maxn],l[maxn],r[maxn],d[maxn],fa[maxn];
int n,root;
queue<int>q;

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

void pop(){
    fa[l[root]]=l[root];fa[r[root]]=r[root];
    root=merge(l[root],r[root]);
}

void create1(){
	root=0;
	for(int i=1;i<=n;i++)
        root=merge(root,i);
}

void create2(){
	root=0;
	while(q.size()!=1){
		int t1=q.front();
		//printf("t1=%d\n",t1);
		q.pop();
		int t2=q.front();
		//printf("t2=%d\n",t2);
		q.pop();
		root=merge(t1,t2);
		//printf("root=%d\n",root);
		q.push(root);
	}
}

void print(int rt){
	if(!rt) return;
	printf("v=%d lc=%d rc=%d\n",v[rt],v[l[rt]],v[r[rt]]);
	print(l[rt]);
	print(r[rt]);
}

int main(){
    d[0]=-1;
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%d",&v[i]);
        l[i]=r[i]=d[i]=0;
        fa[i]=i;
        q.push(i);
    }
	create2();
	print(root);
	printf("max=%d\n",v[root]);
	pop();
	print(root);
    return 0;
}
