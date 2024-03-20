#include<iostream>
#include<algorithm>
#include<cstring>
#include<cmath>
#include<queue>
using namespace std;
const int N=10;
bool bestx[N]; //记录最优解
int w[N],v[N];//辅助数组,用于存储排序后的重量和价值

struct Node{//定义结点,记录当前结点的解信息
    int cp; //已装入背包的物品价值
    double up; //价值上界
    int rw; //背包剩余容量
    int id; //物品号
    bool x[N];
    Node() {}
    Node(int _cp,double _up,int _rw,int _id){
        cp=_cp;
        up=_up;
        rw=_rw;
        id=_id;
        memset(x, 0, sizeof(x));
    }
};

struct Goods{ //物品结构体
    int weight;//重量
    int value;//价值
}goods[N];

struct Object{//辅助物品结构体，用于按单位重量价值(价值/重量比)排序
    int id; //序号
    double d;//单位重量价值
}S[N];


bool cmp(Object a1,Object a2){//排序优先级，按照物品单位重量价值由大到小排序
    return a1.d>a2.d;
}

bool operator <(const Node &a, const Node &b){//队列优先级。up越大越优先
    return a.up<b.up;
}

int bestp,W,n,sumw,sumv;
/*
  bestv 用来记录最优解。
  W为背包的最大容量。
  n为物品的个数。
  sumw为所有物品的总重量。
  sumv为所有物品的总价值。
*/

double Bound(Node tnode){//计算节点的上界 
    double maxvalue=tnode.cp;//已装入背包物品价值
    int t=tnode.id;//排序后序号
    double left=tnode.rw;//剩余容量
    while(t<=n&&w[t]<=left){
        maxvalue+=v[t];
        left-=w[t++];
    }
    if(t<=n)
        maxvalue+=double(v[t])/w[t]*left;
    return maxvalue;
}

int priorbfs(){//优先队列式分支限界法
    int t,tcp,trw;//当前处理的物品序号t，当前装入背包物品价值tcp,当前剩余容量trw
    double tup;  //当前价值上界tup
    priority_queue<Node> q; //创建一个优先队列
    q.push(Node(0,sumv,W,1));//初始化,根结点加入优先队列
    while(!q.empty()){
        Node livenode, lchild, rchild;//定义三个结点型变量
        livenode=q.top();//取出队头元素作为当前扩展结点livenode
        q.pop(); //队头元素出队
        t=livenode.id;//当前处理的物品序号
        // 搜到最后一个物品的时候不需要往下搜索。
        // 如果当前的背包没有剩余容量(已经装满)了，不再扩展。
        if(t>n||livenode.rw==0){
            if(livenode.cp>=bestp){//更新最优解和最优值
            	for(int i=1;i<=n;i++)
            		bestx[i]=livenode.x[i];
            	bestp=livenode.cp;
            }
            continue;
        }
        if(livenode.up<bestp)//如果不满足不再扩展
        	continue;
        tcp=livenode.cp; //当前背包中的价值
        trw=livenode.rw; //背包剩余容量
        if(trw>=w[t]){ //扩展左孩子，满足约束条件，可以放入背包
            lchild.cp=tcp+v[t];
            lchild.rw=trw-w[t];
            lchild.id=t+1;
            tup=Bound(lchild); //计算左孩子上界
            lchild=Node(lchild.cp,tup,lchild.rw,lchild.id);
            for(int i=1;i<=n;i++)//复制以前的解向量
            	lchild.x[i]=livenode.x[i];
            lchild.x[t]=true;
            if(lchild.cp>bestp)//比最优值大才更新
            	bestp=lchild.cp;
            q.push(lchild);//左孩子入队
        }
        rchild.cp=tcp;
        rchild.rw=trw;
        rchild.id=t+1;
        tup=Bound(rchild);//计算右孩子上界
        if(tup>=bestp){//扩展右孩子，满足限界条件，不放入
            rchild=Node(tcp,tup,trw,t+1);
            for(int i=1;i<=n;i++)//复制以前的解向量
            	rchild.x[i]=livenode.x[i];
            rchild.x[t]=false;
            q.push(rchild);//右孩子入队
          }
    }
    return bestp;//返回最优值。
}

int main(){
    bestp=0; //bestv用来记录最优解
    sumw=0; //sumw为所有物品的总重量。
    sumv=0;   //sumv为所有物品的总价值
    cin>>n>>W;
    for(int i=1;i<=n;i++){
        cin>>goods[i].weight>>goods[i].value;//输入第i件物品的重量和价值。
        sumw+=goods[i].weight;
        sumv+=goods[i].value;
        S[i-1].id=i;
        S[i-1].d=1.0*goods[i].value/goods[i].weight;
    }
    if(sumw<=W){
        bestp=sumv;
        cout<<"放入背包的物品最大价值为: "<<bestp<<endl;
        return 0;
    }
    sort(S,S+n,cmp);//按价值重量比非递增排序
    for(int i=1;i<=n;i++){//把排序后的数据传递给辅助数组
        w[i]=goods[S[i-1].id].weight;
        v[i]=goods[S[i-1].id].value;
    }
    priorbfs();//优先队列分支限界法
    cout<<"放入背包的物品最大价值为: "<<bestp<<endl;
    cout<<"放入背包的物品序号为: ";
    for(int i=1;i<=n;i++){ //输出最优解
        if(bestx[i])
           cout<<S[i-1].id<<" ";//输出原物品序号(排序前的)
    }
    return 0;
}

/*测试数据 
4 10
2 6 5 3 4 5 2 4
*/
