// 最小非负且不等于AAA 的数 的 和
#include <array>
#include <iostream>
#include <vector>

using namespace std;
using ll = long long;
#define endl "\n"
vector<int> a;
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
  for (int i = 0; i < n; i++)
    cin >> a[i];
  cin >> strS;
  int sum = 0;
  for (int i = 0; i < n; i++) {
    if (strS[i] != 'M')
      continue;
    for (int j = i + 1; j < n; j++) {
      if (strS[j] != 'E')
        continue;
      for (int k = j + 1; k < n; k++) {
        if (strS[k] != 'X')
          continue;
        sum += mex(a[i], a[j], a[k]);
      }
    }
  }
  cout << sum << endl;
  return 0;
}