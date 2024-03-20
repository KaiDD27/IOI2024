#include<iostream>
#include<queue>//�������ͷ�ļ�
using namespace std;
const int MaxVnum=100;//���������ֵ
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
			G.Edge[i][j]=1; //�ڽӾ�����1��������ͼG.Edge[i][j]=G.Edge[j][i]=1
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

void BFS_AM(AMGraph G,int v){//�����ڽӾ���Ĺ�����ȱ���
    int u,w;
    queue<int>Q; //����һ����ͨ����(�Ƚ��ȳ�)��������int����
    cout<<G.Vex[v]<<"\t";
    visited[v]=true;
    Q.push(v); //Դ��v���
    while(!Q.empty()){ //������в���
        u=Q.front();//ȡ����ͷԪ�ظ�ֵ��u
        Q.pop(); //��ͷԪ�س���
        for(w=0;w<G.vexnum;w++){//���μ��u�������ڽӵ�
            if(G.Edge[u][w]&&!visited[w]){//u��w�ڽӶ���wδ������
            	cout<<G.Vex[w]<<"\t";
            	visited[w]=true;
            	Q.push(w);
            }
        }
    }
}

int main(){
    int v;
    VexType c;
    AMGraph G;
    CreateAMGraph(G);
    print(G);
    cout << "���������ͼ����ʼ�㣺";
	cin>>c;
	v=locatevex(G,c);//���Ҷ���u�Ĵ洢�±�
    if(v!=-1){
        cout<<"���������������ͼ�����"<<endl;
        BFS_AM(G,v);
    }
    else
        cout<<"���붥����Ϣ�����������룡"<<endl;
    return 0;
}
/*��������
6 9
1 2 3 4 5 6
1 3
1 2
2 4
3 5
3 2
4 6
4 3
5 6
5 4
1
*/ 
