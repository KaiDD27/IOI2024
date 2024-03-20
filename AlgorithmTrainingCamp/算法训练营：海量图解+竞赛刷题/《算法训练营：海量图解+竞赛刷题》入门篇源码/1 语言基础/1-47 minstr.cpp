#include<iostream>
#include<string>
using namespace std;

string minstr(string s1,string s2){
	if(s1<s2)
		return s1;
	else
		return s2;
}
 
int main(){
	string s1,s2,s3,min;
	cin>>s1>>s2>>s3;
	min=minstr(s1,minstr(s2,s3));
	cout<<min<<endl;
    return 0;
}
