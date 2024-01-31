#include <iostream>
using namespace std;

const int N = 105;

struct Node{
    int id,nextId;
    //int data;
}nodes[N];

int main()
{
    int n,m;
    cin >> n >> m;
    nodes[0].nextId = 1;
    for(int i =1;i<=n;i++)
    {
        nodes[i].id = i;
        nodes[i].nextId = i+1;
    }
    nodes[n].nextId=1;
    //
    int now =1,prev = 1;
    while((n--)>1)
    {
        for(int i =1;i<m;i++)
        {
            prev = now;
            now = nodes[now].nextId;
        }
        cout << nodes[now].id<< " ";
        nodes[prev].nextId = nodes[now].nextId;
        now = nodes[prev].nextId;
    }
    cout<< nodes[now].id<< endl;
    return 0;
}