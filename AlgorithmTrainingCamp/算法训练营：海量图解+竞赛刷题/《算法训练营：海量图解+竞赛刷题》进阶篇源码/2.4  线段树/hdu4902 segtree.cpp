#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
#define N 100005
#define lson i<<1
#define rson i<<1|1
#define ls l,mid,i<<1
#define rs mid+1,r,i<<1|1
int maxs[N<<2],lazy[N<<2];
int n,m;

int gcd(int a,int b)//最大公约数 
{
    if(!b) return a;
    else return gcd(b,a%b);
}
void PushUp(int i)//上传 
{
    maxs[i]=max(maxs[lson],maxs[rson]);
}
void PushDown(int i)//下传 
{
    if(lazy[i])
    {
        lazy[lson]=lazy[rson]=lazy[i];
        maxs[lson]=maxs[rson]=maxs[i];
        lazy[i]=0;
    }
}
void build(int l,int r,int i)
{
    if(l==r)
    {
    	scanf("%d",&lazy[i]);
    	maxs[i]=lazy[i];
    	return ;
	}
    int mid=(l+r)>>1;
    build(ls);
    build(rs);
    PushUp(i);
}
 
void update1(int x,int L,int R,int l,int r,int i)
{
    if(L<=l&&r<=R)
    {
        lazy[i]=maxs[i]=x;
        return ;
    }
    PushDown(i);
    int mid=(l+r)>>1;
    if(L<=mid)
    	update1(x,L,R,ls);
    if(R>mid)
    	update1(x,L,R,rs);
    PushUp(i);
}
 
void update2(int x,int L,int R,int l,int r,int i)
{
    if(maxs[i]<=x) return ;
    if(lazy[i]&&L<=l&&r<=R)
    {
        lazy[i]=gcd(lazy[i],x);
        maxs[i]=lazy[i];
        return ;
    }
    PushDown(i);
    int mid=(l+r)>>1;
    if(L<=mid)
    	update2(x,L,R,ls);
    if(R>mid)
    	update2(x,L,R,rs);
    PushUp(i);
}
 
void print(int l,int r,int i)
{
    if(l==r)
    {
    	printf("%d ",lazy[i]);
    	return ;
	}
	PushDown(i);
    int mid=(l+r)>>1;
    print(ls);
    print(rs);
}

void print2(int l,int r,int i)//测试 
{
	if(maxs[i])
	{
		printf("%d %d\n",lazy[i],maxs[i]);
	    int mid=(l+r)>>1;
	    print2(ls);
	    print2(rs);
	}
}

int main()
{
    int T,l,r,opt;
    int x;
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d",&n);
        build(1,n,1);
        //print2(1,n,1);
        scanf("%d",&m);
        while(m--)
        {
            scanf("%d%d%d%d",&opt,&l,&r,&x);
            if(opt==1) update1(x,l,r,1,n,1);
            else update2(x,l,r,1,n,1);
            //print2(1,n,1);
        }
        print(1,n,1);
        printf("\n");
    }
    return 0;
}
