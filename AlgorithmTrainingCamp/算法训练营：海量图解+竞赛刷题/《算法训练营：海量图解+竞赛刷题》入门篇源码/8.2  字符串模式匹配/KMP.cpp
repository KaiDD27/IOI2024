#include<iostream>
#include<string>
using namespace std;
int slen,tlen,next[1000+5];

void get_next(string t){//��ģʽ��T��next����
	int j=0,k=-1;
	next[0]=-1;
	while(j<tlen){//ģʽ��t�ĳ���
		if(k==-1||t[j]==t[k])
			next[++j]=++k;
		else
			k=next[k];
	}
	for(int i=0;i<=tlen;i++)
		cout<<next[i]<<" ";
}

void get_next2(string t){ //�Ľ���next����
	int j=0,k=-1;
	next[0]=-1;
	while(j<tlen){//ģʽ��t�ĳ���
		if(k==-1||t[j]==t[k]){
            j++,k++;
            if(t[j]==t[k])
                next[j]=next[k];
            else
                next[j]=k;
		} 
		else
			k=next[k];
	}
	for(int i=0;i<=tlen;i++)
		cout<<next[i]<<" ";
}

int KMP(string s,string t,int pos){
	int i=pos,j=0,sum=0;
	slen=s.length();
	tlen=t.length();
	get_next(t);
	while(i<slen&&j<tlen){
        sum++;
        if(j==-1||s[i]==t[j])//�����ȣ�������ȽϺ�����ַ�
			i++,j++;
		else
			j=next[j];//j���˵�next[j]
    }
	cout<<"һ���Ƚ���"<<sum<<"��"<<endl;
	if(j>=tlen) // ƥ��ɹ�
		return i-tlen+1;
	else
		return -1;
}

int main(){
	string s,t;
	cin>>s>>t;
	cout<<KMP(s,t,0)<<endl;
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
