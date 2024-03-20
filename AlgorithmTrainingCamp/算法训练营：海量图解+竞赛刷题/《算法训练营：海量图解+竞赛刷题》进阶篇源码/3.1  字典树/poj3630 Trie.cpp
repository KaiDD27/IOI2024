#include<iostream>
#include<string>
#include<cstring>
using namespace std;
const int maxn=100005;//最多10000个字符串，每个字符串最多10位 
const int maxz=10;//不同字符个数，例如数字10，小写字母26
int trie[maxn][maxz];
bool end[maxn];//标识单词结束 
int n,tot;//字符串数,下标 

bool insert(string s){//将字符串s插入到字典树中 
	int len=s.length(),p=1;
	for(int i=0;i<len;i++){
		int ch=s[i]-'0';//转换成数字
		if(!trie[p][ch]) 
			trie[p][ch]=++tot;//记录下标 
		else if(i==len-1)//字符串处理完毕，仍不空，说明该串是其它串的前缀 
			return true;
		p=trie[p][ch];
		if(end[p])
			return true;
	}
	end[p]=true;//标记单词结束
	return false;
}

int main(){	
	int T;
	bool ans;
	string s;
	cin>>T;
	while(T--){
		memset(trie,0,sizeof(trie));
		memset(end,false,sizeof(end));
		tot=1;
		ans=false;
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>s;
			if(ans)
				continue;
			if(insert(s))//不能立即结束，仍要读取n个串 
				ans=true;
		}
		if(ans)
			cout<<"NO"<<endl;//有前缀输出NO 
		else
			cout<<"YES"<<endl;
	}
	return 0;
}
