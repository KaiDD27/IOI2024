#include <deque>
#include <iostream>
#include <vector>
using namespace std;
using ll = long long;
#define endl "\n"
vector<ll> scores;
vector<pair<ll, ll>> positions;
ll numGrids, initialJumpDistance, targetScore;
ll minJumpDistance, maxJumpDistance;
bool good(ll g) {
  minJumpDistance = initialJumpDistance - g;
  maxJumpDistance = initialJumpDistance + g;
  if (minJumpDistance <= 0) {
    minJumpDistance = 1;
  }
  scores.assign(numGrids + 1, 0);
  deque<ll> dq;
  ll currentGrid = 0;
  for (int i = 1; i <= numGrids; i++) {
    for (; currentGrid < i &&
           positions[i].first - positions[currentGrid].first >= minJumpDistance;
         currentGrid++) {
      if (dq.empty()) {
        dq.push_back(currentGrid);
      } else {
        while (!dq.empty() && scores[currentGrid] >= scores[dq.back()]) {
          dq.pop_back();
        }
        dq.push_back(currentGrid);
      }
    }
    while (!dq.empty() &&
           positions[i].first - positions[dq.front()].first > maxJumpDistance) {
      dq.pop_front();
    }
    if (!dq.empty()) {
      scores[i] = scores[dq.front()] + positions[i].second;
    } else {
      scores[i] = -999999999999;
    }
    if (scores[i] >= targetScore) {
      return true;
    }
  }
  return false;
}
int main() {
  cin >> numGrids >> initialJumpDistance >> targetScore;
  ll l = 0, r = 1005;
  while (l < r) {
    ll mid = (l + r) / 2;
    if (good(mid)) {
      r = mid;
    } else {
      l = mid + 1;
    }
  }
  cout << l << endl;
  return 0;
}