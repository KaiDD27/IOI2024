#include<cstdio>
#include<cstring>
using namespace std;
const int maxn=100005;
int dp[maxn];//dp[i]��ʾ��1��ʼ����i��Ԫ�ص�����ֵ 

int main(){
	int t,n,cas=0;
	scanf("%d",&t);
	while(t--){
		scanf("%d",&n);
		for(int i=1;i<=n;i++)
			scanf("%d",&dp[i]);//ʡ��ԭ���飬ֱ����dp[] 
		int l=1,r=1;//��¼����
		int start=1;//��¼���
		int MAX=dp[1];
		for(int i=2;i<=n;i++){
            if(dp[i-1]>=0)//dp[i-1]���ڵ���0�����ۼӣ��������¿�ʼ 
                dp[i]=dp[i-1]+dp[i];
            else
				start=i;//���¿�ʼ
            if(dp[i]>MAX){//������ֵ
            	MAX=dp[i];
				l=start;
         	    r=i;
            }
		}
		if(cas)
			printf("\n");
		printf("Case %d:\n",++cas);
		printf("%d %d %d\n",MAX,l,r);
	}
	return 0;
}
