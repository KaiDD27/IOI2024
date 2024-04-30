#include <algorithm>
#include <array>
#include <compare>
#include <iostream>
#include <utility>
#include <vector>

using namespace std;
using ll = long long;
#define endl "\n"
vector<pair<long double, int>> rate;
int main() {
  ios::sync_with_stdio(false); // Fast I/O
  cin.tie(nullptr); // Not safe to use cin/cout & scanf/printf together
  int n;
  cin >> n;
  rate.resize(n);
  for (int i = 0; i < n; i++) {
    long double a, b;
    cin >> a >> b;
    rate[i].first = -(a / (a + b));
    rate[i].second = i;
  }
  sort(rate.begin(), rate.end());
  for (auto ri : rate)
    cout << ri.second + 1 << " ";

  return 0;
}