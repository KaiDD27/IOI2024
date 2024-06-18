#include <bits/stdc++.h>

using namespace std;
int N;



void process_fields(int at, int prev, const vector<vector<int>> &fieldAdjList, vector<int> &fieldGrassType)
{
    int type_num = 1;
    for (int n : fieldAdjList[at])
    {
        if (n == prev)
            continue;

        while (type_num == fieldGrassType[at] || type_num == fieldGrassType[prev])
            type_num++;
        fieldGrassType[n] = type_num;
        process_fields(n, at, fieldAdjList, fieldGrassType);
        type_num++;
    }
}

int main()
{
    ifstream fin("planting.in");
    ofstream fout("planting.out");

    fin >> N;
    vector<vector<int>> fieldAdjList(N);
    vector<int> fieldGrassType(N);
    for (int i = 0; i < N - 1; i++)
    {
        int a, b;
        fin >> a >> b;
        fieldAdjList[--a].push_back(--b);
        fieldAdjList[b].push_back(a);
    }

    fieldGrassType[0] = 1;
    process_fields(0, 0, fieldAdjList, fieldGrassType);
    int ans = 0;
    for (int i = 0; i < fieldGrassType.size(); i++)
        ans = max(fieldGrassType[i], ans);
    fout << ans << endl;
}