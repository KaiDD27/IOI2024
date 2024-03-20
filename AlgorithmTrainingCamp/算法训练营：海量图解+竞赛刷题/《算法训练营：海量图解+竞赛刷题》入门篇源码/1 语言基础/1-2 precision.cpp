#include<iostream>
#include<iomanip>
#include<cmath>
using namespace std;

int main(){
	double d=sqrt(2.0);
	cout<<"精度设置："<<endl;
	for(int i=0;i<5;i++){
		cout<<fixed;//设置fixed后的精度是指小数点后的位数 
		cout<<setprecision(i)<<d<<endl;//设置不同的精度
	}
	cout<<"当前精度为："<<cout.precision()<<endl;
	cout<<"当前域宽：" <<cout.width()<<endl;
	cout<<left;
	cout<<setw(16)<<d<<setw(10)<<d<<setw(10)<<d<<endl; //默认是右对齐
	cout<<"当前填充字符："<<endl;
	cout<<setfill('*')<<setw(10)<<d<<endl; //setfill()函数可以直接插入流中
	return 0;
}
