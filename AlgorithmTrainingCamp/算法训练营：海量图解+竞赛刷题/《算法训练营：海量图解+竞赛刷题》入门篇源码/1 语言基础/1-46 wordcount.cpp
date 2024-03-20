#include<iostream>
#include<string>
using namespace std;

int countword(string s){
	int len,i=0,num=0;
	len=s.length();
	while(i<len){
		while(s[i]==' ')//跳过多个空格 
			i++;
		if(i<len)
			num++;
		while(s[i]!=' '&&i<len)//跳过一个单词 
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
