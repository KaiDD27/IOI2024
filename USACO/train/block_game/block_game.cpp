#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;

int main (void)
{
    int N = 0;
    ifstream cin("blocks.in");
    cin >> N;
    vector< vector<string> > twoWords(N,vector<string>(2));
    for(int n= 0 ;n < N ;n++)
    {
        cin >> twoWords[n][0] >> twoWords[n][1];
    }
    vector<int> charCount(26);
    char letter = 'a';
    ofstream cout("blocks.out");
    
    for(int i=0;i<26;i++)
    {
        for(int n = 0;n < N ;n++)
        {        
            charCount[i] += max(count(twoWords[n][0].begin(),twoWords[n][0].end(),letter),
                               count(twoWords[n][1].begin(),twoWords[n][1].end(),letter));
        }
        cout << charCount[i] << endl;
        letter++;
    }
}