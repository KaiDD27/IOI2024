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
  cin >> N;
  int headLength = 0, tailLength = 0;
  string strCows;
  cin >> strCows;

  if (*strCows.begin() == '1') {
    for (int i = 0; i < strCows.length(); i++) {
      if (strCows[i] == '0') {
        headLength = i;
        break;
      }
    }
  }
  int tmpLength = 0;
  int mnLength = N;
  for (int i = headLength; i < strCows.length(); i++) {
    if (strCows[i] == '1')
      tmpLength++;
    else {
      if (tmpLength != 0) {
        mnLength = min(mnLength, tmpLength);
        subwayLength.push_back(tmpLength);
        tmpLength = 0;
      }
    }
  }
  tailLength = tmpLength;
  int mxNight = N;
  // 形成最短的 subway，所需要的最长的夜，开头和结尾的subway需要特判
  // 如果是奇数，则一个病牛在中间即可，如果是偶数则两个病牛在中间紧贴着。
  if (subwayLength.size() != 0)
    mxNight = (mnLength - 1) / 2;
  if (headLength != 0)
    mxNight = min(headLength - 1, mxNight);
  if (tailLength != 0)
    mxNight = min(tailLength - 1, mxNight);

  // 算出mxNight后，开始遍历所有的subway，统计所需要的最少的初始病牛，开头和结尾的subway需要特判
  int ans = 0;
  if (headLength != 0 && headLength / (2 * mxNight + 1) == 0)
    ans++;
  else {
    if (headLength % (2 * mxNight + 1) == 0)
      ans += headLength / (2 * mxNight + 1);
    else
      ans += (headLength / (2 * mxNight + 1) + 1);
  }
  if (tailLength != 0 && tailLength / (2 * mxNight + 1) == 0)
    ans++;
  else {
    if (tailLength % (2 * mxNight + 1) == 0)
      ans += tailLength / (2 * mxNight + 1);
    else
      ans += (tailLength / (2 * mxNight + 1) + 1);
  }

  for (auto si : subwayLength) {
    if (si % (2 * mxNight + 1) == 0)
      ans += si / (2 * mxNight + 1);
    else
      ans += (si / (2 * mxNight + 1) + 1);
  }

  cout << ans << endl;
  return 0;
}