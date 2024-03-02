#include <array>
#include <iostream>
#include <queue>
const int AORD = 1;
const int CUSID = 2;
using namespace std;
using ll = long long;
#define endl '\n'
priority_queue<array<int, 3>, vector<array<int, 3>>, greater<array<int, 3>>>
    prEvent; // first是日期，second 是事件类型（0表示到达，1表示离开），third
             // 是顾客编号

vector<int> CustomerToRoom;

int main() {
  ios::sync_with_stdio(false); // Fast I/O
  cin.tie(nullptr); // Not safe to use cin/cout & scanf/printf together
  int n;
  cin >> n;
  CustomerToRoom.resize(n);
  for (int i = 0; i < n; i++) {
    int arriveDay, departureDay;
    cin >> arriveDay >> departureDay;
    prEvent.push({arriveDay, 0, i});
    prEvent.push({departureDay, 1, i});
  }

  priority_queue<int, vector<int>, greater<int>> roomHeap;
  int maxRoomNumber = 0;
  while (!prEvent.empty()) {
    auto event = prEvent.top();
    prEvent.pop();
    if (event[AORD] == 0) { // Arrival
      if (roomHeap.empty()) {
        CustomerToRoom[event[CUSID]] = ++maxRoomNumber;
      } else {
        CustomerToRoom[event[CUSID]] = roomHeap.top();
        roomHeap.pop();
      }
    } else { // Departure
      roomHeap.push(CustomerToRoom[event[CUSID]]);
    }
  }

  cout << maxRoomNumber << endl;
  for (auto roomNum : CustomerToRoom) {
    cout << roomNum << " ";
  }
  return 0;
}