#include <iostream>
#include <set>
using namespace std;
typedef long long ll;
#define endl '\n'
multiset<int> msTower;
int main() {
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    int c;
    cin >> c;
    auto it = msTower.upper_bound(c);
    if (it != msTower.end())
      msTower.erase(it);
    msTower.insert(c);
  }
  cout << msTower.size() << endl;
  return 0;
}