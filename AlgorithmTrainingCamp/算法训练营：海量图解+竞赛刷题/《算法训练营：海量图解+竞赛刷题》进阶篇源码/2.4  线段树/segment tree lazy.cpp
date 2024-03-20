#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
const int maxn=100005;
const int inf=0x3f3f3f3f;
int n,a[maxn];

struct node//结点
{ 
	int l,r,mx,lz;//l,r表示区间左右端点，mx表示区间[l,r]的最值，lz为懒标记 
}tree[maxn*4]; //树结点存储数组 

void lazy(int k,int v)
{
	tree[k].mx=v;//更新最值
	tree[k].lz=v;//做懒标记
}

void pushdown(int k)//向下传递懒标记 
{
	lazy(2*k,tree[k].lz);//传递给左孩子
	lazy(2*k+1,tree[k].lz);//传递给右孩子
	tree[k].lz=-1;//清除自己的懒标记 
}

void build(int k,int l,int r)//创建线段树,k表示存储下标,区间[l,r]
{
	tree[k].l=l;
	tree[k].r=r;
	tree[k].lz=-1;//初始化懒操作 
	if(l==r)
	{
		tree[k].mx=a[l];
		return;
	}
	int mid,lc,rc;
	mid=(l+r)/2;//划分点 
	lc=k*2;  //左孩子存储下标 
	rc=k*2+1;//右孩子存储下标 
	build(lc,l,mid);
	build(rc,mid+1,r);
	tree[k].mx=max(tree[lc].mx,tree[rc].mx);//结点的最大值等于左右孩子最值的最大值 		
} 

void update(int k,int l,int r,int v)//将区间[l..r]修改更新为v
{
	if(tree[k].l>=l&&tree[k].r<=r)//找到该区间 
		return lazy(k,v);//更新并做懒标记
	if(tree[k].lz!=-1) 
		pushdown(k);//懒标记下移 
	int mid,lc,rc;
	mid=(tree[k].l+tree[k].r)/2;//划分点 
	lc=k*2;  //左孩子存储下标 
	rc=k*2+1;//右孩子存储下标
	if(l<=mid)
		update(lc,l,r,v);//到左子树更新 
	if(r>mid)
		update(rc,l,r,v);//到右子树更新
	tree[k].mx=max(tree[lc].mx,tree[rc].mx);//返回时修改更新最值
}

int query(int k,int l,int r)//求区间[l..r]的最值 
{
	int Max=-inf;
	if(tree[k].l>=l&&tree[k].r<=r)//找到该区间
		return tree[k].mx;
	if(tree[k].lz!=-1) 
		pushdown(k);//懒标记下移 
	int mid,lc,rc;
	mid=(tree[k].l+tree[k].r)/2;//划分点 
	lc=k*2;  //左孩子存储下标 
	rc=k*2+1;//右孩子存储下标
	if(l<=mid)
		Max=max(Max,query(lc,l,r));//到左子树查询 
	if(r>mid)
		Max=max(Max,query(rc,l,r));//到右子树查询
	return Max;
} 

int main()
{
	int l,r;
	int i,v;
	cin>>n;//10
	for(i=1;i<=n;i++)
		cin>>a[i];//5 3 7 2 12 1 6 4 8 15
	build(1,1,n);//创建线段树 
	cout<<"输入查询最值的区间l r:"<<endl;
	cin>>l>>r;
	cout<<query(1,l,r)<<endl;//求区间[l..r]的最值
	cout<<"输入更新的区间值l r v:"<<endl;
	cin>>l>>r>>v;
	update(1,l,r,v);//将区间[l..r]修改更新为v
	cout<<"输入查询最值的区间l r:"<<endl;
	cin>>l>>r;
	cout<<query(1,l,r)<<endl;//求区间[l..r]的最值
	return 0;
}
