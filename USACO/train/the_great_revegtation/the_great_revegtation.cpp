#include <vector>
#include <fstream>
#include <algorithm>

using namespace std;

int N, M;

int main()
{
    ifstream fin("revegetate.in");
    ofstream fout("revegetate.out");

    fin >> N >> M;

    vector<vector<int>> pasturePairs(N);

    for (int i = 0; i < M; i++)
    {
        int a, b;
        fin >> a >> b;
        pasturePairs[--a].push_back(--b);
        pasturePairs[b].push_back(a);
    }

    vector<int> pasturesGrassType(N, -1);
    vector<bool> GrassType(4);

    for (int i = 0; i < N; i++)
    {
        fill(GrassType.begin(), GrassType.end(), false);

        for (int neighbor : pasturePairs[i])
        {
            int neighborGrassType = pasturesGrassType[neighbor];
            if (neighborGrassType != -1)
                GrassType[neighborGrassType - 1] = true;
        }

        for (int j = 0; j < 4; j++)
        {
            if (!GrassType[j])
            {
                pasturesGrassType[i] = j + 1;
                break;
            }
        }
    }

    for (int i = 0; i < N; i++)
    {
        fout << pasturesGrassType[i];
    }

    return 0;
}