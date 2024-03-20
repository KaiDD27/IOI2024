#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
using namespace std;
int n,k;
int a[100005];

int judge(int x){
	int sum=0;
	for(int i=0;i<n;i++){
		if(a[i]>x)
			sum+=(a[i]-x+k-2)/(k-1);//上取整,或 ceil((a[i]-x)*1.0/(k-1));
		if(sum>x)
			return 0;
	}
	return 1;
}

void solve(){
	int l=1,r=a[n-1],ans;
	while(l<=r){
		int mid=(l+r)>>1;
		if(judge(mid)){
			ans=mid;
			r=mid-1;//减小
		}
		else
			l=mid+1;//增大 
	}
	cout<<ans<<endl;
}                   
                    
int main(){
	while(~scanf("%d",&n)){
		for(int i=0;i<n;i++)
			scanf("%d",&a[i]);
		scanf("%d",&k);
		sort(a,a+n);
		if(k==1){
			printf("%d\n",a[n-1]);
			continue;
		}
		solve();
	}
	return 0;
}
