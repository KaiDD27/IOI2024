/*
    http://usaco.org/index.php?page=viewproblem2&cpid=1203
SAMPLE INPUT:
3
6
1 2 3 1 1 1
3
2 2 3
5
0 0 0 0 0

SAMPLE OUTPUT:
3
2
0
*/

#include <fstream>
#include <vector>
#include <algorithm>
#include <iostream>
#include <stack>

using namespace std;

int main(void)
{
    //ifstream cin("4.in");
    //ofstream cout("4.out");
    int T;
    cin >> T;
    vector <vector <int>> sleepRecords(T,vector<int>());
    for(auto & element :sleepRecords)
    {
        int N = 0;
        cin >> N;
        int sleepMax = 0;
        int sleepTotal = 0;
        for(int n=0;n<N;n++)
        {
            int temp;
            cin >> temp;
            element.push_back(temp);
            sleepTotal+=temp;
            sleepMax = max(temp,sleepMax);   
        }
        int sleepEqualMaxPossible = 0;
        
        
        if(sleepTotal%2 == 0)
        {
            sleepEqualMaxPossible = sleepTotal/2;
        }else if (sleepTotal%3 ==0)
        {
            sleepEqualMaxPossible = sleepTotal/3;
        }else if (sleepTotal%5 ==0)
        {
            sleepEqualMaxPossible = sleepTotal/5;
        }else if (sleepTotal%7 ==0)
        {
            sleepEqualMaxPossible = sleepTotal/7;
        }else
        {
            sleepEqualMaxPossible = (sleepTotal+1)/2;
        }
        
        int ans = -1;

        for(int equalTimes = sleepMax;equalTimes<=sleepEqualMaxPossible;equalTimes++)
        {
            if(equalTimes == 0)
            {
                ans = -2;
                cout << 0 << endl;
                break;
            }
           
            if(sleepTotal%equalTimes != 0)
            {
                continue;
            }

            ans = (N - sleepTotal/equalTimes);
            int temp = 0;
            
            for(int j = 0;j<N;j++)
            {   
                temp += element[j];
                if(temp == equalTimes)
                {
                    temp = 0;
                 
                }else if (temp < equalTimes)
                {
                
                }else
                {
                    ans = -1;
                    break;
                }
            }
            if(ans!=-1)
            {
                cout << ans << endl;
                break;
            }
        }
        if(ans == -1)
        {
            cout << (N-1) << endl;
        }
    }
    return 0;

}