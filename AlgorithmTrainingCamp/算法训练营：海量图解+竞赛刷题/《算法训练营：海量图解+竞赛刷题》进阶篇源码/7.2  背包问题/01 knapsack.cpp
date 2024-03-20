#include<iostream>//01����
#include<cstring>
#include<algorithm>
using namespace std;
#define maxn 10005
#define M 105
int c[M][maxn];//c[i][j]��ʾǰi����Ʒ��������Ϊj������õ�����ֵ
int w[M],v[M];//w[i]��ʾ��i����Ʒ��������v[i]��ʾ��i����Ʒ�ļ�ֵ
int x[M];  //x[i]��ʾ��i����Ʒ�Ƿ���뱳��

int main(){
    int n,W;//n��ʾn����Ʒ��W��ʾ����������
    cout<<"��������Ʒ�ĸ��� n:";
    cin>>n;
    cout<<"�����뱳��������W:";
    cin>>W;
    cout<<"����������ÿ����Ʒ������w�ͼ�ֵv���ÿո�ֿ�:";
    for(int i=1;i<=n;i++)
        cin>>w[i]>>v[i];
    for(int i=1;i<=n;i++)//��ʼ����0��Ϊ0
        c[i][0]=0;
    for(int j=1;j<=W;j++)//��ʼ����0��Ϊ0
        c[0][j]=0;
	for(int i=1;i<=n;i++)//����c[i][j]
		for(int j=1;j<=W;j++)
			if(j<w[i])  //����Ʒ���������ڱ������������򲻷Ŵ���Ʒ
				c[i][j]=c[i-1][j];
            else    //����Ƚϴ���Ʒ���벻���Ƿ���ʹ�ñ����ڵļ�ֵ���
				c[i][j]=max(c[i-1][j],c[i-1][j-w[i]]+v[i]);
	cout<<"װ�뱳��������ֵΪ:"<<c[n][W]<<endl;
    //���ڲ���
    for(int i=1;i<=n;i++){
        for(int j=1;j<=W;j++)
          cout<<c[i][j]<<"\t" ;
        cout<<endl;
    }
    cout<<endl;
    //���������Ž�
    int j=W;
    for(int i=n;i>0;i--)
        if(c[i][j]>c[i-1][j]){
            x[i]=1;
            j-=w[i];
        }
        else
            x[i]=0;
    cout<<"װ�뱳������Ʒ���Ϊ:";
    for(int i=1;i<=n;i++)
        if(x[i]==1)
           cout<<i<<"  ";
    return 0;
} 
