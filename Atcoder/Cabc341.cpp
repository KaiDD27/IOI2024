#include <iostream>
#include <vector>
using namespace std;
using ll = long long;
#define endl "\n"
vector<string> S;
int main() {
  ios::sync_with_stdio(false); // Fast I/O
  cin.tie(nullptr); // Not safe to use cin/cout & scanf/printf together
  int H, W, N;
  string T;
  cin >> H >> W >> N >> T;
  // 第0行和最后一行都作为墙
  S.resize(H + 2);
  for (int i = 0; i <= H + 1; i++) {
    if (i == 0)
      S[i].resize(W + 2, '#');
    else if (i == H + 1)
      S[i].resize(W + 2, '#');
    else {
      // 第0列和最后一列都作为墙
      S[i] = "#";
      cin >> S[i];
      S[i].append("#");
    }
  }
  ll ans = 0;
  for (int line = 1; line <= H; line++) {
    for (int column = 1; column <= W; column++) {
      if (S[line][column] == '#')
        continue;
      bool isValid = true;
      int tLine = line, tColumn = column;
      for (auto ti : T) {
        switch (ti) {
        case 'L':
          if (S[tLine][--tColumn] == '#')
            isValid = false;
          break;
        case 'R':
          if (S[tLine][++tColumn] == '#')
            isValid = false;
          break;
        case 'U':
          if (S[--tLine][tColumn] == '#')
            isValid = false;
          break;
        case 'D':
          if (S[++tLine][tColumn] == '#')
            isValid = false;
          break;
        }
        if (isValid == false)
          break;
      }
      if (isValid == true)
        ans++;
    }
  }
  cout << ans << endl;
  return 0;
}