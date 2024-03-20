#include<iostream>
#include<string>
using namespace std;

int BF(string s,string t,int pos){
	int i=pos,j=0,sum=0;
	int slen=s.length();
	int tlen=t.length();
	while(i<slen&&j<tlen){
        sum++;
        if(s[i]==t[j])//如果相等，则继续比较后面的字符
			i++,j++;
		else{
			i=i-j+1; //i回退到上一轮开始比较的下一个字符
			j=0;  //j回退到第1个字符
		}
    }
	cout<<"一共比较了"<<sum<<"次"<<endl;
	if(j>=tlen) // 匹配成功
		return i-tlen+1;
	else
		return 0;
}

int main(){
	string s,t;
	cin>>s>>t;
	cout<<BF(s,t,0)<<endl;
	return 0;
 }
/*
abaabaabeca
abaabe
*/
/*
aabaaabaaaabea
aaaab
*/

