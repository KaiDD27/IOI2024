#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;
using ll = long long; // 使用ll作为long long的别名
#define endl "\n"
const int MOD = 1e9 + 7; // 定义模数为1e9 + 7

int main() {
  int n, q;
  cin >> n >> q;
  vector<ll> height(n + 1); // 存储松果height
  for (int i = 1; i <= n; i++)
    cin >> height[i];
  sort(height.begin(), height.end());
  vector<ll> throwsSuffixSum(n + 2);    // 当前松果throws 的后缀和
  vector<ll> heightsSuffixSum(n + 2);   // 当前松果heights后缀和
  vector<ll> pineconesSuffixSum(n + 2); // 当前松果数量的后缀和
  for (int i = n; i >= 1; i--) {
    pineconesSuffixSum[i] = pineconesSuffixSum[i + 1] + 1;
    throwsSuffixSum[i] = throwsSuffixSum[i + 1] +
                         pineconesSuffixSum[i] * (height[i] - height[i - 1]);
    heightsSuffixSum[i] =
        pineconesSuffixSum[i] *
        ((height[i] + height[i - 1] + 1) * (height[i] - height[i - 1]) / 2) %
        MOD;
    heightsSuffixSum[i] = (heightsSuffixSum[i] + heightsSuffixSum[i + 1]) % MOD;
  }
  throwsSuffixSum[0] = throwsSuffixSum[1];
  heightsSuffixSum[0] = heightsSuffixSum[1];
  for (int i = 0; i < q; i++) {
    ll t;
    cin >> t;
    if (t > throwsSuffixSum[0]) {
      cout << heightsSuffixSum[0] << endl;
    } else {
      int lo_x = 0, hi_x = n + 1;
      while (lo_x != hi_x) {
        int m = (lo_x + hi_x) / 2;
        if (throwsSuffixSum[m] <= t)
          hi_x = m;
        else
          lo_x = m + 1;
      }
      int x = lo_x;
      ll remaining = t - throwsSuffixSum[x];
      ll num_pinecones = pineconesSuffixSum[x] + 1;
      ll base_height = height[x - 1];
      ll full_lines = remaining / num_pinecones;
      ll full_lines_extra =
          num_pinecones *
          ((base_height + base_height - full_lines + 1) * full_lines / 2) % MOD;

      ll rem = remaining % num_pinecones;
      ll ans = (heightsSuffixSum[x] % MOD + full_lines_extra +
                (rem * (base_height - full_lines)) % MOD) %
               MOD;
      cout << ans << endl;
    }
  }
  return 0;
}