#include <algorithm>
#include <array>
#include <cstdlib>
#include <iostream>
#include <iterator>
#include <map>
#include <vector>

using namespace std;
using ll = long long;
#define endl "\n"
ll n, p;
vector<pair<ll, ll>> postsXY;
vector<array<ll, 4>> cows;
map<pair<ll, ll>, ll> mpXYtoId;
map<pair<ll, ll>, ll> mpYXtoId;
vector<ll> postPresumLength;
bool startAtPost(ll x, ll y, ll postId) {
  if (x == postsXY[postId].first) {
    if (y <= max(postsXY[postId].second, postsXY[postId + 1].second) &&
        y >= min(postsXY[postId].second, postsXY[postId + 1].second))
      return true;
  }
  if (y == postsXY[postId].second) {
    if (x <= max(postsXY[postId].first, postsXY[postId + 1].first) &&
        x >= min(postsXY[postId].first, postsXY[postId + 1].first))
      return true;
  }
  return false;
}
ll getStartPostByPostId(ll x, ll y, ll postId) {
  if (startAtPost(x, y, postId))
    return postId;
  if (startAtPost(x, y, postId - 1))
    return postId - 1;
  return -1;
}
ll getStartPost(ll x, ll y) {
  ll postId = -1;
  auto it = mpXYtoId.lower_bound({x, y});
  if (it != mpXYtoId.end()) {
    ll tmpPostId = it->second;
    postId = getStartPostByPostId(x, y, tmpPostId);
    if (postId != -1)
      return postId;
  }
  if (it != mpXYtoId.begin()) {
    it = prev(it);
    ll tmpPostId = it->second;
    postId = getStartPostByPostId(x, y, tmpPostId);
    if (postId != -1)
      return postId;
  }
  it = mpYXtoId.lower_bound({y, x});
  if (it != mpYXtoId.end()) {
    ll tmpPostId = it->second;
    postId = getStartPostByPostId(x, y, tmpPostId);
    if (postId != -1)
      return postId;
  }
  if (it != mpYXtoId.begin()) {
    it = prev(it);
    ll tmpPostId = it->second;
    postId = getStartPostByPostId(x, y, tmpPostId);
    if (postId != -1)
      return postId;
  }
  return -1;
}
int main() {
  ios::sync_with_stdio(false); // Fast I/O
  cin.tie(nullptr); // Not safe to use cin/cout & scanf/printf together
  cin >> n >> p;
  postsXY.resize(p + 1);
  for (int i = 1; i <= p; i++) {
    cin >> postsXY[i].first >> postsXY[i].second;
    mpXYtoId[{postsXY[i].first, postsXY[i].second}] = i;
    mpYXtoId[{postsXY[i].second, postsXY[i].first}] = i;
  }
  postsXY[0] = postsXY[p];
  cows.resize(n);
  for (auto &ci : cows)
    cin >> ci[0] >> ci[1] >> ci[2] >> ci[3];

  // 化环为线
  postPresumLength.resize(2 * p);
  postPresumLength[0] = 0;
  postsXY.insert(postsXY.end(), postsXY.begin() + 1, postsXY.end() - 1);
  for (int i = 1; i < 2 * p; i++) {
    ll fenceLength = 0;
    if (postsXY[i].first == postsXY[i - 1].first)
      fenceLength = abs(postsXY[i].second - postsXY[i - 1].second);
    else
      fenceLength = abs(postsXY[i].first - postsXY[i - 1].first);
    postPresumLength[i] = postPresumLength[i - 1] + fenceLength;
  }

  for (auto [x1, y1, x2, y2] : cows) {
    ll startPost, finishedPost;
    startPost = getStartPost(x1, y1);
    finishedPost = getStartPost(x2, y2);
    if (startPost == finishedPost) {
      return abs(x1 - x2) + abs(y1 - y2);
    }
    if (startPost > finishedPost) {
      swap(startPost, finishedPost);
      swap(x1, x2);
      swap(y1, y2);
    }
    ll distance = postPresumLength[finishedPost] - postPresumLength[startPost] -
                  abs(x1 - postsXY[startPost].first) -
                  abs(y1 - postsXY[startPost].second) +
                  abs(x2 - postsXY[finishedPost].first) +
                  abs(y2 - postsXY[finishedPost].second);
    // 反方向
    ll tmp = finishedPost;
    finishedPost = startPost + p;
    startPost = tmp;
    swap(x1, x2);
    swap(y1, y2);
    distance = min(distance, postPresumLength[finishedPost] -
                                 postPresumLength[startPost] -
                                 abs(x1 - postsXY[startPost].first) -
                                 abs(y1 - postsXY[startPost].second) +
                                 abs(x2 - postsXY[finishedPost].first) +
                                 abs(y2 - postsXY[finishedPost].second));
    cout << distance << endl;
  }

  return 0;
}