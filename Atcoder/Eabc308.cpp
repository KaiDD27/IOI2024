// 最小非负且不等于AAA 的数 的 和
#include <algorithm>
#include <array>
#include <iostream>
#include <vector>

using namespace std;
using ll = long long;
#define endl "\n"
vector<int> a;
// 第一维是 i，第二维是 0 1 2
vector<array<ll, 3>> mPreSum, xPostSum;
ll mex(ll ai, ll aj, ll ak) {
  for (ll result = 0;; result++) {
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
  mPreSum.resize(n);
  xPostSum.resize(n);
  for (int i = 0; i < n; i++)
    cin >> a[i];
  cin >> strS;
  // 统计 M 的前缀和
  if (strS[0] == 'M')
    mPreSum[0][a[0]]++;
  for (int i = 1; i < n - 2; i++) {
    mPreSum[i] = mPreSum[i - 1];
    if (strS[i] == 'M')
      mPreSum[i][a[i]]++;
  }
  // 统计X的后缀和
  if (strS[n - 1] == 'X')
    xPostSum[n - 1][a[n - 1]]++;
  for (int i = n - 2; i > 1; i--) {
    xPostSum[i] = xPostSum[i + 1];
    if (strS[i] == 'X')
      xPostSum[i][a[i]]++;
  }
  ll sum = 0;
  // 遍历所有可能有效的e，掐头去尾
  for (int i = 1; i < n - 1; i++) {
    if (strS[i] == 'E') {
      for (int mInt = 0; mInt <= 2; mInt++) {
        for (int xInt = 0; xInt <= 2; xInt++) {
          sum += (mex(mInt, a[i], xInt) * mPreSum[i - 1][mInt] *
                  xPostSum[i + 1][xInt]);
        }
      }
    }
  }
  cout << sum << endl;
  return 0;
}