#include<cstdio>
#include<algorithm>
using namespace std;
const int MAXN=10010;
int r[MAXN];
int n,m,x;

int main(){
    int n;
    while(~scanf("%d",&n)){
    	for(int i=0;i<n;i++)
       		scanf("%d",&r[i]);
       	int mid=n>>1;
       	nth_element(r,r+mid,r+n);//nth_element(a+l,a+k,a+r)求[l,r)之间第k小 
       	printf("%d\n",r[mid]);
	}
    return 0;
}
