#include <bits/stdc++.h>
using namespace std;

int N, M, K;

/**
 * @return whether it's possible to construct a
 * valid ordering with given fixed elements
 */
bool check(vector<int> order, vector<int> &hierarchy)
{
    vector<int> cow_to_pos(N, -1);

    for (int i = 0; i < N; i++)
    {
        if (order[i] != -1)
        {
            cow_to_pos[order[i]] = i;
        }
    }

    int h_idx = 0;
    for (int i = 0; i < N && h_idx < M; i++)
    {
        if (cow_to_pos[hierarchy[h_idx]] != -1)
        {
            // we know the next cow has to be in front of it

            if (i > cow_to_pos[hierarchy[h_idx]])
            {
                return false;
            }

            i = cow_to_pos[hierarchy[h_idx]];
            h_idx++;
        }
        else
        {
            while (i < N && order[i] != -1)
            {
                i++;
            }

            // run out of places
            if (i == N)
            {
                return false;
            }

            order[i] = hierarchy[h_idx];
            cow_to_pos[hierarchy[h_idx]] = i;
            h_idx++;
        }
    }

    return true;
}

int main()
{
    freopen("milkorder.in", "r", stdin);
    freopen("milkorder.out", "w", stdout);
    cin >> N >> M >> K;

    vector<int> hierarchy(M);
    for (int i = 0; i < M; i++)
    {
        cin >> hierarchy[i];
        hierarchy[i]--;
    }

    vector<int> order(N, -1);

    for (int i = 0; i < K; i++)
    {
        int cow, pos;
        cin >> cow >> pos;

        order[--pos] = --cow;

        if (cow == 0)
        { // already fixed, nothing we can do
            cout << pos + 1 << endl;
            return 0;
        }
    }

    for (int i = 0; i < N; i++)
    {
        // if already fixed, skip
        if (order[i] == -1)
        {
            // try placing cow 1 @ position i
            order[i] = 0;
            if (check(order, hierarchy))
            {
                cout << i + 1 << endl;
                break;
            }
            order[i] = -1;
        }
    }
}