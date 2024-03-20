#include<cstdio>
#include<cstring>
#include<algorithm>//max,min
#include<cmath>//sqrt
using namespace std;
const int inf=0x3f3f3f3f;
const int maxn=50010;
int L[maxn],R[maxn],belong[maxn],block_max[maxn],block_min[maxn];
int a[maxn],n,m;

void build(){
    int t=sqrt(n*1.0);
    int num=n/t;
	if(n%num) num++;
    for(int i=1;i<=num;i++)
        L[i]=(i-1)*t+1,R[i]=i*t;
    R[num]=n;
    for(int i=1;i<=n;i++)
        belong[i]=(i-1)/t+1;
    for(int i=1;i<=num;i++){//求每块最值 
    	int MIN=inf,MAX=-inf;
    	for(int j=L[i];j<=R[i];j++){
        	MAX=max(MAX,a[j]);
			MIN=min(MIN,a[j]);		
		}
		block_max[i]=MAX;
		block_min[i]=MIN;	
	}
}

int query(int l,int r){
    int MIN=inf,MAX=-inf;
    if(belong[l]==belong[r]){
        for(int i=l;i<=r;i++){
        	MAX=max(MAX,a[i]);
			MIN=min(MIN,a[i]);	
		}
        return MAX-MIN;
    }
    else{
        for(int i=l;i<=R[belong[l]];i++){//左端
        	MAX=max(MAX,a[i]);
			MIN=min(MIN,a[i]);	
		}
        for(int i=belong[l]+1;i<belong[r];i++){//中间
        	MAX=max(MAX,block_max[i]);
			MIN=min(MIN,block_min[i]);	
		}
        for(int i=L[belong[r]];i<=r;i++){//右端
        	MAX=max(MAX,a[i]);
			MIN=min(MIN,a[i]);	
		}
    }
    return MAX-MIN;
}

int main(){
    int l,r;
	while(~scanf("%d%d",&n,&m)){
		for(int i=1;i<=n;i++)//下标从1开始 
			scanf("%d",&a[i]);
		build();
		for(int j=1;j<=m;j++){
			scanf("%d%d",&l,&r);
			printf("%d\n",query(l,r));
		}
	}
    return 0;
}
