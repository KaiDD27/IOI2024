#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<queue>
#include<algorithm>
using namespace std;
const int inf=0x3f3f3f3f;
const int N=1010;
const int M=1000100;
int cnt;
int head[N],pre[N],h[N],g[N];
struct Edge{
   int v,next;
   int cap,flow;
}E[M<<1];//双边

void init(){//初始化 
    memset(head,-1,sizeof(head));
    cnt=0;
}

void add(int u,int v,int c){
    E[cnt].v=v;
    E[cnt].cap=c;
    E[cnt].flow=0;
    E[cnt].next=head[u];
    head[u]=cnt++;
}

void adde(int u,int v,int c){
    add(u,v,c);
    add(v,u,0);
}

void set_h(int t,int n){//标高 
    queue<int> q;
    memset(h,-1,sizeof(h));
    memset(g,0,sizeof(g));
    h[t]=0;
    q.push(t);
    while(!q.empty()){
		int u=q.front();q.pop();
		++g[h[u]];//高度为h[u]的节点个数
		for(int i=head[u];~i;i=E[i].next){
			int v=E[i].v;
			if(h[v]==-1){
				h[v]=h[u]+1;
				q.push(v);
			}
        }
    }
}

int ISAP(int s,int t,int n){
    set_h(t,n);
    int ans=0,u=s,d;
    while(h[s]<n){
        int i=head[u];
        if(u==s)
           d=inf;
        for(;~i;i=E[i].next){
			int v=E[i].v;
			if(E[i].cap>E[i].flow&&h[u]==h[v]+1){
				u=v;
                pre[v]=i;
                d=min(d,E[i].cap-E[i].flow);
                if(u==t){
					while(u!=s){
						int j=pre[u];
						E[j].flow+=d;
						E[j^1].flow-=d;
						u=E[j^1].v;
					}
					ans+=d;
					d=inf;
                }
                break;
            }
        }
        if(i==-1){
			if(--g[h[u]]==0)
				break;
			int hmin=n-1;
			for(int j=head[u];~j;j=E[j].next)
				if(E[j].cap>E[j].flow)
					hmin=min(hmin,h[E[j].v]);
			h[u]=hmin+1;
			++g[h[u]];
			if(u!=s)
				u=E[pre[u]^1].v;
        }
    }
    return ans;
}

int main(){
    int T,cas=0;
    string s;
	scanf("%d",&T);
    while(T--){
        int n,m,d,src,dst;
        int sum=0;//蜥蜴数
        scanf("%d%d",&n,&d);
        for(int i=0;i<n;i++){
            cin>>s;
            if(i==0){//第一次读入 
                m=s.size();
                src=0,dst=2*n*m+1;
                init();
            }
            for(int j=0;j<s.size();j++)
				if(s[j]-'0'>0){ //大于0的拆点 
	                int id=i*m+j+1; //当前点编号
	                adde(id,id+n*m,s[j]-'0');
	                if(i<d||i+d>=n||j<d||j+d>=m)//当前格子能直接跳出棋盘
	                    adde(id+n*m,dst,inf);
	                else{ //不能直接跳出去
	                    for(int k=0;k<n;k++)
		                    for(int h=0;h<m;h++){
		                        int id2=k*m+h+1;
		                        if(id==id2) continue;
		                        if(abs(i-k)+abs(j-h)<=d)
									adde(id+n*m,id2,inf);
		                    }
	                }
            	}
        }
        for(int i=0;i<n;i++){
            cin>>s;
            for(int j=0;j<s.size();j++){
                int id=i*m+j+1;//当前点编号
                if(s[j]=='L'){
                    ++sum;
                    adde(src,id,1);
                }
            }
        }
        int ans=sum-ISAP(src,dst,dst+1);
        if(ans==0) printf("Case #%d: no lizard was left behind.\n",++cas);
        else if(ans==1) printf("Case #%d: 1 lizard was left behind.\n",++cas);
        else printf("Case #%d: %d lizards were left behind.\n",++cas,ans);
    }
    return 0;
}
