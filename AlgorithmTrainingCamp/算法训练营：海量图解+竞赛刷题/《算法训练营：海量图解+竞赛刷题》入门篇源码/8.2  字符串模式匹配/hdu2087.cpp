#include<iostream>
#include<string>
using namespace std;
int slen,tlen,nex[1000+5];//HDU��next��Ϊ�ؼ���,����ֱ������ 

void get_next(string t){//��ģʽ��T��next����
	int j=0,k=-1;
	nex[0]=-1;
	while(j<tlen){//ģʽ��t�ĳ���
		if(k==-1||t[j]==t[k])
			nex[++j]=++k;
		else
			k=nex[k];
	}
}

int KMP(string s,string t){
	int i=0,j=0,cnt=0;
	slen=s.length();
	tlen=t.length();
	get_next(t);
	while(i<slen){
        if(j==-1||s[i]==t[j])//�����ȣ�������ȽϺ�����ַ�
			i++,j++;
		else
			j=nex[j];//j���˵�nex[j]
		if(j==tlen){ //ƥ��ɹ�
			cnt++;
			j=0;//�������ص���j��0���¿�ʼ����������ص���j=nex[j]
		}
	}
	return cnt;
}

int main(){
	string s,t;
	while(cin>>s&&s!="#"){
		cin>>t;
		cout<<KMP(s,t)<<endl;
	}
	return 0;
}
