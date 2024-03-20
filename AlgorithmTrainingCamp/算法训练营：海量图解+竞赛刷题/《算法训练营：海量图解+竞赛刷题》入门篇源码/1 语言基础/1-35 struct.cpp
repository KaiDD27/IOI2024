#include<iostream>
#include<string>
using namespace std;

typedef struct student{//学生信息结构体 
	string name;
	string number;
	string sex;
	int age; 
	float score;
}stu;

int main(){
	stu a;//student a;
	cout<<"请输入学生的姓名、学号、性别、年龄、分数："<<endl;
	cin>>a.name>>a.number>>a.sex>>a.age>>a.score;
	cout<<"name: "<<a.name<<endl;
	cout<<"number: "<<a.number<<endl;
	cout<<"sex: "<<a.sex<<endl;
	cout<<"age: "<<a.age<<endl;
	cout<<"score: "<<a.score<<endl;
	return 0;
} 
