#include <algorithm>
#include <array>
#include <iostream>
#include <queue>
#include <utility>
const int ARRIVAL = 0;
const int DEPARTURE = 1;
const int INDEX = 2;
using namespace std;
using ll = long long;
#define endl '\n'
vector<array<int, 3>> customerPlan;
vector<int> customerRoom;
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>>
    prRoom;
int main() {
  ios::sync_with_stdio(false); // Fast I/O
  cin.tie(nullptr); // Not safe to use cin/cout & scanf/printf together
  int n;
  cin >> n;
  customerPlan.resize(n);
  customerRoom.resize(n);
  for (int i = 0; i < n; i++) {
    cin >> customerPlan[i][ARRIVAL] >> customerPlan[i][DEPARTURE];
    customerPlan[i][INDEX] = i;
  }
  sort(customerPlan.begin(), customerPlan.end());
  int maxRoomNumber = 0;
  for (int i = 0; i < n; i++) {
    if (!prRoom.empty() && customerPlan[i][ARRIVAL] > prRoom.top().first) {
      customerRoom[customerPlan[i][INDEX]] = prRoom.top().second;
      prRoom.pop();
    } else {
      customerRoom[customerPlan[i][INDEX]] = ++maxRoomNumber;
    }
    prRoom.push(
        {customerPlan[i][DEPARTURE], customerRoom[customerPlan[i][INDEX]]});
  }
  cout << maxRoomNumber << endl;
  for (auto i : customerRoom) {
    cout << i << " ";
  }
  return 0;
}