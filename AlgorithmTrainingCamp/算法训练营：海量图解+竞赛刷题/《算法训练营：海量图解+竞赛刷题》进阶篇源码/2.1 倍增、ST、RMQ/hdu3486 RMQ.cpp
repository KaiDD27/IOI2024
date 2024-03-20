#include<cstdio>
#include<algorithm>
using namespace std;
const int N=200010;
int a[N];
int n,k;
int F[N][20],lb[N];

void Initlog(){
	lb[0]=-1;
    for(int i=1;i<=N;i++)
        lb[i]=lb[i-1]+(i&(i-1)?0:1);
}

void ST(int n){
    for(int i=1;i<=n;i++)
		F[i][0]=a[i];
    for(int j=1;j<=lb[n];j++)
        for(int i=1;i<=n-(1<<j)+1;i++)
            F[i][j]=max(F[i][j-1],F[i+(1<<(j-1))][j-1]);
}

int RMQ(int l,int r){
    int k=lb[r-l+1];
    return max(F[l][k],F[r-(1<<k)+1][k]);
}

bool ok(int m){
    int t=n/m,s=0;
    for(int i=0;i<m;i++)
		s+=RMQ(t*i+1,t*i+t);
    return s>k;
}

void solve(int n){
	ST(n);
    int l=1,r=n,ans;
    while(l<=r){//二分找m
        int m=(l+r)>>1;
        if(ok(m)) r=m-1,ans=m;
        else l=m+1;
    }
    printf("%d\n",ans);        
//    while(l<r){//二分找划分数  
//        int m=(l+r)/2;
//        if(ok(m)) r=m;
//        else l=m+1;
//    }
//	printf("%d\n",l);
}

int main(){
    Initlog();
	while(scanf("%d%d",&n,&k),n>=0||k>=0){
        int sum=0;
        for(int i=1;i<=n;i++){
            scanf("%d",&a[i]);
            sum+=a[i];
        }
        if(sum<=k)
			printf("-1\n");
		else
			solve(n);  
    }
    return 0;
}
