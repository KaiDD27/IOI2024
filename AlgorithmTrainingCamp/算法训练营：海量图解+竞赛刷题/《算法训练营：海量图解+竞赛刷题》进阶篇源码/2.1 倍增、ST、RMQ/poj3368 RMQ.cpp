#include<cstdio>
#include<algorithm>//min,max
using namespace std;
const int maxn=100010;
int a[maxn];//���� 
int lb[maxn];//�洢logֵ 
int F[maxn][20];//F(i,j)��ʾ����[i��i+2^j-1]����ֵ�����䳤��Ϊ2^j

void Initlog(){//�������logֵ,���浽����lb[] 
	lb[0]=-1;
	for(int i=1;i<maxn;i++)
		lb[i]=(i&(i-1))?lb[i-1]:lb[i-1]+1;
}

void ST_create(int n){//ÿ����������n��ͬ����������� 
	for(int j=1;j<=lb[n];j++)
		for(int i=1;i<=n-(1<<j)+1;i++)//n-2^j+1
			F[i][j]=max(F[i][j-1],F[i+(1<<(j-1))][j-1]);		
}

int RMQ(int l,int r){//������[l..r]����ֵ�� 
	if(l>r) return 0;
	int k=lb[r-l+1];
	return max(F[l][k],F[r-(1<<k)+1][k]);
}

int main(){
	int n,q,l,r;
	Initlog();
	while(~scanf("%d",&n)&&n){
		scanf("%d",&q);
		for(int i=1;i<=n;i++){//�±��1��ʼ 
			scanf("%d",&a[i]);
			if(i==1){
				F[i][0]=1;
				continue;
			}	
			if(a[i]==a[i-1])
				F[i][0]=F[i-1][0]+1;
			else
				F[i][0]=1;
		}
		ST_create(n);
		for(int j=1;j<=q;j++){
			scanf("%d%d",&l,&r);
			int t=l;
			while(t<=r&&a[t]==a[t-1])
				t++;
			printf("%d\n",max(t-l,RMQ(t,r)));
		}
	}
	return 0;
}
