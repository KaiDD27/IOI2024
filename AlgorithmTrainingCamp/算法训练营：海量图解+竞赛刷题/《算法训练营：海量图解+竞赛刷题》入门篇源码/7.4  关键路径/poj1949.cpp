#include<cstdio>
#include<algorithm>
using namespace std;
const int maxn=10010;
int d[maxn],n;

int main(){
	int ans=0,w,num,y;
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d%d",&w,&num);
		d[i]=w;
		for(int j=1;j<=num;j++){
			scanf("%d",&y);
			d[i]=max(d[i],d[y]+w);
		}
		ans=max(ans,d[i]);
	}
	printf("%d\n",ans);
	return 0;
}
