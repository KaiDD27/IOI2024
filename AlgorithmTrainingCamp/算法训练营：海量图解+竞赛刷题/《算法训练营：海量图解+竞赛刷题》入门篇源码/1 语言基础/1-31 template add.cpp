#include<iostream>
using namespace std;

template<typename T>//Ä£°å 
T add(T x,T y){
	return x+y;
} 

int main(){
	int a,b;
	double c,d;
	cin>>a>>b>>c>>d;
	cout<<add(a,b)<<"\t"<<add(c,d)<<endl;
	return 0;
} 
