/*
http://www.usaco.org/index.php?page=viewproblem2&cpid=739
SAMPLE INPUT:
3 8
AATCCCAT
GATTGCAA
GGTCGCAA
ACTCCCAG
ACTCGCAT
ACTTCCAT
SAMPLE OUTPUT:
22
*/

#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void)
{
    ifstream cin("cownomics.in");
    ofstream cout("cownomics.out");

    int N,M;
    cin >> N >> M;
    vector<vector<int>> spotCows(N,vector<int>(M)),plainCows(N,vector<int>(M));
    for(auto & element : spotCows)
    {
        for(int i = 0;i<M;i++)
        {
            char charTemp;
            cin >> charTemp;
            switch (charTemp)
            {
                case 'A':
                    element[i] = 0;
                    break;
                case 'C':
                    element[i] = 1;
                    break;
                case 'G':
                    element[i]= 2;
                    break;
                default:
                    element[i]= 3;
            }
        }
    }
    for(auto & element : plainCows)
    {
        for(int i = 0;i<M;i++)
        {
            char charTemp;
            cin >> charTemp;
            switch (charTemp)
            {
                case 'A':
                    element[i] = 0;
                    break;
                case 'C':
                    element[i] = 1;
                    break;
                case 'G':
                    element[i]= 2;
                    break;
                default:
                    element[i]= 3;
            }
        }
    }

    vector <int> spotSets(N),plainSets(N);
    int ans = 0;
    for(int m1 = 0 ;m1<M;m1++)
    {   
        for(int m2 = m1+1;m2<M;m2++)
        {  
            for(int m3 = m2+1; m3<M;m3++)
            {  
                for(int i = 0 ;i< N ;i++)
                {
                    spotSets[i] = spotCows[i][m1]*16+spotCows[i][m2]*4+spotCows[i][m3];
                    plainSets[i] =  plainCows[i][m1]*16+plainCows[i][m2]*4+plainCows[i][m3];
                }
                bool isSets = true;
                for(auto &element1 :spotSets)
                {
                    if(isSets == false)
                        break;
                    for(auto &element2 : plainSets)
                    {
                       if(element1 == element2)
                        {
                            isSets = false;
                            break;
                        }
                    }
                }
                if(isSets == true)
                    ans++;
            }
        }
    }
    cout << ans << endl;
    
}