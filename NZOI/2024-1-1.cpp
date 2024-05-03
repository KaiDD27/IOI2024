#include <algorithm>
#include <array>
#include <iostream>
#include <vector>

using namespace std;
using ll = long long;
#define endl "\n"
vector<int> w;
int main() {
  ios::sync_with_stdio(false); // Fast I/O
  cin.tie(nullptr); // Not safe to use cin/cout & scanf/printf together
  int n;
  cin >> n;
  w.resize(n);
  for (auto &wi : w)
    cin >> wi;
  sort(w.begin(), w.end());
  int cnt = 1;
  for (int i = 1; i < w.size(); i++) {
    if (w[i] != w[i - 1])
      cnt++;
  }
  cout << cnt << endl;
  return 0;
}