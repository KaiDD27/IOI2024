#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
using namespace std;
vector<int> E[100005];
int n,T;

int dfs(int u){
    if(E[u].size()==0) return 1;
    int k=E[u].size();
	vector<int> d;
    for(int i=0;i<k;i++)
        d.push_back(dfs(E[u][i]));
    sort(d.begin(),d.end());
    int c=(k*T-1)/100+1,ans=0;//c=ceil(k*T/100.0)
    for(int i=0;i<c;i++) 
        ans+=d[i];
    return ans;
}

int main(){
    while(~scanf("%d%d",&n,&T)&&n){
        for(int i=0;i<=n;i++)
			E[i].clear();
        for(int i=1;i<=n;i++){
            int u;
            scanf("%d",&u);
            E[u].push_back(i);
        }
        printf("%d\n",dfs(0));
    }
    return 0;
}
