#include<iostream>
#include<cstring>
using namespace std;
struct node{
	int a,b;
	double r,c;
}e[210];
double dis[110];
int n,m,s,cnt=0;
double v;

void add(int a,int b,double r,double c){
	e[cnt].a=a;
	e[cnt].b=b;
	e[cnt].r=r;
	e[cnt++].c=c;
}

bool bellman_ford(){//判正环 
	memset(dis,0,sizeof(dis));
	dis[s]=v;
	for(int i=1;i<n;i++){//执行n-1次 
		bool flag=false;
		for(int j=0;j<cnt;j++)//注意：边数是2m或使用cnt
			if(dis[e[j].b]<(dis[e[j].a]-e[j].c)*e[j].r){
				dis[e[j].b]=(dis[e[j].a]-e[j].c)*e[j].r;
				flag=true;
			}
		if(!flag)
			return false;
	}
	for(int j=0;j<cnt;j++)//再执行1次，还能松弛说明有环
		if(dis[e[j].b]<(dis[e[j].a]-e[j].c)*e[j].r)
			return true;
	return false;
}

int main(){
	int a,b;
	double rab,cab,rba,cba;
	cin>>n>>m>>s>>v;
	for(int i=0;i<m;i++){
		cin>>a>>b>>rab>>cab>>rba>>cba;
		add(a,b,rab,cab);
		add(b,a,rba,cba);
	}
	if(bellman_ford())
		cout<<"YES"<<endl;
	else
		cout<<"NO"<<endl;
	return 0;
}
