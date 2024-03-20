#include<cstdio>
#include<algorithm>
#define maxn 260
using namespace std;
int a[maxn][maxn],lb[maxn];
int Fmax[maxn][maxn][11],Fmin[maxn][maxn][11];

void Initlog(){//�������logֵ,���浽����lb[]
	lb[0]=-1;
	for(int i=1;i<maxn;i++)
		lb[i]=(i&(i-1))?lb[i-1]:lb[i-1]+1;
}

void ST(int n){
	for(int k=1;k<=n;k++)//��һά 
        for(int i=1;i<=n;i++)
            Fmax[k][i][0]=Fmin[k][i][0]=a[k][i];	
	for(int k=1;k<=n;k++)
		for(int j=1;j<=lb[n];j++)
			for(int i=1;i+(1<<j)-1<=n;i++){
				Fmax[k][i][j]=max(Fmax[k][i][j-1],Fmax[k][i+(1<<(j-1))][j-1]);
				Fmin[k][i][j]=min(Fmin[k][i][j-1],Fmin[k][i+(1<<(j-1))][j-1]);
			}
}

void solve(int x,int y,int B){//������Ϊ(x,y)�ĵط���ʼ��������չB���� 
	int k=lb[B];
    int maxx=-1;
	int minx=0x3f3f3f3f;
    int l=y,r=y+B-1;
    for(int i=x;i<x+B;i++){//��ѯÿһ�е���ֵ
        maxx=max(maxx,max(Fmax[i][l][k],Fmax[i][r-(1<<k)+1][k]));
        minx=min(minx,min(Fmin[i][l][k],Fmin[i][r-(1<<k)+1][k]));
    }
	printf("%d\n",maxx-minx);
}

int main(){
	int N,B,K;
	int x,y; //ÿ�β�ѯ������
	Initlog();
	while(scanf("%d%d%d",&N,&B,&K)!=EOF){
		for(int i=1;i<=N;i++)
			for(int j=1;j<=N;j++)
				scanf("%d",&a[i][j]);	
		ST(N);
		for(int i=0;i<K;i++){
			scanf("%d%d",&x,&y);
			solve(x,y,B);
		}
	}
	return 0;
}
