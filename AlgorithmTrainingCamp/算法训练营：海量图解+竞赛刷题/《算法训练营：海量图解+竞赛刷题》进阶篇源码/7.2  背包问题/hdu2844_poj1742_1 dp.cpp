#include<cstdio>//���ر����������Ʋ��hdu2844����ͨ��,poj1742��ʱ����Ҫ�Ż� 
#include<cstring>
#include<algorithm>
using namespace std;
#define M 100005
bool dp[M];//dp[j]��ʾ��Ϊj����Ϸ�ʽ�Ƿ���� 
int v[105],c[105];//��ֵ������

void multi_knapsack(int n,int W){//�����Ʋ�� 
    for(int i=1;i<=n;i++) {
		if(c[i]*v[i]>=W){//ת����ȫ���� 
            for(int j=v[i];j<=W;j++)
                if(dp[j-v[i]])//��� dp[j-v[i]]�ǿɴ�ģ��� dp[j]Ҳ���� 
					dp[j]=1;
        }
        else{
            for(int k=1;c[i]>0;k<<=1){//�����Ʋ��
	            int x=min(k,c[i]);
	            for(int j=W;j>=v[i]*x;j--)//ת��01���� 
	                if(dp[j-v[i]*x])//��� dp[j-v[i]*x]�ǿɴ�ģ��� dp[j]Ҳ���� 
						dp[j]=1;
	            c[i]-=x;
        	} 
    	}
	}
}

int main(){
    int n,m;//n�������ֱ�۸�m
    while(~scanf("%d%d",&n,&m),n+m){
    	for(int i=1;i<=n;i++)//��ֵ 
    		scanf("%d",&v[i]);
    	for(int i=1;i<=n;i++)
    		scanf("%d",&c[i]);//����
		memset(dp,0,sizeof(dp));
		dp[0]=1;//��ʼ״̬0�ɴ� 
		multi_knapsack(n,m);
		int ans=0;
		for(int i=1;i<=m;i++)//�ۼӴ�
			ans+=dp[i];
		printf("%d\n",ans);
	}
    return 0;
}
