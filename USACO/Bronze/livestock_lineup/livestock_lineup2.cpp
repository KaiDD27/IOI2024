#include <algorithm>
#include <fstream>
#include <map>
#include <string>
#include <vector>

using namespace std;

vector<string> cowsName{"Bessie", "Buttercup", "Belinda", "Beatrice", "Bella", "Blue", "Betsy", "Sue"};
map<string, vector<string>> neighbors;
map<string, bool> added;
vector<string> order;
int N;
int main()
{
    ifstream fin("lineup.in");
    ofstream fout("lineup.out");
    sort(cowsName.begin(), cowsName.end());
    fin >> N;
    for (int r = 0; r < N; r++)
    {
        string cow1;
        string cow2;
        string trash;
        fin >> cow1 >> trash >> trash >> trash >> trash >> cow2;

        // insert into neighbors
        neighbors[cow1].push_back(cow2);
        neighbors[cow2].push_back(cow1);
    }

    // 初始化 added
    for (string cow : cowsName)
    {
        added[cow] = false;
    }

    for (int c = 0; c < cowsName.size(); c++)
    {
        if (!added[cowsName[c]] && neighbors[cowsName[c]].size() <= 1)
        {
            added[cowsName[c]] = true;
            order.push_back(cowsName[c]);

            if (neighbors[cowsName[c]].size() == 1)
            {
                string prev = cowsName[c];
                string at = neighbors[cowsName[c]][0];
                while (neighbors[at].size() == 2)
                {
                    added[at] = true;
                    order.push_back(at);

                    string a = neighbors[at][0];
                    string b = neighbors[at][1];
                    string temp_at = a == prev ? b : a;
                    prev = at;
                    at = temp_at;
                }
                added[at] = true;
                order.push_back(at);
            }
        }
    }

    ofstream out("lineup.out");
    for (string c : order)
    {
        out << c << endl;
    }
}