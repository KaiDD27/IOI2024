#include<iostream>
#include<cstring>
#include<string>
#include<algorithm>
#include<queue>
using namespace std;
const int maxn=100;

struct node{
	int freq,va,id;//频率，优先值，序号 
	node(int x=0,int y=0,int z=0){//构造函数 
		freq=x,va=y,id=z;
	}
	bool operator <(const node &b) const{
		if(freq==b.freq)
			return va>b.va;
		return freq>b.freq;
	}
};
int R,N;//基数，字母个数
int n,c;//补虚拟字母后的个数，新生成字母编号 
int fre[maxn],father[maxn],code[maxn];
priority_queue<node>Q;//优先队列 

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
		while((n-R)%(R-1)!=0)//补虚拟结点 
			n++;
		while(!Q.empty())//优先队列清空 
			Q.pop();
		for(int i=0;i<n;i++)//所有结点入队 
			Q.push(node(fre[i],i,i));
		c=n;//新合成结点编号
		int rec=0;//统计所有频率和值
		while(Q.size()!=1){//剩余一个结点停止合并
			int sum=0,minva=n;
			for(int i=0;i<R;i++){
				sum+=Q.top().freq;//统计频率和 
				minva=min(Q.top().va,minva);//求最小优先值 
				father[Q.top().id]=c;//记录双亲 
				code[Q.top().id]=i;//记录编码 
				Q.pop(); //出队 
			}
			Q.push(node(sum,minva,c));//新结点入队 
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
			reverse(s.begin(),s.end());//翻转编码 
			cout<<"    "<<char('A'+i)<<": "<<s<<endl;
		}
		cout<<endl;
		cas++; 
	 } 
	return 0;
}
