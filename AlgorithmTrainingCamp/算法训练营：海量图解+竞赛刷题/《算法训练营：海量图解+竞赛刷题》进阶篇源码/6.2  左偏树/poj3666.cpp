#include<cstdio>
#include<algorithm>
using namespace std;
const int N=2005;
int n,a[N],b[N],root[N],num[N];
struct LeftTree{
    int l,r,sz;
    int key,dis;
}tr[N];
int cnt_tr;

int NewTree(int k){
    tr[++cnt_tr].key=k;
    tr[cnt_tr].l=tr[cnt_tr].r=tr[cnt_tr].dis=0;
    tr[cnt_tr].sz=1;
    return cnt_tr;
}

int Merge(int x,int y){
    if(!x||!y) return x+y;
    if(tr[x].key<tr[y].key) swap(x,y);
    tr[x].r=Merge(tr[x].r,y);
    if(tr[tr[x].l].dis<tr[tr[x].r].dis) swap(tr[x].l,tr[x].r);
    tr[x].dis=tr[tr[x].r].dis+1;
    tr[x].sz=tr[tr[x].l].sz+tr[tr[x].r].sz+1;
    return x;
}

int Top(int x){return tr[x].key;}
void Pop(int &x){x=Merge(tr[x].l,tr[x].r);}

int solve(int a[]){
	int cnt=0;//分段数 
	int ans=0;//最小代价 
	cnt_tr=0;//节点编号 
    for(int i=0;i<n;i++){
        root[++cnt]=NewTree(a[i]);//创建单节点左偏树 
        num[cnt]=1;//第cnt分段的元素个数 
        while(cnt>1&&Top(root[cnt])<Top(root[cnt-1])){
            cnt--;
            root[cnt]=Merge(root[cnt],root[cnt+1]);
            num[cnt]+=num[cnt+1];
            if(tr[root[cnt]].sz*2>num[cnt]+1) Pop(root[cnt]);
        }
    }
    int k=0;
    for(int i=1;i<=cnt;i++)
        for(int j=0,x=Top(root[i]);j<num[i];j++)
            ans+=abs(a[k++]-x);
    return ans;
}

int main(){
    while(~scanf("%d",&n)){
        for(int i=0;i<n;i++)
            scanf("%d",&a[i]),b[n-i-1]=a[i];
        printf("%d\n",min(solve(a),solve(b)));//非递减或非递增取最小代价 
    }
    return 0;
}
