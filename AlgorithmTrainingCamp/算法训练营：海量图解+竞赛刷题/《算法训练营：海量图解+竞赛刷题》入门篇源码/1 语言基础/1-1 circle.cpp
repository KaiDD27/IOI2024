#include<iostream>//输入输出头文件 
//i=input 输入
//o=output 输出
//stream 流
using namespace std;//命名空间 
//std=standard 标准的

int main(){//主函数	
	const double pi=3.14159;
	double r, c, s;
	cout<<"输入圆的半径：";
	cin>>r;
	c=2.0*pi*r;
	s=pi*r*r;
	cout<<"圆的周长为："<<c<<endl;
	cout<<"圆的面积为："<<s<<endl;
	
//	int a=10,*p;
//	int &b=a;
//	p=&a;
//	string s="C++";
//	string *ps=&s;
//	cout<<p<<endl;  //输出结果是指针p的值，a变量的地址
//	cout<<b<<endl;  //输出结果是b的值10
//	cout<<*p<<endl; //输出结果是指针p指向的变量的值，即a的值10
//	cout<<ps<<endl; //输出结果是指针ps的的值，s变量的地址
//	cout<<*ps<<endl; //输出结果是指针ps指向的变量的值，即s的值”C++”
//	a=20;
//	cout<<a<<endl;  
//	cout<<b<<endl;  
//	b=30;
//	cout<<a<<endl;  
//	cout<<b<<endl;

	//cout<<"hello world!"<<endl;//输出 
//	char c1,c2;
//	cin>>c1>>c2;
//	cout<<c1<<" "<<c2;
	//cout<<10<<endl;
	//cout<<'a'<<endl;
	//cout<<"C++"<<endl;
//	int a=10;
//	string s="C++";
//	float f=1.2;
//	cout<<a<<endl;  //输出int类型的变量
//	cout<<s<<endl;  //输出string类型的变量
//	cout<<f<<endl;  //输出float类型的变量

//	int n;
//	string s;
//	float f;
//	cin>>n>>s>>f;
//	cout<<n<<" "<<s<<" "<<f<<endl;
	return 0;//返回0 
 } 
