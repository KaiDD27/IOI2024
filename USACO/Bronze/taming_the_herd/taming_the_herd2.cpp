#include <vector>
#include <fstream>
#include <algorithm>

using namespace std;

int main(void)
{
    ifstream fin("taming.in");
    ofstream fout("taming.out");

    int N = 0;
    fin >> N;
    vector<int> Logs(N, -1);

    int sureBreak = 0;
    int possible = 0;
    for (int i = 0; i < N; i++)
    {
        fin >> Logs[i];
    }
    Logs[0] = 0;

    int shouldbe = -1;
    for (int i = N - 1; i >= 0; i--)
    {
        if ((shouldbe != -1) && (Logs[i] != -1) && (shouldbe != Logs[i]))
        {
            fout << -1 << endl;
            return 0;
        }
        if (shouldbe == -1)
        {
            shouldbe = Logs[i];
        }
        if (Logs[i] == -1)
        {
            Logs[i] = shouldbe;
        }
        if (Logs[i] == 0)
        {
            sureBreak++;
        }
        if (Logs[i] == -1)
        {
            possible++;
        }
        if (shouldbe > -1)
            shouldbe--;
    }
    fout << sureBreak << " " << sureBreak + possible << endl;
}
