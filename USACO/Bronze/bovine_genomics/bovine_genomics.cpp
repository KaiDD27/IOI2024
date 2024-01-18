/*
http://www.usaco.org/index.php?page=viewproblem2&cpid=736
SAMPLE INPUT:
3 8
AATCCCAT
GATTGCAA
GGTCGCAA
ACTCCCAG
ACTCGCAT
ACTTCCAT
SAMPLE OUTPUT:
1
*/
#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;

int N,M;

bool explain(vector <vector<char>> &spotNomics ,vector <vector<char>> &plainNomics,int m, char c)
{
    bool existSpot = false ;
    bool existPlain = false;
    for(int n = 0;n < N;n++)
    {
        
        if(spotNomics[n][m]== c)
            existSpot = true;
        if(plainNomics[n][m]== c)
            existPlain = true;
    }
    
    return !(existSpot && existPlain);  
}

int main(void)
{
    ifstream cin("cownomics.in");
    ofstream cout("cownomics.out");
    
    cin >> N >> M;
    vector <vector<char>> spotNomics(N,vector<char>(M)),plainNomics(N,vector<char>(M));
    for(auto &element :spotNomics)
    {
        for(int i = 0 ;i<M ;i++)
        {
            cin >> element[i];
        }
    }
    for(auto &element :plainNomics)
    {
        for(int i = 0 ;i<M ;i++)
        {
            cin >> element[i];
        }
    }
    int ans = 0;
    for(int m = 0;m<M;m++)
    {
        if(explain(spotNomics,plainNomics,m,'A')&&explain(spotNomics,plainNomics,m,'C')&&explain(spotNomics,plainNomics,m,'G')&&explain(spotNomics,plainNomics,m,'T'))
            ans++;
    }
    cout << ans << endl;
}