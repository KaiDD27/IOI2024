#include<iostream>
using namespace std;
int a[100];
int add(int a[],int n){
	int sum=0; 
	for(int i=0;i<n;i++)
		sum+=a[i];
	return sum;
}

int main(){
	int n,s;
	float avg;
	cin>>n;
	for(int i=0;i<n;i++)
		cin>>a[i];
	s=add(a,n); 
	avg=float(s)/n;
	cout<<s<<"\t"<<avg<<endl; 
    return 0;
}
