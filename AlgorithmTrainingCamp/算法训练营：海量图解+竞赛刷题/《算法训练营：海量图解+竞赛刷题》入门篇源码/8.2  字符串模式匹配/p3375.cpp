#include<iostream>
#include<string>
using namespace std;
int slen,tlen;
int next[1000000+5];

void get_next(string t){//��ģʽ��T��next����ֵ
	int j=0,k=-1;
	next[0]=-1;
	while(j<tlen){//ģʽ��t�ĳ���
		if(k==-1||t[j]==t[k])
			next[++j]=++k;
		else
			k=next[k];
	}
}

void KMP(string s,string t){
	int i=0,j=0;
	slen=s.length();
	tlen=t.length();
	get_next(t);
	while(i<slen){
        if(j==-1||s[i]==t[j]){//�����ȣ�������ȽϺ�����ַ�
			i++;
			j++;
		}
		else
			j=next[j]; //j���˵�next[j]
		if(j==tlen){ //ƥ��ɹ�
			cout<<i-tlen+1<<endl;
			j=next[j];//�������ص���j��0���¿�ʼ����������ص���j=nex[j]
		}
	}
}

int main(){
	string s,t;
	cin>>s>>t;
	KMP(s,t);
	for(int i=1;i<=tlen;i++)
		cout<<next[i]<<" ";
	return 0;
} 
