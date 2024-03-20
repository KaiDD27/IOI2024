#include<cstdio>//4735ms
#include<cmath>
#include<algorithm>
using namespace std;
const int INF=0x3f3f3f3f;
const int N=1005;
int n,k,a[N],b[N],root[N],num[N],l[N],r[N];
int cost[N][N],dp[N][N];
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

void cal(int a[],int pos){
	int cnt=0;//分段数 
	int ans=0;//最小代价 
	cnt_tr=0;//节点编号 
    for(int i=pos;i<=n;i++){
        root[++cnt]=NewTree(a[i]);//创建单节点左偏树 
        num[cnt]=1;//第cnt分段的元素个数
        l[cnt]=r[cnt]=i;
        while(cnt>1&&Top(root[cnt])<Top(root[cnt-1])){
            cnt--;
            for(int j=l[cnt];j<=r[cnt];j++)
            	ans-=abs(Top(root[cnt])-a[j]);
            root[cnt]=Merge(root[cnt],root[cnt+1]);
            num[cnt]+=num[cnt+1];
            r[cnt]=r[cnt+1];
            if(tr[root[cnt]].sz*2>num[cnt]+1) Pop(root[cnt]);
        }
        for(int j=l[cnt];j<=r[cnt];j++)
            ans+=abs(Top(root[cnt])-a[j]);
        cost[pos][i]=min(cost[pos][i],ans);
    }
}

int main(){
    while(~scanf("%d%d",&n,&k),n+k){
        for(int i=1;i<=n;i++)
            scanf("%d",&a[i]),b[i]=-a[i]-i,a[i]-=i;
        for(int i=1;i<=n;i++)
        	for(int j=1;j<=n;j++)
        		cost[i][j]=INF;
        for(int i=1;i<=n;i++)
        	cal(a,i);
        for(int i=1;i<=n;i++)
        	cal(b,i);
		for(int i=1;i<=n;i++){
			dp[i][1]=cost[1][i];
			for(int j=2;j<=min(i,k);j++){
				dp[i][j]=INF;
				for(int p=1;p<i;p++)
					dp[i][j]=min(dp[i][j],dp[p][j-1]+cost[p+1][i]);
			}
		}
		printf("%d\n",dp[n][k]);
    }
    return 0;
}
