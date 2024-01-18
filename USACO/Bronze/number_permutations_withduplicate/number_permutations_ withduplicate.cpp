#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

string s;
vector<string> perms;
vector<int> int_count;

void search(const string &curr = "")
{
    if(curr.size() == s.size())
    {
        perms.push_back(curr);
        return;
    }
    for(int i = 0;i<int_count.size();i++)
    {
        if(int_count[i]> 0)
        {
            int_count[i]--;
            search(curr+(char)(i+'1'));
            int_count[i]++;
        }
    }
}

int main(void) {
    cin >> s;
    sort(s.begin(),s.end());
    int_count.resize(s[s.size()-1]-'0');
    for(auto & i:s) 
    {
        int_count[i-'1']++;
    }

    search();

    cout << perms.size() << '\n';
    for(const auto &perm : perms)
    {
        cout << perm << '\n';
    }
    return 0;
}