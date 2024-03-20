#include<cstdio>
#include<cstring>
const int MAXN=200010;//因为有影子数据量*2，不然会越界！！run time error！！！
using namespace std;
int n,m;
int fa[MAXN],h[MAXN]; //h用来区分树的高度，但其不存储树的具体高度

void Init(){
	for(int i=1;i<=2*n;i++){
		fa[i]=i;
		h[i]=0;
	}	
}

int Find(int x){
	if(x!=fa[x])
		fa[x]=Find(fa[x]);	
    return fa[x];
}

void Union(int x,int y){
    int a=Find(x);
    int b=Find(y);
    if(a==b) return;
    if(h[a]>h[b]) //启发式合并，把矮树合并到高树之下
        fa[b]=a;
    else{
        fa[a]=b;
        if(h[a]==h[b])//若树的高度一样，合并后树根的树高+1
            h[b]++;
    }
}

int main(){
    int T;
    scanf("%d", &T);
    while(T--){
        scanf("%d%d",&n,&m);
    	Init();
        while(m--){
            char ch[2];
            int x,y;
            scanf("%s%d%d",ch,&x,&y);
            if(ch[0]=='D'){
                Union(x,y+n);
                Union(x+n,y);
            }
			else{
                if(Find(y+n)==Find(x)||Find(x+n)==Find(y))
                	printf("In different gangs.\n");
                else if(Find(x)==Find(y)||Find(x+n)==Find(y+n))
                    	printf("In the same gang.\n");
                	else
                    	printf("Not sure yet.\n");
            }
        }
    }
    return 0;
}
