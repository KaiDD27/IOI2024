#include<iostream>
#include<cstring>
using namespace std;
const int maxn=10000;
int n,a[maxn][maxn],c[maxn][maxn];//二维树状数组 

int lowbit(int i)//区间长度 
{
	return (-i)&i;
}

void add(int x,int y,int z)//a[x][y]加上z
{
	for(int i=x;i<=n;i+=lowbit(i))
		for(int j=y;j<=n;j+=lowbit(j))
			c[i][j]+=z;
} 

int sum(int x,int y)//求左上角(1,1)到右下角(x,y)矩阵区间和 
{
	int s=0;
	for(int i=x;i>0;i-=lowbit(i))
		for(int j=y;j>0;j-=lowbit(j))
			s+=c[i][j];
	return s; 
}

int sum(int x1,int y1,int x2,int y2)//求左上角(x1,y1)到右下角(x2,y2)子矩阵区间和 
{
	return sum(x2,y2)-sum(x1-1,y2)-sum(x2,y1-1)+sum(x1-1,y1-1); 
}

int main()
{
	for(int i=1;i<=n;i++)
		memset(c[i],0,sizeof(c[i]));
	cin>>n;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
		{
			cin>>a[i][j];
			add(i,j,a[i][j]);//加入树状数组 
		} 
	int x1,y1,x2,y2;
	cin>>x1>>y1;
	cout<<sum(x1,y1)<<endl;
	cin>>x1>>y1>>x2>>y2;
	cout<<sum(x1,y1,x2,y2)<<endl;
	return 0;
}
