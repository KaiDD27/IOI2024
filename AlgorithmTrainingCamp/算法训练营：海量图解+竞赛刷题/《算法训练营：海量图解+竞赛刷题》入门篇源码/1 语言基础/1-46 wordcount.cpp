#include<iostream>
#include<string>
using namespace std;

int countword(string s){
	int len,i=0,num=0;
	len=s.length();
	while(i<len){
		while(s[i]==' ')//��������ո� 
			i++;
		if(i<len)
			num++;
		while(s[i]!=' '&&i<len)//����һ������ 
			i++;
	}
	return num; 
}

int main(){
	string s1;
	getline(cin,s1);
	cout<<countword(s1)<<endl;
    return 0;
}
