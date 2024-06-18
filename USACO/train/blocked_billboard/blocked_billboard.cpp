#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;

struct Rectangle
{
    int x1, y1, x2, y2;
    int area() { return (x2 - x1) * (y2 - y1); }   
};

int intersect(Rectangle a, Rectangle b)
{
    int xOverlap = max(0, min(a.x2, b.x2) - max(a.x1, b.x1));
    int yOverlap = max(0, min(a.y2, b.y2) - max(a.y1, b.y1));
    return xOverlap * yOverlap;
}

int main(void)
{
    ifstream cin("billboard.in");
    ofstream cout("billboard.out");
    Rectangle a, b, t;
    cin >> a.x1 >> a.y1 >> a.x2 >> a.y2 >> b.x1 >> b.y1 >> b.x2 >> b.y2 >> t.x1 >> t.y1 >> t.x2 >> t.y2;
    cout << a.area() + b.area() - intersect(a, t) - intersect(b, t) << endl;
    return 0;
}

/*
struct Rectangle
{
    int x1, y1, x2, y2;
};

const int MAX_POS = 2000;
bool visiable[MAX_POS][MAX_POS];

int main(void)
{
    ifstream cin("billboard.in");
    ofstream cout("billboard.out");
    Rectangle a, b, t;
    cin >> a.x1 >> a.y1 >> a.x2 >> a.y2 >> b.x1 >> b.y1 >> b.x2 >> b.y2 >> t.x1 >> t.y1 >> t.x2 >> t.y2;    
    a.x1+=MAX_POS/2;
    a.x2+=MAX_POS/2;
    a.y1+=MAX_POS/2;
    a.y2+=MAX_POS/2;
    b.x1+=MAX_POS/2;
    b.x2+=MAX_POS/2;
    b.y1+=MAX_POS/2;
    b.y2+=MAX_POS/2;
    t.x1+=MAX_POS/2;
    t.x2+=MAX_POS/2;
    t.y1+=MAX_POS/2;
    t.y2+=MAX_POS/2;
    for(int i=a.x1;i<a.x2;i++)
        for(int j=a.y1;j<a.y2;j++)
            visiable[i][j]=true;
    for(int i=b.x1;i<b.x2;i++)
        for(int j=b.y1;j<b.y2;j++)
            visiable[i][j]=true;
    for(int i=t.x1;i<t.x2;i++)
        for(int j=t.y1;j<t.y2;j++)
            visiable[i][j]=false;
    int ans=0;
    for(int i=0;i<MAX_POS;i++)
        for(int j=0;j<MAX_POS;j++)
            if(visiable[i][j])
                ans++;
    return 0;
}

const int MAX_POS = 2000;
bool visiable[MAX_POS][MAX_POS];
int main(void)
{
    ifstream cin("billboard.in");
    ofstream cout("billboard.out");
    for(int r=0;r<3;r++)
    {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        x1+=MAX_POS/2;
        x2+=MAX_POS/2;
        y1+=MAX_POS/2;
        y2+=MAX_POS/2;
        for(int i=x1;i<x2;i++)
            for(int j=y1;j<y2;j++)
                visiable[i][j]=(r<2);
    }
    int ans=0;
    for(int i=0;i<MAX_POS;i++)
        for(int j=0;j<MAX_POS;j++)
            if(visiable[i][j])
                ans++;
    cout << ans << endl;
    return 0;
}
*/