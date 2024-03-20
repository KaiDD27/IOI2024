#include<iostream>
#include<algorithm>
#include<cstring>
#include<cmath>
#include<queue>
using namespace std;
const int N=10;
bool bestx[N];
//定义结点。每个节点来记录当前的解。
struct Node{
    int cp,rp; //cp为当前装入背包的物品总价值，rp为剩余物品的总价值
    int rw; //剩余容量
    int id; //物品号
    bool x[N];//解向量
    Node(){}
    Node(int _cp,int _rp,int _rw,int _id){
        cp=_cp;
        rp=_rp;
        rw=_rw;
        id=_id;
        memset(x,0,sizeof(x));//解向量初始化为0
    }
};

struct Goods{//物品
    int weight;//重量 
    int value;//价值 
}goods[N];

int bestp,W,n,sumw,sumv;
/*
  bestp用来记录最优解
  W为背包最大容量。
  n为物品的个数。
  sumw为所有物品的总重量。
  sumv为所有物品的总价值。
*/

int bfs(){//队列式分支限界法 
    int t,tcp,trp,trw;//当前处理的物品序号t，装入背包物品价值tcp,剩余容量trw
    queue<Node> q; //创建一个普通队列(先进先出)
    q.push(Node(0,sumv,W,1)); //压入一个初始节点
    while(!q.empty()){
        Node livenode,lchild,rchild;//定义三个结点型变量
        livenode=q.front();//取出队头元素作为当前扩展结点livenode
        q.pop(); //队头元素出队
        t=livenode.id;//当前处理的物品序号
        // 搜到最后一个物品的时候不需要往下搜索
        // 如果当前的背包没有剩余容量(已经装满)了，不再扩展
        if(t>n||livenode.rw==0){
            if(livenode.cp>=bestp){//更新最优解和最优值
				for(int i=1;i<=n;i++)
					bestx[i]=livenode.x[i];
              bestp=livenode.cp;
            }
            continue;
        }
        if(livenode.cp+livenode.rp<bestp)//判断当前结点是否满足限界条件，如果不满足不再扩展
			continue;
        tcp=livenode.cp; //当前背包中的价值
        trp=livenode.rp-goods[t].value; //不管当前物品装入与否，剩余价值都会减少。
        trw=livenode.rw; //背包剩余容量
        if(trw>=goods[t].weight){ //扩展左孩子，满足约束条件，可以放入背包
            lchild.rw=trw-goods[t].weight;
            lchild.cp=tcp+goods[t].value;
            lchild=Node(lchild.cp,trp,lchild.rw,t+1);
            for(int i=1;i<t;i++)//复制以前的解向量
            	lchild.x[i]=livenode.x[i];
            lchild.x[t]=true;
            if(lchild.cp>bestp)//比最优值大才更新
               bestp=lchild.cp;
            q.push(lchild);//左孩子入队
        }
        if(tcp+trp>=bestp){//扩展右孩子,满足限界条件，不放入背包
            rchild=Node(tcp,trp,trw,t+1);
            for(int i=1;i<t;i++)//复制以前的解向量
				rchild.x[i]=livenode.x[i];
            rchild.x[t]=false;
            q.push(rchild);//右孩子入队
        }
    }
    return bestp;//返回最优值
}

int main(){
    cin>>n>>W;//输入物品的个数和背包的容量
    bestp=0; //bestv用来记录最优解
    sumw=0; //sumw为所有物品的总重量。
    sumv=0;  //sumv为所有物品的总价值
    for(int i=1;i<=n;i++){//输入每个物品的重量和价值,用空格分开
        cin>>goods[i].weight>>goods[i].value;//输入第i件物品的重量和价值。
        sumw+=goods[i].weight;
        sumv+=goods[i].value;
    }
    if(sumw<=W){
        bestp=sumv;
        cout<<"放入背包的物品最大价值为: "<<bestp<<endl;
        return 0;
    }
    bfs();
    cout<<"放入背包的物品最大价值为: "<<bestp<<endl;
    cout<<"放入背包的物品序号为: ";
    for(int i=1;i<=n;i++){// 输出最优解
        if(bestx[i])
           cout<<i<<"  ";
    }
    return 0;
}

/*测试数据 
4 10
2 6 5 3 4 5 2 4
*/
