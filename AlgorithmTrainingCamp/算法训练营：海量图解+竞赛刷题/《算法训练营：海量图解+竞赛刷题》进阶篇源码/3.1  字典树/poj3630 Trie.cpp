#include<iostream>
#include<string>
#include<cstring>
using namespace std;
const int maxn=100005;//���10000���ַ�����ÿ���ַ������10λ 
const int maxz=10;//��ͬ�ַ���������������10��Сд��ĸ26
int trie[maxn][maxz];
bool end[maxn];//��ʶ���ʽ��� 
int n,tot;//�ַ�����,�±� 

bool insert(string s){//���ַ���s���뵽�ֵ����� 
	int len=s.length(),p=1;
	for(int i=0;i<len;i++){
		int ch=s[i]-'0';//ת��������
		if(!trie[p][ch]) 
			trie[p][ch]=++tot;//��¼�±� 
		else if(i==len-1)//�ַ���������ϣ��Բ��գ�˵���ô�����������ǰ׺ 
			return true;
		p=trie[p][ch];
		if(end[p])
			return true;
	}
	end[p]=true;//��ǵ��ʽ���
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
			if(insert(s))//����������������Ҫ��ȡn���� 
				ans=true;
		}
		if(ans)
			cout<<"NO"<<endl;//��ǰ׺���NO 
		else
			cout<<"YES"<<endl;
	}
	return 0;
}
