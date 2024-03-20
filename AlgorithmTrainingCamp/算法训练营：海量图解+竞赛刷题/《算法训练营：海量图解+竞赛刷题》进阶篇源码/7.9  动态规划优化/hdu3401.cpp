#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int INF=0x3f3f3f3f;
const int maxn=2010;
int dp[maxn][maxn],ap[maxn],bp[maxn],as[maxn],bs[maxn]; 
struct Qnode{
	int num,val;
}queue[maxn];

int main(){
	int t,p,w,cas;
	scanf("%d",&cas);
	while(cas--){
		scanf("%d%d%d",&t,&p,&w);
		for(int i=1;i<=t;i++)
			scanf("%d%d%d%d",&ap[i],&bp[i],&as[i],&bs[i]);
		memset(dp,-INF,sizeof(dp));
		for(int i=1;i<=w+1;i++){//���й�Ʊ���ǵ������
			for(int j=0;j<=min(as[i],p);j++)
				dp[i][j]=-j*ap[i];
		}
		for(int i=2;i<=t;i++){
			for(int j=0;j<=p;j++)//û�н���
        		dp[i][j]=max(dp[i-1][j],dp[i][j]);
        	if(i<w+2) continue;
			int pre=i-w-1;
	        int st=0,ed=0;
	        for(int j=0;j<=p;j++){ //����
	        	int tmp=dp[pre][j]+j*ap[i];
	            while(st<ed&&tmp>=queue[ed-1].val)
	                ed--;
				queue[ed].num=j;
				queue[ed++].val=tmp;//ed++ֻ�����ִ��һ�� 
				while(st<ed&&j-queue[st].num>as[i])
	               st++;
				dp[i][j]=max(dp[i][j],queue[st].val-j*ap[i]);
	        }
	        st=0,ed=0;
	        for(int j=p;j>=0;j--){//����
	            int tmp=dp[pre][j]+j*bp[i];
	            while(st<ed&&tmp>=queue[ed-1].val)
	                ed--;
	            queue[ed].num=j;
				queue[ed++].val=tmp;
	            while(st<ed&&queue[st].num-j>bs[i])//j=p..0,����ӵı�Ŵ󣬱�֤��queue[st].num-j>=0
	                st++;
	            dp[i][j]=max(dp[i][j],queue[st].val-j*bp[i]);
	        }
	    }
		printf("%d\n",dp[t][0]);
	}
	return 0;
}
