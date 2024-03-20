#include<iostream>
#include<string>
#include<sstream>
#include<cstring>
using namespace std;
const int maxn=500005;
const int maxz=26;//��ͬ�ַ���������������10��Сд��ĸ26
int trie[maxn][maxz];
string word[maxn];//���뵥�� 
int value[maxn];//ֵ���±�
bool end[maxn];//��ǽ��� 
int n,tot;//�ַ�����,�±� 

void insert(string s,int k){//���ַ���s���뵽�ֵ����� 
	int len=s.length(),p=1;
	for(int i=0;i<len;i++){
		int ch=s[i]-'a';//ת��������
		if(!trie[p][ch]) 
			trie[p][ch]=++tot;//��¼�±� 
		p=trie[p][ch];
	}
	value[p]=k;//��¼�±�
	end[p]=1; 
}

int query(string s){
	int len=s.length(),p=1;
	for(int i=0;i<len;i++){
		int ch=s[i]-'a';//ת��������
		p=trie[p][ch];
		if(!p)
			return 0;
	}
	if(end[p])
		return value[p];//�����±� 
	return 0;	
}

int main(){	
	string s,s1;
	memset(trie,0,sizeof(trie));
	tot=1;
	int i=1;
	while(getline(cin,s)){
		if(!s.size())
			break;
		stringstream ss(s);
		ss>>word[i]>>s1;
		insert(s1,i);
		i++;
	}
	while(cin>>s){
		int k=query(s);
		if(k)
			cout<<word[k]<<endl;
		else
			cout<<"eh"<<endl;
	}
	return 0;
}
