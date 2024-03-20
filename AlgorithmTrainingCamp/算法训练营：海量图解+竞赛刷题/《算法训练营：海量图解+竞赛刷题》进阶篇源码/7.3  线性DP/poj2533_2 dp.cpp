#include<cstdio>//最长上升子序列，优化算法，时间复杂度O(nlogn)
#include<algorithm>
using namespace std;
const int maxn=1010;
int d[maxn];//d[]表示从最长上升序列的元素
int a[maxn];

int main(){
    int n;
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
    int len=1;
    d[1]=a[1];
    for(int i=2;i<=n;i++){
        if(a[i]==d[len]) continue;
		if(a[i]>d[len])
            d[++len]=a[i];
        else//a[i]覆盖d[]中第一个大于a[i]的数 
        	*upper_bound(d+1,d+len+1,a[i])=a[i];
    }
    printf("%d\n",len);
    return 0;
}
