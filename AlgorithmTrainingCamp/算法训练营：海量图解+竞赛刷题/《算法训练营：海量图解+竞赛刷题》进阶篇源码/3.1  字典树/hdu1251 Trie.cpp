#include<iostream>
#include<string>
#include<cstring>
using namespace std;
const int maxn=500005;
const int maxz=26;//不同字符个数，例如数字10，小写字母26
int trie[maxn][maxz];
int cnt[maxn];//计数器 

void insert(string s){//将字符串s插入到字典树中 
	int len=s.length(),p=1;
	for(int i=0;i<len;i++){
		int ch=s[i]-'a';//转换成数字
		if(!trie[p][ch]) 
			trie[p][ch]=++tot;//记录下标 
		p=trie[p][ch];
		cnt[p]++;//统计有多少个单词经过 
	}
}

int query(string s){
	int len=s.length(),p=1;
	for(int i=0;i<len;i++){
		int ch=s[i]-'a';//转换成数字
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
