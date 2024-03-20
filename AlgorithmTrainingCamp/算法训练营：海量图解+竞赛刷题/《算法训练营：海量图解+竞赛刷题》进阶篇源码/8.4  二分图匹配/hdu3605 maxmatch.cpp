#include<cstdio>//二分图多重匹配，匈牙利算法，1279ms
#include<cstring>
using namespace std;
const int N=100002;
int cap[12],g[N][12],cnt[12],match[12][N];
bool vis[12];
int n,m;

int dfs(int u){
    for(int i=0;i<m;i++){
        if(g[u][i]&&!vis[i]){
            vis[i]=true;
            if(cnt[i]<cap[i]){//匹配次数小于容量 
                match[i][cnt[i]++]=u;
                return 1;
            }
            for(int j=0;j<cnt[i];j++){
                if(dfs(match[i][j])){
                    match[i][j]=u;
                    return 1;
                }
            }
        }
    }
    return 0;
}

int main(){
    while(~scanf("%d%d",&n,&m)){
        for(int i=0;i<n;i++)
            for(int j=0;j<m;j++)
                scanf("%d",&g[i][j]);
        for(int i=0;i<m;i++)
            scanf("%d",&cap[i]);
        memset(cnt,0,sizeof(cnt));
        bool flag=true;
        for(int i=0;i<n;i++){
            memset(vis,0,sizeof(vis));
            if(!dfs(i)){
                flag=false;
                break;
            }
        }
        if(flag) printf("YES\n");
        else printf("NO\n");
    }
    return 0;
}
