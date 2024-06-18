#include <vector>
#include <fstream>
#include <algorithm>
#include <set>
#include <cmath>
using namespace std;

int N;

struct Rectangle{
    int minx,miny,maxx,maxy;
};

Rectangle findRec(int color,vector<vector<int>> finalcanvas)
{
    int minx=N-1,miny=N-1,maxx=0,maxy=0;
    for(int y = 0;y<N;y++)
    {
        for(int x=0;x<N;x++)
        {
            if(finalcanvas[y][x]==color)
            {
                minx=min(minx,x);
                maxx = max(maxx,x);
                miny=min(miny,y);
                maxy=max(maxy,y);
            }
        }
    }
    Rectangle rec {minx,miny,maxx,maxy};
    return rec;
}

int paint(int color,Rectangle rec,vector<vector<int>> &tempcanvas)
{
    for(int y =rec.miny;y<=rec.maxy;y++)
    {
        for(int x = rec.minx;x<=rec.maxx;x++)
        {
            tempcanvas[y][x] = color;
        }
    }
    return 0;
}

int works(vector <int> colorseq,vector<vector<int>> finalcanvas)
{
    vector<vector<int> > tempcanvas (N,vector<int>(N,0));
    for(int i = 0;i<colorseq.size();i++)
    {
        Rectangle rec = findRec(colorseq[i],finalcanvas);
        paint(colorseq[i],rec,tempcanvas);
    }
    if(tempcanvas == finalcanvas)
    {
        return colorseq[0];
    }
    return -1;
}

int main(void)
{
    ifstream fin("art.in");
    ofstream fout("art.out");

    fin >> N;
    vector<vector<int>> canvas(N, vector<int>(N, 0));
    set<int> mySet;
    for (int i = 0; i < N; i++)
    {
        string strLine;
        fin >> strLine;
        for (int j = 0; j < N; j++)
        {
            canvas[i][j] = strLine[j] - '0';
            if (canvas[i][j] != 0)
                mySet.insert(canvas[i][j]);
        }
    }
    vector<int> usedColorsSeq(mySet.begin(), mySet.end());

    set<int> drawnfirstColor;
    do
    {   
        if(drawnfirstColor.count(usedColorsSeq[0])==0)
        {
            int firstcolor = works(usedColorsSeq,canvas);
            if(firstcolor !=-1)
            {
                drawnfirstColor.insert(firstcolor);
            }
        }
    } while (next_permutation(usedColorsSeq.begin(), usedColorsSeq.end()));

    fout << drawnfirstColor.size() << endl;
    return 0;
}