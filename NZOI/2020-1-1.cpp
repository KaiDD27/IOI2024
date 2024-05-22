//
#include <algorithm>
#include <array>
#include <cstdlib>
#include <iostream>
#include <vector>

using namespace std;
using ll = long long;
#define endl "\n"
const int MAX = 1000000000;

int main() {
  ios::sync_with_stdio(false); // Fast I/O
  cin.tie(nullptr); // Not safe to use cin/cout & scanf/printf together
  int d;
  vector<int> gap(3, 0);
  cin >> gap[0] >> gap[1] >> gap[2] >> d;

  int minDist = MAX + 10;
  bool flag = false;
  for (auto gi : gap) {
    int dist = MAX + 20;
    // 可以在超过1e9的地方有建筑
    dist = (d / gi + 1) * gi - d;
    // 本题没有说明 0
    // 处是否有三种建筑，这是出题不严谨处，按照测试用例来看，应该是 0
    // 处有三个建筑
    dist = min(dist, d - (d / gi) * gi);
    if (minDist == dist)
      flag = true;
    else if (dist < minDist) {
      minDist = dist;
      flag = false;
    }
  }
  /**/

  cout << minDist << endl;
  if (flag == true)
    cout << "can't make up my mind" << endl;
  return 0;
}