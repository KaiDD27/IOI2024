#include<iostream>
#include<cstdlib>
#include<ctime>
using namespace std;
const int maxn=100005;
int n,cnt,root,maxval,minval;//结点数，结点存储下标累计，树根 
struct node{
	int lc,rc;//左右孩子
	int val,pri;//值，优先级
	int num;//编号 
}tr[maxn];

int New(int val,int num){//生成新结点 
	tr[++cnt].val=val;
	tr[cnt].pri=rand();
	tr[cnt].num=num;
	tr[cnt].rc=tr[cnt].lc=0;
	return cnt;
}

void zig(int &p){//右旋 
	int q=tr[p].lc;
	tr[p].lc=tr[q].rc;
	tr[q].rc=p;
	p=q;//现在q为根 
}

void zag(int &p){//左旋 
	int q=tr[p].rc;
	tr[p].rc=tr[q].lc;
	tr[q].lc=p;
	p=q;//现在q为根 
}

void Insert(int &p,int val,int num){//在p的子树插入值val 
	if(!p){
		p=New(val,num);
		return;
	}
	if(val<=tr[p].val){
		Insert(tr[p].lc,val,num);
		if(tr[p].pri<tr[tr[p].lc].pri)
			zig(p);	
	}
	else{
		Insert(tr[p].rc,val,num);
		if(tr[p].pri<tr[tr[p].rc].pri)
			zag(p);	
	}
}

void Delete(int &p,int val){//在p的子树删除值val 
	if(!p)
		return;
	if(val==tr[p].val){
		if(!tr[p].lc||!tr[p].rc)
			p=tr[p].lc+tr[p].rc;//有一个儿子为空，直接用儿子代替
		else if(tr[tr[p].lc].pri>tr[tr[p].rc].pri){
				zig(p);
				Delete(tr[p].rc,val);
		 	}
		 	else{
				zag(p);
				Delete(tr[p].lc,val);
		 	}
		return;
	}
	if(val<tr[p].val)
		Delete(tr[p].lc,val);	
	else
		Delete(tr[p].rc,val);
}

void printmax(int p){//找优先级最大的结点编号 
	while(tr[p].rc){
		p=tr[p].rc;
	}
	cout<<tr[p].num<<endl;
	maxval=tr[p].val;
}

void printmin(int p){//找优先级最低的结点编号 
	while(tr[p].lc){
		p=tr[p].lc;
	}
	cout<<tr[p].num<<endl;
	minval=tr[p].val;
}

int main(){
	int num,val;
	srand(time(0));
	while(cin>>n&&n){
		switch(n){
			case 1:
				cin>>num>>val;
				Insert(root,val,num);
				break;
			case 2:
				if(!root)
					cout<<0<<endl;
				else{
					printmax(root);
					Delete(root,maxval);
				}
				break;
			case 3:
				if(!root)
					cout<<0<<endl;
				else{
					printmin(root);
					Delete(root,minval);
				}
				break;
		}	
	}
	return 0;
}
