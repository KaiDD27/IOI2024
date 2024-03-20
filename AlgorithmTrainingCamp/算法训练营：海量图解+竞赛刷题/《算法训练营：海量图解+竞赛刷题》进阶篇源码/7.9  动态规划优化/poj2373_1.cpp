#include<cstdio>//�߶����Ż�DP 750ms��ʤ 
#include<algorithm>
#include<cstring>
#define lc k<<1
#define rc k<<1|1
using namespace std;
const int maxL=1000005,inf=0x3f3f3f3f;
bool flag[maxL];
int n,L,a,b,s,e;

struct tree{
    int l,r,val;
}tree[maxL*4];

void build(int k,int l,int r){//�����߶��� 
    tree[k].l=l;
    tree[k].r=r;
    tree[k].val=inf;//��ʼΪ����� 
    if(l==r)return;
    int mid=(l+r)>>1;
    build(lc,l,mid);
    build(rc,mid+1,r);
}
void update(int k,int pos,int val){
    int ll=tree[k].l,rr=tree[k].r;
    if(ll==pos&&rr==pos){
        tree[k].val=min(tree[k].val,val);
        return;
    }
    int mid=(ll+rr)>>1;
    if(pos<=mid)
        update(lc,pos,val);
    else
        update(rc,pos,val);
    tree[k].val=min(tree[lc].val,tree[rc].val);
}

int getmin(int k,int l,int r){
    int ll=tree[k].l,rr=tree[k].r;
    if(ll>=l&&rr<=r)
        return tree[k].val;
    int mid=(ll+rr)>>1;
    if(r<=mid)
        return getmin(lc,l,r);
    else if(l>mid)
        return getmin(rc,l,r);
    else
        return min(getmin(lc,l,mid),getmin(rc,mid+1,r));
}

int solve(){
	build(1,0,L/2);//�����߶�����ż��λ�� 
    update(1,0,0);//��0��λ��Ϊ0
    for(int i=a*2;i<=L;i+=2){
        if(flag[i]){
            int l=i/2-b,r=i/2-a;//(i-2*b)/2,(i-2*a)/2
            l=max(0,l);
            int tmp=getmin(1,l,r);
            if(tmp<inf)
            	update(1,i/2,tmp+1);//��Ӧi/2��λ�� 
        }
    }
    return getmin(1,L/2,L/2);
}

int main(){
    while(~scanf("%d%d",&n,&L)){
        scanf("%d%d",&a,&b);
        memset(flag,true,sizeof(flag));
        for(int i=0;i<n;i++){
            scanf("%d%d",&s,&e);
            for(int j=s+1;j<e;j++)//Ԥ����[s,e]���䲻�����ָ� 
				flag[j]=0;
        }
        int ans=solve();
        printf("%d\n",ans<inf?ans:-1);
    }
    return 0;
}
