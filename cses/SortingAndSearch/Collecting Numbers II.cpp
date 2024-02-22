#include <algorithm>
#include <iostream>
using namespace std;
typedef long long ll;
#define endl '\n'

int idx[200100];
int x[200100];

int main() {
  int n, m, rounds = 1;
  cin >> n >> m;
  for (int i = 1; i <= n; i++) {
    cin >> x[i];
    idx[i] = i;
  }
  sort(idx + 1, idx + 1 + n, [&](int i, int j) { return x[i] < x[j]; });
  for (int i = 1; i <= n; i++) {
    if (idx[i] < idx[i - 1])
      rounds++;
  }
  idx[0] = 0, idx[n + 1] = n + 1;

  for (int i = 0; i < m; i++) {
    int a, b;
    cin >> a >> b;
    int tmpSmall = min(x[a], x[b]);
    int tmpBig = max(x[a], x[b]);
    int tmpRoundOld = 0;
    if (idx[tmpSmall] < idx[tmpSmall - 1])
      tmpRoundOld++;
    if (idx[tmpSmall + 1] < idx[tmpSmall])
      tmpRoundOld++;
    if ((tmpBig != tmpSmall + 1) && (idx[tmpBig] < idx[tmpBig - 1]))
      tmpRoundOld++;
    if (idx[tmpBig + 1] < idx[tmpBig])
      tmpRoundOld++;

    swap(idx[x[a]], idx[x[b]]);
    swap(x[a], x[b]);

    tmpSmall = min(x[a], x[b]);
    tmpBig = max(x[a], x[b]);
    int tmpRoundNew = 0;
    if (idx[tmpSmall] < idx[tmpSmall - 1])
      tmpRoundNew++;
    if (idx[tmpSmall + 1] < idx[tmpSmall])
      tmpRoundNew++;
    if ((tmpBig != tmpSmall + 1) && (idx[tmpBig] < idx[tmpBig - 1]))
      tmpRoundNew++;
    if (idx[tmpBig + 1] < idx[tmpBig])
      tmpRoundNew++;

    rounds = rounds + tmpRoundNew - tmpRoundOld;
    cout << rounds << endl;
  }

  return 0;
}