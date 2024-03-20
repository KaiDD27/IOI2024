#include<cstdio>
#include<cstdlib>
#include<ctime>
using namespace std;
const int maxn=30010;
int num[maxn],num1[maxn];
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

int main(){
    int n,a,b,m;
	srand(time(0));
    while(scanf("%d%d",&n,&m)!=-1){
        root=0;
		for(int i=1;i<=n;i++)
			scanf("%d",&num[i]);
        for(int i=1;i<=m;i++)
			scanf("%d",&num1[i]);
		int t=1,k=1;
        while(t<=m){
            while(k<=num1[t]){
                Insert(root,num[k]);
                k++;
            }
            int ans=Findkth(root,t++);
            printf("%d\n",ans);
        }
    }
    return 0;
}
