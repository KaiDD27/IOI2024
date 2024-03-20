#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
using namespace std;
const int maxn=105;
const double inf=0x3f3f3f3f;//类型double 
double m[maxn][maxn],low[maxn];
bool vis[maxn];
int n;
struct cell{
	double x,y,z,r;//球形单元的圆心，半径 
}c[maxn];

double clu(cell c1,cell c2){//计算两个球单元的距离
	double x=(c1.x-c2.x)*(c1.x-c2.x);
	double y=(c1.y-c2.y)*(c1.y-c2.y);
	double z=(c1.z-c2.z)*(c1.z-c2.z);
	double d=sqrt(x+y+z);
	if(d-c1.r-c2.r<=0)
		return 0.000;
	else
		return d-c1.r-c2.r;
}

double prim(int s){//返回值类型double
	for(int i=0;i<n;i++)
		low[i]=m[s][i];
	memset(vis,false,sizeof(vis));
	vis[s]=1;
	double sum=0.000;
	int t;
	for(int i=1;i<n;i++){//执行n-1次
		double min=inf;
		for(int j=0;j<n;j++){//找最小
			if(!vis[j]&&low[j]<min){
				min=low[j];
				t=j;
			}
		}
		sum+=min;
		vis[t]=1;
		for(int j=0;j<n;j++){//更新
			if(!vis[j]&&low[j]>m[t][j])
				low[j]=m[t][j];
		}	 
	}
	return sum;
}

int main(){
	while(cin>>n&&n){
		//memset(m,0x3f,sizeof(m));//不可以对浮点数赋值
		for(int i=0;i<n;i++)
			for(int j=0;j<n;j++)
				if(i=j)
					m[i][j]=0;
				else
					m[i][j]=inf;
		for(int i=0;i<n;i++)
			cin>>c[i].x>>c[i].y>>c[i].z>>c[i].r;
		for(int i=0;i<n;i++)
			for(int j=0;j<n;j++)
				if(i!=j)
					m[i][j]=m[j][i]=clu(c[i],c[j]);
		printf("%.3lf\n",prim(0));
	}
	return 0;
}
