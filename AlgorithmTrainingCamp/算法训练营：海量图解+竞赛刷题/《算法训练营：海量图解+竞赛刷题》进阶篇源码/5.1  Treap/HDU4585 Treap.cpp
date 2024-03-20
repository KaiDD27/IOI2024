#include<cstdio>
#include<cstdlib>
#include<ctime>
#include<cstring>
#include <algorithm>
using namespace std;
const int maxn=200010;//ע�⣡100000�ᳬʱ 
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

void Update(int &p){//����������С 
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

int Findkth(int &p,int k){//���kС����
    if(!p) return 0;
    int t=tr[tr[p].lc].size;
    if(k<t+1) return Findkth(tr[p].lc,k);
    else if(k>t+tr[p].num) return Findkth(tr[p].rc,k-(t+tr[p].num));
    else return tr[p].val;
}

int Rank(int p,int val){//���� 
    if(!p)
		return 0;
	if(tr[p].val==val)
		return tr[tr[p].lc].size+1;
	if(val<tr[p].val)
		return Rank(tr[p].lc,val);
	else
		return Rank(tr[p].rc,val)+tr[tr[p].lc].size+tr[p].num;
}

int id[5000010];
int main(){
    int n,a,b;
    while(scanf("%d",&n)!=-1){
		if(n==0) break;
		root=0;
        int ans1,ans2;
        memset(id,0,sizeof(id));
        scanf("%d%d",&a,&b);
        printf("%d 1\n",a);
        id[b]=a;
		Insert(root,b);
        for(int i=1;i<n;i++){
            scanf("%d%d",&a,&b);
            id[b]=a;
			Insert(root,b);
            int ans;
            int k=Rank(root,b);//��ֵ������ 
            ans1=Findkth(root,k-1);//�����β�ֵ 
            ans2=Findkth(root,k+1);
            if(!ans1) ans=ans2;
            else if(!ans2) ans=ans1;
	            else{
					if(b-ans1<=ans2-b)
	                    ans=ans1;
	                else ans=ans2;
	        	}
            printf("%d %d\n",a,id[ans]);
        }
    }
    return 0;
}
