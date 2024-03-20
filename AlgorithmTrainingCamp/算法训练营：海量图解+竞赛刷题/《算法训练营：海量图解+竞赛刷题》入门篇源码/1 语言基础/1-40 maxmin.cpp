#include<iostream>
using namespace std;
int a[100];
int max(int *a,int n){
	int max=a[0]; 
	for(int i=1;i<n;i++)
		if(a[i]>max)
			max=a[i];
	return max;
}

int min(int a[],int n){
	int min=a[0]; 
	for(int i=1;i<n;i++)
		if(a[i]<min)
			min=a[i];
	return min;
}

int main(){
	int n;
	cin>>n;
	for(int i=0;i<n;i++)
		cin>>a[i];
	cout<<"max="<<max(a,n)<<endl; 
	cout<<"min="<<min(a,n)<<endl; 
    return 0;
}
