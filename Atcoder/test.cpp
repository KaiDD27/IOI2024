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
  int wQuotient = w / wMOD, bQuotient = b / bMOD;
  int wRemain = w % wMOD, bRemain = b % bMOD;
  bool flag = "No";
  if (wRemain != 0 && bRemain != 0) {
    if (wQuotient != bQuotient) {
      flag = false;
    } else if (setWB.count({wRemain, bRemain})) {
      flag = true;
    }
  } else if (wRemain == 0 && bRemain == 0) {
    if (wQuotient == bQuotient) {
      flag = true;
    } else {
      flag = false;
    }
  } else if (wRemain == 0) {
    if (wQuotient > bQuotient) {
      if (setWB.count({wMOD, bRemain})) {
        flag = true;
      } else {
        flag = false;
      }
    } else if (wQuotient == bQuotient) {
      if (setWB.count({0, bRemain})) {
        flag = true;
      } else {
        flag = false;
      }
    }
  } else if (bRemain == 0) {
    if (bQuotient > wQuotient) {
      if (setWB.count({wRemain, bMOD})) {
        flag = true;
      } else {
        flag = false;
      }
    } else if (bQuotient == wQuotient) {
      if (setWB.count({wRemain, 0})) {
        flag = true;
      } else {
        flag = false;
      }
    }
  }
  if (flag == true)
    cout << "Yes" << endl;
  else
    cout << "No" << endl;
  return 0;
}