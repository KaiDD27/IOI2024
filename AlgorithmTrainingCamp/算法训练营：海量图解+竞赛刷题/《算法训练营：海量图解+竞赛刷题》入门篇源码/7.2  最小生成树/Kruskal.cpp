#include<iostream>
#include<algorithm>
using namespace std;
const int N=100;
int fa[N];
int n,m;
struct Edge{
    int u,v,w;
}e[N*N];

bool cmp(Edge x, Edge y){
    return x.w<y.w;
}

void Init(int n){//初始化集合号为自身 
    for(int i=1;i<=n;i++)
        fa[i]=i;
}

int Merge(int a,int b){//合并 
    int p=fa[a];
    int q=fa[b];
    if(p==q) return 0;
    for(int i=1;i<=n;i++){//检查所有结点，把集合号是q的改为p
		if(fa[i]==q)
			fa[i]=p;//a的集合号赋值给b集合号
    }
    return 1;
}

int Kruskal(int n){//求最小生成树 
    int ans=0;
    sort(e,e+m,cmp);
    for(int i=0;i<m;i++)
        if(Merge(e[i].u,e[i].v)){
            ans+=e[i].w;
            n--;
            if(n==1)//n-1次合并算法结束 
            	return ans;
        }
    return 0;
}

int main(){
    cin>>n>>m;
    Init(n);
    for(int i=1;i<=m;i++)
        cin>>e[i].u>>e[i].v>>e[i].w;
    cout<<"最小的花费是："<<Kruskal(n)<<endl;
    return 0;
}
/*测试数据 
7 12
1 2 23
1 6 28
1 7 36
2 3 20
2 7 1
3 4 15
3 7 4
4 5 3
4 7 9
5 6 17
5 7 16
6 7 25
*/
