#include<iostream>
#include<algorithm>
#include<cstring>
#include<queue>
using namespace std;
const int maxn=105;
const int INF=0x3f3f3f3f;
int n;
int energy[maxn];
int power[maxn]; //记录到每一点的力量值
int cnt[maxn];  //记录访问每一个点的次数
bool g[maxn][maxn],vis[maxn];
bool reach[maxn][maxn];

void floyd(){//判断连通性 
    for(int k=1;k<=n;k++)
        for(int i=1; i<=n;i++)
            for(int j=1;j<=n;j++)
            	if(reach[i][j]||(reach[i][k]&&reach[k][j]))
					reach[i][j]=true;
}

bool spfa(int s){//判正环和求最大能量值 
    queue<int> q;
    memset(power,0,sizeof(power));
    memset(vis,0,sizeof(vis));
    memset(cnt,0,sizeof(cnt));
    power[s]=100;
    q.push(s);
    vis[s]=1;
    cnt[s]++;
    while(!q.empty()){
        int v=q.front();
        q.pop();
        vis[v]=0;
        for(int i=1;i<=n;i++){
            if(g[v][i]&&power[i]<power[v]+energy[i]&&power[v]+energy[i]>0){
                power[i]=power[v]+energy[i];
                if(!vis[i]){
                	if(++cnt[i]>=n)//有正环
                		return reach[v][n]; //返回v到n是否连通
                	vis[i]=1;
					q.push(i);
				}
            }
        }
    }
    return power[n]>0;
}

void solve(){
    int k,door;
	while(cin>>n&&n!=-1){
        memset(g,false,sizeof(g));
        memset(reach,false,sizeof(reach));
        for(int i=1;i<=n;i++){
            cin>>energy[i]>>k;
            for(int j=1;j<=k;j++){
                cin>>door;
                g[i][door]=true;
                reach[i][door]=true;
            }
        }
        floyd();
        if(!reach[1][n]){
            cout<<"hopeless"<<endl;
            continue;
        }
        if(spfa(1))
            cout<<"winnable"<<endl;
        else
            cout<<"hopeless"<<endl;
    }
}

int main(){
    solve();
    return 0;
}
