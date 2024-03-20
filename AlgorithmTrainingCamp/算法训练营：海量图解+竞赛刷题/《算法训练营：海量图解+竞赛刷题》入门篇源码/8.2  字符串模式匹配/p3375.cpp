#include<iostream>
#include<string>
using namespace std;
int slen,tlen;
int next[1000000+5];

void get_next(string t){//求模式串T的next函数值
	int j=0,k=-1;
	next[0]=-1;
	while(j<tlen){//模式串t的长度
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
        if(j==-1||s[i]==t[j]){//如果相等，则继续比较后面的字符
			i++;
			j++;
		}
		else
			j=next[j]; //j回退到next[j]
		if(j==tlen){ //匹配成功
			cout<<i-tlen+1<<endl;
			j=next[j];//不允许重叠，j从0重新开始，如果允许重叠，j=nex[j]
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
