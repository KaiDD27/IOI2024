#include <algorithm>
#include <iostream>
#include <utility>
using namespace std;
typedef long long ll;
#define endl '\n'

vector<pair<int, int>> x;
int main() {
  int ans = 1, n;
  cin >> n;
  x.resize(n);
  for (int i = 0; i < n; i++) {
    cin >> x[i].first;
    x[i].second = i;
  }
  sort(x.begin(), x.end());
  for (int i = 1; i < n; i++) {
    if (x[i].second < x[i - 1].second) // 统计连续value 中的逆序对
      ans++;
  }
  cout << ans << endl;
  return 0;
}