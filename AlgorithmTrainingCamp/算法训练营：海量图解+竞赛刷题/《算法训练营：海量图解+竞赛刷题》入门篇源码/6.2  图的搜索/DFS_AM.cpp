#include<iostream>
using namespace std;
const int MaxVnum=100;     //���������ֵ
bool visited[MaxVnum];  //���ʱ�־���飬���ֵΪ"false"
typedef char VexType;  //������������ͣ�������Ҫ����
typedef int EdgeType;  //����Ȩֵ���������ͣ�������Ȩֵ��ͼ����Ϊ0��1
typedef struct{
	VexType Vex[MaxVnum];
	EdgeType Edge[MaxVnum][MaxVnum];
	int vexnum,edgenum; //������������
}AMGraph;

int locatevex(AMGraph G,VexType x){
    for(int i=0;i<G.vexnum;i++)//���Ҷ�����Ϣ���±�
		if(x==G.Vex[i])
			return i;
    return -1;//û�ҵ�
}

void CreateAMGraph(AMGraph &G){//��������ͼ���ڽӾ���
    int i,j;
    VexType u,v;
    cout<<"�����붥������"<<endl;
    cin>>G.vexnum;
    cout<<"���������:"<<endl;
    cin>>G.edgenum;
    cout<<"�����붥����Ϣ:"<<endl;
    for(int i=0;i<G.vexnum;i++)//���붥����Ϣ�����붥����Ϣ����
        cin>>G.Vex[i];
    for(int i=0;i<G.vexnum;i++)//��ʼ���ڽӾ�������ֵΪ0��������������ʼ���ڽӾ���Ϊ�����
		for(int j=0;j<G.vexnum;j++)
			G.Edge[i][j]=0;
    cout<<"������ÿ�����������������㣺"<<endl;
    while(G.edgenum--){
		cin>>u>>v;
		i=locatevex(G,u);//���Ҷ���u�Ĵ洢�±�
		j=locatevex(G,v);//���Ҷ���v�Ĵ洢�±�
		if(i!=-1&&j!=-1)
			G.Edge[i][j]=G.Edge[j][i]=1; //������ͼG.Edge[i][j]=1
		else{
			cout<<"���붥����Ϣ�����������룡"<<endl;
			G.edgenum++;//�������벻��
		}
    }
}

void print(AMGraph G){//����ڽӾ���
    cout<<"ͼ���ڽӾ���Ϊ��"<<endl;
    for(int i=0;i<G.vexnum;i++){
        for(int j=0;j<G.vexnum;j++)
        	cout<<G.Edge[i][j]<<"\t";
        cout<<endl;
    }
}

void DFS_AM(AMGraph G,int v){//�����ڽӾ����������ȱ���
    int w;
    cout<<G.Vex[v]<<"\t";
    visited[v]=true;
    for(w=0;w<G.vexnum;w++)//���μ��v�������ڽӵ�
		if(G.Edge[v][w]&&!visited[w])//v��w�ڽӶ���wδ������
			DFS_AM(G,w);//��w���㿪ʼ�ݹ�������ȱ���
}

int main(){
    int v;
    VexType c;
    AMGraph G;
    CreateAMGraph(G);//��������ͼ���ڽӾ��� 
    print(G);
    cout<<"�����������ͨͼ����ʼ�㣺";
	cin>>c;
	v=locatevex(G,c);//���Ҷ���u�Ĵ洢�±�
    if(v!=-1){
        cout<<"�����������������ͨͼ�����"<<endl;
        DFS_AM(G,v);
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
