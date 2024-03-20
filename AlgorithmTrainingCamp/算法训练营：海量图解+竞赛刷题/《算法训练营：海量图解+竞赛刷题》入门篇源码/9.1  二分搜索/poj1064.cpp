#include<iostream>
#include<cstdio>
#include<cmath>
#include<algorithm>
using namespace std;
#define inf 0x3f3f3f3f
#define eps 1e-7
double L[10005];
int n,k;

bool judge(double x){//�����и���������ӵĳ���Ϊx���жϹ������и�
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
		double ans=solve()+eps;//Ҳ������solve()��ֱ�ӷ���r��ѭ������ʱr��l��eps 
		printf("%.2lf\n", floor(ans*100)/100); //ȡ���ޣ���int(ans*100)/100.0
	}
	return 0;
}
