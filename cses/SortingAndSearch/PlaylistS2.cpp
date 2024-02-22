#include <algorithm>
#include <iostream>
#include <map>
using namespace std;
typedef long long ll;
#define endl '\n'
map<int, int> hp;

int main() {
  int n, ans = 0, start = 0;
  cin >> n;
  for (int i = 0; i < n; i++) {
    int curr;
    cin >> curr;
    if (hp.count(curr) && hp[curr] >= start) {
      start = hp[curr] + 1;
    }
    hp[curr] = i;
    ans = max(ans, i - start + 1);
  }
  cout << ans << endl;
  return 0;
}
