#include<iostream>
#include<limits>
#include<iomanip>
using namespace std;

int main(){
    short short_min=SHRT_MIN,short_max=SHRT_MAX;
    int int_min=INT_MIN,int_max=INT_MAX;
    long long_min=LONG_MIN,long_max=LONG_MAX;
    long long llong_min=LONG_LONG_MIN,llong_max=LONG_LONG_MAX;
    cout<<"short: " <<sizeof(short)<<" bytes"<<endl;
    cout<<"int: " <<sizeof(int)<<" bytes"<<endl;
    cout<<"long: " <<sizeof(long)<<" bytes"<<endl;
    cout<<"long long: "<<sizeof(long long)<<" bytes"<<endl;
    cout<<"long double: "<<sizeof(long double)<<" bytes"<<endl<<endl;
	cout<<"short: "<<short_min<<" ~ "<<short_max<<endl;
    cout<<"int: " <<int_min<<" ~ "<<int_max<<endl;
    cout<<"long: " <<long_min<<" ~ "<<long_max<<endl;
    cout<<"long long: "<<llong_min<<" ~ "<<llong_max<<endl;
    cout<<"long double: "<<(numeric_limits<long double>::min)()<<" ~ "<<(numeric_limits<long double>::max)()<<endl;
    return 0;
}
