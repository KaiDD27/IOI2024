#include<iostream>
#include<string>
using namespace std;
int slen,tlen,nex[1000+5];//HDU将next视为关键字,会出现编译错误 

void get_next(string t){//求模式串T的next函数
	int j=0,k=-1;
	nex[0]=-1;
	while(j<tlen){//模式串t的长度
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
        if(j==-1||s[i]==t[j])//如果相等，则继续比较后面的字符
			i++,j++;
		else
			j=nex[j];//j回退到nex[j]
		if(j==tlen){ //匹配成功
			cnt++;
			j=0;//不允许重叠，j从0重新开始，如果允许重叠，j=nex[j]
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
