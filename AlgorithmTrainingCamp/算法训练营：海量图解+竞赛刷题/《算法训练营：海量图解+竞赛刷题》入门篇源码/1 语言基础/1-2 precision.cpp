#include<iostream>
#include<iomanip>
#include<cmath>
using namespace std;

int main(){
	double d=sqrt(2.0);
	cout<<"�������ã�"<<endl;
	for(int i=0;i<5;i++){
		cout<<fixed;//����fixed��ľ�����ָС������λ�� 
		cout<<setprecision(i)<<d<<endl;//���ò�ͬ�ľ���
	}
	cout<<"��ǰ����Ϊ��"<<cout.precision()<<endl;
	cout<<"��ǰ���" <<cout.width()<<endl;
	cout<<left;
	cout<<setw(16)<<d<<setw(10)<<d<<setw(10)<<d<<endl; //Ĭ�����Ҷ���
	cout<<"��ǰ����ַ���"<<endl;
	cout<<setfill('*')<<setw(10)<<d<<endl; //setfill()��������ֱ�Ӳ�������
	return 0;
}
