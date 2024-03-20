#include<iostream>
#include<cstring>
#include<string>
using namespace std;
struct data{
    int l,r;
    char c;
}tree[110];
int cnt=1;

void insert(int t,char ch){
    if(!tree[t].c){
        tree[t].c=ch;
        return;
    }
    if(ch<tree[t].c){
        if(!tree[t].l){
            tree[++cnt].c=ch;
            tree[t].l=cnt;
        }
        else
			insert(tree[t].l,ch);
    }
    if(ch>tree[t].c){
        if(!tree[t].r){
            tree[++cnt].c=ch;
            tree[t].r=cnt;
        }
        else
			insert(tree[t].r,ch);
    }
}

void preorder(int t){
    if(!tree[t].c)
		return;
    cout<<tree[t].c;
    preorder(tree[t].l);
    preorder(tree[t].r);
}

int main(){
    string s1,s;
    while(1){
        s="";
        memset(tree,0,sizeof(tree));
        while(cin>>s1&&s1[0]!='*'&&s1[0]!='$')
			s+=s1;
        for(int i=s.length()-1;i>=0;i--) 
        	insert(1,s[i]);
        preorder(1);
        cout<<endl;
        if(s1[0]=='$')
			break;
    }
}
