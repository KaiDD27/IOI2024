#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

int N = 0;
vector<int> cowlineoriginal;
vector<int> cowlineorderd;
int main(void)
{
    ifstream fin("outofplace.in");
    ofstream fout("outofplace.out");

    fin >> N;
    cowlineoriginal.resize(N, 0);

    for (int i = 0; i < N; i++)
    {
        fin >> cowlineoriginal[i];
    }
    cowlineorderd = cowlineoriginal;
    sort(cowlineorderd.begin(), cowlineorderd.end());
    int ans =0;
    for (int i = 0; i < N; i++)
    {
        if (cowlineoriginal[i] != cowlineorderd[i])
        {
            for (int j = i; j < N; j++)
            {
                if (cowlineoriginal[j] == cowlineorderd[i] && cowlineoriginal[j] != cowlineorderd[j])
                {
                    swap(cowlineoriginal[i], cowlineoriginal[j]);
                    ans++;
                }
            }
        }
    }
    fout << ans << endl;
    return 0;
}