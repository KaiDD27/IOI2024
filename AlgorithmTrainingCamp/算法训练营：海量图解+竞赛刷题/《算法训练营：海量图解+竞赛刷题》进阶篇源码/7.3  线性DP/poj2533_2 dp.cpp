#include<cstdio>//����������У��Ż��㷨��ʱ�临�Ӷ�O(nlogn)
#include<algorithm>
using namespace std;
const int maxn=1010;
int d[maxn];//d[]��ʾ����������е�Ԫ��
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
        else//a[i]����d[]�е�һ������a[i]���� 
        	*upper_bound(d+1,d+len+1,a[i])=a[i];
    }
    printf("%d\n",len);
    return 0;
}
