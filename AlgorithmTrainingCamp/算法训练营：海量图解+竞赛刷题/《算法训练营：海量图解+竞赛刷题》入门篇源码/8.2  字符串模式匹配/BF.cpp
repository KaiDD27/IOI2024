#include<iostream>
#include<string>
using namespace std;

int BF(string s,string t,int pos){
	int i=pos,j=0,sum=0;
	int slen=s.length();
	int tlen=t.length();
	while(i<slen&&j<tlen){
        sum++;
        if(s[i]==t[j])//�����ȣ�������ȽϺ�����ַ�
			i++,j++;
		else{
			i=i-j+1; //i���˵���һ�ֿ�ʼ�Ƚϵ���һ���ַ�
			j=0;  //j���˵���1���ַ�
		}
    }
	cout<<"һ���Ƚ���"<<sum<<"��"<<endl;
	if(j>=tlen) // ƥ��ɹ�
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

