#include <fstream>
#include <algorithm>
using namespace std;

bool usedCow[100];
bool usedPos[100];
int pos[100];

int nCows, M, nFixed;

int ord[100];

int cFixed[101];
int pFixed[101];

bool works()
{
    for (int i = 0; i < nCows; i++)
        usedCow[i] = usedPos[i] = 0;
    for (int i = 0; i < nFixed; i++)
    {
        if (usedCow[cFixed[i]] && pos[cFixed[i]] == pFixed[i])
            continue;
        if (usedCow[cFixed[i]])
            return 0;
        if (usedPos[pFixed[i]])
            return 0;
        usedCow[cFixed[i]] = 1;
        usedPos[pFixed[i]] = 1;
        pos[cFixed[i]] = pFixed[i];
    }
    int j = 0;
    for (int i = 0; i < M; i++)
    {
        int cow = ord[i];
        if (usedCow[cow])
        {
            if (j > pos[cow])
                return 0;
            j = pos[cow];
            continue;
        }
        while (usedPos[j])
        {
            j++;
            if (j == nCows)
                return 0;
        }
        usedPos[j] = 1;
        pos[cow] = j;
    }
    return 1;
}

int main()
{
        ifstream fin("milkorder.in");
    ofstream fout("milkorder.out");
    fin >> nCows >> M >> nFixed;
    for (int i = 0; i < M; i++)
    {
        fin >> ord[i];
        ord[i]--;
    }
    for (int i = 0; i < nFixed; i++)
    {
        fin >> cFixed[i] >> pFixed[i];
        cFixed[i]--, pFixed[i]--;
    }
    nFixed++;
    for (int i = 0; i < nCows; i++)
    {
        cFixed[nFixed - 1] = 0;
        pFixed[nFixed - 1] = i;
        if (works())
        {
            fout << i + 1 << '\n';
            return 0;
        }
    }
}
