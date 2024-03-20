#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
const int maxn=100005;
const int inf=0x3f3f3f3f;
int n,a[maxn];

struct node//结点
{ 
	int l,r,mx;//l,r表示区间左右端点，mx表示区间[l,r]的最值 
}tree[maxn*4]; //树结点存储数组 

void build(int k,int l,int r)//创建线段树,k表示存储下标,区间[l,r]
{
	tree[k].l=l;
	tree[k].r=r;
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

void update(int k,int i,int v)//将a[i]修改更新为v 
{
	if(tree[k].l==tree[k].r&&tree[k].l==i)//找到a[i]
	{
		tree[k].mx=v;
		return ;
	} 
	int mid,lc,rc;
	mid=(tree[k].l+tree[k].r)/2;//划分点 
	lc=k*2;  //左孩子存储下标 
	rc=k*2+1;//右孩子存储下标
	if(i<=mid)
		update(lc,i,v);//到左子树修改更新 
	else
		update(rc,i,v);//到右子树修改更新
	tree[k].mx=max(tree[lc].mx,tree[rc].mx);//返回时修改更新最值 
}

int query(int k,int l,int r)//求区间[l..r]的最值 
{
	if(tree[k].l>=l&&tree[k].r<=r)//找到该区间 
		return tree[k].mx;	
	int mid,lc,rc;
	mid=(tree[k].l+tree[k].r)/2;//划分点 
	lc=k*2;  //左孩子存储下标 
	rc=k*2+1;//右孩子存储下标
	int Max=-inf;//注意，局部变量，全局变量不可以 
	if(l<=mid)
		Max=max(Max,query(lc,l,r));//到左子树查询
	if(r>mid)
		Max=max(Max,query(rc,l,r));//到右子树查询
	return Max;
}

void print(int k)
{
	if(tree[k].mx)
	{
		cout<<k<<"\t"<<tree[k].l<<"\t"<<tree[k].r<<"\t"<<tree[k].mx<<"\t"<<endl;
		print(k<<1);
		print((k<<1)+1);
	}		
}

int main()
{
	int l,r;
	int i,v;
	cin>>n;//10 
	for(i=1;i<=n;i++)
		cin>>a[i];//5 3 7 2 12 1 6 4 8 15
	build(1,1,n);//创建线段树 
	print(1);
	cout<<"输入查询最值的区间l r:"<<endl;
	cin>>l>>r;
	cout<<query(1,l,r)<<endl;//求区间[l..r]的最值
	cout<<"输入修改元素的下标和值i v:"<<endl;
	cin>>i>>v;
	update(1,i,v);//将a[i]修改更新为v
	cout<<"输入查询最值的区间l r:"<<endl;
	cin>>l>>r;
	cout<<query(1,l,r)<<endl;//求区间[l..r]的最值
	return 0;
}
