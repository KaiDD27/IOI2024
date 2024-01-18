#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;

struct rect
{
    int x1,x2,y1,y2;
};

int main(void)
{
    ifstream cin("billboard.in");
    ofstream cout("billboard.out");
    rect a,b;
    cin >> a.x1 >> a.y1 >> a.x2 >> a.y2 >> b.x1 >> b.y1 >> b.x2 >> b.y2;
    int widthA = a.x2-a.x1;
    int heightA = a.y2- a.y1;
    int area = 0;

    vector< vector<bool> > A(widthA,vector<bool>(heightA));
    for(int i = 0 ;i <widthA;i++)
    {   for(int j = 0; j<heightA;j++)
        {    
            int x=a.x1+i,y=a.y1+j;
            A[i][j]=( x<b.x1 || x>=b.x2 || y<b.y1 || y>=b.y2);
            if(A[i][j])
                area++;
        }
    }
    
    if((A[0][0]+A[0][heightA-1]+A[widthA-1][0]+A[widthA-1][heightA-1])>=3)
    {
        area =heightA*widthA;
    
    }else if ((A[0][0]+A[0][heightA-1]+A[widthA-1][0]+A[widthA-1][heightA-1])==0)
    {
        area=0;
    }
    
    cout << area;
    return 0;
}