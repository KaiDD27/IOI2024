#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
const int maxn=100005;
const int inf=0x3f3f3f3f;
int n,a[maxn];

struct node//���
{ 
	int l,r,mx;//l,r��ʾ�������Ҷ˵㣬mx��ʾ����[l,r]����ֵ 
}tree[maxn*4]; //�����洢���� 

void build(int k,int l,int r)//�����߶���,k��ʾ�洢�±�,����[l,r]
{
	tree[k].l=l;
	tree[k].r=r;
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

void update(int k,int i,int v)//��a[i]�޸ĸ���Ϊv 
{
	if(tree[k].l==tree[k].r&&tree[k].l==i)//�ҵ�a[i]
	{
		tree[k].mx=v;
		return ;
	} 
	int mid,lc,rc;
	mid=(tree[k].l+tree[k].r)/2;//���ֵ� 
	lc=k*2;  //���Ӵ洢�±� 
	rc=k*2+1;//�Һ��Ӵ洢�±�
	if(i<=mid)
		update(lc,i,v);//���������޸ĸ��� 
	else
		update(rc,i,v);//���������޸ĸ���
	tree[k].mx=max(tree[lc].mx,tree[rc].mx);//����ʱ�޸ĸ�����ֵ 
}

int query(int k,int l,int r)//������[l..r]����ֵ 
{
	if(tree[k].l>=l&&tree[k].r<=r)//�ҵ������� 
		return tree[k].mx;	
	int mid,lc,rc;
	mid=(tree[k].l+tree[k].r)/2;//���ֵ� 
	lc=k*2;  //���Ӵ洢�±� 
	rc=k*2+1;//�Һ��Ӵ洢�±�
	int Max=-inf;//ע�⣬�ֲ�������ȫ�ֱ��������� 
	if(l<=mid)
		Max=max(Max,query(lc,l,r));//����������ѯ
	if(r>mid)
		Max=max(Max,query(rc,l,r));//����������ѯ
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
	build(1,1,n);//�����߶��� 
	print(1);
	cout<<"�����ѯ��ֵ������l r:"<<endl;
	cin>>l>>r;
	cout<<query(1,l,r)<<endl;//������[l..r]����ֵ
	cout<<"�����޸�Ԫ�ص��±��ֵi v:"<<endl;
	cin>>i>>v;
	update(1,i,v);//��a[i]�޸ĸ���Ϊv
	cout<<"�����ѯ��ֵ������l r:"<<endl;
	cin>>l>>r;
	cout<<query(1,l,r)<<endl;//������[l..r]����ֵ
	return 0;
}
