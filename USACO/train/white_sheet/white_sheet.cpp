#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Rect
{
    long long x1,x2,y1,y2;
    long long area()
    {
        return (x2-x1)*(y2-y1);
    }
};

long long intersectOf2(Rect m, Rect n)
{
    long long xOverlap = max(0LL, min(m.x2, n.x2) - max(m.x1, n.x1)); // Use max instead of max
    long long yOverlap = max(0LL, min(m.y2, n.y2) - max(m.y1, n.y1)); // Use max instead of max
    return xOverlap * yOverlap;
}

long long intersectOf3(Rect m, Rect n, Rect l)
{
    long long xOverlap = max(0LL, min(l.x2, min(m.x2, n.x2)) - max(l.x1, max(m.x1, n.x1))); // Use max instead of max
    long long yOverlap = max(0LL, min(l.y2, min(m.y2, n.y2)) - max(l.y1, max(m.y1, n.y1))); // Use max instead of max
    return xOverlap * yOverlap;
}

int main(void)
{
    Rect a,b,c;
    cin >> a.x1 >> a.y1 >> a.x2 >> a.y2 >> b.x1 >> b.y1 >> b.x2 >> b.y2 >> c.x1 >> c.y1 >> c.x2 >> c.y2;
    long long overlapAB = intersectOf2(a,b);
    long long overlapAC = intersectOf2(a,c);
    long long overlapABC = intersectOf3(a,b,c);
    if( a.area()== (overlapAB + overlapAC - overlapABC))
        cout << "NO\n";
    else 
        cout << "YES\n";
    return 0;
}