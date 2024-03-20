#include<cstring>//递推，输出路径 
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
    memset(dp,0x3f,sizeof(dp));
    memset(g,0x3f,sizeof(g));
    memset(path,-1,sizeof(path));
}

void Traveling(){//计算dp[S][u]
	dp[(1<<n)-1][0]=0;//注意：1<<n一定要加括号 
	for(int S=(1<<n)-2;S>=0;S--)
        for(int u=0;u<n;u++)
            for(int v=0;v<n;v++){
            	if((u!=0&&!(S>>u&1))||g[u][v]==INF) continue;//可以加约束条件，不加状态多 
				if(!(S>>v&1)&&dp[S][u]>dp[S|1<<v][v]+g[u][v]){
                    dp[S][u]=dp[S|1<<v][v]+g[u][v];
                    cout<<"S="<<(bitset<5>(S))<<"\t   u="<<u<<"\tv="<<v<<"\tdp["<<(bitset<5>(S))<<"]["<<u<<"]=";
					cout<<"dp["<<(bitset<5>(S|1<<v))<<"]["<<v<<"]+"<<g[u][v]<<"="<<dp[S][u]<<endl;
                    path[S][u]=v;//记录后继节点
                }
        	}
}

void print(int S,int u){//打印路径
    if(S==(1<<n)-1) return;
    int v=path[S][u];//u的后继v
    cout<<"-->"<<v;
	print(S|1<<v,v);//将v加入已走过的节点集合，再从v出发
}

int main(){
/*无向图 
5 9
0 1 3
0 3 8
0 4 9
1 2 3
1 3 10
1 4 5
2 3 4
2 4 3
3 4 20
*/
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
       //g[u][v]=g[v][u]=w;//无向图 
       g[u][v]=w;//有向图 
    }
    Traveling();
    cout<<"最短路径: "<<0;
    print(0,0);
    cout<<endl;
    cout<<"最短路径长度:"<<dp[0][0]<<endl;
    return 0;
}
