/*
http://www.usaco.org/index.php?page=viewproblem2&cpid=687

SAMPLE INPUT:
10
Bessie 1
Maggie 13
Elsie 3
Elsie 4
Henrietta 4
Gertie 12
Daisy 7
Annabelle 10
Bessie 6
Henrietta 5
SAMPLE OUTPUT:
Henrietta
*/

#include <algorithm>
#include <fstream>
#include <map>
#include <vector>

using namespace std;

map<string,int> cow;
int M = 1e9;
vector<string> names{"Bessie",    "Elsie",  "Daisy",    "Gertie",
                     "Annabelle", "Maggie", "Henrietta"};
int secondSmallest;
int N = 0;
vector<pair<string, int>> CowMilks(names.size());
pair<string, int> cowMilk;
string strSecondName;
int count = 0;
int main(void) {
  ifstream fin("notlast.in");
  ofstream fout("notlast.out");
  fin >> N;
  if (N == 0) {
    fout << "Tie" << endl;
    return 0;
  }
  for (int i = 0; i < N; i++) {
    string name;
    int milk;
    fin >> name >> milk;
    cow[name] += milk;
  }
  for (auto& name : names) {
    M = min(cow[name], M);
    cowMilk = make_pair(name, cow[name]);
    CowMilks.push_back(cowMilk);
  }
  sort(CowMilks.begin(), CowMilks.end(),
       [](const pair<string, int>& a, const pair<string, int>& b) {
         return a.second < b.second;
       });

  for (int i = 0; i < CowMilks.size(); i++) {
    if (CowMilks[i].second > M) {
      strSecondName = CowMilks[i].first;
      if (i == CowMilks.size() - 1) {
        fout << strSecondName << endl;
        return 0;
      } else if (CowMilks[i + 1].second == CowMilks[i].second) {
        fout << "Tie" << endl;
        return 0;
      } else {
        fout << strSecondName << endl;
        return 0;
      }
    }
  }
  fout << "Tie" << endl;
  return 0;
}
