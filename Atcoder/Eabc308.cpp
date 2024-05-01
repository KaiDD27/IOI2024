// 最小非负且不等于AAA 的数 的 和
#include <algorithm>
#include <array>
#include <iostream>
#include <vector>

using namespace std;
using ll = long long;
#define endl "\n"
vector<int> a;
// 第一维是 1-n，第二维是 m e x，第三维是 0 1 2
vector<array<array<ll, 3>, 3>> mexCharPreSum;
int mex(int ai, int aj, int ak) {
  for (int result = 0;; result++) {
    if (result != ai && result != aj && result != ak)
      return result;
  }
}
int main() {
  ios::sync_with_stdio(false); // Fast I/O
  cin.tie(nullptr); // Not safe to use cin/cout & scanf/printf together
  int n;
  cin >> n;
  string strS;
  a.resize(n);
  mexCharPreSum.resize(n);
  for (int i = 0; i < n; i++)
    cin >> a[i];
  cin >> strS;
  ll sum = 0;
  switch (strS[0]) {
  case 'M':
    mexCharPreSum[0][0][a[0]]++;
    break;
  case 'E':
    mexCharPreSum[0][1][a[0]]++;
    break;
  case 'X':
    mexCharPreSum[0][2][a[0]]++;
    break;
  }
  for (int i = 1; i < n; i++) {
    mexCharPreSum[i] = mexCharPreSum[i - 1];
    switch (strS[i]) {
    case 'M':
      mexCharPreSum[i][0][a[i]]++;
      break;
    case 'E':
      mexCharPreSum[i][1][a[i]]++;
      break;
    case 'X':
      mexCharPreSum[i][2][a[i]]++;
      break;
    }
  }

  // 遍历所有可能有效的e，掐头去尾
  array<ll, 3> xSum = mexCharPreSum[n - 1][2];
  for (int i = 1; i < n - 1; i++) {
    if (strS[i] == 'E') {
      array<ll, 3> mBefore = mexCharPreSum[i - 1][0];
      array<ll, 3> xBefore = mexCharPreSum[i - 1][2];
      vector<bool> minInt(4, false);
      for (int mInt = 0; mInt <= 2; mInt++) {
        for (int xInt = 0; xInt <= 2; xInt++) {
          fill(minInt.begin(), minInt.end(), false);
          minInt[a[i]] = true;
          minInt[mInt] = true;
          minInt[xInt] = true;
          for (int j = 0; j < 4; j++) {
            if (minInt[j] == false) {
              sum += (j * mBefore[mInt] * (xSum[xInt] - xBefore[xInt]));
              break;
            }
          }
        }
      }
    }
  }
  cout << sum << endl;
  return 0;
}