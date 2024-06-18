#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <cmath>

int N = 0;
using namespace std;
int main()
{
    cin >> N;
    string strFEB;
    cin >> strFEB;
    int countF = count(strFEB.begin(), strFEB.end(), 'F');
    set<int> mySet;
    for (int i = 0; i < (1 << countF); i++)
    {
        int bitmasks = i;
        string strTemp = strFEB;
        for (int s = 0, j = 0; s < strTemp.size() && j <= countF; s++)
        {
            if (strTemp[s] == 'F')
            {
                if (bitmasks >> j & 1)
                    strTemp[s] = 'B';
                else
                    strTemp[s] = 'E';
                j++;
            }
        }
        int excitecount = 0;
        for (size_t n = 1; n < strTemp.size(); n++)
        {
            if (strTemp[n] == strTemp[n - 1])
                excitecount++;
        }
        mySet.insert(excitecount);
        // cout << strTemp << endl;
    }
    cout << mySet.size() << endl;
    for (auto set : mySet)
    {
        cout << set << endl;
    }
}