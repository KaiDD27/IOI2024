#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

int N;
int main()
{
    ifstream fin("factory.in");
    ofstream fout("factory.out");

    fin >> N;
    int outDegree[N];
    for (int i = 0; i < N; i++)
    {
        outDegree[i] = 0;
    }
    for (int i = 0; i < N - 1; i++)
    {
        int a, b;
        fin >> a >> b;
        outDegree[--a]++;
    }
    int ans = -1;
    for (int i = 0; i < N; i++)
    {
        if (outDegree[i] > 1)
        {
            fout << -1 << endl;
            return 0;
        }
        else if (outDegree[i] == 0)
        {
            if (ans == -1)
                ans = i;
            else
            {
                fout << -1 << endl;
                return 0;
            }
        }
    }
    fout << ans + 1 << endl;
    return 0;
}