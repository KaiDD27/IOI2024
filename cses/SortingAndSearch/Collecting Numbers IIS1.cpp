#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;
#define endl '\n'
// 这个问题不能用pair，因为要保持原有的次序
vector<int> x, pos;
int main() {
  int n, m, rounds = 1;
  cin >> n >> m;
  x.resize(n + 2);
  pos.resize(n + 2);
  // 边界墙，不影响统计
  x[0] = 0, pos[0] = 0, x[n + 1] = n + 1, pos[n + 1] = n + 1;
  for (int i = 1; i <= n; i++) {
    cin >> x[i];
    pos[i] = i;
  }
  sort(pos.begin(), pos.end(), [&](int i, int j) { return x[i] < x[j]; });
  for (int i = 1; i <= n; i++) {
    if (pos[i] < pos[i - 1])
      rounds++;
  }

  for (int i = 0; i < m; i++) {
    int a, b;
    cin >> a >> b;
    int smallNum = min(x[a], x[b]);
    int bigNum = max(x[a], x[b]);
    int oldRoundCount = 0;
    if (pos[smallNum] < pos[smallNum - 1])
      oldRoundCount++;
    if (pos[smallNum + 1] < pos[smallNum])
      oldRoundCount++;
    if ((bigNum != smallNum + 1) && (pos[bigNum] < pos[bigNum - 1]))
      oldRoundCount++;
    if (pos[bigNum + 1] < pos[bigNum])
      oldRoundCount++;

    swap(pos[smallNum], pos[bigNum]);
    swap(x[a], x[b]);

    int newRoundCount = 0;
    if (pos[smallNum] < pos[smallNum - 1])
      newRoundCount++;
    if (pos[smallNum + 1] < pos[smallNum])
      newRoundCount++;
    if ((bigNum != smallNum + 1) && (pos[bigNum] < pos[bigNum - 1]))
      newRoundCount++;
    if (pos[bigNum + 1] < pos[bigNum])
      newRoundCount++;

    rounds = rounds + newRoundCount - oldRoundCount;
    cout << rounds << endl;
  }

  return 0;
}