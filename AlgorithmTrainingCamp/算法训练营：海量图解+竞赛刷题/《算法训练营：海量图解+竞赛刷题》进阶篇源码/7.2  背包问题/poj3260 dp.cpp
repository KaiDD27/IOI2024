#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int INF=0x3f3f3f;
const int maxn=105;
const int maxm=10000+120*120+5;//T+maxv*maxv+5
int N,T;
int v[maxn],c[maxn];
int dp_pay[maxm],dp_change[maxm]; //�ֱ��ʾ֧�������㣬ע���Ͻ�֤��

void multi_knapsack(int n,int W){//���ر���,�����Ʋ�� 
	memset(dp_pay,0x3f,sizeof(dp_pay)); 
    dp_pay[0]=0;
    for(int i=1;i<=N;i++){
    	if(c[i]*v[i]>=W){
            for(int j=v[i];j<=W;j++)
                dp_pay[j]=min(dp_pay[j],dp_pay[j-v[i]]+1);
        }
        else{
            for(int k=1;c[i]>0;k<<=1){//�����Ʋ��
	            int x=min(k,c[i]);
	            for(int j=W;j>=v[i]*x;j--)//ת��01���� 
	                dp_pay[j]=min(dp_pay[j],dp_pay[j-v[i]*x]+x);
	            c[i]-=x;
	    	} 
        }
	}    
} 

void complete_knapsack(int n,int W){//��ȫ����
	memset(dp_change,0x3f,sizeof(dp_change));
	dp_change[0]=0;
    for(int i=1;i<=n;i++)
        for(int j=v[i];j<=W;j++)
            dp_change[j]=min(dp_change[j],dp_change[j-v[i]]+1);
}

int main(){
    while(~scanf("%d%d",&N,&T)){
        int maxv=0,W;
        for(int i=1;i<=N;i++)
            scanf("%d",&v[i]),maxv=max(maxv,v[i]);
        for(int i=1;i<=N;i++)
            scanf("%d",&c[i]);
        maxv=maxv*maxv;
        multi_knapsack(N,maxv+T);//��Ǯ�����ر��� 
    	complete_knapsack(N,maxv);//���㣬��ȫ���� 
        //ͳ����Сֵ
        int ans=INF;
        for(int i=0;i<=maxv;i++)//������T+i����Ǯ���ջ���i����Ǯ,ʵ���Ͼ����˼۸�T����Ʒ��
            ans=min(ans,dp_pay[i+T]+dp_change[i]);
        if(ans==INF)
			ans=-1; //�����ҳ����������Ϊ-1.
        printf("%d\n",ans);
    }
    return 0;
}
