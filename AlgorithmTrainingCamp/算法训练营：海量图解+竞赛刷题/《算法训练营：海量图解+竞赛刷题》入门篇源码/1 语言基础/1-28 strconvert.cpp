#include<iostream>
#include<string>
using namespace std;

void strconvert(string &s){//char *s�ַ�������
	for(int i=0;i<s.length();i++)//strlen(s)
		if(s[i]>='a'&&s[i]<='z')
			s[i]-=32;
	cout<<s<<endl;
}

int main(){
	string str;//char str[10]�ַ������� 
	cin>>str;
	strconvert(str);
	cout<<str<<endl;
	return 0;
} 
