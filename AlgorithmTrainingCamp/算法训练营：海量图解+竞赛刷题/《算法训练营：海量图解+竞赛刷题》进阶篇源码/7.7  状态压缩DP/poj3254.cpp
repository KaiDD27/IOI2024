#include<cstdio>
#include<cstring>
using namespace std;
#define mod 100000000
int m,n,top=0;
int state[600];
int dp[20][600];//dp[i][j]��ʾ��i�У���j�ֱ��ʱ��ǰi�еĿ��з����� 
int cur[20];

bool check(int x){//�жϱ��x�Ķ��������Ƿ������ڵ�1�����򷵻�0
   if(x&x<<1) return 0;
   return 1;
}

bool fit(int x,int k){//�жϱ��x����ֲ����Ƿ������صķ���ƥ�� 
   if(x&cur[k]) return 0;
   return 1;
}

void init(){//��¼����û������1�ı�� 
   top=0;
   for(int i=0;i<1<<n;i++)//n�����ӣ�2^n����� 
       if(check(i)) state[++top]=i;
}

void solve(){
	for(int j=1;j<=top;j++)//�����һ�� 
		if(fit(state[j],1))
			dp[1][j]=1;
	for(int i=2;i<=m;i++)
		for(int j=1;j<=top;j++){//state[j]��i�е�״̬
			if(!fit(state[j],i)) continue;
            for(int k=1;k<=top;k++){//state[k]��i-1�е�״̬ 
				if(!fit(state[k],i-1)) continue;
				if(state[j]&state[k]) continue;//�������г�ͻ 
                dp[i][j]=(dp[i][j]+dp[i-1][k])%mod;
            }
		}
} 

int main(){
    while(~scanf("%d%d",&m,&n)){
		init();
		memset(dp,0,sizeof(dp));
		for(int i=1;i<=m;i++){
			cur[i]=0;
			int num;
			for(int j=1;j<=n;j++){
				scanf("%d",&num);
				if(num==0) cur[i]+=(1<<(n-j));//0�ļ�¼Ϊ1
			}
		}
		solve();
		int ans=0;
		for(int j=1;j<=top;j++)//�ۼ����һ�� 
			ans=(ans+dp[m][j])%mod;
		printf("%d\n",ans);
	}
	return 0;
}
