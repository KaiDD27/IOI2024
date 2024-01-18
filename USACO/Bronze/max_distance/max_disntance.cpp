/*
https://codeforces.com/gym/102951/problem/A
inputCopy
3
321 -15 -525
404 373 990
outputCopy
1059112
*/
#include <fstream>
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

struct Point {
    int x ,y;
};

int square(Point a ,Point b)
{
    return (a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y);
}
int main(void)
{
    
    int N = 0;
    cin >> N ;
    vector <Point> P(N);
    for(auto &element : P)
    {
        cin >> element.x;
    }
    for(auto &element : P)
    {
        cin  >> element.y;
    }
    int ans = 0;
    for(auto element1 : P)
    {
        for(auto element2 :P)
        {
            int distance = square(element1, element2);
            ans = max(ans, distance);
        }
    }
    cout << ans << endl;
}