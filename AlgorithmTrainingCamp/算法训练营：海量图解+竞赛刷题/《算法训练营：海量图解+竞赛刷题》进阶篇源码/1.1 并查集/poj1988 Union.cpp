#include<cstdio>
#include<cstring>
using namespace std;
#define N 30010
int n,fa[N],d[N],cnt[N];

void Init(){
	for(int i=1;i<N;i++){
		fa[i]=i;
		d[i]=0;
		cnt[i]=1;
	}	
}

int Find(int x){
	int fx=fa[x];
	if(x!=fa[x]){
		fa[x]=Find(fa[x]);
		d[x]+=d[fx];
	} 	
    return fa[x];
}

void Union(int x,int y){
    int a,b;
    a=Find(x);
    b=Find(y);
	fa[a]=b;
    d[a]=cnt[b];
    cnt[b]+=cnt[a];
}

int main(){
	char op[3];
	int i,j;
	while(~scanf("%d",&n)){
		Init();
		while(n--){
			scanf("%s",op);
			if(op[0]=='C'){
				scanf("%d",&i);
				int fi=Find(i);
				printf("%d\n",d[i]);
			}
			else{
				scanf("%d%d",&i,&j);
				Union(i,j);
			}
		}
	}
	return 0;
}
