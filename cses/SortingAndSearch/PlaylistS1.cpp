#include <iostream>
#include <set>
#include <vector>
using namespace std;
vector<int> k;
int main() {
  int n, ans = 0;
  cin >> n;
  k.resize(n);
  set<int> unique;
  for (int i = 0, start = 0; i < n; i++) {
    cin >> k[i];
    auto it = unique.find(k[i]);
    while (it != unique.end()) {
      unique.erase(k[start++]);
      it = unique.find(k[i]);
    }
    unique.insert(k[i]);
    ans = max(ans, (int)unique.size());
  }
  cout << ans << endl;
  return 0;
}