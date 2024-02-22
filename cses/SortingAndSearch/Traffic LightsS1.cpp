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
  set<int> lights;
  multiset<int> distance;
  cin >> x >> n;
  lights.emplace(0);
  lights.emplace(x);
  distance.emplace(x);
  for (int i = 0; i < n; i++) {
    int num;
    cin >> num;
    auto it = lights.emplace(num).first;
    int currLight = *it, nextLight = *next(it), prevLight = *prev(it);
    auto itToDel = distance.find(nextLight - prevLight);
    if (itToDel != distance.end()) {
      distance.erase(itToDel);
    }
    distance.emplace(nextLight - currLight);
    distance.emplace(currLight - prevLight);
    cout << *distance.rbegin() << " ";
  }
  return 0;
}