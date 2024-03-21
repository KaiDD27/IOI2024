#include <algorithm>
#include <array>
#include <iostream>
#include <set>
#include <vector>
using namespace std;
using ll = long long;
#define endl '\n'
vector<array<int, 3>> leftAsc;
const int LEFT = 0;
const int RIGHT = 1;
const int INDEX = 2;
int main() {
  ios::sync_with_stdio(false); // Fast I/O
  cin.tie(nullptr); // Not safe to use cin/cout & scanf/printf together
  int n;
  cin >> n;
  leftAsc.resize(n);
  vector<int> isContained(n, 0), containsOther(n, 0);
  for (int i = 0; i < n; i++) {
    cin >> leftAsc[i][LEFT] >> leftAsc[i][RIGHT];
    leftAsc[i][INDEX] = i;
  }

  sort(leftAsc.begin(), leftAsc.begin() + n,
       [&](array<int, 3> a, array<int, 3> b) {
         return a[LEFT] == b[LEFT] ? a[RIGHT] > b[RIGHT] : a[LEFT] < b[LEFT];
       });

  multiset<int> ms;

  for (int i = n - 1; i >= 0; i--) {
    int right = leftAsc[i][RIGHT], index = leftAsc[i][INDEX];
    // distance 是线性时间，所以可能是 O（n）
    containsOther[index] = distance(ms.begin(), ms.upper_bound(right));
    ms.insert(right);
  }

  ms.clear();

  for (int i = 0; i < n; i++) {
    int right = leftAsc[i][RIGHT], index = leftAsc[i][INDEX];
    isContained[index] = distance(ms.lower_bound(right), ms.end());
    ms.insert(right);
  }

  for (auto ans : containsOther)
    cout << ans << " ";
  cout << endl;
  for (auto ans : isContained)
    cout << ans << " ";
  return 0;
}