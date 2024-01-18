#include <vector>
#include <fstream>
#include <algorithm>

using namespace std;

void swapLine(int head, int end, vector<int> &CowsLine)
{
    while (head < end)
    {
        swap(CowsLine[head], CowsLine[end]);
        head++;
        end--;
    }
}

int N, K;
int A1, A2, B1, B2;
int main()
{
    ifstream fin("swap.in");
    ofstream fout("swap.out");

    fin >> N >> K >> A1 >> A2 >> B1 >> B2;
    vector<int> CowsLine(N + 1, 0); // 0 empty

    for (int i = 1; i <= N; i++)
    {
        CowsLine[i] = i;
    }
    int swapback = -1;
    for (int i = 1; i <= K; i++)
    {
        swapLine(A1, A2, CowsLine);
        swapLine(B1, B2, CowsLine);
        swapback = i;
        for (int j = 1; j <= N; j++)
        {
            if (CowsLine[j] != j)
            {
                swapback = -1;
                break;
            }
        }
        if (swapback != -1)
        {
            break;
        }
    }
    for (int i = 1; i <= K % swapback; i++)
    {
        swapLine(A1, A2, CowsLine);
        swapLine(B1, B2, CowsLine);
    }

    for (int j = 1; j <= N; j++)
        fout << CowsLine[j] << endl;
}