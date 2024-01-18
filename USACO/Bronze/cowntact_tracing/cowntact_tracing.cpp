/*
http://www.usaco.org/index.php?page=viewproblem2&cpid=1037&lang=en
SAMPLE INPUT:
4 3
1100
7 1 2
5 2 3
6 2 4
SAMPLE OUTPUT:
1 1 Infinity
*/
#include <fstream>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int main(void)
{
    ifstream fin("tracing.in");
    ofstream fout("tracing.out");
    int N,T;
    fin >> N >> T;
    string strInfectCow;
    fin >> strInfectCow;
    
    vector<vector<int>> Shake(T,vector<int>(3));
    for(auto & element :Shake)
    {
        fin >> element[0] >> element[1] >> element[2];
    }

    sort(Shake.begin(),Shake.end(),[](const vector<int> &a ,const vector<int> &b){return a[0]<b[0];});

    vector <int> infectSmallKCows(N);
    
    int smallK = -1;
    int bigK = -1;
    int zeroPcount = 0;
    for(int n = 0;n<N;n++)
    {
        if(strInfectCow[n]=='0')
            continue;

        bool boolZeroP = false;
        for(int k=0;k<=T;k++)
        {
            string strTempInfectCow(N,'0');
            strTempInfectCow[n]='1';
            for(auto & element : infectSmallKCows)
            {
                element = 0;
            }
            infectSmallKCows[n] = k;

            for(auto &element :Shake)
            {
                int a = element[1]-1,b = element[2]-1;
                if(strTempInfectCow[a]=='1'&&strTempInfectCow[b]=='0')
                {
                    if(infectSmallKCows[a]>0)
                    {
                        strTempInfectCow[b] = '1';
                        infectSmallKCows[b] = k;
                        infectSmallKCows[a]--;
                    }                    
                }
                else if(strTempInfectCow[a]=='0'&&strTempInfectCow[b]=='1')
                {
                    if(infectSmallKCows[b]>0)
                    {
                        strTempInfectCow[a] = '1';
                        infectSmallKCows[a] = k;
                        infectSmallKCows[b]--;
                    }   
                }
                else if(strTempInfectCow[a]=='1'&&strTempInfectCow[b]=='1')
                {
                    if(infectSmallKCows[a]>0)
                    { 
                        infectSmallKCows[a]--;
                    } 
                    if(infectSmallKCows[b]>0)
                    {
                        infectSmallKCows[b]--;
                    } 
                }
            }
            if(strTempInfectCow == strInfectCow)
            {
                boolZeroP = true;
                if(smallK == -1)
                {   
                    smallK =k;
                    bigK = k;
                }
                else 
                {
                    smallK = min(smallK,k);
                    bigK = max(bigK,k);
                }
            }   
        }
        if(boolZeroP == true)
        {
            zeroPcount++;
        }
        
    }

    fout << zeroPcount << " " << smallK << " ";
    if(bigK == T)
        fout << "Infinity";
    else 
        fout << bigK;
    
    return 0 ;

}