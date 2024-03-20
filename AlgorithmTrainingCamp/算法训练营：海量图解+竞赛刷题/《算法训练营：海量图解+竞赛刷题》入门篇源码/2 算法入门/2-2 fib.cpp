#include<iostream>
#include<ctime>
using namespace std;

long double fib1(int n){
    if(n<1)
        return -1;
    else if(n==1||n==2)
            return 1;
        else
            return fib1(n-1)+fib1(n-2);
}

long double fib2(int n){
    long double temp;
    if(n<1)
        return -1;
    long double *a=new long double[n+1];
    a[1]=a[2]=1;
    for(int i=3;i<=n;i++){
        a[i]=a[i-1]+a[i-2];
        //cout<<a[i]<<endl;
    }
    temp=a[n];
    delete []a;
    return temp;
}

int main(){
	time_t s,e,sumtime;
	int n;
	cin>>n;//10 30 50 100
    s=clock();
    cout<<"fib1("<<n<<")="<<fib1(n)<<"\t\t";
    e=clock();
    sumtime=e-s;
    cout<<"time1="<<sumtime<<endl;
//    s=clock();
//    cout<<"fib2("<<n<<")="<<fib2(n)<<"\t\t";
//    e=clock();
//    sumtime=e-s;
//    cout<<"time2="<<sumtime<<endl;
    return 0;
}
