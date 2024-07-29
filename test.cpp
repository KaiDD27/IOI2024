#include <algorithm>
#include <array>
#include <cstdlib>
#include <iostream>
#include <map>
#include <utility>
#include <vector>
using namespace std;
using ll = long long;
#define endl "\n"
vector<array<ll, 2>> posts;
vector<ll> preSum;
vector<array<ll, 4>> cows;
vector<array<ll, 2>> indexToPost;
array<array<vector<pair<ll, bool>>, 1000 + 1>, 1000 + 1> xyToIndex;
int main() {
  ios::sync_with_stdio(false); // Fast I/O
  cin.tie(nullptr); // Not safe to use cin/cout & scanf/printf together
  ll n, p;
  cin >> n >> p;
  posts.resize(p);
  preSum.resize(p);
  cows.resize(n);
  indexToPost.resize(n);
  for (auto &[x, y] : posts) {
    cin >> x >> y;
  }
  ll sum = 0;
  for (int i = 1; i < p; i++) {
    sum +=
        abs(posts[i][0] - posts[i - 1][0]) + abs(posts[i][1] - posts[i - 1][1]);
    preSum[i] = sum;
  }
  sum +=
      abs(posts[0][0] - posts[p - 1][0]) + abs(posts[0][1] - posts[p - 1][1]);
  for (int i = 0; i < n; i++) {
    auto &[x1, y1, x2, y2] = cows[i];
    cin >> x1 >> y1 >> x2 >> y2;
    xyToIndex[x1][y1].push_back({i, false});
    xyToIndex[x2][y2].push_back({i, true});
  }
  for (int i = 0; i < p; i++) {
    ll nextPos = i + 1;
    if (nextPos == p) {
      nextPos = 0;
    }
    if (posts[i][0] == posts[nextPos][0]) {
      for (int j = min(posts[i][1], posts[nextPos][1]);
           j <= max(posts[i][1], posts[nextPos][1]); j++) {
        for (auto [index, isEnd] : xyToIndex[posts[i][0]][j]) {
          if (isEnd == true) {
            indexToPost[index][1] = i;
          } else {
            indexToPost[index][0] = nextPos;
          }
        }
      }
    } else {
      for (int j = min(posts[i][0], posts[nextPos][0]);
           j <= max(posts[i][0], posts[nextPos][0]); j++) {
        for (auto [index, isEnd] : xyToIndex[j][posts[i][1]]) {
          if (isEnd == true) {
            indexToPost[index][1] = i;
          } else {
            indexToPost[index][0] = nextPos;
          }
        }
      }
    }
  }
  for (int i = 0; i < n; i++) {
    auto &[x1, y1, x2, y2] = cows[i];
    ll ans = abs(preSum[indexToPost[i][0]] - preSum[indexToPost[i][1]]);
    ans += abs(x1 - posts[indexToPost[i][0]][0]) +
           abs(y1 - posts[indexToPost[i][0]][1]);
    ans += abs(x2 - posts[indexToPost[i][1]][0]) +
           abs(y2 - posts[indexToPost[i][1]][1]);
    ans = min(ans, sum - ans);
    cout << ans << endl;
  }
  return 0;
}