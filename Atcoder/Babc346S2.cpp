// 直接用求MOD的话，处理边界值很麻烦，所以采用减法
#include <array>
#include <iostream>
#include <set>
#include <utility>
#include <vector>

using namespace std;
using ll = long long;
#define endl "\n"
set<pair<int, int>> setWB;
int main() {
  ios::sync_with_stdio(false); // Fast I/O
  cin.tie(nullptr); // Not safe to use cin/cout & scanf/printf together
  int w, b;
  cin >> w >> b;
  string strS = "wbwbwwbwbwbw";
  strS += strS;
  for (int start = 0; start < 12; start++) {
    for (int fin = start; fin < start + 12; fin++) {
      int wCnt = 0, bCnt = 0;
      for (int i = start; i <= fin; i++) {
        if (strS[i] == 'w')
          wCnt++;
        else
          bCnt++;
      }
      setWB.insert({wCnt, bCnt});
    }
  }
  int wMOD = 7, bMOD = 5;
  int wTmp = w, bTmp = b;
  while (wTmp >= 0 && bTmp >= 0) {
    if (setWB.count({wTmp, bTmp})) {
      cout << "Yes" << endl;
      return 0;
    }
    wTmp -= wMOD;
    bTmp -= bMOD;
  }
  cout << "No" << endl;
  return 0;
}