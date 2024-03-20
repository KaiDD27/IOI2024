#include<cstdio>
#include<cstring>
#include<algorithm>
const int INF=0x3f3f3f3f;
using namespace std;
int n,m,ans;
int tri[12]={0,1,3,9,27,81,243,729,2187,6561,19683,59049};//������ÿλΪ1ʱ��Ӧʮ���ƣ����3λ��1��(100)3=9 
int dig[60000][11];//dig[S][j]״̬S�ĵ�jλ�Ƕ���
int edge[11][11],dp[60000][11];//3^10=59050
 
void init(){
	for(int i=0;i<59050;i++){//Ԥ����״̬S�ĵ�jλ
       int t=i;
       for(int j=1;j<=10;++j){//��i״̬ת��Ϊ3���ƣ���¼ÿһλ
           dig[i][j]=t%3;
           t/=3;
           if(t==0) break;
       }
   }
}

void solve(){
	memset(dp,0x3f,sizeof(dp));
	for(int i=1;i<=n;i++)
		dp[tri[i]][i]=0;//��ʼ��״̬Ϊtri[i]ʱ����i������С����Ϊ0
	ans=INF;
	for(int S=0;S<tri[n+1];S++){
		bool visit_all=1;//������еĳ��ж�����1������ 
		for(int u=1;u<=n;u++){
			if(dig[S][u]==0){//u��û������ 
				visit_all=0;
				continue;
			}
			for(int v=1;v<=n;v++){
				if(dig[S][v]==0) continue;//v��δ���ʣ�������״̬���ᳬ��2�� 
				dp[S][u]=min(dp[S][u],dp[S-tri[u]][v]+edge[u][v]);//u��S�м�ȥ 
			}
		}
		if(visit_all){//���еĳ��ж�����1������
			for(int u=1;u<=n;u++)
				ans=min(ans,dp[S][u]);
		}
	}
}

int main(){
	init();
	while(~scanf("%d%d",&n,&m)){
		memset(edge,0x3f,sizeof(edge));
		int a,b,c;
		while(m--){
			scanf("%d%d%d",&a,&b,&c);
 			edge[a][b]=edge[b][a]=min(edge[a][b],c);
		} 
		solve();
		if(ans==INF)
			ans=-1;
		printf("%d\n",ans);
	}
	return 0;
}
