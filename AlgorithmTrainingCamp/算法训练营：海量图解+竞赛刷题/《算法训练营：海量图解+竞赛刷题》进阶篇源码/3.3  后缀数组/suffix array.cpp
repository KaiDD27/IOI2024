#include<iostream>
#include<string>
#include<cstring>
using namespace std;
const int maxn=100;
const int maxm=10000;
int n; 
int ss[maxn],sa[maxn];
int wa[maxn],wb[maxn],wv[maxn],c[maxm];//c[]���ڻ�������ͳ�� 
 
int cmp(int *r,int a,int b,int l){
    return r[a]==r[b]&&r[a+l]==r[b+l];
}

void print(int *s,int t){
	for(int i=0;i<t;i++)
        cout<<s[i]<<"\t";
    cout<<endl;
}

void print_suffix(string s,int *sa){
	for(int i=1;i<=n;i++)
		cout<<s.substr(sa[i])<<endl;
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
    cout<<"��ʼ����������"<<endl;
    cout<<"rank:\t";
    print(x,n);
    cout<<"sa:\t";
    print(sa,n);
    for(k=1;k<=n;k<<=1){
        //ֱ������sa����ڶ��ؼ��� 
		p=0;
		for(i=n-k;i<n;i++) 
            y[p++]=i;//�����λ���±�������ǰ�� 
        for(i=0;i<n;i++)
            if(sa[i]>=k)
                y[p++]=sa[i]-k;
        cout<<"�ڶ��ؼ�����������"<<endl;
        cout<<"y:\t";
		print(y,n); 
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
		cout<<"x[y[i]]:";
		print(wv,n); 
		cout<<"sa:\t";
    	print(sa,n);
		//����sa��x���飬���¼����µ�x����
        swap(x,y);//y�����Ѿ�û���ã�����x��Ҫʹ��x�������ݣ���˷���yʹ�� 
		p=1,x[sa[0]]=0;
        for(i=1;i<n;i++)
            x[sa[i]]=cmp(y,sa[i-1],sa[i],k)?p-1:p++;
        cout<<"��"<<k<<"����������"<<endl;
        cout<<"rank:\t";
		print(x,n);
		cout<<"sa:\t";
    	print(sa,n);
    	if(p>=n)//������� 
    		break;
    	m=p;
    }
}

int rank[maxn], height[maxn];
void calheight(int *r,int *sa,int n){
    int i,j,k=0;
    for(i=1;i<=n;i++)
		rank[sa[i]]=i;
	cout<<"�������飺"<<endl; 
	print(rank,n);
    for(i=0;i<n;i++){
    	if(k)
    		k--;
    	j=sa[rank[i]-1];
    	while(r[i+k]==r[j+k])
    		k++;
    	height[rank[i]]=k;
	}
	cout<<"�߶����飺"<<endl; 
	print(height+1,n);
}

int main(){	
	string s;
	cin>>s;//aabaaaab
	n=s.size();
	for(int i=0;i<n;i++)
		ss[i]=s[i]-'a'+1;
	ss[n]=0;
	da(ss,sa,n+1,maxm);
	print_suffix(s,sa);
	calheight(ss,sa,n);
	return 0;
}
