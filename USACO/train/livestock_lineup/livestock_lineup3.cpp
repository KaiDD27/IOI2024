#include <algorithm>
#include <fstream>
#include <map>
#include <string>
#include <vector>

using namespace std;

vector<string> cowsSortedName{"Bessie", "Buttercup", "Belinda", "Beatrice", "Bella", "Blue", "Betsy", "Sue"};
map<string, int> cowsName;
map<int, vector<int>> neighbors;
vector<bool> added;
vector<string> order;
int N;

int main()
{
    ifstream fin("lineup.in");
    ofstream fout("lineup.out");

    // Sort the cow names in alphabetical order
    sort(cowsSortedName.begin(), cowsSortedName.end());

    // Initialize the added vector
    added.resize(cowsSortedName.size(), false);

    // Initialize the cowsName map
    for (int i = 0; i < cowsSortedName.size(); i++)
    {
        cowsName[cowsSortedName[i]] = i;
    }

    // Read the number of cows from the input file
    fin >> N;

    // Process the input data
    for (int r = 0; r < N; r++)
    {
        string cow1, cow2, trash;
        fin >> cow1 >> trash >> trash >> trash >> trash >> cow2;

        // Insert into neighbors map
        neighbors[cowsName[cow1]].push_back(cowsName[cow2]);
        neighbors[cowsName[cow2]].push_back(cowsName[cow1]);
    }

    // Find the cows that should be added to the order vector
    for (int c = 0; c < cowsName.size(); c++)
    {
        if (!added[c] && neighbors[c].size() <= 1)
        {
            added[c] = true;
            order.push_back(cowsSortedName[c]);

            if (neighbors[c].size() == 1)
            {
                int prev = c;
                int at = neighbors[c][0];

                // Add the neighbors to the order vector
                while (neighbors[at].size() == 2)
                {
                    added[at] = true;
                    order.push_back(cowsSortedName[at]);
                    int temp = at;
                    at = prev == neighbors[at][0] ? neighbors[at][1] : neighbors[at][0];
                    prev = temp;
                }

                added[at] = true;
                order.push_back(cowsSortedName[at]);
            }
        }
    }

    // Write the cow names in the order vector to the output file

    for (string c : order)
    {
        fout << c << endl;
    }
}