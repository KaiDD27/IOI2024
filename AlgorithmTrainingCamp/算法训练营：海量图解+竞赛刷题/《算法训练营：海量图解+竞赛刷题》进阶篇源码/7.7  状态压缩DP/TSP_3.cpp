#include<cstring>//记忆化递归，输出路径 
#include<bitset>
#include<iostream>
#include<algorithm>
using namespace std;
const int INF=0x3f3f3f3f;
int dp[1<<15][20];//dp[S][u]:S表示已经过的节点，从u出发走完所有剩余顶点回到起点的最短距离
int g[15][15];
int path[1<<15][15];//最优路径
int n,m; //n个节点，m条边

void Init(){
    memset(dp,-1,sizeof(dp));
    memset(g,0x3f,sizeof(g));
    memset(path,-1,sizeof(path));
}

int Traveling(int S,int u){//计算dp[S][u],记忆化递归 
    if(dp[S][u]>=0)
    	return dp[S][u];
	if(S==(1<<n)-1&&u==0)
		return dp[S][u]=0;//递归结束条件
    int ans=INF;
	for(int v=0;v<n;v++)
		if(!(S>>v&1)&&g[u][v]!=INF){
			int tmp=Traveling(S|1<<v,v)+g[u][v];
			//cout<<"S="<<(bitset<5>(S))<<"\t   u="<<u<<"\tv="<<v<<"\ttmp="<<tmp<<endl;
			if(ans>tmp){
				ans=tmp;
				cout<<"S="<<(bitset<5>(S))<<"\t   u="<<u<<"\tv="<<v<<"\tdp["<<(bitset<5>(S))<<"]["<<u<<"]=";
				cout<<"dp["<<(bitset<5>(S|1<<v))<<"]["<<v<<"]+"<<g[u][v]<<"="<<ans<<endl;
				path[S][u]=v;//记录后继节点
			}		
		}
    return dp[S][u]=ans;
}

void print(int S,int u){//打印路径
    if(S==(1<<n)-1) return;
    int v=path[S][u];//u的后继v
    cout<<"--->"<<v;
	print(S|1<<v,v);//将v加入已走过的节点集合，再从v出发
}

int main(){
/*有向图 
5 8
0 1 3
0 3 4
1 2 5
2 0 4
2 3 5
3 4 3
4 0 7
4 1 6
*/
	int u,v,w;//u,v代表城市，w代表u和v城市之间路的长度
    cin>>n>>m;
    Init();
    for(int i=0;i<m;i++){
       cin>>u>>v>>w;
       //g[u][v]=g[v][u]=w;
       g[u][v]=w;
    }
    Traveling(0,0);
    cout<<"最短路径: "<<0;
    print(0,0);
    cout<<endl;
    cout<<"最短路径长度:"<<dp[0][0]<<endl;
    return 0;
}
