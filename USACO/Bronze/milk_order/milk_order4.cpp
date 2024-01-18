#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

bool checkHierachy(vector<int> order, vector<int> cowofPos, vector<int> &hierarchy)
{
    int iH = 0;
    for (int iO = 0; iO < order.size() && iH < hierarchy.size(); iO++)
    {
        if (cowofPos[hierarchy[iH]] != -1)
        {
            if (cowofPos[hierarchy[iH]] < iO)
            {
                return false;
            }
            iO = cowofPos[hierarchy[iH]];
            iH++;
        }
        else
        {
            while (order[iO] != -1)
            {
                iO++;
            }
            if (iO == order.size())
            {
                return false;
            }
            order[iO] = hierarchy[iH];
            cowofPos[hierarchy[iH]] = iO;
            iH++;
        }
    }
    /*
    int iOPos = 0;
    for (int iH = 0; iH < hierarchy.size(); iH++)
    {
        if (cowofPos[hierarchy[iH]] != -1)
        {
            if (cowofPos[hierarchy[iH]] < iOPos)
            {
                return false;
                break;
            }
            iOPos = cowofPos[hierarchy[iH]];
            continue;
        }
        else
        {
            for (int iO = iOPos; iO < order.size(); iO++)
            {
                if (order[iO] != -1)
                {
                    continue;
                }
                else
                {
                    order[iO] = hierarchy[iH];
                    cowofPos[hierarchy[iH]] = iO;

                    iOPos = iO + 1;
                    if (iOPos == order.size() && iH != hierarchy.size() - 1)
                    {
                        return false;
                    }
                    break;
                }
            }
        }
    }
    */
    return true;
}

int main(void)
{
    ifstream fin("milkorder.in");
    ofstream fout("milkorder.out");

    int N, M, K;
    fin >> N >> M >> K;
    vector<int> order(N, -1);
    vector<int> hierarchy(M);
    vector<int> cowofPos(N, -1);

    for (int i = 0; i < M; i++)
    {
        fin >> hierarchy[i];
        hierarchy[i]--;
    }

    for (int i = 0; i < K; i++)
    {
        int cow, pos;
        fin >> cow >> pos;
        order[--pos] = --cow;
        cowofPos[cow] = pos;

        if (cow == 0)
        {
            fout << pos + 1 << endl;
            return 0;
        }
    }

    for (int i = 0; i < order.size(); i++)
    {
        if (order[i] == -1) //  empty
        {
            order[i] = 0;
            cowofPos[0] = i;
            if (checkHierachy(order, cowofPos, hierarchy))
            {
                fout << i + 1 << endl;
                return 0;
            }
            else
            {
                order[i] = -1;
                cowofPos[0] = -1;
            }
        }
    }
}