#include<iostream>
#include<cstring>//c-����ַ��� ͷ�ļ� 
#include<string>//string�����ַ��� ͷ�ļ� 
using namespace std;
const int maxsize=100;
int main(){
	//C��� 
	char s1[maxsize],s2[maxsize],s3[maxsize],s4[maxsize];
	cin.get(s1,100);
	cout<<"s1="<<s1<<endl;
	cin.getline(s1,10,':');
	cout<<strlen(s1)<<endl;
	cout<<"s1="<<s1<<endl;
	
	cin.getline(s2,maxsize);
	cout<<strlen(s2)<<endl;
	cout<<"s2="<<s2<<endl;
    
	cin.get(s3,maxsize).get();//ȥ�����з� 
    cout<<"s3="<<s3<<endl;
    
	cin.get(s4,maxsize);
    cout<<"s4="<<s4<<endl;
    
	cin>>s1;//������з�
    cout<<"s1="<<s1<<endl;
    
	cin.get();//ȥ�����з� 
    cin.getline(s2,maxsize);
    cout<<"s2="<<s2<<endl;
 	
    //c++���
    string str1,str2;
	cin>>str1;//ֻ��һ������
    cout<<"str1="<<str1<<endl<<endl;
    cin.get();
	getline(cin,str2);//������з�
    cout<<"str2="<<str2<<endl<<endl;
    getline(cin,str1);//������з�
    cout<<"str1="<<str1<<endl;
    return 0;
}
