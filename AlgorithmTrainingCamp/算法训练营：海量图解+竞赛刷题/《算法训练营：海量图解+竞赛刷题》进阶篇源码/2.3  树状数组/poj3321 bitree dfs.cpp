#include<stdio.h>
#include<iostream>
#include<algorithm>
#include<cstring>
#include<cmath>
using namespace std;
const int maxn=1e5+10;
int N,q;
int c[maxn];
int a[maxn];
int L[maxn],R[maxn];
int head[maxn];
int cnt;
int dfn;
struct edge{
    int u,v;
    int next;
}E[2*maxn];

void adde(int u,int v){
    E[++cnt].u=u;
    E[cnt].v=v;
    E[cnt].next=head[u];
    head[u]=cnt;
}

int lowbit(int x){
    return x&(-x);
}

void add(int i,int v){
    for(;i<=N;i+=lowbit(i))
        c[i]+=v;
}

int sum(int i){
    int ans=0;
    for(;i>0;i-=lowbit(i)){
        ans+=c[i];
    }
    return ans;
}

void init(){
    memset(c,0,sizeof(c));
    memset(L,0,sizeof(L));
    memset(R,0,sizeof(R));
    memset(head,0,sizeof(head));
    cnt=0;
    dfn=1;
    for(int i=1;i<=N;i++){
        a[i]=1;
        add(i,1);
    }
}

void dfs(int u,int fa){
    L[u]=dfn++;
    for(int i=head[u];i;i=E[i].next){
        int v=E[i].v;
        if(v==fa) continue;
        dfs(v,u);
    }
    R[u]=dfn-1;
}

int main(){
    scanf("%d",&N);
    int u,v;
    init();
    for(int i=1;i<N;i++){
        scanf("%d%d",&u,&v);
        adde(u,v);
    }
    dfs(1,1);
//  printf("²âÊÔdfsÐòÁÐ\n"); 
//	for(int i=1;i<=N;i++)//²âÊÔ 
//    	printf("%d %d\n",L[i],R[i]);
//  printf("\n");	
    scanf("%d",&q);
    char op[10];
    for(int i=1;i<=q;i++){
        scanf("%s %d",op,&v);
        if(op[0]=='C'){
            if(a[L[v]])
                add(L[v],-1);
            else
                add(L[v],1);
            a[L[v]]^=1;
        }
        else{
            int s1=sum(R[v]);
            int s2=sum(L[v]-1);
            printf("%d\n",s1-s2);
        }
    }
    return 0;
}

