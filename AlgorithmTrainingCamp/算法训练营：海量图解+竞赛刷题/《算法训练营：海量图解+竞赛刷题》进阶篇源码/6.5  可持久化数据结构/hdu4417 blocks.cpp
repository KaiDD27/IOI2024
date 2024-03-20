#include<cstdio>
#include<cstring>
#include<algorithm>//sort 
#include<cmath>//sqrt
using namespace std;
/*
lower_bound( )和upper_bound( )都是利用二分查找的方法在一个排好序的数组中进行查找的。
在从小到大的排序数组中，执行 
lower_bound( begin,end,num)：从数组的begin位置到end-1位置二分查找第一个大于或等于num的数字，找到返回该数字的地址，不存在则返回end。
upper_bound( begin,end,num)：从数组的begin位置到end-1位置二分查找第一个大于num的数字，找到返回该数字的地址，不存在则返回end。
通过返回的地址减去起始地址begin,得到找到数字在数组中的下标。
*/
const int maxn=1e5+10;
int L[maxn],R[maxn],belong[maxn];
int a[maxn],temp[maxn],n,m;

void build()
{
    int t=sqrt(n);
    int num=n/t;
	if(n%num) num++;
    for(int i=1;i<=num;i++)
        L[i]=(i-1)*t+1,R[i]=i*t;
    R[num]=n;
    for(int i=1;i<=n;i++)
        belong[i]=(i-1)/t+1;
    for(int i=1;i<=num;i++)
        sort(temp+L[i],temp+1+R[i]);//每块排序
}

int query(int l,int r,int h)
{
    int ans=0;
    if(belong[l]==belong[r])
    {
        for(int i=l;i<=r;i++)
            if(a[i]<=h) ans++;
    }
    else
    {
        for(int i=l;i<=R[belong[l]];i++)//左端 
            if(a[i]<=h) ans++;
        for(int i=belong[l]+1;i<belong[r];i++)//中间 
            ans+=upper_bound(temp+L[i],temp+R[i]+1,h)-temp-L[i];
        for(int i=L[belong[r]];i<=r;i++)//右端 
            if(a[i]<=h) ans++;
    }
    return ans;
}

int main()
{
    int T;
    scanf("%d",&T);
    for(int cas=1;cas<=T;cas++)
    {
        scanf("%d%d",&n,&m);
        for(int i=1;i<=n;i++)
        {
            scanf("%d",&a[i]);
            temp[i]=a[i];
        }
        build();
        printf("Case %d:\n",cas);
        while(m--)
        {
            int l,r,h; 
            scanf("%d%d%d",&l,&r,&h);
            printf("%d\n",query(++l,++r,h));
        }
    }
    return 0;
}
