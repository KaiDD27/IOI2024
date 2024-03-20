#include<iostream>
#include<string>
using namespace std;
int slen,tlen,next[1000+5];

void get_next(string t){//求模式串T的next函数
	int j=0,k=-1;
	next[0]=-1;
	while(j<tlen){//模式串t的长度
		if(k==-1||t[j]==t[k])
			next[++j]=++k;
		else
			k=next[k];
	}
	for(int i=0;i<=tlen;i++)
		cout<<next[i]<<" ";
}

void get_next2(string t){ //改进的next函数
	int j=0,k=-1;
	next[0]=-1;
	while(j<tlen){//模式串t的长度
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
        if(j==-1||s[i]==t[j])//如果相等，则继续比较后面的字符
			i++,j++;
		else
			j=next[j];//j回退到next[j]
    }
	cout<<"一共比较了"<<sum<<"次"<<endl;
	if(j>=tlen) // 匹配成功
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
