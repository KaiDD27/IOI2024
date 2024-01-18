/*
http://www.usaco.org/index.php?page=viewproblem2&cpid=963
SAMPLE INPUT:
3 4
4 1 2 3
4 1 3 2
4 2 1 3
SAMPLE OUTPUT:
4
The consistent pairs of cows are (1,4)
, (2,4)
, (3,4)
, and (1,3)
*/
#include <fstream>
#include <algorithm>
#include <vector>
using namespace std;

int main(void)
{
    ifstream cin("gymnastics.in");
    ofstream cout("gymnastics.out");
    int K,N;
    cin >> K >> N;
    vector<vector<int>> Rank(K,vector<int>(N));
    for(auto & element :Rank)
    {
        for(int n = 0 ;n < N ;n++)
        {
            cin >> element[n];
        }

    }
    int ans = 0;
    for(int i =1 ;i <=N;i++)
    {  
        for(int j=i+1; j<=N;j++)
        {
            bool boolConsistent = true;
            int intCompare = 0;// 0 is initial,1 is i>j,2 is j>i
            for(auto &element : Rank)
            {
                auto it1 = cind(element.begin(),element.end(),i);
                auto it2 = cind(element.begin(),element.end(),j);
                int index1 = distance(element.begin(),it1);
                int index2 = distance(element.begin(),it2);
                if(intCompare ==0)
                {
                    if(index1 < index2)
                    {
                        intCompare = 1;
                    }
                    else
                        intCompare = 2;
                }else if((intCompare == 1)&& (index1 > index2))
                {
                    boolConsistent = false;
                    break;
                }else if((intCompare == 2)&& (index1 < index2))
                {
                    boolConsistent = false;
                    break;
                }

            }
            ans+=boolConsistent;
        }
    }
    cout << ans << endl;
}