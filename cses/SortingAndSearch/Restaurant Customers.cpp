#include <algorithm>
#include <iostream>
using namespace std;
typedef long long ll;
#define endl '\n'

vector<pair<int, int>> ab;

int main() {
  int n;
  int ans = 0, cnt = 0;
  cin >> n;
  ab.resize(2 * n);
  for (int i = 0; i < n * 2; i++) {
    cin >> ab[i].first;
    ab[i].second = i % 2; // 0 =arrival ,1=leaving
  }
  sort(ab.begin(), ab.end());
  for (auto p : ab) {
    if (p.second == 0) { // arrival
      cnt++;
      ans = max(ans, cnt);
    } else { // leaving
      cnt--;
    }
  }
  cout << ans << endl;
  return 0;
}