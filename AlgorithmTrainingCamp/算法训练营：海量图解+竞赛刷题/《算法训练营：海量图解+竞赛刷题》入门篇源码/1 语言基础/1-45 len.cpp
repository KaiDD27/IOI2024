#include<iostream>
#include<cstring>//c-����ַ��� ͷ�ļ� 
#include<string>//c++����ַ��� ͷ�ļ� 
/*C-���    
strlen()������ 
strcpy()������ 
strcat()��ƴ�� 
strcmp()���Ƚ� 
strchr()�������ַ� 
strrchr()���Ҳ�����ַ�
strstr()�������ַ���
strlwr()��ת��Сд 
strupr()��ת����д 
*/ 
//string��: .size, . length,=,+,==,!=,>=,<=,find 
using namespace std;

int main(){
	char s1[100];
	char s2[20]="Hello!";
	string str1,str2;
	cin>>s1;
	cout<<strlen(s1)<<endl;//�󳤶� 
	strcat(s1,s2);//ƴ��
	strcat(s1,"abc");//ƴ��
	cout<<s1<<endl;
	cout<<strcmp(s1,s2)<<endl;//�Ƚ�
	cout<<strstr(s1,s2)<<endl;//�����ַ���������ָ��
	strcpy(s1,s2);//���� 
	cout<<s1<<endl;
	cout<<strchr(s1,'l')<<endl;//�����ַ�������ָ��
	cout<<strrchr(s1,'l')<<endl;//���Ҳ�����ַ�������ָ��
	cout<<strlwr(s1)<<endl;//תСд 
	cout<<strupr(s1)<<endl;//ת��д
	
	cin>>str1>>str2;
	cout<<str1+str2<<endl;//ƴ�� 
	cout<<str1.find(str2)<<endl;//���ң���������
    return 0;
}
