#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
const int maxn=100005;
const int inf=0x3f3f3f3f;
int n,a[maxn];

struct node//���
{ 
	int l,r,mx,lz;//l,r��ʾ�������Ҷ˵㣬mx��ʾ����[l,r]����ֵ��lzΪ����� 
}tree[maxn*4]; //�����洢���� 

void lazy(int k,int v)
{
	tree[k].mx=v;//������ֵ
	tree[k].lz=v;//�������
}

void pushdown(int k)//���´�������� 
{
	lazy(2*k,tree[k].lz);//���ݸ�����
	lazy(2*k+1,tree[k].lz);//���ݸ��Һ���
	tree[k].lz=-1;//����Լ�������� 
}

void build(int k,int l,int r)//�����߶���,k��ʾ�洢�±�,����[l,r]
{
	tree[k].l=l;
	tree[k].r=r;
	tree[k].lz=-1;//��ʼ�������� 
	if(l==r)
	{
		tree[k].mx=a[l];
		return;
	}
	int mid,lc,rc;
	mid=(l+r)/2;//���ֵ� 
	lc=k*2;  //���Ӵ洢�±� 
	rc=k*2+1;//�Һ��Ӵ洢�±� 
	build(lc,l,mid);
	build(rc,mid+1,r);
	tree[k].mx=max(tree[lc].mx,tree[rc].mx);//�������ֵ�������Һ�����ֵ�����ֵ 		
} 

void update(int k,int l,int r,int v)//������[l..r]�޸ĸ���Ϊv
{
	if(tree[k].l>=l&&tree[k].r<=r)//�ҵ������� 
		return lazy(k,v);//���²��������
	if(tree[k].lz!=-1) 
		pushdown(k);//��������� 
	int mid,lc,rc;
	mid=(tree[k].l+tree[k].r)/2;//���ֵ� 
	lc=k*2;  //���Ӵ洢�±� 
	rc=k*2+1;//�Һ��Ӵ洢�±�
	if(l<=mid)
		update(lc,l,r,v);//������������ 
	if(r>mid)
		update(rc,l,r,v);//������������
	tree[k].mx=max(tree[lc].mx,tree[rc].mx);//����ʱ�޸ĸ�����ֵ
}

int query(int k,int l,int r)//������[l..r]����ֵ 
{
	int Max=-inf;
	if(tree[k].l>=l&&tree[k].r<=r)//�ҵ�������
		return tree[k].mx;
	if(tree[k].lz!=-1) 
		pushdown(k);//��������� 
	int mid,lc,rc;
	mid=(tree[k].l+tree[k].r)/2;//���ֵ� 
	lc=k*2;  //���Ӵ洢�±� 
	rc=k*2+1;//�Һ��Ӵ洢�±�
	if(l<=mid)
		Max=max(Max,query(lc,l,r));//����������ѯ 
	if(r>mid)
		Max=max(Max,query(rc,l,r));//����������ѯ
	return Max;
} 

int main()
{
	int l,r;
	int i,v;
	cin>>n;//10
	for(i=1;i<=n;i++)
		cin>>a[i];//5 3 7 2 12 1 6 4 8 15
	build(1,1,n);//�����߶��� 
	cout<<"�����ѯ��ֵ������l r:"<<endl;
	cin>>l>>r;
	cout<<query(1,l,r)<<endl;//������[l..r]����ֵ
	cout<<"������µ�����ֵl r v:"<<endl;
	cin>>l>>r>>v;
	update(1,l,r,v);//������[l..r]�޸ĸ���Ϊv
	cout<<"�����ѯ��ֵ������l r:"<<endl;
	cin>>l>>r;
	cout<<query(1,l,r)<<endl;//������[l..r]����ֵ
	return 0;
}
