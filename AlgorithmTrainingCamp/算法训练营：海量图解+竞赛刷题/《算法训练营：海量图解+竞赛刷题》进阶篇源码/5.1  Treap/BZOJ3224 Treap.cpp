#include<iostream>
#include<cstdlib>
#include<ctime>
using namespace std;
const int maxn=100005;
int n,cnt,root;//����������洢�±��ۼƣ����� 
struct node{
	int lc,rc;//���Һ���
	int val,pri;//ֵ�����ȼ�
	int num,size;//�ظ����������������Ĵ�С 
}tr[maxn];

int New(int val){//�����½�� 
	tr[++cnt].val=val;
	tr[cnt].pri=rand();
	tr[cnt].num=tr[cnt].size=1;
	tr[cnt].rc=tr[cnt].lc=0;
	return cnt;
}

void Update(int p){//����������С 
	tr[p].size=tr[tr[p].lc].size+tr[tr[p].rc].size+tr[p].num;
}

void zig(int &p){//���� 
	int q=tr[p].lc;
	tr[p].lc=tr[q].rc;
	tr[q].rc=p;
	tr[q].size=tr[p].size;
	Update(p);
	p=q;//����qΪ�� 
}

void zag(int &p){//���� 
	int q=tr[p].rc;
	tr[p].rc=tr[q].lc;
	tr[q].lc=p;
	tr[q].size=tr[p].size;
	Update(p);
	p=q;//����qΪ�� 
}

void Insert(int &p,int val){//��p����������ֵval 
	if(!p){
		p=New(val);
		return;
	}
	tr[p].size++;
	if(val==tr[p].val){
		tr[p].num++;
		return;
	}
	if(val<tr[p].val){
		Insert(tr[p].lc,val);
		if(tr[p].pri<tr[tr[p].lc].pri)
			zig(p);	
	}
	else{
		Insert(tr[p].rc,val);
		if(tr[p].pri<tr[tr[p].rc].pri)
			zag(p);	
	}
}

void Delete(int &p,int val){//��p������ɾ��ֵval 
	if(!p)
		return;
	tr[p].size--;
	if(val==tr[p].val){
		if(tr[p].num>1){
			tr[p].num--;
			return;
		}
		if(!tr[p].lc||!tr[p].rc)
			p=tr[p].lc+tr[p].rc;//��һ������Ϊ�գ�ֱ���ö��Ӵ���
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

int GetPre(int val){//��ǰ�� 
	int p=root;
	int res=0;
	while(p){
		if(tr[p].val<val){
			res=tr[p].val;
			p=tr[p].rc;
		}
		else
			p=tr[p].lc;
	}
	return res;
}

int GetNext(int val){//�Һ�� 
	int p=root;
	int res=0;
	while(p){
		if(tr[p].val>val){
			res=tr[p].val;
			p=tr[p].lc;
		}
		else
			p=tr[p].rc;
	}
	return res;
}

int GetRankByVal(int p,int val){
	if(!p)
		return 0;
	if(tr[p].val==val)
		return tr[tr[p].lc].size+1;
	if(val<tr[p].val)
		return GetRankByVal(tr[p].lc,val);
	else
		return GetRankByVal(tr[p].rc,val)+tr[tr[p].lc].size+tr[p].num;
}

int GetValByRank(int p,int rank){
	if(!p)
		return 0;
	if(tr[tr[p].lc].size>=rank)
		return GetValByRank(tr[p].lc,rank);
	if(tr[tr[p].lc].size+tr[p].num>=rank)
		return tr[p].val;
	return GetValByRank(tr[p].rc,rank-tr[tr[p].lc].size-tr[p].num);
}

//void print(int p)
//{
//	//cout<<"tr[i].val<<" "<<tr[i].pri<<" "<<tr[i].num<<" "<<tr[i].size<<" "<<tr[i].lc<<" "<<tr[i].rc"<<endl;
//	if(p)
//	{
//		print(tr[p].lc);
//		cout<<tr[p].val<<" "<<tr[p].pri<<" "<<tr[p].num<<" "<<tr[p].size<<" "<<tr[p].lc<<" "<<tr[p].rc<<" "<<endl;
//		print(tr[p].rc);
//	}
//}

int main(){
	int x;
	cin>>n;
	//srand(time(0));
	while(n--){
		int opt,x;
		cin>>opt>>x;
		switch(opt){
			case 1:
				Insert(root,x);
				//print(root);
				break;
			case 2:
				Delete(root,x);
				//print(root);
				break;
			case 3:
				cout<<GetRankByVal(root,x)<<endl;
				break;
			case 4:
				cout<<GetValByRank(root,x)<<endl;
				break;
			case 5:
				cout<<GetPre(x)<<endl;
				break;
			case 6:
				cout<<GetNext(x)<<endl;
				break;
		}	
	}
	return 0;
}
