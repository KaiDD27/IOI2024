#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void)
{
    ifstream cin("measurement.in");
    ofstream cout("measurement.out");

    vector <int> Mildred(101),Elsie(101),Bessie(101);
    int N=0;
    cin >> N;
    vector <int> iDay(N),iChange(N); 
    vector <string> strCow(N);
    for(int n = 0 ;n<N;n++)
    {
        cin >> iDay[n] >> strCow[n] >> iChange[n] ;
    }
    Mildred[0]=7;
    Elsie[0]=7;
    Bessie[0]=7;
    bool boolOldMildred = true;
    bool boolOldElsie = true;
    bool boolOldBessie = true;
    bool boolMildred = true;
    bool boolElsie = true;
    bool boolBessie = true;
    int iAdjustDays = 0;
    for(int i = 1;i<= 100;i++)
    {
        Mildred[i]=Mildred[i-1];
        Elsie[i]=Elsie[i-1];
        Bessie[i]=Bessie[i-1];
        bool boolChangeDay = false;
        for(int n =0;n < N ;n++)
        {
            if(i==iDay[n])
            {
                if(strCow[n]=="Mildred")
                {
                    Mildred[i]+=iChange[n];
                }else if (strCow[n] =="Elsie")
                {
                    Elsie[i]+=iChange[n];
                }else if (strCow[n]== "Bessie")
                {
                    Bessie[i]+=iChange[n];
                }
                boolChangeDay = true;
            }
        }
        if(boolChangeDay == true)
        {
            int iMax = max(max(Mildred[i],Elsie[i]),Bessie[i]);
            if(Mildred[i]== iMax)
                boolMildred = true;
            else
                boolMildred = false;
            if(Elsie[i]== iMax)
                boolElsie =true;
            else 
                boolElsie = false;
            
            if(Bessie[i]== iMax)
                boolBessie = true;
            else 
                boolBessie = false;
            
            if(!((boolOldMildred == boolMildred)&&(boolOldElsie == boolElsie)&&(boolOldBessie == boolBessie)))
            {
                iAdjustDays++;
            }
            boolOldMildred = boolMildred;
            boolOldElsie = boolElsie;
            boolOldBessie = boolBessie;
        }
    }
    cout << iAdjustDays;
    return 0;
}