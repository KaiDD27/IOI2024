#include<iostream>
#include<cstdio>
#include<cmath>
#include<algorithm>
using namespace std;
#define inf 0x3f3f3f3f
#define eps 1e-7
double L[10005];
int n,k;

bool judge(double x){//假设切割出来的绳子的长度为x，判断够不够切割
	int num=0;
	for(int i=0;i<n;i++)
		num+=(int)(L[i]/x);
	return num>=k;
}

double solve(){
	double l=0;
	double r=*(max_element(L,L+n));//inf;
	while(r-l>eps){//for(int i=0;i<100;i++){
		double mid=(l+r)/2;
		if(judge(mid))
			l=mid;
		else
			r=mid;
	}
	return l;
}

int main(){
	while(~scanf("%d%d",&n,&k)){
		for(int i=0;i<n;i++)
			scanf("%lf",&L[i]);
		double ans=solve()+eps;//也可以在solve()中直接返回r，循环结束时r比l多eps 
		printf("%.2lf\n", floor(ans*100)/100); //取下限，或int(ans*100)/100.0
	}
	return 0;
}
