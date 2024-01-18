/*
http://www.usaco.org/index.php?page=viewproblem2&cpid=832
SAMPLE INPUT:
6 3 2
4 5 6
5 3
3 1
SAMPLE OUTPUT:
4
*/

#include <algorithm>
#include <fstream>
#include <vector>

using namespace std;
int N, M, K;
vector<int> order;
vector<int> cowofpos;
vector<int> pos;
vector<int> cows;
bool flagOneHaveOrder = false;
int main(void)
{
    ifstream fin("milkorder.in");
    ofstream fout("milkorder.out");
    fin >> N >> M >> K;
    cows.resize(N, 0);
    order.resize(M);
    for (int i = 0; i < M; i++)
    {
        fin >> order[i];
    }
    cowofpos.resize(K);
    pos.resize(K);
    for (int i = 0; i < K; i++)
    {
        fin >> cowofpos[i] >> pos[i];
    }
    for (int i = 0; i < K; i++)
    {
        cows[pos[i] - 1] = cowofpos[i];
        if (cowofpos[i] == 1)
        {
            fout << pos[i] << endl;
            return 0;
        }
    }

    for (int i = 0; i < M; i++)
    {
        if (order[i] == 1)
        {
            flagOneHaveOrder = true;
            break;
        }
    }

    if (flagOneHaveOrder)
    {
        int pos = 0;
        for (int i = 0; i < M; i++)
        {
            for (int j = pos; j < N; j++)
            {
                auto it = find(cows.begin(), cows.end(), order[i]);
                if (it == cows.end())
                {
                    if (cows[j] == 0)
                    {
                        cows[j] = order[i];
                        if (order[i] == 1)
                        {
                            fout << j + 1 << endl;
                            return 0;
                        }
                        break;
                    }
                }
                else
                {
                    pos = it - cows.begin();
                    break;
                }
            }
        }
    }
    else
    {
        int pos = N - 1;
        for (int i = M - 1; i >= 0; i--)
        {
            for (int j = pos; j >= 0; j--)
            {
                auto it = find(cows.begin(), cows.end(), order[i]);
                if (it == cows.end())
                {
                    if (cows[j] == 0)
                    {
                        cows[j] = order[i];

                        break;
                    }
                }
                else
                {
                    pos = it - cows.begin();
                    break;
                }
            }
        }
        for (int i = 0; i < N; i++)
        {
            if (cows[i] == 0)
            {
                fout << i + 1 << endl;
                return 0;
            }
        }
    }
}
