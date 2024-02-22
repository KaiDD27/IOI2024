#include <iostream>
#include <map>
#include <queue>
#include <set>

using namespace std;

typedef long long ll;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  int x, n;
  set<int> lights;
  priority_queue<int> distances;
  map<int, int> count;
  cin >> x >> n;
  lights.insert(0);
  lights.insert(x);
  distances.push(x);
  count[x] = 1;
  for (int i = 0; i < n; i++) {
    int num;
    cin >> num;
    auto it = lights.insert(num).first;
    int currP = *it, nextP = *next(it), prevP = *prev(it);
    count[nextP - prevP]--;
    if (count[nextP - prevP] == 0) {
      while (!distances.empty() && count[distances.top()] == 0) {
        distances.pop();
      }
    }
    distances.push(nextP - currP);
    distances.push(currP - prevP);
    count[nextP - currP]++;
    count[currP - prevP]++;
    cout << distances.top() << " ";
  }
  return 0;
}