#include<iostream>
#include<algorithm>
#include<cmath>//使用log函数
/*log():以e为底的对数，exp(5)=e^5,log(exp(5))=5
  log10():以10为底的对数
  log2():以2为底的对数 
  任何一个其它的对数logm(n)=log(n)/log(m)*/
using namespace std;
const int maxn=105;
int n,a[maxn],F[maxn][maxn];//F(i,j)表示区间[i，i+2^j-1]的最值，区间长度为2^j

void ST_create()
{
	for(int i=1;i<=n;i++)//初始化 
		F[i][0]=a[i];
	int k=log2(n);//log(n)/log(2);
	for(int j=1;j<=k;j++)
		for(int i=1;i<=n-(1<<j)+1;i++)//n-2^j+1
			F[i][j]=max(F[i][j-1],F[i+(1<<(j-1))][j-1]);
}

int ST_query(int l,int r)//求区间[l..r]的最值 
{
	int k=log2(r-l+1);
	return max(F[l][k],F[r-(1<<k)+1][k]);//取两个区间最值 
}

int ST_print()
{
	int k=log2(n);
	for(int j=0;j<=k;j++)
	{	
		for(int i=1;i<=n-(1<<j)+1;i++)//n-2^j+1,打印第一列 
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
	ST_create();//创建ST表
	ST_print();
	cout<<"输入查询最值的区间l r:"<<endl;
	cin>>l>>r;
	cout<<ST_query(l,r)<<endl;//求区间[l..r]的最值
	return 0;
}
