#include <vector>
#include <fstream>
#include <algorithm>

using namespace std;

struct Cow
{
    Cow *a;
    Cow *b;
    int label;
};

int N, K;
int A1, A2, B1, B2;
int main()
{
    ifstream fin("swap.in");
    ofstream fout("swap.out");

    fin >> N >> K >> A1 >> A2 >> B1 >> B2;

    vector<Cow> Cows(N + 1);
    Cow *beforeHeadCow = &Cows[1];
    Cow *afterEndCow = &Cows[N];
    Cows[1].label = 1;
    Cows[1].a = beforeHeadCow;
    Cows[1].b = &Cows[2];
    Cows[N].label = N;
    Cows[N].a = &Cows[N - 1];
    Cows[N].b = afterEndCow;
    for (int i = 2; i <= N - 1; i++)
    {
        Cows[i].label = i;
        Cows[i].a = &Cows[i - 1];
        Cows[i].b = &Cows[i + 1];
    }

    for(int i = 0;i<K;i++)
    {
        
    }
}