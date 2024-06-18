#include <vector>
#include <fstream>
#include <algorithm>

using namespace std;

int N = 0;
vector<vector<bool>> cows;
int ans = 0;
void flipcows(int x, int y)
{
    for (int i = 0; i <= x; i++)
        for (int j = 0; j <= y; j++)
            cows[j][i] = !cows[j][i];
    ans++;
}

int main(void)
{
    ifstream fin("cowtip.in");
    ofstream fout("cowtip.out");

    fin >> N;
    cows = vector<vector<bool>>(N, vector<bool>(N));
    for (int i = 0; i < N; i++)
    {
        string strCows = "";
        fin >> strCows;
        for (int j = 0; j < N; j++)
            cows[i][j] = strCows[j] == '1';
    }

    for (int n = N - 1; n >= 0; n--)
    {
        if (cows[n][n])
        {
            flipcows(n, n);
        }
        for (int x = n - 1; x >= 0; x--)
        {
            if (cows[n][x])
                flipcows(x, n);
        }
        for (int y = n - 1; y >= 0; y--)
        {
            if (cows[y][n])
                flipcows(n, y);
        }
    }

    fout << ans << endl;
    return 0;
}