#include<iostream>
using namespace std;
int a[1000000];//ȫ�֣���̬ 

int main(){
	//int a[1000000];//�ֲ�����̬���ֲ�����̫������� 
	int b[5]={2,4,5};
	int c[]={1,2,3,4};
	cout<<sizeof(b)<<endl;
	cout<<sizeof(c)<<endl;
	for(int i=0;i<15;i++)
		cout<<b[i]<<endl;
	cout<<endl;
	for(int i=0;i<15;i++)
		a[i]=i;
	for(int i=0;i<15;i++)
		cout<<a[i]<<endl;
    return 0;
}
