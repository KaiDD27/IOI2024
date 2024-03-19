#include <iostream>
#include <set>
#include <tuple>
#include <utility>
#include <vector>
using namespace std;
using ll = long long;
#define endl '\n'
vector<pair<ll, ll>> location;
set<tuple<ll, ll, ll>> setPADofPowerZero;
const ll PAD = 0, TARGET = 1;
const ll LEFT = 0, RIGHT = 1;
int main() {
  ios::sync_with_stdio(false); // Fast I/O
  cin.tie(nullptr); // Not safe to use cin/cout & scanf/printf together
  int N, S;
  cin >> N >> S;
  location.resize(N);
  for (auto &li : location)
    cin >> li.first >> li.second;
  ll brokenTargetCnt = 0;
  for (ll pos = S - 1, direction = RIGHT, power = 1; pos >= 0 && pos < N;) {
    // 如果这次进入同一个位置的 PAD，且 PAD 的power为 0，且 Bessie
    // 自己的方向和Power都和上次相同，则说明已经进入无限循环了，可以 break 了。
    if (location[pos].first == PAD && location[pos].second == 0 &&
        setPADofPowerZero.count(make_tuple(pos, direction, power)) == 1)
      break;
    else {
      setPADofPowerZero.insert(make_tuple(pos, direction, power));
    }

    if (location[pos].first == PAD) {
      power += location[pos].second;
      if (direction == RIGHT)
        direction = LEFT;
      else
        direction = RIGHT;

    } else {
      if (location[pos].second != -1 && power >= location[pos].second) {
        brokenTargetCnt++;
        location[pos].second = -1;
      }
    }
    if (direction == RIGHT)
      pos += power;
    else
      pos -= power;
  }
  cout << brokenTargetCnt << endl;
  return 0;
}