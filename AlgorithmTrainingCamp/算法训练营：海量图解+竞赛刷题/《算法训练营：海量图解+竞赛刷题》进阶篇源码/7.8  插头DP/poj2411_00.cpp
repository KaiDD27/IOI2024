#include<cstdio>//Ԥ����669ms,��Ԥ����1235ms
#include<cstring>
#include<algorithm>
using namespace std;
int N,M;
long long dp[12][1<<11];//�����ε�����һ��Ϊ1���������Ϊ0 
bool flag[1<<11];
 
void init(){//Ԥ���� 
	for(int i=0;i<(1<<M);i++){//����0�ĸ�������Ϊż�� 
		bool cnt=0;
		for(int j=0;j<M;j++)
			if(i>>j&1){
				if(cnt)
					break;
				cnt=0;
			}
			else
				cnt^=1;
		flag[i]=cnt?0:1;
	}
} 

void solve(){
	memset(dp,0,sizeof(dp));
	dp[0][0]=1; 
	for(int i=1;i<=N;i++)
		for(int j=0;j<(1<<M);j++)
			for(int k=0;k<(1<<M);k++)
	            if((j&k)==0&&flag[j|k])
	            	dp[i][j]+=dp[i-1][k];
}
	

int main(){
	while(~scanf("%d%d",&N,&M),N+M){
		init();
		solve();
		printf("%lld\n",dp[N][0]);
	}
	return 0;
}
