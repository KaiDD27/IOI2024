#include<cstdio>
#include<algorithm>
#define maxn 260
using namespace std;
int a[maxn][maxn],lb[maxn];
int Fmax[maxn][maxn][11],Fmin[maxn][maxn][11];

void Initlog(){//求解所有log值,保存到数组lb[]
	lb[0]=-1;
	for(int i=1;i<maxn;i++)
		lb[i]=(i&(i-1))?lb[i-1]:lb[i-1]+1;
}

void ST(int n){
	for(int k=1;k<=n;k++)//多一维 
        for(int i=1;i<=n;i++)
            Fmax[k][i][0]=Fmin[k][i][0]=a[k][i];	
	for(int k=1;k<=n;k++)
		for(int j=1;j<=lb[n];j++)
			for(int i=1;i+(1<<j)-1<=n;i++){
				Fmax[k][i][j]=max(Fmax[k][i][j-1],Fmax[k][i+(1<<(j-1))][j-1]);
				Fmin[k][i][j]=min(Fmin[k][i][j-1],Fmin[k][i+(1<<(j-1))][j-1]);
			}
}

void solve(int x,int y,int B){//从坐标为(x,y)的地方开始，右下扩展B长度 
	int k=lb[B];
    int maxx=-1;
	int minx=0x3f3f3f3f;
    int l=y,r=y+B-1;
    for(int i=x;i<x+B;i++){//查询每一行的最值
        maxx=max(maxx,max(Fmax[i][l][k],Fmax[i][r-(1<<k)+1][k]));
        minx=min(minx,min(Fmin[i][l][k],Fmin[i][r-(1<<k)+1][k]));
    }
	printf("%d\n",maxx-minx);
}

int main(){
	int N,B,K;
	int x,y; //每次查询的坐标
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
