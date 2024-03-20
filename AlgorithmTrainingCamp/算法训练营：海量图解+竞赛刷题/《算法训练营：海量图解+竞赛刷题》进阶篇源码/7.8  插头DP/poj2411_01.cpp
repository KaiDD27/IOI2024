#include<cstdio>//��Ԥ����1235ms,Ԥ����669ms
#include<cstring>
#include<algorithm>
using namespace std;
int N,M;
long long dp[12][1<<11];//�����ε�����һ��Ϊ1���������Ϊ0 
 
bool check(int x){//�������0�ĸ���Ϊż�� 
    int cnt=0;
    for(int i=0;i<M;i++)
		if(x>>i&1){
			if(cnt&1)//����
				return 0;  
	        cnt=0;
		}
		else 
			cnt++;
    if(cnt&1)  
		return 0;
	return 1;     
}

void solve(){
	memset(dp,0,sizeof(dp));
	dp[0][0]=1; 
	for(int i=1;i<=N;i++)
		for(int j=0;j<(1<<M);j++)
			for(int k=0;k<(1<<M);k++)
	            if((j&k)==0&&check(j|k))
	            	dp[i][j]+=dp[i-1][k];
}
	

int main(){
	while(~scanf("%d%d",&N,&M),N+M){
		solve();
		printf("%lld\n",dp[N][0]);//ע���������ͣ���Ҫдd%!
	}
	return 0;
}
