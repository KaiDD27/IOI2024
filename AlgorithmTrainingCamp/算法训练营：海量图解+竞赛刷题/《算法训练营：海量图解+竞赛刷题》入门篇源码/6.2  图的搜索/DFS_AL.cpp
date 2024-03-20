#include<iostream>
using namespace std;
const int MaxVnum=100;  //顶点数最大值
bool visited[MaxVnum];  //访问标志数组，其初值为"false"
typedef char VexType;   //顶点的数据类型为字符型
typedef struct AdjNode{ //定义邻接点类型
	int v; //邻接点下标
	struct AdjNode *next; //指向下一个邻接点
}AdjNode;

typedef struct VexNode{ //定义顶点类型
   VexType data; // VexType为顶点的数据类型，根据需要定义
   AdjNode *first; //指向第一个邻接点
}VexNode;

typedef struct{//定义邻接表类型
    VexNode  Vex[MaxVnum];
    int vexnum,edgenum; //顶点数，边数
}ALGraph;

int locatevex(ALGraph G,VexType x){
    for(int i=0;i<G.vexnum;i++)//查找顶点信息的下标
		if(x==G.Vex[i].data)
        	return i;
    return -1;//没找到
}

void insertedge(ALGraph &G,int i,int j){//插入一条边
    AdjNode *s;
    s=new AdjNode;
    s->v=j;
    s->next=G.Vex[i].first;
    G.Vex[i].first=s;
}

void printg(ALGraph G){//输出邻接表
	cout<<"----------邻接表如下：----------"<<endl;
	for(int i=0;i<G.vexnum;i++){
		AdjNode *t=G.Vex[i].first;
		cout<<G.Vex[i].data<<"：  ";
		while(t!=NULL){
		   cout<<"["<<t->v<<"]  ";
		   t=t->next;
		}
		cout<<endl;
	}
}

void CreateALGraph(ALGraph &G){//创建无向图邻接表
    int i,j;
    VexType u,v;
    cout<<"请输入顶点数和边数:"<<endl;
    cin>>G.vexnum>>G.edgenum;
    cout<<"请输入顶点信息:"<<endl;
    for(i=0;i<G.vexnum;i++)//输入顶点信息，存入顶点信息数组
		cin>>G.Vex[i].data;
    for(i=0;i<G.vexnum;i++)
        G.Vex[i].first=NULL;
    cout<<"请依次输入每条边的两个顶点u,v"<<endl;
    while(G.edgenum--){
        cin>>u>>v;
        i=locatevex(G,u);//查找顶点u的存储下标
        j=locatevex(G,v);//查找顶点v的存储下标
        if(i!=-1&&j!=-1){
            insertedge(G,i,j);
            insertedge(G,j,i);//无向图多插入一条边
        }
        else{
			cout<<"输入顶点信息错！请重新输入！"<<endl;
			G.edgenum++;//本次输入不算
        }
    }
}

void DFS_AL(ALGraph G,int v){//基于邻接表的深度优先遍历
    int w;
    AdjNode *p;
    cout<<G.Vex[v].data<<"\t";
    visited[v]=true;
    p=G.Vex[v].first;
    while(p){//依次检查v的所有邻接点
		w=p->v;//w为v的邻接点
		if(!visited[w])//w未被访问
       		DFS_AL(G,w);//从w出发，递归深度优先遍历
		p=p->next;
    }
}

void DFS_AL(ALGraph G){//非连通图，基于邻接表的深度优先遍历
    for(int i=0;i<G.vexnum;i++)//非连通图需要查漏点，检查未被访问的顶点
    	if(!visited[i])//i未被访问,以i为起点再次深度优先遍历
       		DFS_AL(G,i);
}

int main(){
    ALGraph G;
    int v;
    VexType c;
    CreateALGraph(G);//创建无向图的邻接表
    printg(G);//输出邻接表
    cout<<"请输入遍历连通图的起始点：";
	cin>>c;
	v=locatevex(G,c);//查找顶点u的存储下标
    if(v!=-1){
        cout<<"深度优先搜索遍历连通图结果："<<endl;
        DFS_AL(G,v);
    }
    else
        cout<<"输入顶点信息错！请重新输入！"<<endl;
    return 0;
}
/*测试数据 
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
