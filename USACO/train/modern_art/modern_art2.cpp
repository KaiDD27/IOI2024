#include <vector>
#include <fstream>
#include <algorithm>
#include <set>
#include <cmath>
using namespace std;

int N;

struct Rectangle
{
    int minx, miny, maxx, maxy;
};

Rectangle findRec(int color, vector<vector<int>> finalcanvas)
{
    int minx = N - 1, miny = N - 1, maxx = 0, maxy = 0;
    for (int y = 0; y < N; y++)
    {
        for (int x = 0; x < N; x++)
        {
            if (finalcanvas[y][x] == color)
            {
                minx = min(minx, x);
                maxx = max(maxx, x);
                miny = min(miny, y);
                maxy = max(maxy, y);
            }
        }
    }
    Rectangle rec{minx, miny, maxx, maxy};
    return rec;
}

bool onTopOf(int color, Rectangle rec, vector<vector<int>> finalcanvas)
{
    for (int y = rec.miny; y <= rec.maxy; y++)
        for (int x = rec.minx; x <= rec.maxx; x++)
            if (finalcanvas[y][x] == color)
                return true;
    return false;
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
    vector<int> usedcolors(mySet.begin(), mySet.end());
    vector<Rectangle> Recs(usedcolors.size());
    for (int i = 0; i < usedcolors.end() - usedcolors.begin(); i++)
        Recs[i] = findRec(usedcolors[i], canvas);

    int ans = 0;
    for (int i = 0; i < usedcolors.end() - usedcolors.begin(); i++)
    {
        int drawnfirst = true;
        for (int j = 0; j < Recs.end() - Recs.begin(); j++)
        {
            if (i != j && onTopOf(usedcolors[i], Recs[j], canvas))
            {
                drawnfirst = false;
                break;
            }
        }
        if (drawnfirst)
        {
            ans++;
        }
    }
    fout << ans << endl;
    return 0;
}