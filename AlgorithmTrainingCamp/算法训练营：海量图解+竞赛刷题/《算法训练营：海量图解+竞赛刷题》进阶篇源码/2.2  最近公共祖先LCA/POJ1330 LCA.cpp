#include<cstdio>
using namespace std;
const int maxn=10010;
int fa[maxn];
bool flag[maxn];

void Init(int n){
	for(int i=1;i<=n;i++){
		fa[i]=i;
		flag[i]=0;
	} 
}

int LCA(int u,int v){
    if(u==v)
    	return u;
	flag[u]=1;
	while(fa[u]!=u){//u向上走到根
		u=fa[u];
		flag[u]=1;
	}
	if(flag[v]) 
		return v;
	while(fa[v]!=v){//v向上
		v=fa[v];
		if(flag[v])
			return v;
	}
	return 0;   	
}

int main(){
	int n,u,v,T;
	scanf("%d",&T);
	while(T--){
		scanf("%d",&n);
		Init(n);
		for(int i=1;i<n;i++){
			scanf("%d%d",&u,&v);
			fa[v]=u;
		}
		scanf("%d%d",&u,&v);
		printf("%d\n",LCA(u,v));
	}
	return 0;
}
