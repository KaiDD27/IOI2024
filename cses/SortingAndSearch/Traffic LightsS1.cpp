#include <iostream>
#include <iterator>
#include <set>
using namespace std;
typedef long long ll;
#define endl '\n'

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  int x, n;
  set<int> setLight;
  multiset<int> msDistance;
  cin >> x >> n;
  // 边界放两个路灯，不影响结果
  setLight.insert(0);
  setLight.insert(x);
  msDistance.insert(x);
  for (int i = 0; i < n; i++) {
    int num;
    cin >> num;
    auto it = setLight.insert(num).first;
    int currLight = *it, nextLight = *next(it), prevLight = *prev(it);
    auto itToDel = msDistance.find(nextLight - prevLight);
    if (itToDel != msDistance.end()) {
      msDistance.erase(itToDel);
    }
    msDistance.insert(nextLight - currLight);
    msDistance.insert(currLight - prevLight);
    cout << *msDistance.rbegin() << " ";
  }
  return 0;
}