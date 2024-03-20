#include<iostream>
#include<cstring>//c-风格字符串 头文件 
#include<string>//string对象字符串 头文件 
using namespace std;
const int maxsize=100;
int main(){
	//C风格 
	char s1[maxsize],s2[maxsize],s3[maxsize],s4[maxsize];
	cin.get(s1,100);
	cout<<"s1="<<s1<<endl;
	cin.getline(s1,10,':');
	cout<<strlen(s1)<<endl;
	cout<<"s1="<<s1<<endl;
	
	cin.getline(s2,maxsize);
	cout<<strlen(s2)<<endl;
	cout<<"s2="<<s2<<endl;
    
	cin.get(s3,maxsize).get();//去掉换行符 
    cout<<"s3="<<s3<<endl;
    
	cin.get(s4,maxsize);
    cout<<"s4="<<s4<<endl;
    
	cin>>s1;//会读换行符
    cout<<"s1="<<s1<<endl;
    
	cin.get();//去掉换行符 
    cin.getline(s2,maxsize);
    cout<<"s2="<<s2<<endl;
 	
    //c++风格
    string str1,str2;
	cin>>str1;//只读一个单词
    cout<<"str1="<<str1<<endl<<endl;
    cin.get();
	getline(cin,str2);//会读换行符
    cout<<"str2="<<str2<<endl<<endl;
    getline(cin,str1);//会读换行符
    cout<<"str1="<<str1<<endl;
    return 0;
}
