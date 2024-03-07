#include <algorithm>
#include <iostream>
#include <set>
#include <vector>

using namespace std;
using ll = long long;
#define endl '\n'

multiset<int> msSmall, msLarge;
vector<int> x;
int main() {
  ios::sync_with_stdio(false); // Fast I/O
  cin.tie(nullptr); // Not safe to use cin/cout & scanf/printf together
  int n, k;
  cin >> n >> k;
  x.resize(n);
  for (auto &xi : x)
    cin >> xi;
  if (k == 1) {
    for (int i = 0; i < n; i++) {
      cout << 0 << " ";
    }
    return 0;
  }
  vector<int> vTemp(x.begin(), x.begin() + k);
  int median = 0;
  sort(vTemp.begin(), vTemp.end());
  if (k % 2 == 0) {
    msSmall.insert(vTemp.begin(), vTemp.begin() + k / 2);
    msLarge.insert(vTemp.begin() + k / 2, vTemp.end());
  } else {
    msSmall.insert(vTemp.begin(), vTemp.begin() + k / 2 + 1);
    msLarge.insert(vTemp.begin() + k / 2 + 1, vTemp.end());
  }
  median = *msSmall.rbegin();
  ll sumSmall = 0, sumLarge = 0;
  for (auto si : msSmall)
    sumSmall += si;
  for (auto bi : msLarge)
    sumLarge += bi;
  ll cost = 0;
  if (k % 2 == 0)
    cost = sumLarge - sumSmall;
  else
    cost = sumLarge - sumSmall + median;
  cout << cost << " ";
  for (int r = k; r < n; r++) {
    int l = r - k;
    auto it = msSmall.find(
        x[l]); // multiset
               // 里面尽量不要用count来判断是否存在，因为如果重复元素太多，太耗时间
    if (it != msSmall.end()) {
      msSmall.erase(it);
      sumSmall -= x[l];
    } else {
      msLarge.erase(msLarge.find(x[l]));
      sumLarge -= x[l];
    }

    if (!msSmall.empty() && x[r] <= *msSmall.rbegin()) {
      msSmall.insert(x[r]);
      sumSmall += x[r];
    } else {
      msLarge.insert(x[r]);
      sumLarge += x[r];
    }

    if (msLarge.size() > k / 2) {
      msSmall.insert(*msLarge.begin());
      sumSmall += *msLarge.begin();
      sumLarge -= *msLarge.begin();
      msLarge.erase(msLarge.begin());
    } else if (msLarge.size() < k / 2) {
      msLarge.insert(*msSmall.rbegin());
      sumLarge += *msSmall.rbegin();
      sumSmall -= *msSmall.rbegin();
      msSmall.erase(prev(msSmall.end()));
    }
    median = *msSmall.rbegin();
    if (k % 2 == 0)
      cost = sumLarge - sumSmall;
    else
      cost = sumLarge - sumSmall + median;
    cout << cost << " ";
  }
  return 0;
}