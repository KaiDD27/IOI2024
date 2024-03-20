#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
long long dp[2][1<<12];
long long ans; 
int n,m,v;

void solve(){
	int total=1<<(m+1);
	int pre=0,now=1;
    memset(dp[pre],0,sizeof(dp[pre]));
    dp[pre][0]=1;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            scanf("%d",&v);
            memset(dp[now],0,sizeof(dp[now]));
            int j0=1<<j;
            int j1=j0<<1;
            for(int S=0;S<total;S++){
            	bool p=S&j0,q=S&j1;//ǰһ�����ӵ�����״̬ 
				if(v==0){//�ϰ�������� 
					if(!p&&!q)
						dp[now][S]+=dp[pre][S];
				}else{
					if(p^q)//��һ��Ϊ1��һ��Ϊ0
						dp[now][S]+=dp[pre][S];//ԭ״̬����
					dp[now][S^j0^j1]+=dp[pre][S];//�෴״̬
				}
			}
			swap(pre,now);//������һ�����Ӻ󽻻� 
        }
        memset(dp[now],0,sizeof(dp[now]));//Ϊ������һ����׼�� 
        for(int S=0;S<total/2;S++)//����״̬���0111...1
            dp[now][S<<1]=dp[pre][S];//Ҳ����+=���ٶȸ���15ms��=,46ms 
        swap(pre,now);//�������pre�Ǵ�����Ľ��,Ϊ��һ����׼�� 
    }
    ans=dp[now][0];
}

int main(){
    int T,cas=1;
    scanf("%d",&T);
    while(T--){
        scanf("%d%d",&n,&m);
		solve();
        printf("Case %d: There are %I64d ways to eat the trees.\n",cas++,ans);
    }
    return 0;
}
