#include<iostream>
using namespace std;
const int INF=0x3f3f3f3f;
const int N=100;
bool s[N];//���s[i]=true,˵������i�Ѽ���U
int c[N][N],closest[N],lowcost[N];

void Prim(int n){    
    s[1]=true; //��ʼʱ��������Uֻ��һ��Ԫ�أ�������1
    for(int i=1;i<=n;i++){
        if(i!=1){
            lowcost[i]=c[1][i];
            closest[i]=1;
            s[i]=false;
        }
        else
            lowcost[i]=0;
    }
    for(int i=1;i<n;i++){
        int temp=INF;
        int t=1;
        for(int j=1;j<=n;j++){//�ڼ�����V-u��Ѱ�Ҿ��뼯��U����Ķ���t
            if(!s[j]&&lowcost[j]<temp){
                t=j;
                temp=lowcost[j];
            }
        }
        if(t==1)
            break;//�Ҳ���t������ѭ��
        s[t]=true;//����t���뼯��U
        for(int j=1;j<=n;j++){ //����lowcost��closest
            if(!s[j]&&c[t][j]<lowcost[j]){
                lowcost[j]=c[t][j];
                closest[j]=t;
            }
        }
    }
}

int main(){
    int n,m,u,v,w;
    cin>>n>>m;
    int sumcost=0;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
            c[i][j]=INF;
    for(int i=1;i<=m;i++){
        cin>>u>>v>>w;
        c[u][v]=c[v][u]=w;
    }
    Prim(n);
    cout<<"����lowcost:"<<endl;
    for(int i=1;i<=n;i++)
        cout<<lowcost[i]<<" ";
    cout<<endl;
    for(int i=1;i<=n;i++)
       sumcost+=lowcost[i];
    cout<<"��С�Ļ��ѣ�"<<sumcost<<endl;
    return 0;
}
/*�������� 
7 12
1 2 23
1 6 28
1 7 36
2 3 20
2 7 1
3 4 15
3 7 4
4 5 3
4 7 9
5 6 17
5 7 16
6 7 25

�������� 
����lowcost:
0 23 4 9 3 17 1
��С�Ļ��ѣ�57
*/
