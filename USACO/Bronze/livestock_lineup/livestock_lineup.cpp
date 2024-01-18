#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

int N;
vector<string> cowsName{"Bessie", "Buttercup", "Belinda", "Beatrice", "Bella", "Blue", "Betsy", "Sue"};
vector<string> beside_a, beside_b;

int where(string strCow)
{
    for (int i = 0; i < cowsName.size(); i++)
    {
        if (strCow == cowsName[i])
            return i;
    }
    return -1;
}

bool satisfies_constraints()
{
    for (int i = 0; i < N; i++)
    {
        if (abs(where(beside_a[i]) - where(beside_b[i])) != 1)
            return false;
    }
    return true;
}

int main(void)
{
    ifstream fin("lineup.in");
    ofstream fout("lineup.out");
    sort(cowsName.begin(), cowsName.end());
    fin >> N;
    string a, t, b;
    beside_a.resize(N);
    beside_b.resize(N);
    for (int i = 0; i < N; i++)
    {
        fin >> a;
        fin >> t >> t >> t >> t;
        fin >> b;
        beside_a[i] = a;
        beside_b[i] = b;
    }
    do
    {
        if (satisfies_constraints())
        {
            for (int i = 0; i < cowsName.size(); i++)
                fout << cowsName[i] << endl;
            break;
        }
    } while (next_permutation(cowsName.begin(), cowsName.end()));
    return 0;
}