#include<cstdio>//带修改可持久化trie
using namespace std;
const int maxn=600005;
int n,m,tot;
int trie[maxn*24][2],maxs[maxn*24],s[maxn],rt[maxn];

void insert(int i,int k,int p,int q) {
    maxs[q]=i;//新节点q对应的s[]下标 
	if(k<0) return;
    int c=s[i]>>k&1;//取第k位
    if(p) trie[q][c^1]=trie[p][c^1];//另一子树复制上一版本 
    trie[q][c]=++tot;//创建新节点
    insert(i,k-1,trie[p][c],trie[q][c]);
}

int query(int q,int k,int val,int limit) {
    if(k<0) return s[maxs[q]]^val;
    int c=val>>k&1;
    if(maxs[trie[q][c^1]]>=limit)
        return query(trie[q][c^1],k-1,val,limit);
    else
        return query(trie[q][c],k-1,val,limit);
}

int main(){
    int l,r,x;
    char op[2];
	scanf("%d%d",&n,&m);
    maxs[0]=-1;
    rt[0]=++tot;
    insert(0,23,0,rt[0]);
    for(int i=1;i<=n;i++){
        scanf("%d",&x);
        s[i]=s[i-1]^x;
        rt[i]=++tot;
        insert(i,23,rt[i-1],rt[i]);
    }
    for(int i=1;i<=m;i++){
        scanf("%s",op);
        if(op[0]=='A'){
            scanf("%d",&x);
            rt[++n]=++tot;
            s[n]=s[n-1]^x;
            insert(n,23,rt[n-1],rt[n]);
        }
        else{
            scanf("%d%d%d",&l,&r,&x);
            printf("%d\n",query(rt[r-1],23,x^s[n],l-1));
        }
    }
}
