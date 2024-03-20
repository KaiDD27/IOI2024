#include<cstdio>
#include<string.h>
#include<cstring>
#include<algorithm>
using namespace std;
const int maxn=100500;//100���ַ����м������100����ÿ���ַ������1000 
int n,k;
char s[maxn];
int belong[maxn];//������һ���ַ��� 
int r[maxn],sa[maxn],rank[maxn],height[maxn];;
int wa[maxn],wb[maxn],wv[maxn],c[maxn];//c[]���ڻ�������ͳ��,���д��maxm=500,����ʾRuntime Error,�м���������� 

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
        //ֱ������sa����ڶ��ؼ��� 
		p=0;
		for(i=n-k;i<n;i++) 
            y[p++]=i;//�����λ���±�������ǰ�� 
        for(i=0;i<n;i++)
            if(sa[i]>=k)
                y[p++]=sa[i]-k;
        //���������һ�ؼ���
        for(i=0;i<n;i++)
            wv[i]=x[y[i]];//���ڶ��ؼ���������ת��Ϊ���Σ��������� 
        for(i=0;i<m;i++)
            c[i]=0;
        for(i=0;i<n;i++)
            c[wv[i]]++;
        for(i=1;i<m;i++)
            c[i]+=c[i-1];
        for(i=n-1;i>=0;i--)
            sa[--c[wv[i]]]=y[i];
		//����sa��x���飬���¼����µ�x����
        swap(x,y);//y�����Ѿ�û���ã�����x��Ҫʹ��x�������ݣ���˷���yʹ�� 
		p=1,x[sa[0]]=0;
        for(i=1;i<n;i++)
            x[sa[i]]=cmp(y,sa[i-1],sa[i],k)?p-1:p++;
    	if(p>=n)//������� 
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
		memset(vis,0,sizeof(vis));//���� 
		while(i<=n&&height[i]<mid)
			i++;
		if(i>n)
			break;
		vis[belong[sa[i-1]]]=1;//��Ǹ��ַ��� 
		while(i<=n&&height[i]>=mid){
			vis[belong[sa[i]]]=1;//������Լ����Ӵ���ֻ���һ��
			i++;
		}
		int cnt=0;
		for(int j=1;j<=m;j++)
			if(vis[j])
				cnt++;
		if(cnt>m/2){
			if(!flag)
				return 1;//��������1�������������������������������������Ӵ� 
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
		check(res,n,k,1);//��� 
}

int main(){
	int len=0;
	while(scanf("%d",&k),k){
		memset(s,0,sizeof(s));
		n=0;
		for(int i=1;i<=k;i++){//��k���ַ��������������м��������ַ���� 
			scanf("%s",s+n);
			if(i==1)
				len=strlen(s);
			for(;s[n]!='\0';n++){
				belong[n]=i;//������ڵ�i���ַ��� 
				r[n]=s[n]-'a'+1;//a-z 97-122
			}
			s[n]='#';//35
			r[n]=100+i;
			n++;
		}
		n--;
		r[n]=0;//ĩβ��һ��������ֵ��С���� 
		da(r,sa,n+1,300);
		calheight(r,sa,n);
		solve(1,len);
		printf("\n");
	}
	return 0;
}
