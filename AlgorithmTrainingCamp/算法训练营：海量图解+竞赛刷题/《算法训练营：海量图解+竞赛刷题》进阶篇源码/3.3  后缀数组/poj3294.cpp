#include<cstdio>
#include<string.h>
#include<cstring>
#include<algorithm>
using namespace std;
const int maxn=100500;//100个字符串中间添加了100个，每个字符串最大1000 
int n,k;
char s[maxn];
int belong[maxn];//属于哪一个字符串 
int r[maxn],sa[maxn],rank[maxn],height[maxn];;
int wa[maxn],wb[maxn],wv[maxn],c[maxn];//c[]用于基数排序统计,如果写成maxm=500,则提示Runtime Error,中间结果可能溢出 

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

bool check(int mid,int n,int m,int flag){
	int i=2;
	bool vis[105];
	while(1){
		memset(vis,0,sizeof(vis));//清零 
		while(i<=n&&height[i]<mid)
			i++;
		if(i>n)
			break;
		vis[belong[sa[i-1]]]=1;//标记该字符串 
		while(i<=n&&height[i]>=mid){
			vis[belong[sa[i]]]=1;//如果是自己的子串，只标记一次
			i++;
		}
		int cnt=0;
		for(int j=1;j<=m;j++)
			if(vis[j])
				cnt++;
		if(cnt>m/2){
			if(!flag)
				return 1;//立即返回1，否则输出，继续运行输出所有满足条件的子串 
			else{
				for(int j=sa[i-1],t=0;t<mid;j++,t++)
					printf("%c",s[j]);
				printf("\n");
			}
		}
	}
	return 0;
}

void solve(int L,int R){
	int res=-1,mid;
	while(L<=R){
		mid=(L+R)>>1;
		if(check(mid,n,k,0)){
			res=mid;
			L=mid+1;
		}
		else
			R=mid-1;
	}
	if(res==-1)
		printf("?\n");
	else
		check(res,n,k,1);//输出 
}

int main(){
	int len=0;
	while(scanf("%d",&k),k){
		memset(s,0,sizeof(s));
		n=0;
		for(int i=1;i<=k;i++){//将k个字符串连接起来，中间用特殊字符间隔 
			scanf("%s",s+n);
			if(i==1)
				len=strlen(s);
			for(;s[n]!='\0';n++){
				belong[n]=i;//标记属于第i个字符串 
				r[n]=s[n]-'a'+1;//a-z 97-122
			}
			s[n]='#';//35
			r[n]=100+i;
			n++;
		}
		n--;
		r[n]=0;//末尾补一个比所有值都小的数 
		da(r,sa,n+1,300);
		calheight(r,sa,n);
		solve(1,len);
		printf("\n");
	}
	return 0;
}
