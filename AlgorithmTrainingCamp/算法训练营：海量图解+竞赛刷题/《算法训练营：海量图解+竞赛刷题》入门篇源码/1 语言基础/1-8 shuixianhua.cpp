#include <iostream>
using namespace std;

int main(){
    int num,a,b,c;
	cin>>num;
	a=num%10;  //��λ����
	b=(num/10)%10; //ʮλ����
	c=num/100;     //��λ����
	if(num==(a*a*a+b*b*b+c*c*c))
		cout<<num<<"��ˮ�ɻ���"<<endl;
    else
        cout<<num<<"����ˮ�ɻ���"<<endl;
    return 0;
}
