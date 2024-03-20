#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int N,M;
char map[110][20],num[70],top;
int stk[70],cur[70];
int dp[110][70][70];
 
bool check(int x){//�жϸ�״̬�Ƿ�Ϸ������������ڵ�1֮��ľ��벻��С��3
	if(x&(x<<1)) return 0;
	if(x&(x<<2)) return 0;
	return 1;
}

void init(){//��¼���п��ܵĺϷ�״̬�����60��
	top=0;
	for(int i=0;i<(1<<M);i++)
		if(check(i)) stk[top++]=i;
}

bool fit(int x,int k){//�ж�״̬x�Ƿ����ͼ��k��ƥ�䣬ȷ���ڱ����Ӳ�����ƽԭ��
	if(cur[k]&x) return 0;
	return 1;
}

int count(int x){//ͳ��״̬x�Ķ�������1�ĸ���
	int cnt=0;
	while(x){
		cnt++;
		x&=(x-1);
	}
	return cnt;
}

int solve(){
	int ans=0;
	memset(dp,-1,sizeof(dp));
	for(int j=0;j<top;j++){//��ʼ����һ��״̬
		num[j]=count(stk[j]);
		if(fit(stk[j],1)){
			dp[1][j][0]=num[j];//��һ��״̬Ϊj,��һ��״̬Ϊ��0��״̬����000000
			ans=max(ans,dp[1][j][0]);
		}
	}
	for(int i=2;i<=N;i++){
		for(int j=0;j<top;j++){
			if(!fit(stk[j],i)) continue;//ƥ����
            for(int k=0;k<top;k++)
            {
                if(stk[j]&stk[k]) continue;//�����⣬����һ�в��������ڵ�1 
                for(int t=0;t<top;t++)
                {
                    if(stk[j]&stk[t]) continue;//�����⣬�������в��������ڵ�1 
                    if(dp[i-1][k][t]==-1) continue;
                    dp[i][j][k]=max(dp[i][j][k],dp[i-1][k][t]+num[j]);
				}
				if(i==N) ans=max(ans,dp[i][j][k]);
            }
		}
	}
	return ans;
}

int main(){
	while(~scanf("%d%d",&N,&M)){
		init();
		for(int i=1;i<=N;i++)//��M�е�ͼ
			scanf("%s",map[i]+1);
		for(int i=1;i<=N;i++){//Ԥ�����ͼ״̬ 
			cur[i]=0;
			for(int j=1;j<=M;j++)
				if(map[i][j]=='H')
					cur[i]+=(1<<(j-1));
		}
		printf("%d\n",solve());
	}
	return 0;
}
