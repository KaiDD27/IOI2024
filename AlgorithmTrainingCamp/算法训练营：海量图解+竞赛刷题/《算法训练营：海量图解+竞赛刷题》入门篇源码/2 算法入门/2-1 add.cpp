#include<iostream>
#include<cmath>//ʹ��pow������Ҫ����ͷ�ļ� 
#include<ctime>//ʹ��clock������Ҫ����ͷ�ļ� 
using namespace std;
const int n=1e8;

int sum1(int n){
    int sum=0;
    for(int i=1;i<=n;i++)
        sum+=pow(-1,i);//��ʾ��-1��^i 
    return sum;
}

int sum2(int n){
    int sum=0;
    if(n%2==0)
        sum=0;
    else
        sum=-1;
    return sum;
}

int main(){
    time_t s,e,sumtime;
    s=clock();
    cout<<"sum1= "<<sum1(n)<<"\t\t";
    e=clock();
    sumtime=e-s;
    cout<<"time1= "<<sumtime<<endl;
    s=clock();
    cout<<"sum2= "<<sum2(n)<<"\t\t";
    e=clock();
    sumtime=e-s;
    cout<<"time2= "<<sumtime<<endl;
    return 0;
}
