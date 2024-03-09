#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;
using ll = long long;
#define endl '\n'
vector<int> subwayLength;
int main() {
  ios::sync_with_stdio(false); // Fast I/O
  cin.tie(nullptr); // Not safe to use cin/cout & scanf/printf together
  int N;
  string strCows;
  cin >> N >> strCows;

  // 找出最短的subway，头尾需要特殊处理
  int mnLength = N;
  for (int i = 0, tmpLength = 0; i < strCows.length(); i++) {
    if (strCows[i] == '1')
      tmpLength++;
    else {
      if (tmpLength != 0) {
        subwayLength.push_back(tmpLength);
        if (tmpLength == i) // 说明是从头开始的subway
        {
          mnLength = min(mnLength, 2 * tmpLength - 1);
        } else {
          mnLength = min(mnLength, tmpLength);
        }
        tmpLength = 0;
      }
    }
    // 从尾开始，且不是从头开始的subway，
    if (i == strCows.length() - 1 && tmpLength != 0) {
      subwayLength.push_back(tmpLength);
      mnLength = min(mnLength, 2 * tmpLength - 1);
    }
  }

  // 最短的 subway所需要的最长的夜
  // 如果是奇数，则一个病牛在中间即可，如果是偶数则两个病牛在中间紧贴着。
  int mxNight = N;
  mxNight = (mnLength - 1) / 2;

  // 算出mxNight后，开始遍历所有的subway，统计所需要的最少的初始病牛，开头和结尾的subway需要特判
  int ans = 0;
  for (auto si : subwayLength) {
    if (si % (2 * mxNight + 1) == 0)
      ans += max(si / (2 * mxNight + 1), 1);
    else
      ans += max((si / (2 * mxNight + 1) + 1), 1);
  }

  cout << ans << endl;
  return 0;
}