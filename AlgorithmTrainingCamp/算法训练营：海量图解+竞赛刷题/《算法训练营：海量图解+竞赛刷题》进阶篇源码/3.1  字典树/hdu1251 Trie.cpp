#include<iostream>
#include<string>
#include<cstring>
using namespace std;
const int maxn=500005;
const int maxz=26;//��ͬ�ַ���������������10��Сд��ĸ26
int trie[maxn][maxz];
int cnt[maxn];//������ 

void insert(string s){//���ַ���s���뵽�ֵ����� 
	int len=s.length(),p=1;
	for(int i=0;i<len;i++){
		int ch=s[i]-'a';//ת��������
		if(!trie[p][ch]) 
			trie[p][ch]=++tot;//��¼�±� 
		p=trie[p][ch];
		cnt[p]++;//ͳ���ж��ٸ����ʾ��� 
	}
}

int query(string s){
	int len=s.length(),p=1;
	for(int i=0;i<len;i++){
		int ch=s[i]-'a';//ת��������
		p=trie[p][ch];
		if(!p)
			return 0;
	}
	return cnt[p];	
}

int main(){	
	string s;
	memset(trie,0,sizeof(trie));
	memset(cnt,0,sizeof(cnt));
	tot=1;
	while(getline(cin,s)){
		if(!s.size())
			break;
		insert(s);
	}
	while(cin>>s)
		cout<<query(s)<<endl;
	return 0;
}
