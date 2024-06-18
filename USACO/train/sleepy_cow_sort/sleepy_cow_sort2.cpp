#include <vector>
#include <fstream>
#include <algorithm>

using namespace std;

int main(void)
{
    ifstream fin("sleepy.in");
    ofstream fout("sleepy.out");
    int N = 0;
    fin >> N;
    vector<int> cows(N, 0);
    for (int i = 0; i < N; i++)
    {
        fin >> cows[i];
    }
    int ans = N - 1;
    for (int i = N - 2; i >= 0; i--)
    {
        if (cows[i] < cows[i + 1])
            ans--;
        else
        {
            break;
        }
    }
    fout << ans << endl;
    return 0;
}