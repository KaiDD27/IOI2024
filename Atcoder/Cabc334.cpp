#include <algorithm>
#include <array>
#include <iostream>
#include <vector>

using namespace std;
using ll = long long;
#define endl "\n"
vector<ll> preSumWeirdness;
vector<ll> suffixSumWeirdness;
vector<ll> a;
int main() {
  ios::sync_with_stdio(false); // Fast I/O
  cin.tie(nullptr); // Not safe to use cin/cout & scanf/printf together
  ll n, k;
  cin >> n >> k;
  a.resize(k);
  for (auto &ai : a)
    cin >> ai;
  ll totalWeirdness = 0;
  if (k % 2 == 0) {
    for (int i = 0; i + 1 < k; i = i + 2) {
      totalWeirdness += (a[i + 1] - a[i]);
    }
    cout << totalWeirdness << endl;
    return 0;
  }
  if (k == 1) {
    cout << totalWeirdness << endl;
    return 0;
  }
  preSumWeirdness.resize(k);
  for (int i = 0; i < k; i++) {
    if (i == 1) {
      preSumWeirdness[i] = a[i] - a[i - 1];
    } else if (i % 2 == 1) {
      preSumWeirdness[i] = preSumWeirdness[i - 2] + a[i] - a[i - 1];
    }
  }
  suffixSumWeirdness.resize(k);
  for (int i = k - 1; i >= 0; i--) {
    if (i == k - 2) {
      suffixSumWeirdness[i] = a[i + 1] - a[i];
    } else if (i % 2 == 1) {
      suffixSumWeirdness[i] = suffixSumWeirdness[i + 2] + a[i + 1] - a[i];
    }
  }
  ll ans = 0;
  for (int i = 0; i < k; i = i + 2) {
    if (i == 0) {
      ans = suffixSumWeirdness[1];
      continue;
    }
    if (i == k - 1) {
      ans = min(ans, preSumWeirdness[k - 2]);
      continue;
    }
    ans = min(ans, preSumWeirdness[i - 1] + suffixSumWeirdness[i + 1]);
  }
  cout << ans << endl;
  return 0;
}