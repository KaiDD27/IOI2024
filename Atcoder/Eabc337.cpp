#include <algorithm>
#include <array>
#include <bitset>
#include <iostream>
#include <vector>

using namespace std;
using ll = long long;
#define endl "\n"

int main() {

  int n;
  cin >> n;
  int tmpN = n - 1;
  int m = 0;
  while (tmpN > 0) {
    tmpN /= 2;
    m++;
  }
  cout << m << endl;
  for (int i = 0; i < m; i++) {
    int juiceCnt = 0;
    for (int j = 0; j < n; j++) {
      if (j & (1 << i))
        juiceCnt++;
    }
    cout << juiceCnt << " ";
    for (int j = 0; j < n; j++) {
      if (j & (1 << i))
        cout << j + 1 << " ";
    }
    cout << endl;
  }
  string strS;
  cin >> strS;
  reverse(strS.begin(), strS.end());
  bitset<7> b(strS);
  cout << b.to_ulong() + 1 << endl;

  return 0;
}