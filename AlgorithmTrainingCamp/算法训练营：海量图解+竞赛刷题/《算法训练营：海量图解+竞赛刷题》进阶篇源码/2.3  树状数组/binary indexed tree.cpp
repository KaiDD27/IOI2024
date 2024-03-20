#include<iostream>
#include<cstring>
using namespace std;
const int maxn=10000;
int n,a[maxn],c[maxn],s[maxn];

int lowbit(int i)//c[i]�����䳤�� 
{
	return (-i)&i;
}

void add(int i,int z)//a[i]����z
{
	for(;i<=n;i+=lowbit(i))//ֱ�Ӻ�̣�������i+=lowbit(i)
		c[i]+=z;	
} 

int sum(int i)//��ǰ׺��a[1]..a[i] 
{
	int s=0;
	for(;i>0;i-=lowbit(i))//ֱ��ǰ�� i-=lowbit(i);
		s+=c[i];
	return s; 
}

int sum(int i,int j)//�������a[i]..a[j] 
{
	return sum(j)-sum(i-1); 
}

int main()
{
	memset(c,0,sizeof(c));
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		add(i,a[i]);//������״���� 
	} 
	int x1,x2;
	cin>>x1;
	cout<<sum(x1)<<endl;
	cin>>x1>>x2;
	cout<<sum(x1,x2)<<endl;
	return 0;
}
