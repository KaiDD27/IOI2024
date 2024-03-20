#include<cstdio>
#include<cstring>
#include<algorithm>
#define maxn 1010
#define maxk 1000010
#define lowbit(x) (x)&(-x)
int c[maxn],kas,n,m,k;
using namespace std;
typedef long long LL;
struct Edge {
    int x, y;
}e[maxk];
bool cmp(Edge a,Edge b)
{
    return a.x<b.x||(a.x==b.x&&a.y<b.y);
}

void add(int i)//加1操作，参数省略
{
    while(i<=m)//y点有m个
	{
        ++c[i];
        i+=lowbit(i);
    }
}

int sum(int i)
{
    int s=0;
    while(i>0)
	{
        s+=c[i];
        i-=lowbit(i);
    }
    return s;
}

int main()
{
    int T;
    scanf("%d",&T);
    while (T--)
	{
		memset(c,0,sizeof(c));
	    scanf("%d%d%d",&n,&m,&k);
	    for(int i=0;i<k;i++)
			scanf("%d%d",&e[i].x,&e[i].y);
	    sort(e,e+k,cmp);
	    LL ans=0;
	    for(int i=0;i<k;i++){
	        ans+=i-sum(e[i].y);
	        add(e[i].y);
	    }
	    printf("Test case %d: %lld\n",++kas,ans);
	}
    return 0;
}
