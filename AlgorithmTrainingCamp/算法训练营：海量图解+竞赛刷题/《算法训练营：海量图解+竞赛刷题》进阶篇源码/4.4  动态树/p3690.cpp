#include<cstdio>
#include<algorithm>
#define MAXN 300005
#define lc c[x][0]
#define rc c[x][1]
using namespace std;
int n,m,a[MAXN];

struct Link_Cut_Tree{
	int top,c[MAXN][2],fa[MAXN],v[MAXN],st[MAXN],rev[MAXN];
	void update(int x){v[x]=v[lc]^v[rc]^a[x];}//���µ�ǰ�ڵ��ֵ��·���ϵ�ֵXOR�� 
	void pushdown(int x){//�´������� 
		if(rev[x]){
			rev[lc]^=1;rev[rc]^=1;rev[x]^=1;
			swap(lc,rc);
		}
	}
	bool isroot(int x){return c[fa[x]][0]!=x&&c[fa[x]][1]!=x;}//�ж��Ƿ�������Splay�ĸ��ڵ�  
	void rotate(int x){//��ת����x���y�ĸ��ڵ� 
		int y=fa[x],z=fa[y],k;
		k=x==c[y][0];
		if(!isroot(y)) c[z][c[z][1]==y]=x;//���y���Ǹ��ڵ㣬��ô��z�Ķ���y���x
		fa[x]=z;fa[y]=x;fa[c[x][k]]=y;
		c[y][!k]=c[x][k];c[x][k]=y;
		update(y);update(x);
	}
	void splay(int x){
		st[top=1]=x;
		for(int i=x;!isroot(i);i=fa[i]) st[++top]=fa[i];//һ��Ҫ�������� 
		while(top) pushdown(st[top--]);
		while(!isroot(x)){//��x������ 
			int y=fa[x],z=fa[y];
			if(!isroot(y)) (c[y][0]==x)^(c[z][0]==y)?rotate(x):rotate(y);
			rotate(x);
		}
	}
	void access(int x){//����һ��x����������
		for(int y=0;x;x=fa[y=x])
			splay(x),rc=y,update(x);
	}
	void makeroot(int x){//��������x���ԭ���ĸ� 
		access(x);splay(x);rev[x]^=1;
	}
	int findroot(int x){//��x�ĸ��ڵ� 
		access(x);splay(x);
		while(lc) x=lc;
		return x;
	}
	void split(int x,int y){//����һ��x��y��·��Ϊһ��Splay 
		makeroot(x);access(y);splay(y);
	}
	void cut(int x,int y){//ɾ��һ��x��y�ı� 
		split(x,y);
		if(c[y][0]!=x||c[x][1]) return;//�ӵ㣬��ʱx��y������ӣ���xû���Ҷ��ӣ������˵��x--y�м��нڵ� 
		c[y][0]=fa[c[y][0]]=0;update(y);
	}
	void link(int x,int y){//��һ��x��y����� 
		makeroot(x);fa[x]=y;
	}
}LCT;

int main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++) scanf("%d",&a[i]),LCT.v[i]=a[i];
	while(m--){
		int opt,x,y;
		scanf("%d%d%d",&opt,&x,&y);
		if(opt==0){
			LCT.split(x,y);
			printf("%d\n",LCT.v[y]);
		}else
		if(opt==1){
			if(LCT.findroot(x)!=LCT.findroot(y))//����ͨ 
				LCT.link(x,y);
		}else
		if(opt==2){
			if(LCT.findroot(x)==LCT.findroot(y))//��ͨ 
				LCT.cut(x,y);
		}else
		if(opt==3){
			LCT.splay(x);a[x]=y;
		}
	}
	return 0;
}
