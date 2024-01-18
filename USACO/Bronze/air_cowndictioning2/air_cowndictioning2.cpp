/*
http://www.usaco.org/index.php?page=viewproblem2&cpid=1276
SAMPLE INPUT:
2 4
1 5 2
7 9 3
2 9 2 3
1 6 2 8
1 2 4 2
6 9 1 5
SAMPLE OUTPUT:
10
One possible solution that results in the least amount of money spent is to select those that cool the intervals [2,9]
, [1,2]
, and [6,9]
, for a cost of 3+2+5=10
.
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

struct Cows
{
    int s,t,c;
};

struct Condition
{
    int a,b,p,m;
};

int N,M;

int main(void)
{
    cin >> N >> M;
    vector <Cows> NCows(N);
    vector <Condition> MCondition(M);
    vector <int> stallReduce;
    for(auto &cow :NCows) {cin >> cow.s >> cow.t >> cow.c;}
    for(auto &condition :MCondition) {cin >> condition.a >> condition.b >> condition.p >> condition.m;}
    int largestBitmasks=0;
    for(int i =0;i<M;i++) largestBitmasks+=static_cast<int>(pow(2,i));
    int minMoney = 1000*M;
    for(int bitmasks = 0;bitmasks<=largestBitmasks;bitmasks++)
    {
        int money = 0;
        bool works = true;
        stallReduce = vector<int>(101,0);
        
        for(int condition = 0 ;condition < M ;condition ++)
        {
            if(bitmasks & static_cast<int>( pow(2,condition)))
            {
                for(int stall = MCondition[condition].a;stall <= MCondition[condition].b;stall++)
                {
                    stallReduce[stall]+=MCondition[condition].p;
                }
                money+=MCondition[condition].m;
            }
        }

        for(auto &cow :NCows)
        {
            for(int stall = cow.s;stall <=cow.t;stall++)
            {
                if(cow.c>stallReduce[stall])
                {
                    works = false;
                    break;
                }
            }
        }
        if(works == true)
        {
            minMoney = min(money,minMoney);
        }
    }
    cout << minMoney << endl;
    return 0;
}