#include<cstdio>
#include<algorithm>
#include<cstring>
#include<queue>
using namespace std;

const int maxn=105;
const int K=4;
const int MOD=100000;

struct mat{
	int a[maxn][maxn];
	mat(){
		memset(a,0,sizeof(a));
	}
};
int root,L;

mat mul(mat A,mat B){//矩阵乘法
    mat C;
    for(int i=0;i<L;i++)
        for(int j=0;j<L;j++)
            for(int k=0;k<L;k++)
                C.a[i][j]=(C.a[i][j]+(long long)A.a[i][k]*B.a[k][j])%MOD;
    return C;
}

mat pow(mat A,int n){//A^n
    mat ans;
    for(int i=0;i<L;i++)
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
	int idx(char ch){//转化数字
        switch(ch){
            case 'A':return 0;
            case 'C':return 1;
            case 'T':return 2;
            case 'G':return 3;
        }
        return -1;
    }
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
            int ch=idx(s[i]);
            if(next[p][ch]==-1)
				next[p][ch]=newNode();
            p=next[p][ch];
        }
        end[p]++;
    }
    void build(){//构建AC自动机
        queue<int> Q;
        fail[root]=root;
        for(int i=0;i<K;i++){
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
                if(next[now][i]!=-1){
                    fail[next[now][i]]=next[fail[now]][i];
                    Q.push(next[now][i]);
                }
				else
					next[now][i]=next[fail[now]][i];
            }
        }
    }

    int query(int n){
        mat F;
        int ids=0;
        memset(id,-1,sizeof(id));
        for(int i=0;i<L;i++)//对未标记的结点重新编号 
        	if(!end[i])
        		id[i]=ids++;
        for(int u=0;u<L;u++){
        	if(end[u]) continue;
        	for(int j=0;j<K;j++){
                int v=next[u][j];
                if(!end[v])
					F.a[id[u]][id[v]]++;
            }
		}
		L=ids;
	    F=pow(F,n);
	    int res=0;
	    for(int i=0;i<L;i++)
	    	res=(res+F.a[0][i])%MOD;
	    return res;
    }
}ac;

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
        printf("%d\n",ac.query(n));
    }
    return 0;
}
