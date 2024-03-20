#include<iostream>
#include<string>
using namespace std;

float half(float x){
	return x/2;
}

string half(string s){
	int n=s.length()/2;
	char *str=new char[n];
	for(int i=0;i<n;i++)
		str[i]=s[i];
	return str;
}

int main(){
	float n;
	string st;
	cin>>n>>st;
	cout<<half(n)<<endl;
	cout<<half(st)<<endl;
	return 0;
} 
