#include<iostream>
#include<cstring>
#include<stack>
using namespace std;
const int maxn=10010,maxe=50010;
int n,m,cnt;
int head[maxn]; //��ʽǰ����ͷ 
int in[maxn],topo[maxn]; //���,�������� 
int ve[maxn]; //�¼�vi�����緢��ʱ��
int vl[maxn]; //�¼�vi����ٷ���ʱ��
stack<int>s;
struct node{
	int to,next,w;
}e[maxe];

void add(int u,int v,int w){
	e[cnt].to=v;
	e[cnt].next=head[u];
	head[u]=cnt;
	e[cnt++].w=w;
}

bool TopoSort(){//��������
	int cnt=0;
    for(int i=0;i<n;i++)
        if(in[i]==0)
        	s.push(i);
    while(!s.empty()){
		int u=s.top();
    	s.pop();
    	topo[cnt++]=u;
    	for(int i=head[u];~i;i=e[i].next){
    		int v=e[i].to;
            if(--in[v]==0)
        		s.push(v);
		}      
	}
	if(cnt<n) return 0;//������ͼ�л�·
	return 1;
}

bool CriticalPath(){//�ؼ�·�� 
    if(TopoSort()){
        cout<<"��������Ϊ��"<<endl;
        for(int i=0;i<n;i++)//�����������
            cout<<topo[i]<<"\t";
        cout<<endl;
    }
    else{
    	cout<<"��ͼ�л������������У�"<<endl;
    	return 0;
	} 
    for(int i=0;i<n;i++)//��ʼ�����緢��ʱ��Ϊ0
		ve[i]=0;
    //�����˴�����ÿ���¼������緢��ʱ��
    for(int j=0;j<n;j++){
		int u=topo[j];  //ȡ�����������еĶ���
		for(int i=head[u];~i;i=e[i].next){
    		int v=e[i].to,w=e[i].w;
            if(ve[v]<ve[u]+w)
        		ve[v]=ve[u]+w;
		} 
    }
    for(int i=0;i<n;i++) //��ʼ��ÿ���¼�����ٷ���ʱ��Ϊve[n]
		vl[i]=ve[n-1];
    for(int j=n-1;j>=0;j--){//������������ÿ���¼�����ٷ���ʱ��
		int u=topo[j];  //ȡ�����������еĶ���
		for(int i=head[u];~i;i=e[i].next){
    		int v=e[i].to,w=e[i].w;
            if(vl[u]>vl[v]-w)
        		vl[u]=vl[v]-w;
		}
    }
    cout<<"�¼������緢��ʱ�����ٷ���ʱ�䣺"<<endl;
	for(int i=0;i<n;i++)
       cout<<ve[i]<<"\t"<<vl[i]<<endl;
	cout<<"�ؼ��·��Ϊ:"<<endl;
    for(int u=0;u<n;u++){ //ÿ��ѭ�����viΪ���ʼ������л
		for(int i=head[u];~i;i=e[i].next){
    		int v=e[i].to,w=e[i].w;
            int e=ve[u];    //����<vi, vj>�����翪ʼʱ��e
			int l=vl[v]-w; //����<vi, vj>����ٿ�ʼʱ��l
			if(e==l)   //��Ϊ�ؼ���������<vi, vj>
				cout<<"<"<<u<<","<<v<<">"<<endl;
		}
	}
	return 1;
}

int main(){
    int u,v,w;
	cin>>n>>m;
	memset(head,-1,sizeof(head));
    memset(in,0,sizeof(in));
    for(int i=0;i<m;i++){
        cin>>u>>v>>w;
        add(u,v,w);
        in[v]++;
    }
    CriticalPath();
    return 0;
}
/*�������� 
6 8
0 1 2
0 2 15
1 3 10
1 4 19
2 1 4
2 4 11
3 5 6
4 5 5
*/

