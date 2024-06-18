#include <vector>
#include <set>
#include <fstream>
#include <cmath>
#include <algorithm>
#include <iostream>

using namespace std;

int N;

int main(void)
{
    ifstream fin("hoofball.in");
    ofstream fout("hoofball.out");

    fin >> N;

    vector<int> cowpox(N, -1);
    for (int i = 0; i < N; i++)
    {
        fin >> cowpox[i];
    }
    sort(cowpox.begin(), cowpox.end());
    int ballcount = 0;
    bool flagpreviousright = true;
    int rightcount = 1;
    int leftcount = 0;
    vector<char> cowdirection(N, 'a');
    cowdirection[0] = '>';     // right
    cowdirection[N - 1] = '<'; // left

    if (N == 1 || N == 2)
    {
        fout << 1 << endl;
        return 0;
    }
    // fout << cowdirection[0] << " " << ballcount << endl;
    for (int i = 1; i < N - 1; i++)
    {
        if (flagpreviousright) // pre right
        {
            if (cowpox[i] - cowpox[i - 1] > cowpox[i + 1] - cowpox[i]) // right
            {
                rightcount++;
                cowdirection[i] = '>';
            }
            else // left
            {
                flagpreviousright = false;
                leftcount++;
                cowdirection[i] = '<';
            }
        }
        else // pre left
        {
            if (cowpox[i] - cowpox[i - 1] > cowpox[i + 1] - cowpox[i]) // right
            {
                if (rightcount > 1)
                    ballcount++;
                if (leftcount > 1)
                    ballcount++;
                if (rightcount == 1 && leftcount == 1)
                    ballcount++;
                flagpreviousright = true;
                rightcount = 1;
                leftcount = 0;
                cowdirection[i] = '>';
            }
            else // left
            {
                cowdirection[i] = '<';
                leftcount++;
            }
        }
        // fout << cowdirection[i] << " " << ballcount << endl;
    }
    leftcount++;
    if (rightcount > 1)
        ballcount++;
    if (leftcount > 1)
        ballcount++;
    if (rightcount == 1 && leftcount == 1)
        ballcount++;

    fout << ballcount << endl;
    // for (int i = 0; i < N; i++)
    //   fout << cowdirection[i] << " ";
    return 0;
}