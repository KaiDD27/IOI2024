#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

int main(void)
{
    ifstream fin("sleepy.in");
    ofstream fout("sleepy.out");
    int N = 0;
    fin >> N;
    vector<int> Cows(N, 0);
    for (int i = 0; i < N; i++)
    {
        fin >> Cows[i];
    }
    int ans = 0;
    do
    {
        int temp = 1e9;
        for (int i = N - 1; i >= 0; i--)
        {
            if (i == 0)
            {
                fout << ans << endl;
                /*
                for (auto &cow : Cows)
                {
                    fout << cow << " ";
                }
                */
                return 0;
            }
            if ((Cows[0] < Cows[i]) && (temp > Cows[i]))
            {
                temp = Cows[i];
                continue;
            }
            else
            {
                Cows.insert(Cows.begin() + i + 1, Cows[0]);
                Cows.erase(Cows.begin());
                ans++;
                break;
            }
        }
        /* code */
    } while (true);
    return 0;
}