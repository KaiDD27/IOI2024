#include <bits/stdc++.h>
using namespace std;

// FastIO: see General -> Fast Input and Output
void setIO(string name = "")
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    if (!name.empty())
    {
        freopen((name + ".in").c_str(), "r", stdin);
        freopen((name + ".out").c_str(), "w", stdout);
    }
}

int main()
{
    setIO("planting");

    int field_num;
    cin >> field_num;

    vector<int> deg(field_num + 1); // 1-indexed
    for (int p = 0; p < field_num - 1; p++)
    {
        int field1, field2;
        cin >> field1 >> field2;

        deg[field1]++;
        deg[field2]++;
    }

    int max_deg = 0;
    for (int f = 1; f <= field_num; f++)
    {
        max_deg = max(max_deg, deg[f]);
    }

    cout << max_deg + 1 << endl;
}