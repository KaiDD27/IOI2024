#include <algorithm>
#include <iostream>
#include <utility>
#include <vector>

using namespace std;
using ll = long long;
#define endl '\n'
vector<pair<int, int>> task; // first为a,second为d
// ∑R=∑D−∑A−∑S，D 和 A 都已知，所以S 最小，则 R 最大。
int main() {
  ios::sync_with_stdio(false); // Fast I/O
  cin.tie(nullptr); // Not safe to use cin/cout & scanf/printf together
  ll n;
  cin >> n;
  task.resize(n);
  for (auto &t : task) { // 一定要带&，否则只是操作副本，无法复制
    cin >> t.first >> t.second;
  }
  sort(task.begin(), task.end());
  ll sumR = 0;
  ll start = 0;
  for (auto t : task) {
    start += t.first;
    sumR += (t.second - start);
  }
  cout << sumR << endl;
  return 0;
}