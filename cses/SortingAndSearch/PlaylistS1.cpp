#include <deque>
#include <iostream>
#include <set>
using namespace std;

int main() {
  int n, ans = 0;
  cin >> n;
  deque<int> order;
  set<int> unique;
  for (int i = 0; i < n; i++) {
    int curr;
    cin >> curr;
    while (unique.count(curr)) {
      unique.erase(order.front());
      order.pop_front();
    }
    order.push_back(curr);
    unique.emplace(curr);
    ans = max(ans, (int)unique.size());
  }
  cout << ans << endl;
  return 0;
}