#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

struct Event {
  int time;
  int index;
  bool isArrival;
};

int main() {
  int n;
  cin >> n;
  vector<Event> events;
  for (int i = 0; i < n; ++i) {
    int arrival, departure;
    cin >> arrival >> departure;
    events.push_back({arrival, i, true});
    events.push_back({departure, i, false});
  }

  // Sort events by time, if times are equal, departure comes before arrival
  sort(events.begin(), events.end(), [](const Event &a, const Event &b) {
    return a.time == b.time ? a.isArrival > b.isArrival : a.time < b.time;
  });

  queue<int> available_rooms;
  vector<int> room_assignment(n);
  int max_rooms = 0;

  for (const auto &e : events) {
    if (e.isArrival) {
      int room_number;
      if (available_rooms.empty()) {
        max_rooms++;
        room_number = max_rooms;
      } else {
        room_number = available_rooms.front();
        available_rooms.pop();
      }
      room_assignment[e.index] = room_number;
    } else {
      available_rooms.push(room_assignment[e.index]);
    }
  }

  cout << max_rooms << "\n";
  for (int i = 0; i < n; ++i) {
    cout << room_assignment[i] << " ";
  }
  cout << "\n";

  return 0;
}