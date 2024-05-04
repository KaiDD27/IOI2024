#include <array>
#include <iostream>
#include <map>
#include <vector>

using namespace std;
using ll = long long;
#define endl "\n"
map<int, int> mpA;
vector<int> ans;
int main() {
  ios::sync_with_stdio(false); // Fast I/O
  cin.tie(nullptr); // Not safe to use cin/cout & scanf/printf together
  int n;
  cin >> n;
  ans.resize(n + 1);
  for (int i = 1; i <= n; i++) {
    int ai;
    cin >> ai;
    if (ai == -1) {
      ans[1] = i;
    }
    mpA[ai] = i;
  }
  cout << ans[1] << " ";
  for (int i = 2; i <= n; i++) {
    ans[i] = mpA[ans[i - 1]];
    cout << ans[i] << " ";
  }
  return 0;
}