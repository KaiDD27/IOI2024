#include <fstream>
#include <vector>
#include <algorithm>
#include <map>
#include <set>

using namespace std;
int N;

void Relationship(string cowA, string cowB, map<string, string> &cowsMother)
{
}

int main()
{
    ifstream fin("family.in");
    ofstream fout("family.out");
    string cowA, cowB;
    fin >> N >> cowA >> cowB;
    map<string, string> cowsMother;
    for (int i = 0; i < N; i++)
    {
        string mother, daughter;
        fin >> mother >> daughter;
        cowsMother[daughter] = mother;
    }

    Relationship(cowA, cowB, cowsMother);

    if (cowsMother[cowA] == cowsMother[cowB])
    {
        fout << "SIBLINGS" << endl;
        return 0;
    }

    string cowAncestor = cowA;
    int g_num = 0;
    bool cowAncestorIscow = false;
    bool cowAuntIscow = false;
    while (cowsMother.count(cowAncestor) > 0)
    {
        if (cowsMother[cowAncestor] == cowB)
        {
            cowAncestorIscow = true;
            break;
        }
        if (cowsMother[cowAncestor] == cowsMother[cowB])
        {
            cowAuntIscow = true;
            break;
        }
        cowAncestor = cowsMother[cowAncestor];
        g_num++;
    }
    if (cowAncestorIscow)
    {
        fout << cowB << " is the ";
        for (; g_num > 1; g_num--)
        {
            fout << "great-";
        }
        if (g_num == 1)
        {
            fout << "grand-";
        }

        fout << "mother of " << cowA << endl;
        return 0;
    }
    else if (cowAuntIscow)
    {
        fout << cowB << " is the ";

        for (; g_num > 1; g_num--)
        {
            fout << "great-";
        }

        fout << "aunt of " << cowA << endl;
        return 0;
    }

    g_num = 0;
    cowAncestorIscow = false;
    cowAncestor = cowB;
    cowAuntIscow = false;
    while (cowsMother.count(cowAncestor) > 0)
    {
        if (cowsMother[cowAncestor] == cowA)
        {
            cowAncestorIscow = true;
            break;
        }
        if (cowsMother[cowAncestor] == cowsMother[cowA])
        {
            cowAuntIscow = true;
            break;
        }

        cowAncestor = cowsMother[cowAncestor];
        g_num++;
    }
    if (cowAncestorIscow)
    {
        fout << cowA << " is the ";
        for (; g_num > 1; g_num--)
        {
            fout << "great-";
        }
        if (g_num == 1)
        {
            fout << "grand-";
        }

        fout << "mother of " << cowB << endl;
        return 0;
    }
    else if (cowAuntIscow)
    {
        fout << cowA << " is the ";

        for (; g_num > 1; g_num--)
        {
            fout << "great-";
        }

        fout << "aunt of " << cowB << endl;
        return 0;
    }

    set<string> cowAAncestor;
    cowAncestor = cowA;
    while (cowsMother.count(cowAncestor) > 0)
    {
        cowAAncestor.insert(cowsMother[cowAncestor]);
        cowAncestor = cowsMother[cowAncestor];
    }
    cowAncestor = cowB;
    while (cowsMother.count(cowAncestor) > 0)
    {
        if (cowAAncestor.count(cowsMother[cowAncestor]) > 0)
        {
            fout << "COUSINS" << endl;
            return 0;
        }
        cowAncestor = cowsMother[cowAncestor];
    }
    fout << "NOT RELATED" << endl;

    return 0;
}