#include<iostream>
#include<cstring>
#include<string>
#include<algorithm>
#include<queue>
using namespace std;
const int maxn=100;

struct node{
	int freq,va,id;//Ƶ�ʣ�����ֵ����� 
	node(int x=0,int y=0,int z=0){//���캯�� 
		freq=x,va=y,id=z;
	}
	bool operator <(const node &b) const{
		if(freq==b.freq)
			return va>b.va;
		return freq>b.freq;
	}
};
int R,N;//��������ĸ����
int n,c;//��������ĸ��ĸ�������������ĸ��� 
int fre[maxn],father[maxn],code[maxn];
priority_queue<node>Q;//���ȶ��� 

int main(){
	int cas=1;
	while(cin>>R&&R){
		cin>>N;
		memset(fre,0,sizeof(fre));
		int total=0;
		for(int i=0;i<N;i++){
			cin>>fre[i];
			total+=fre[i];
		}
		n=N;
		while((n-R)%(R-1)!=0)//�������� 
			n++;
		while(!Q.empty())//���ȶ������ 
			Q.pop();
		for(int i=0;i<n;i++)//���н����� 
			Q.push(node(fre[i],i,i));
		c=n;//�ºϳɽ����
		int rec=0;//ͳ������Ƶ�ʺ�ֵ
		while(Q.size()!=1){//ʣ��һ�����ֹͣ�ϲ�
			int sum=0,minva=n;
			for(int i=0;i<R;i++){
				sum+=Q.top().freq;//ͳ��Ƶ�ʺ� 
				minva=min(Q.top().va,minva);//����С����ֵ 
				father[Q.top().id]=c;//��¼˫�� 
				code[Q.top().id]=i;//��¼���� 
				Q.pop(); //���� 
			}
			Q.push(node(sum,minva,c));//�½����� 
			c++;
			rec+=sum;
		 } 
		c--;
		printf("Set %d; average length %0.2f\n",cas,1.0*rec/total);
		for(int i=0;i<N;i++){
			int cur=i;
			string s;
			while(cur!=c){
				s.push_back(code[cur]+'0');
				cur=father[cur];	
			}
			reverse(s.begin(),s.end());//��ת���� 
			cout<<"    "<<char('A'+i)<<": "<<s<<endl;
		}
		cout<<endl;
		cas++; 
	 } 
	return 0;
}
