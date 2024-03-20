#include<iostream>
#include<algorithm>
#include<cmath>//ʹ��log����
/*log():��eΪ�׵Ķ�����exp(5)=e^5,log(exp(5))=5
  log10():��10Ϊ�׵Ķ���
  log2():��2Ϊ�׵Ķ��� 
  �κ�һ�������Ķ���logm(n)=log(n)/log(m)*/
using namespace std;
const int maxn=105;
int n,a[maxn],F[maxn][maxn];//F(i,j)��ʾ����[i��i+2^j-1]����ֵ�����䳤��Ϊ2^j

void ST_create()
{
	for(int i=1;i<=n;i++)//��ʼ�� 
		F[i][0]=a[i];
	int k=log2(n);//log(n)/log(2);
	for(int j=1;j<=k;j++)
		for(int i=1;i<=n-(1<<j)+1;i++)//n-2^j+1
			F[i][j]=max(F[i][j-1],F[i+(1<<(j-1))][j-1]);
}

int ST_query(int l,int r)//������[l..r]����ֵ 
{
	int k=log2(r-l+1);
	return max(F[l][k],F[r-(1<<k)+1][k]);//ȡ����������ֵ 
}

int ST_print()
{
	int k=log2(n);
	for(int j=0;j<=k;j++)
	{	
		for(int i=1;i<=n-(1<<j)+1;i++)//n-2^j+1,��ӡ��һ�� 
			cout<<F[i][j]<<" ";
		cout<<endl;
	}
}

int main()
{
	int l,r;
	int i,v;
	cin>>n;
	for(i=1;i<=n;i++)
		cin>>a[i];//5 3 7 2 12 1 6 4 8 15
	ST_create();//����ST��
	ST_print();
	cout<<"�����ѯ��ֵ������l r:"<<endl;
	cin>>l>>r;
	cout<<ST_query(l,r)<<endl;//������[l..r]����ֵ
	return 0;
}
