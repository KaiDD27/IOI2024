#include <array>
#include <iostream>
#include <vector>

using namespace std;
using ll = long long;
#define endl "\n"
vector<string> a, b;
int main() {
  ios::sync_with_stdio(false); // Fast I/O
  cin.tie(nullptr); // Not safe to use cin/cout & scanf/printf together
  int n;
  cin >> n;
  a.resize(n);
  b.resize(n);
  for (auto &ai : a)
    cin >> ai;
  for (auto &bi : b)
    cin >> bi;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      if (a[i][j] != b[i][j]) {
        cout << i + 1 << " " << j + 1 << endl;
        return 0;
      }
    }
  }
  return 0;
}