#include<iostream>
#include<cstring>//c-风格字符串 头文件 
#include<string>//c++风格字符串 头文件 
/*C-风格：    
strlen()：长度 
strcpy()：复制 
strcat()：拼接 
strcmp()：比较 
strchr()：查找字符 
strrchr()：右侧查找字符
strstr()：查找字符串
strlwr()：转换小写 
strupr()：转换大写 
*/ 
//string类: .size, . length,=,+,==,!=,>=,<=,find 
using namespace std;

int main(){
	char s1[100];
	char s2[20]="Hello!";
	string str1,str2;
	cin>>s1;
	cout<<strlen(s1)<<endl;//求长度 
	strcat(s1,s2);//拼接
	strcat(s1,"abc");//拼接
	cout<<s1<<endl;
	cout<<strcmp(s1,s2)<<endl;//比较
	cout<<strstr(s1,s2)<<endl;//查找字符串，返回指针
	strcpy(s1,s2);//复制 
	cout<<s1<<endl;
	cout<<strchr(s1,'l')<<endl;//查找字符，返回指针
	cout<<strrchr(s1,'l')<<endl;//从右侧查找字符，返回指针
	cout<<strlwr(s1)<<endl;//转小写 
	cout<<strupr(s1)<<endl;//转大写
	
	cin>>str1>>str2;
	cout<<str1+str2<<endl;//拼接 
	cout<<str1.find(str2)<<endl;//查找，返回索引
    return 0;
}
