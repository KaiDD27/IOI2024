#include <fstream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

int main()
{
    ifstream fin("planting.in");
    ofstream fout("planting.out");
    int N;
    fin >> N;

    vector<vector<int>> fieldsAdjList(N);

    for (int i = 0; i < N - 1; i++)
    {
        int a, b;
        fin >> a >> b;
        fieldsAdjList[a - 1].push_back(b - 1);
        fieldsAdjList[b - 1].push_back(a - 1);
    }
    int ans = 0;
    for (auto adList : fieldsAdjList)
    {
        ans = max(ans, static_cast<int>(adList.size()) + 1);
    }

    fout << ans << endl;
    return 0;
}