#include <bits/stdc++.h>
using namespace std;

const int MAX_N = 10000;

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

vector<int> grass_type;
vector<vector<int>> neighbors;

void process_fields(int at, int prev)
{
    // Start with grass type 1.
    int type_num = 1;
    for (int n : neighbors[at])
    {
        if (n == prev)
        {
            continue;
        }
        // While the current grass type is being used, increment it.
        while (type_num == grass_type[at] || type_num == grass_type[prev])
        {
            type_num++;
        }

        // Set the grass type for the neighboring field.
        grass_type[n] = type_num;

        // Recursively color the other fields.
        process_fields(n, at);

        // We can't use this grass type again.
        type_num++;
    }
}

int main()
{
    setIO("planting");

    int field_num;
    cin >> field_num;

    grass_type = vector<int>(field_num);
    neighbors = vector<vector<int>>(field_num);
    for (int f = 0; f < field_num - 1; f++)
    {
        int field1, field2;
        cin >> field1 >> field2;
        neighbors[--field1].push_back(--field2);
        neighbors[field2].push_back(field1);
    }

    // Set our starting field to be type 1.
    grass_type[0] = 1;
    process_fields(0, 0);

    int min_type = 0;
    for (int t : grass_type)
    {
        min_type = max(min_type, t);
    }

    cout << min_type << endl;
}