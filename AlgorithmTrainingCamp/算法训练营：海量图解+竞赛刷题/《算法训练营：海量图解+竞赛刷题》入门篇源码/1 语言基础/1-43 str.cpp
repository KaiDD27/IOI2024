#include<iostream>
#include<cstring>
using namespace std;
int main(){
	char s1[100];
	char s2[20]="hello£¡";
	char s3[]="a";
	char s4='a';
	char s5[3]={'a','b','c'};
	char s6[3]={'a','b','\0'};
	cin>>s1;
	//s1[5]='\0';
	cout<<strlen(s1)<<endl;
	cout<<s1<<"  "<<s2<<"  "<<s3<<"  "<<s4<<"  "<<endl;
	cout<<s5<<"  "<<s6<<"  "<<endl;
	cout<<"jasfljfalfsd" "123"<<endl;
	cout<<"jasfljfalfsd"
	"123"<<endl;
	cout<<"jasfljfalfsd	  123"<<endl;
	return 0;
}
