#include<iostream>
using namespace std;
int a[1000000];//全局，静态 

int main(){
	//int a[1000000];//局部，动态，局部数组太大会闪退 
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
