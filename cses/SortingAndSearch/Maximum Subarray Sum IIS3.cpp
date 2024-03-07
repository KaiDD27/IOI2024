#include <algorithm>
#include <functional>
#include <iostream>
#include <queue>
#include <unordered_map>
#include <vector>

using namespace std;
using ll = long long;
#define endl '\n'
vector<int> x;
vector<ll> preSum;
// 优先队列是最快的，因为不需要整体排序
priority_queue<ll, vector<ll>, greater<ll>> prPreSum;
// unordered_map插入查询时间复杂度是 O(1)
unordered_map<ll, int> umpPreSumDel;
int main() {
  ios::sync_with_stdio(false); // Fast I/O
  cin.tie(nullptr); // Not safe to use cin/cout & scanf/printf together
  int n, a, b;
  ll ans = -1e17;
  cin >> n >> a >> b;
  x.resize(n + 1);
  preSum.resize(n + 1);
  for (ll i = 1, sum = 0; i <= n; i++) {
    cin >> x[i];
    sum += x[i];
    preSum[i] = sum;
  }
  for (int l = 0, r = a; r <= n; r++) {
    prPreSum.push(preSum[r - a]);
    if (l < r - b) {
      umpPreSumDel[preSum[l]]++;
      while (!prPreSum.empty()) {
        if ((umpPreSumDel[prPreSum.top()]) > 0) {
          umpPreSumDel[prPreSum.top()]--;
          prPreSum.pop();
        } else
          break;
      }
      l++;
    }
    ans = max(ans, preSum[r] - prPreSum.top());
  }
  cout << ans << endl;
  return 0;
}