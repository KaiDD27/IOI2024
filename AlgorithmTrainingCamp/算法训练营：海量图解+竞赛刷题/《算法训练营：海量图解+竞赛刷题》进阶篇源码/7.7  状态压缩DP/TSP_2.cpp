#include<cstring>//���仯�ݹ飬�����·�� 
#include<iostream>
#include<algorithm>
using namespace std;
const int INF=0x3f3f3f3f;
int dp[1<<15][20];//dp[S][u]:S��ʾ�Ѿ����Ľڵ㣬��u������������ʣ�ඥ��ص�������̾���
int g[15][15];
int n,m; //n���ڵ㣬m����

void Init(){
    memset(dp,-1,sizeof(dp));
    memset(g,0x3f,sizeof(g));
}

int Traveling(int S,int u){//����dp[S][u],���仯�ݹ� 
	if(dp[S][u]>=0)
    	return dp[S][u];
	if(S==(1<<n)-1&&u==0)
		return dp[S][u]=0;//�ݹ��������
    int ans=INF;
	for(int v=0;v<n;v++)
		if(!(S>>v&1)&&g[u][v]!=INF)
			ans=min(ans,Traveling(S|1<<v,v)+g[u][v]);
    return dp[S][u]=ans;
}

int main(){
/*����ͼ 
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
	int u,v,w;//u,v������У�w����u��v����֮��·�ĳ���
    cin>>n>>m;
    Init();
    for(int i=0;i<m;i++){
       cin>>u>>v>>w;
       //g[u][v]=g[v][u]=w;
       g[u][v]=w;
    }
    cout<<"���·������:"<<Traveling(0,0)<<endl;
    return 0;
}
