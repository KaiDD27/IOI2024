#include <algorithm>
#include <iostream>
#include <utility>
#include <vector>
using namespace std;
typedef long long ll;
#define endl '\n'

vector<pair<int, int>> x;
int main() {
  int n, m, rounds = 1;
  cin >> n >> m;
  x.resize(n + 2);
  // 边界墙，不影响统计
  x[0].first = 0, x[0].second = 0, x[n + 1].first = n + 1,
  x[n + 1].second = n + 1;
  for (int i = 1; i <= n; i++) {
    cin >> x[i].first;
    x[i].second = i;
  }
  sort(x.begin(), x.end());
  for (int i = 1; i <= n; i++) {
    if (x[i].second < x[i - 1].second)
      rounds++;
  }

  for (int i = 0; i < m; i++) {
    int a, b;
    cin >> a >> b;
    int smallNum = min(x[a].first, x[b].first);
    int bigNum = max(x[a].first, x[b].first);
    int oldRoundCount = 0;
    if (x[smallNum].second < x[smallNum - 1].second)
      oldRoundCount++;
    if (x[smallNum + 1].second < x[smallNum].second)
      oldRoundCount++;
    if ((bigNum != smallNum + 1) && (x[bigNum].second < x[bigNum - 1].second))
      oldRoundCount++;
    if (x[bigNum + 1].second < x[bigNum].second)
      oldRoundCount++;

    swap(x[smallNum], x[bigNum]);

    int newRoundCount = 0;
    if (x[smallNum].second < x[smallNum - 1].second)
      newRoundCount++;
    if (x[smallNum + 1].second < x[smallNum].second)
      newRoundCount++;
    if ((bigNum != smallNum + 1) && (x[bigNum].second < x[bigNum - 1].second))
      newRoundCount++;
    if (x[bigNum + 1].second < x[bigNum].second)
      newRoundCount++;

    rounds = rounds + newRoundCount - oldRoundCount;
    cout << rounds << endl;
  }

  return 0;
}