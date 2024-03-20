#include<iostream>
#include<string>
#include<cstring>
#include<algorithm>
using namespace std;
const int maxn=40010;
const int maxm=30;
int n,k,mx; 
int ss[maxn],sa[maxn],rank[maxn],height[maxn];;
int wa[maxn],wb[maxn],wv[maxn],c[maxm];//c[]用于基数排序统计 
 
int cmp(int *r,int a,int b,int l){
    return r[a]==r[b]&&r[a+l]==r[b+l];
}

void da(int *r,int *sa,int n,int m){
    int i,k,p,*x=wa,*y=wb;
    for(i=0;i<m;i++) 
        c[i]=0;
    for(i=0;i<n;i++) 
        c[x[i]=r[i]]++;
    for(i=1;i<m;i++) 
        c[i]+=c[i-1];
    for(i=n-1;i>=0;i--) 
        sa[--c[x[i]]]=i;
    for(k=1;k<=n;k<<=1){
        //直接利用sa排序第二关键字 
		p=0;
		for(i=n-k;i<n;i++) 
            y[p++]=i;//补零的位置下标排在最前面 
        for(i=0;i<n;i++)
            if(sa[i]>=k)
                y[p++]=sa[i]-k;
        //基数排序第一关键字
        for(i=0;i<n;i++)
            wv[i]=x[y[i]];//将第二关键字排序结果转换为名次，进行排序 
        for(i=0;i<m;i++)
            c[i]=0;
        for(i=0;i<n;i++)
            c[wv[i]]++;
        for(i=1;i<m;i++)
            c[i]+=c[i-1];
        for(i=n-1;i>=0;i--)
            sa[--c[wv[i]]]=y[i];
		//根据sa和x数组，重新计算新的x数组
        swap(x,y);//y数组已经没有用，更新x需要使用x本身数据，因此放入y使用 
		p=1,x[sa[0]]=0;
        for(i=1;i<n;i++)
            x[sa[i]]=cmp(y,sa[i-1],sa[i],k)?p-1:p++;
    	if(p>=n)//排序结束 
    		break;
    	m=p;
    }
}

void calheight(int *r,int *sa,int n){
    int i,j,k=0;
    for(i=1;i<=n;i++)
		rank[sa[i]]=i;
    for(i=0;i<n;i++){
    	if(k)
    		k--;
    	j=sa[rank[i]-1];
    	while(r[i+k]==r[j+k])
    		k++;
    	height[rank[i]]=k;
	}
}

int check(int mid){
	int cnt=1,temp=sa[1],ans=-1;
	for(int i=1;i<=n;i++){
		if(height[i]<mid){
			cnt=1;
			temp=sa[i];
		}	
		else{
			cnt++;
			temp=max(temp,sa[i]);
		}
		if(cnt>=k)
			ans=max(ans,temp);	
	}
	return ans;
}

void solve(){
	int L=1,R=n,res=-1,ans=-1;
	while(L<=R){
		int mid=(L+R)>>1;
		mx=check(mid);
		if(mx!=-1){
			res=mid;
			ans=mx;
			L=mid+1;
		}
		else
			R=mid-1;
	}
	if(ans!=-1)
		cout<<res<<" "<<ans<<endl;
	else
		cout<<"none"<<endl;
}

int main(){	
	string s;
	while(cin>>k&&k){
		cin>>s;
		n=s.length();
		if(k==1){//坑点，特别注意
			cout<<n<<" 0"<<endl;
			continue;
		}
		for(int i=0;i<n;i++)
			ss[i]=s[i]-'a'+1;
		ss[n]=0;
		da(ss,sa,n+1,30);
		calheight(ss,sa,n);
		solve();
	}
	return 0;
}
