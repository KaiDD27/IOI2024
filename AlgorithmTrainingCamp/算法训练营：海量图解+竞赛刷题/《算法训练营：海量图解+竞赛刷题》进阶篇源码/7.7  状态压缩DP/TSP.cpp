#include<cstring>//���ƣ����·�� 
#include<bitset>
#include<iostream>
#include<algorithm>
using namespace std;
const int INF=0x3f3f3f3f;
int dp[1<<15][20];//dp[S][u]:S��ʾ�Ѿ����Ľڵ㣬��u������������ʣ�ඥ��ص�������̾���
int g[15][15];
int path[1<<15][15];//����·��
int n,m; //n���ڵ㣬m����

void Init(){
    memset(dp,0x3f,sizeof(dp));
    memset(g,0x3f,sizeof(g));
    memset(path,-1,sizeof(path));
}

void Traveling(){//����dp[S][u]
	dp[(1<<n)-1][0]=0;//ע�⣺1<<nһ��Ҫ������ 
	for(int S=(1<<n)-2;S>=0;S--)
        for(int u=0;u<n;u++)
            for(int v=0;v<n;v++){
            	if((u!=0&&!(S>>u&1))||g[u][v]==INF) continue;//���Լ�Լ������������״̬�� 
				if(!(S>>v&1)&&dp[S][u]>dp[S|1<<v][v]+g[u][v]){
                    dp[S][u]=dp[S|1<<v][v]+g[u][v];
                    cout<<"S="<<(bitset<5>(S))<<"\t   u="<<u<<"\tv="<<v<<"\tdp["<<(bitset<5>(S))<<"]["<<u<<"]=";
					cout<<"dp["<<(bitset<5>(S|1<<v))<<"]["<<v<<"]+"<<g[u][v]<<"="<<dp[S][u]<<endl;
                    path[S][u]=v;//��¼��̽ڵ�
                }
        	}
}

void print(int S,int u){//��ӡ·��
    if(S==(1<<n)-1) return;
    int v=path[S][u];//u�ĺ��v
    cout<<"-->"<<v;
	print(S|1<<v,v);//��v�������߹��Ľڵ㼯�ϣ��ٴ�v����
}

int main(){
/*����ͼ 
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
       //g[u][v]=g[v][u]=w;//����ͼ 
       g[u][v]=w;//����ͼ 
    }
    Traveling();
    cout<<"���·��: "<<0;
    print(0,0);
    cout<<endl;
    cout<<"���·������:"<<dp[0][0]<<endl;
    return 0;
}
