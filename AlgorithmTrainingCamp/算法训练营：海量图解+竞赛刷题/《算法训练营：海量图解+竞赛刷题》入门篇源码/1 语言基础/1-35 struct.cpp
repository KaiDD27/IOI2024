#include<iostream>
#include<string>
using namespace std;

typedef struct student{//ѧ����Ϣ�ṹ�� 
	string name;
	string number;
	string sex;
	int age; 
	float score;
}stu;

int main(){
	stu a;//student a;
	cout<<"������ѧ����������ѧ�š��Ա����䡢������"<<endl;
	cin>>a.name>>a.number>>a.sex>>a.age>>a.score;
	cout<<"name: "<<a.name<<endl;
	cout<<"number: "<<a.number<<endl;
	cout<<"sex: "<<a.sex<<endl;
	cout<<"age: "<<a.age<<endl;
	cout<<"score: "<<a.score<<endl;
	return 0;
} 
