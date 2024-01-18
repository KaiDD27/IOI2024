/*
http://www.usaco.org/index.php?page=viewproblem2&cpid=617
SAMPLE INPUT:
7 10
7 3
5 5
9 7
3 1
7 7
5 3
9 1
SAMPLE OUTPUT:
2
*/

#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

struct Point {
    int x,y;
};

int main(void)
{
    ifstream cin("balancing.in");
    ofstream cout("balancing.out");
    int N,B;
    cin >> N >> B;
    vector<Point> cowPosition(N);
    for(auto & element :cowPosition)
    {
        cin >> element.x >> element.y;
    }

    int ans = N;
    int minLeftRightX = 0;
    int minUpDownY = 0;

    int x = 0, y = 0;
    for(auto & element1 :cowPosition)
    {
        x = element1.x+1;
        for(auto & element2 :cowPosition)
        {
            y = element2.y+1;
            int leftUpCount = 0,leftDownCount = 0, rightUpCount = 0,rightDownCount = 0;
            for(auto & element :cowPosition)
            {
                if(element.x<x&&element.y>y)
                    leftUpCount++;
                if(element.x<x&&element.y<y)
                    leftDownCount++;
                if(element.x>x&&element.y>y)
                    rightUpCount++;
                if(element.x>x&&element.y<y)
                    rightDownCount++;
            } 
            if(ans>max(rightDownCount,max(rightUpCount,max(leftUpCount,leftDownCount))))
            {
                ans = max(rightDownCount,max(rightUpCount,max(leftUpCount,leftDownCount)));
                minLeftRightX = x;
                minUpDownY = y;
            }
        }
    }

    cout << ans << endl;
    return 0;
}