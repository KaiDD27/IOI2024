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
    vector<int> Days(N, 2); // 0,1,2

    int min_count = 1;
    int x_count = N - 1;
    for (int i = 0, log = -2; i < N; i++)
    {
        fin >> log;
        if (i == 0)
        {
            Days[0] = 1;
            continue;
        }
        if (log == 0)
        {
            Days[i] = 1;
            min_count++;
            x_count--;
        }
        else if (log > 0)
        {
            Days[i] = 0;
            x_count--;
            if (Days[i - log] == 0)
            {
                fout << -1 << endl;
                return 0;
            }
            else if (Days[i - log] == 2)
            {
                Days[i - log] = 1;
                x_count--;
                min_count++;
            }

            for (int j = 1; j < log; j++)
            {
                if (Days[i - j] == 1)
                {
                    fout << -1 << endl;
                    return 0;
                }
                else if (Days[i - j] == 2)
                {
                    Days[i - j] = 0;
                    x_count--;
                }
            }
        }
    }

    fout << min_count << " " << min_count + x_count;
    return 0;
}