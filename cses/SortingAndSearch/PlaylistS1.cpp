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
    while (unique.count(k[i])) {
      unique.erase(k[start++]);
    }
    unique.insert(k[i]);
    ans = max(ans, (int)unique.size());
  }
  cout << ans << endl;
  return 0;
}