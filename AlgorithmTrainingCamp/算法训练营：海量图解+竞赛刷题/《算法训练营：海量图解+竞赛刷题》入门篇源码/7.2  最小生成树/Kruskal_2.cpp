#include<iostream>
#include<algorithm>
using namespace std;
const int N=100;
int fa[N];
int n,m;

struct Edge{
    int u,v,w;
}e[N*N];

bool cmp(Edge x,Edge y){
    return x.w<y.w;
}

void Init(int n){//��ʼ�����Ϻ�Ϊ���� 
    for(int i=1;i<=n;i++)
        fa[i]=i;
}

int Find(int x){//������ 
    if(x!=fa[x])
		fa[x]=Find(fa[x]);
    return fa[x];
}

bool Merge(int a,int b){
    int p=Find(a);
    int q=Find(b);
    if(p==q) return 0;
    fa[q]=p;
    return 1;
}

int Kruskal(int n){
    int ans=0;
    sort(e,e+m,cmp);
    for(int i=0;i<m;i++)
        if(Merge(e[i].u,e[i].v)){
            ans+=e[i].w;
            n--;
            if(n==1)
                return ans;
        }
    return 0;
}

int main(){
    cin>>n>>m;
    Init(n);
    for(int i=1;i<=m;i++)
        cin>>e[i].u>>e[i].v>>e[i].w;
    cout<<"��С�Ļ��ѣ�"<<Kruskal(n)<<endl;
    return 0;
}
/*�������� 
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
