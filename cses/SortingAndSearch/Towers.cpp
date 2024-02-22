#include <iostream>
#include <set>
using namespace std;
typedef long long ll;
#define endl '\n'
multiset<int> tower;
int main() {
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    int c;
    cin >> c;
    auto it = tower.upper_bound(c);
    if (it != tower.end())
      tower.erase(it);
    tower.emplace(c);
  }
  cout << tower.size() << endl;
  return 0;
}