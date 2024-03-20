#include<cstdio>
#include<cstring>
using namespace std;
const int maxn=105;
int n,m,k,ans;
int g[maxn][maxn],x[maxn];

bool check(int t){
    for(int j=1;j<t;j++){
        if(g[t][j]&&(x[t]==x[j]))
        	return 0;
    }
    return 1;
}

void Backtrack(int t){
    if(t>n){
        ans++;
        return;
    }
    for(int i=1;i<=m;i++){
        x[t]=i;
        if(check(t))
			Backtrack(t+1);
    }    
}

int main(){
	scanf("%d%d%d",&n,&k,&m);
	int u,v;
	for(int i=1;i<=k;i++){
        scanf("%d%d",&u,&v);
        g[u][v]=g[v][u]=1;
    }
    Backtrack(1);
    printf("%d",ans);
    return 0; 
}
