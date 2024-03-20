#include<iostream>
#include<cstdio>
using namespace std;
#define inf 0x3f3f3f3f
#define maxn 1006
#define eps 1e-7
int n;
double A,num[maxn],ans;

bool check(double mid){//判断第二个灯的高度为mid是否可行 
    num[2]=mid;
    for(int i=3;i<=n;i++){
        num[i]=2*num[i-1]-num[i-2]+2;
        if(num[i]<eps) return false; //写小于0由于精度问题会wa
    }
    ans=num[n];
    return true;
}

void solve(){
	num[1]=A;
    double l=0.0;
    double r=A;//inf
    while(r-l>eps){//for(int i=0;i<100;i++)
        double mid=(l+r)/2;
        if(check(mid))
			r=mid;
        else
			l=mid;
    }
}

int main(){
	while(~scanf("%d%lf",&n,&A)){
		solve();
        printf("%.2lf\n",ans);
    }
    return 0;
}

