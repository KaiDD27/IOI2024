#include <vector>
#include <fstream>
#include <algorithm>

using namespace std;

int N;
int main(void)
{
    ifstream fin("breedflip.in");
    ofstream fout("breedflip.out");

    fin >> N;
    string A, B;
    fin >> A >> B;

    int curIdx = 0;
    bool matched = true;
    int ans = 0;
    while (curIdx < N)
    {
        if (A[curIdx] != B[curIdx])
        {
            if (matched == true)
            {
                ans++;
                matched = false;
            }
        }
        else
        {
            matched = true;
        }
        curIdx++;
    }
    fout << ans << endl;
}