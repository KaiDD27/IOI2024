#include<iostream>
using namespace std;

int gcd(int x,int y){//���Լ�� 
	int t;
	t=x%y;//������ 
	while(t!=0){
		x=y;   //y�������� 
		y=t;   //����������
		t=x%y; //������ 
	}
	return y;
}

int lcm(int x,int y){//��С������ 
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
