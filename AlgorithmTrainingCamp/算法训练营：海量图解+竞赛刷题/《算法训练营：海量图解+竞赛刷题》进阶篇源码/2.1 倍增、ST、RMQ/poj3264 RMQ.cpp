#include<cstdio>
#include<algorithm>//min,max
#include<cmath>//log
using namespace std;
const int maxn=50010;
int h[maxn];
int Fmax[maxn][20];//F(i,j)��ʾ����[i��i+2^j-1]����ֵ�����䳤��Ϊ2^j
int Fmin[maxn][20];
int N,Q;

void ST_create()
{
	for(int i=1;i<=N;i++)//��ʼ�� 
		Fmax[i][0]=Fmin[i][0]=h[i];
	int k=log2(N);//log(N)/log(2.0);
	for(int j=1;j<=k;j++)
		for(int i=1;i<=N-(1<<j)+1;i++)//N-2^j+1
		{
			Fmax[i][j]=max(Fmax[i][j-1],Fmax[i+(1<<(j-1))][j-1]);
			Fmin[i][j]=min(Fmin[i][j-1],Fmin[i+(1<<(j-1))][j-1]);
		}			
}

int RMQ(int l,int r)//������[l..r]����ֵ�� 
{
	int k=log2(r-l+1);
	int m1=max(Fmax[l][k],Fmax[r-(1<<k)+1][k]);
	int m2=min(Fmin[l][k],Fmin[r-(1<<k)+1][k]);
	return m1-m2;//ȡ����������ֵ�� 
}

int main()
{
	int a,b;
	while(~scanf("%d%d",&N,&Q))
	{
		for(int i=1;i<=N;i++)//�±��1��ʼ 
			scanf("%d",&h[i]);
		ST_create();
		for(int j=1;j<=Q;j++)
		{
			scanf("%d%d",&a,&b);
			printf("%d\n",RMQ(a,b));
		}
	}
	return 0;
}
