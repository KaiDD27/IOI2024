#include <array>
#include <iostream>
#include <map>
#include <vector>

using namespace std;
using ll = long long;
#define endl "\n"
map<char, int> mpTeaToId;
map<string, vector<int>> mpNameToPantry;
vector<string> names;
vector<int> teaDemandCnt(6, 0);
int main() {
  ios::sync_with_stdio(false); // Fast I/O
  cin.tie(nullptr); // Not safe to use cin/cout & scanf/printf together
  int n, k;
  cin >> n >> k;
  mpTeaToId['G'] = 0;
  mpTeaToId['C'] = 1;
  mpTeaToId['E'] = 2;
  mpTeaToId['P'] = 3;
  mpTeaToId['L'] = 4;
  mpTeaToId['S'] = 5;
  for (int i = 0; i < n; i++) {
    string strName;
    char chTea;
    cin >> strName >> chTea;
    teaDemandCnt[mpTeaToId[chTea]]++;
  }
  for (int i = 0; i < n; i++) {
    string strName;
    vector<int> pantry(6, 0);
    cin >> strName;
    for (auto &pi : pantry)
      cin >> pi;
    mpNameToPantry[strName] = pantry;
  }
  names.resize(k);
  for (auto &ni : names)
    cin >> ni;

  for (auto ni : names) {
    int failCnt = 0;
    auto pantry = mpNameToPantry[ni];
    for (int i = 0; i < 6; i++) {
      pantry[i] -= teaDemandCnt[i];
    }
    for (auto pi : pantry) {
      if (pi < 0)
        failCnt += (-pi);
    }
    cout << ni << " ";
    if (failCnt == 0)
      cout << "Successful" << endl;
    else if (failCnt <= 2)
      cout << "Mildly Successful (" << failCnt << ")" << endl;
    else
      cout << "Disaster (" << failCnt << ")" << endl;
  }
  return 0;
}