#include<iostream>
using namespace std;

int count(int a[],int n){
	int sum=0;
	for(int i=0;i<n;i++)
		if(a[i]<60)
			sum++;
	return sum;
}

int main(){
	int n;
	cin>>n;
	int *a=new int[n];//¶¯Ì¬Êý×é
	for(int i=0;i<n;i++)
		cin>>a[i];
	cout<<"no pass:"<<count(a,n)<<endl; 
	delete[] a;
    return 0;
}
