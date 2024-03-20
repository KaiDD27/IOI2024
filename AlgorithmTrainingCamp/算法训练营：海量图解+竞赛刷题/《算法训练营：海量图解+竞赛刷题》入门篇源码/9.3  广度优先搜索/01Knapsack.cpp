#include<iostream>
#include<algorithm>
#include<cstring>
#include<cmath>
#include<queue>
using namespace std;
const int N=10;
bool bestx[N];
//�����㡣ÿ���ڵ�����¼��ǰ�Ľ⡣
struct Node{
    int cp,rp; //cpΪ��ǰװ�뱳������Ʒ�ܼ�ֵ��rpΪʣ����Ʒ���ܼ�ֵ
    int rw; //ʣ������
    int id; //��Ʒ��
    bool x[N];//������
    Node(){}
    Node(int _cp,int _rp,int _rw,int _id){
        cp=_cp;
        rp=_rp;
        rw=_rw;
        id=_id;
        memset(x,0,sizeof(x));//��������ʼ��Ϊ0
    }
};

struct Goods{//��Ʒ
    int weight;//���� 
    int value;//��ֵ 
}goods[N];

int bestp,W,n,sumw,sumv;
/*
  bestp������¼���Ž�
  WΪ�������������
  nΪ��Ʒ�ĸ�����
  sumwΪ������Ʒ����������
  sumvΪ������Ʒ���ܼ�ֵ��
*/

int bfs(){//����ʽ��֧�޽編 
    int t,tcp,trp,trw;//��ǰ�������Ʒ���t��װ�뱳����Ʒ��ֵtcp,ʣ������trw
    queue<Node> q; //����һ����ͨ����(�Ƚ��ȳ�)
    q.push(Node(0,sumv,W,1)); //ѹ��һ����ʼ�ڵ�
    while(!q.empty()){
        Node livenode,lchild,rchild;//������������ͱ���
        livenode=q.front();//ȡ����ͷԪ����Ϊ��ǰ��չ���livenode
        q.pop(); //��ͷԪ�س���
        t=livenode.id;//��ǰ�������Ʒ���
        // �ѵ����һ����Ʒ��ʱ����Ҫ��������
        // �����ǰ�ı���û��ʣ������(�Ѿ�װ��)�ˣ�������չ
        if(t>n||livenode.rw==0){
            if(livenode.cp>=bestp){//�������Ž������ֵ
				for(int i=1;i<=n;i++)
					bestx[i]=livenode.x[i];
              bestp=livenode.cp;
            }
            continue;
        }
        if(livenode.cp+livenode.rp<bestp)//�жϵ�ǰ����Ƿ������޽���������������㲻����չ
			continue;
        tcp=livenode.cp; //��ǰ�����еļ�ֵ
        trp=livenode.rp-goods[t].value; //���ܵ�ǰ��Ʒװ�����ʣ���ֵ������١�
        trw=livenode.rw; //����ʣ������
        if(trw>=goods[t].weight){ //��չ���ӣ�����Լ�����������Է��뱳��
            lchild.rw=trw-goods[t].weight;
            lchild.cp=tcp+goods[t].value;
            lchild=Node(lchild.cp,trp,lchild.rw,t+1);
            for(int i=1;i<t;i++)//������ǰ�Ľ�����
            	lchild.x[i]=livenode.x[i];
            lchild.x[t]=true;
            if(lchild.cp>bestp)//������ֵ��Ÿ���
               bestp=lchild.cp;
            q.push(lchild);//�������
        }
        if(tcp+trp>=bestp){//��չ�Һ���,�����޽������������뱳��
            rchild=Node(tcp,trp,trw,t+1);
            for(int i=1;i<t;i++)//������ǰ�Ľ�����
				rchild.x[i]=livenode.x[i];
            rchild.x[t]=false;
            q.push(rchild);//�Һ������
        }
    }
    return bestp;//��������ֵ
}

int main(){
    cin>>n>>W;//������Ʒ�ĸ����ͱ���������
    bestp=0; //bestv������¼���Ž�
    sumw=0; //sumwΪ������Ʒ����������
    sumv=0;  //sumvΪ������Ʒ���ܼ�ֵ
    for(int i=1;i<=n;i++){//����ÿ����Ʒ�������ͼ�ֵ,�ÿո�ֿ�
        cin>>goods[i].weight>>goods[i].value;//�����i����Ʒ�������ͼ�ֵ��
        sumw+=goods[i].weight;
        sumv+=goods[i].value;
    }
    if(sumw<=W){
        bestp=sumv;
        cout<<"���뱳������Ʒ����ֵΪ: "<<bestp<<endl;
        return 0;
    }
    bfs();
    cout<<"���뱳������Ʒ����ֵΪ: "<<bestp<<endl;
    cout<<"���뱳������Ʒ���Ϊ: ";
    for(int i=1;i<=n;i++){// ������Ž�
        if(bestx[i])
           cout<<i<<"  ";
    }
    return 0;
}

/*�������� 
4 10
2 6 5 3 4 5 2 4
*/
