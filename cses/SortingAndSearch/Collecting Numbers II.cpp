#include <algorithm>
#include <iostream>
using namespace std;
typedef long long ll;
#define endl '\n'

vector<int> x, idx;
int main() {
  int n, m, rounds = 1;
  cin >> n >> m;
  x.resize(n + 2);
  idx.resize(n + 2);
  // 边界墙，不影响统计
  x[0] = 0, idx[0] = 0, x[n + 1] = n + 1, idx[n + 1] = n + 1;
  for (int i = 1; i <= n; i++) {
    cin >> x[i];
    idx[i] = i;
  }
  sort(idx.begin(), idx.end(), [&](int i, int j) { return x[i] < x[j]; });
  for (int i = 1; i <= n; i++) {
    if (idx[i] < idx[i - 1])
      rounds++;
  }

  for (int i = 0; i < m; i++) {
    int a, b;
    cin >> a >> b;
    int smallNum = min(x[a], x[b]);
    int bigNum = max(x[a], x[b]);
    int oldRoundCount = 0;
    if (idx[smallNum] < idx[smallNum - 1])
      oldRoundCount++;
    if (idx[smallNum + 1] < idx[smallNum])
      oldRoundCount++;
    if ((bigNum != smallNum + 1) && (idx[bigNum] < idx[bigNum - 1]))
      oldRoundCount++;
    if (idx[bigNum + 1] < idx[bigNum])
      oldRoundCount++;

    swap(idx[smallNum], idx[bigNum]);
    swap(smallNum, bigNum);

    int newRoundCount = 0;
    if (idx[smallNum] < idx[smallNum - 1])
      newRoundCount++;
    if (idx[smallNum + 1] < idx[smallNum])
      newRoundCount++;
    if ((bigNum != smallNum + 1) && (idx[bigNum] < idx[bigNum - 1]))
      newRoundCount++;
    if (idx[bigNum + 1] < idx[bigNum])
      newRoundCount++;

    rounds = rounds + newRoundCount - oldRoundCount;
    cout << rounds << endl;
  }

  return 0;
}