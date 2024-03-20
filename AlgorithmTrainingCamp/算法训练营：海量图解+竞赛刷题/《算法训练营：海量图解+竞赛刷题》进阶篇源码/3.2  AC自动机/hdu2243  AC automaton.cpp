#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<queue>
using namespace std;
typedef unsigned long long ll;
const int maxn=40;
const int K=26;
int root,L;

struct mat{
	ll a[maxn][maxn];
	int n;
	mat(int _n){
		n=_n;
		memset(a,0,sizeof(a));
	}
};

mat mul(mat A,mat B){//矩阵乘法
    mat C(A.n);
    for(int i=0;i<A.n;i++)
        for(int j=0;j<B.n;j++)
            for(int k=0;k<A.n;k++)
                C.a[i][j]+=A.a[i][k]*B.a[k][j];
    return C;
}

mat pow(mat A,int n){//A^n
    mat ans(A.n);
    for(int i=0;i<A.n;i++)
        ans.a[i][i]=1;//单位矩阵 
    while(n>0){
        if(n&1)
			ans=mul(ans,A);
        A=mul(A,A);
        n>>=1;
    }
    return ans;
}

struct ACAutomata{
    int next[maxn][K],fail[maxn],end[maxn],id[maxn];
    int newNode(){//新建结点
        for(int i=0;i<K;i++)
			next[L][i]=-1;
        end[L]=0;
        return L++;
    }
    void init(){//初始化
        L=0;
        root=newNode();
    }
    void insert(char s[]){//插入一个结点
        int len=strlen(s);
        int p=root;
        for (int i=0;i<len;i++){
            int ch=s[i]-'a';
            if(next[p][ch]==-1)
				next[p][ch]=newNode();
            p=next[p][ch];
        }
        end[p]++;
    }
    void build(){//构建AC自动机
        queue<int> Q;
        fail[root]=root;
        for (int i=0;i<K;i++){
            if(next[root][i]==-1){
                next[root][i]=root;
            }
			else{
                fail[next[root][i]]=root;
                Q.push(next[root][i]);
            }
        }
        while(Q.size()){
            int now=Q.front();
            Q.pop();
            if(end[fail[now]])
				end[now]++;//重要!!如果当前结点的失败指针end有结束标记，当前结点的end++ 
            for(int i=0;i<K;i++){
                if (next[now][i]!=-1){
                    fail[next[now][i]]=next[fail[now]][i];
                    Q.push(next[now][i]);
                }
				else
					next[now][i]=next[fail[now]][i];
            }
        }
    }

    ll query(int n){
        int ids=0;
        memset(id,-1,sizeof(id));
        for(int i=0;i<L;i++)//对未标记的结点重新编号 
        	if(!end[i])
        		id[i]=ids++;
        mat F(ids+1);		
        for(int u=0;u<L;u++){
        	if(end[u]) continue;
        	for(int j=0;j<K;j++){
                int v=next[u][j];
                if(!end[v])
					F.a[id[u]][id[v]]++;
            }
		}
		for(int i=0;i<ids+1;i++)
			F.a[i][ids]=1;
//		cout<<"ids="<<ids<<endl;
//		for(int i=0;i<F.n;i++)
//		{
//			for(int j=0;j<F.n;j++)
//				cout<<F.a[i][j]<<" ";
//			cout<<endl;
//		}
	    F=pow(F,n);
//	    for(int i=0;i<F.n;i++)
//		{
//			for(int j=0;j<F.n;j++)
//				cout<<F.a[i][j]<<" ";
//			cout<<endl;
//		}
	    ll res=0;
	    for(int i=0;i<L;i++)
	    	res+=F.a[0][i];
	    return --res;
    }
}ac;

ll pow_2(int n){//求26+26^2+...+26^n
	mat C(2);
    C.a[0][0]=26;
    C.a[0][1]=C.a[1][1]=1;
    C=pow(C,n);
    ll ans=C.a[0][0]+C.a[0][1];
    return --ans;
}

int main(){
    int m,n;
    char str[20];
    while(~scanf("%d%d",&m,&n)){
        ac.init();
        while (m--){
            scanf("%s",str);
            ac.insert(str);
        }
        ac.build();
        cout<<pow_2(n)-ac.query(n)<<endl;
    }
    return 0;
}
