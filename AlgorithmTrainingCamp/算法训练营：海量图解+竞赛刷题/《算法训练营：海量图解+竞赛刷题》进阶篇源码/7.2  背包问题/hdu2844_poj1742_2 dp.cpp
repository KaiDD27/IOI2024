#include<cstdio>//数组优化
#include<cstring>
using namespace std;
#define M 100005
int v[105],c[105],used[M];
bool dp[M];
 
int main(){
    int n,m,ans;
    while(~scanf("%d%d",&n,&m),n&&m){
        for(int i=1;i<=n;i++)
            scanf("%d",&v[i]);
        for(int i=1;i<=n;i++)
            scanf("%d",&c[i]);
        memset(dp,0,sizeof(dp));
        ans=0,dp[0]=1;
        for(int i=1;i<=n;i++){
            memset(used,0,sizeof(used));
            for(int j=v[i];j<=m;j++){
                if(!dp[j]&&dp[j-v[i]]&&used[j-v[i]]<c[i]){
                    dp[j]=1;
                    used[j]=used[j-v[i]]+1;
                    ans++;
                }
            }
        }
        printf("%d\n",ans);
    }
    return 0;
}

