#include<iostream>
using namespace std;

int gcd(int x,int y){//最大公约数 
	int t;
	t=x%y;//求余数 
	while(t!=0){
		x=y;   //y做被除数 
		y=t;   //余数做除数
		t=x%y; //求余数 
	}
	return y;
}

int lcm(int x,int y){//最小公倍数 
	int g;
	g=gcd(x,y);
	return (x*y/g);
}

int main(){
	int a,b,c,d;
	cin>>a>>b;
	c=gcd(a,b);
	d=lcm(a,b);
	cout<<c<<"\t"<<d<<endl;
	return 0;
} 
