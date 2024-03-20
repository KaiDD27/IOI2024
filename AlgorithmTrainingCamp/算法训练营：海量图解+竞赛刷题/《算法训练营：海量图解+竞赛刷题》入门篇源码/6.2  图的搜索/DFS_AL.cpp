#include<iostream>
using namespace std;
const int MaxVnum=100;  //���������ֵ
bool visited[MaxVnum];  //���ʱ�־���飬���ֵΪ"false"
typedef char VexType;   //�������������Ϊ�ַ���
typedef struct AdjNode{ //�����ڽӵ�����
	int v; //�ڽӵ��±�
	struct AdjNode *next; //ָ����һ���ڽӵ�
}AdjNode;

typedef struct VexNode{ //���嶥������
   VexType data; // VexTypeΪ������������ͣ�������Ҫ����
   AdjNode *first; //ָ���һ���ڽӵ�
}VexNode;

typedef struct{//�����ڽӱ�����
    VexNode  Vex[MaxVnum];
    int vexnum,edgenum; //������������
}ALGraph;

int locatevex(ALGraph G,VexType x){
    for(int i=0;i<G.vexnum;i++)//���Ҷ�����Ϣ���±�
		if(x==G.Vex[i].data)
        	return i;
    return -1;//û�ҵ�
}

void insertedge(ALGraph &G,int i,int j){//����һ����
    AdjNode *s;
    s=new AdjNode;
    s->v=j;
    s->next=G.Vex[i].first;
    G.Vex[i].first=s;
}

void printg(ALGraph G){//����ڽӱ�
	cout<<"----------�ڽӱ����£�----------"<<endl;
	for(int i=0;i<G.vexnum;i++){
		AdjNode *t=G.Vex[i].first;
		cout<<G.Vex[i].data<<"��  ";
		while(t!=NULL){
		   cout<<"["<<t->v<<"]  ";
		   t=t->next;
		}
		cout<<endl;
	}
}

void CreateALGraph(ALGraph &G){//��������ͼ�ڽӱ�
    int i,j;
    VexType u,v;
    cout<<"�����붥�����ͱ���:"<<endl;
    cin>>G.vexnum>>G.edgenum;
    cout<<"�����붥����Ϣ:"<<endl;
    for(i=0;i<G.vexnum;i++)//���붥����Ϣ�����붥����Ϣ����
		cin>>G.Vex[i].data;
    for(i=0;i<G.vexnum;i++)
        G.Vex[i].first=NULL;
    cout<<"����������ÿ���ߵ���������u,v"<<endl;
    while(G.edgenum--){
        cin>>u>>v;
        i=locatevex(G,u);//���Ҷ���u�Ĵ洢�±�
        j=locatevex(G,v);//���Ҷ���v�Ĵ洢�±�
        if(i!=-1&&j!=-1){
            insertedge(G,i,j);
            insertedge(G,j,i);//����ͼ�����һ����
        }
        else{
			cout<<"���붥����Ϣ�����������룡"<<endl;
			G.edgenum++;//�������벻��
        }
    }
}

void DFS_AL(ALGraph G,int v){//�����ڽӱ��������ȱ���
    int w;
    AdjNode *p;
    cout<<G.Vex[v].data<<"\t";
    visited[v]=true;
    p=G.Vex[v].first;
    while(p){//���μ��v�������ڽӵ�
		w=p->v;//wΪv���ڽӵ�
		if(!visited[w])//wδ������
       		DFS_AL(G,w);//��w�������ݹ�������ȱ���
		p=p->next;
    }
}

void DFS_AL(ALGraph G){//����ͨͼ�������ڽӱ��������ȱ���
    for(int i=0;i<G.vexnum;i++)//����ͨͼ��Ҫ��©�㣬���δ�����ʵĶ���
    	if(!visited[i])//iδ������,��iΪ����ٴ�������ȱ���
       		DFS_AL(G,i);
}

int main(){
    ALGraph G;
    int v;
    VexType c;
    CreateALGraph(G);//��������ͼ���ڽӱ�
    printg(G);//����ڽӱ�
    cout<<"�����������ͨͼ����ʼ�㣺";
	cin>>c;
	v=locatevex(G,c);//���Ҷ���u�Ĵ洢�±�
    if(v!=-1){
        cout<<"�����������������ͨͼ�����"<<endl;
        DFS_AL(G,v);
    }
    else
        cout<<"���붥����Ϣ�����������룡"<<endl;
    return 0;
}
/*�������� 
8 9
1 2 3 4 5 6 7 8
1 3
1 2
2 6
2 5
2 4
3 8
3 7
4 5
7 8
1
*/ 
