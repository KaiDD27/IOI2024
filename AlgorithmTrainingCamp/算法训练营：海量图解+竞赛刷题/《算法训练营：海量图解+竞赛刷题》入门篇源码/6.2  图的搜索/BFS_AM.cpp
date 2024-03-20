#include<iostream>
#include<queue>//引入队列头文件
using namespace std;
const int MaxVnum=100;//顶点数最大值
bool visited[MaxVnum];  //访问标志数组，其初值为"false"
typedef char VexType;  //顶点的数据类型，根据需要定义
typedef int EdgeType;  //边上权值的数据类型，若不带权值的图，则为0或1
typedef struct{
	VexType Vex[MaxVnum];
	EdgeType Edge[MaxVnum][MaxVnum];
	int vexnum,edgenum; //顶点数，边数
}AMGraph;

int locatevex(AMGraph G,VexType x){
    for(int i=0;i<G.vexnum;i++)//查找顶点信息的下标
		if(x==G.Vex[i])
       		return i;
    return -1;//没找到
}

void CreateAMGraph(AMGraph &G){//创建有向图的邻接矩阵
    int i,j;
    VexType u,v;
    cout<<"请输入顶点数："<<endl;
    cin>>G.vexnum;
    cout<<"请输入边数:"<<endl;
    cin>>G.edgenum;
    cout<<"请输入顶点信息:"<<endl;
    for(int i=0;i<G.vexnum;i++)//输入顶点信息，存入顶点信息数组
		cin>>G.Vex[i];
    for(int i=0;i<G.vexnum;i++)//初始化邻接矩阵所有值为0，如果是网，则初始化邻接矩阵为无穷大
		for(int j=0;j<G.vexnum;j++)
			G.Edge[i][j]=0;
    cout<<"请输入每条边依附的两个顶点："<<endl;
    while(G.edgenum--){
       cin>>u>>v;
       i=locatevex(G,u);//查找顶点u的存储下标
       j=locatevex(G,v);//查找顶点v的存储下标
		if(i!=-1&&j!=-1)
			G.Edge[i][j]=1; //邻接矩阵储置1，若无向图G.Edge[i][j]=G.Edge[j][i]=1
		else{
			cout<<"输入顶点信息错！请重新输入！"<<endl;
			G.edgenum++;//本次输入不算
		}
    }
}

void print(AMGraph G){//输出邻接矩阵
    cout<<"图的邻接矩阵为："<<endl;
    for(int i=0;i<G.vexnum;i++){
        for(int j=0;j<G.vexnum;j++)
			cout<<G.Edge[i][j]<<"\t";
        cout<<endl;
    }
}

void BFS_AM(AMGraph G,int v){//基于邻接矩阵的广度优先遍历
    int u,w;
    queue<int>Q; //创建一个普通队列(先进先出)，里面存放int类型
    cout<<G.Vex[v]<<"\t";
    visited[v]=true;
    Q.push(v); //源点v入队
    while(!Q.empty()){ //如果队列不空
        u=Q.front();//取出队头元素赋值给u
        Q.pop(); //队头元素出队
        for(w=0;w<G.vexnum;w++){//依次检查u的所有邻接点
            if(G.Edge[u][w]&&!visited[w]){//u、w邻接而且w未被访问
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
    cout << "请输入遍历图的起始点：";
	cin>>c;
	v=locatevex(G,c);//查找顶点u的存储下标
    if(v!=-1){
        cout<<"广度优先搜索遍历图结果："<<endl;
        BFS_AM(G,v);
    }
    else
        cout<<"输入顶点信息错！请重新输入！"<<endl;
    return 0;
}
/*测试数据
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
