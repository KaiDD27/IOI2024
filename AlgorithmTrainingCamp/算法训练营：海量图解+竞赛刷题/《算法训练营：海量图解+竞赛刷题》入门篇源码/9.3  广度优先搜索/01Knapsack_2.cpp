#include<iostream>
#include<algorithm>
#include<cstring>
#include<cmath>
#include<queue>
using namespace std;
const int N=10;
bool bestx[N]; //��¼���Ž�
int w[N],v[N];//��������,���ڴ洢�����������ͼ�ֵ

struct Node{//������,��¼��ǰ���Ľ���Ϣ
    int cp; //��װ�뱳������Ʒ��ֵ
    double up; //��ֵ�Ͻ�
    int rw; //����ʣ������
    int id; //��Ʒ��
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

struct Goods{ //��Ʒ�ṹ��
    int weight;//����
    int value;//��ֵ
}goods[N];

struct Object{//������Ʒ�ṹ�壬���ڰ���λ������ֵ(��ֵ/������)����
    int id; //���
    double d;//��λ������ֵ
}S[N];


bool cmp(Object a1,Object a2){//�������ȼ���������Ʒ��λ������ֵ�ɴ�С����
    return a1.d>a2.d;
}

bool operator <(const Node &a, const Node &b){//�������ȼ���upԽ��Խ����
    return a.up<b.up;
}

int bestp,W,n,sumw,sumv;
/*
  bestv ������¼���Ž⡣
  WΪ���������������
  nΪ��Ʒ�ĸ�����
  sumwΪ������Ʒ����������
  sumvΪ������Ʒ���ܼ�ֵ��
*/

double Bound(Node tnode){//����ڵ���Ͻ� 
    double maxvalue=tnode.cp;//��װ�뱳����Ʒ��ֵ
    int t=tnode.id;//��������
    double left=tnode.rw;//ʣ������
    while(t<=n&&w[t]<=left){
        maxvalue+=v[t];
        left-=w[t++];
    }
    if(t<=n)
        maxvalue+=double(v[t])/w[t]*left;
    return maxvalue;
}

int priorbfs(){//���ȶ���ʽ��֧�޽編
    int t,tcp,trw;//��ǰ�������Ʒ���t����ǰװ�뱳����Ʒ��ֵtcp,��ǰʣ������trw
    double tup;  //��ǰ��ֵ�Ͻ�tup
    priority_queue<Node> q; //����һ�����ȶ���
    q.push(Node(0,sumv,W,1));//��ʼ��,�����������ȶ���
    while(!q.empty()){
        Node livenode, lchild, rchild;//������������ͱ���
        livenode=q.top();//ȡ����ͷԪ����Ϊ��ǰ��չ���livenode
        q.pop(); //��ͷԪ�س���
        t=livenode.id;//��ǰ�������Ʒ���
        // �ѵ����һ����Ʒ��ʱ����Ҫ����������
        // �����ǰ�ı���û��ʣ������(�Ѿ�װ��)�ˣ�������չ��
        if(t>n||livenode.rw==0){
            if(livenode.cp>=bestp){//�������Ž������ֵ
            	for(int i=1;i<=n;i++)
            		bestx[i]=livenode.x[i];
            	bestp=livenode.cp;
            }
            continue;
        }
        if(livenode.up<bestp)//��������㲻����չ
        	continue;
        tcp=livenode.cp; //��ǰ�����еļ�ֵ
        trw=livenode.rw; //����ʣ������
        if(trw>=w[t]){ //��չ���ӣ�����Լ�����������Է��뱳��
            lchild.cp=tcp+v[t];
            lchild.rw=trw-w[t];
            lchild.id=t+1;
            tup=Bound(lchild); //���������Ͻ�
            lchild=Node(lchild.cp,tup,lchild.rw,lchild.id);
            for(int i=1;i<=n;i++)//������ǰ�Ľ�����
            	lchild.x[i]=livenode.x[i];
            lchild.x[t]=true;
            if(lchild.cp>bestp)//������ֵ��Ÿ���
            	bestp=lchild.cp;
            q.push(lchild);//�������
        }
        rchild.cp=tcp;
        rchild.rw=trw;
        rchild.id=t+1;
        tup=Bound(rchild);//�����Һ����Ͻ�
        if(tup>=bestp){//��չ�Һ��ӣ������޽�������������
            rchild=Node(tcp,tup,trw,t+1);
            for(int i=1;i<=n;i++)//������ǰ�Ľ�����
            	rchild.x[i]=livenode.x[i];
            rchild.x[t]=false;
            q.push(rchild);//�Һ������
          }
    }
    return bestp;//��������ֵ��
}

int main(){
    bestp=0; //bestv������¼���Ž�
    sumw=0; //sumwΪ������Ʒ����������
    sumv=0;   //sumvΪ������Ʒ���ܼ�ֵ
    cin>>n>>W;
    for(int i=1;i<=n;i++){
        cin>>goods[i].weight>>goods[i].value;//�����i����Ʒ�������ͼ�ֵ��
        sumw+=goods[i].weight;
        sumv+=goods[i].value;
        S[i-1].id=i;
        S[i-1].d=1.0*goods[i].value/goods[i].weight;
    }
    if(sumw<=W){
        bestp=sumv;
        cout<<"���뱳������Ʒ����ֵΪ: "<<bestp<<endl;
        return 0;
    }
    sort(S,S+n,cmp);//����ֵ�����ȷǵ�������
    for(int i=1;i<=n;i++){//�����������ݴ��ݸ���������
        w[i]=goods[S[i-1].id].weight;
        v[i]=goods[S[i-1].id].value;
    }
    priorbfs();//���ȶ��з�֧�޽編
    cout<<"���뱳������Ʒ����ֵΪ: "<<bestp<<endl;
    cout<<"���뱳������Ʒ���Ϊ: ";
    for(int i=1;i<=n;i++){ //������Ž�
        if(bestx[i])
           cout<<S[i-1].id<<" ";//���ԭ��Ʒ���(����ǰ��)
    }
    return 0;
}

/*�������� 
4 10
2 6 5 3 4 5 2 4
*/
