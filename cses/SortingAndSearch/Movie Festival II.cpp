#include <algorithm>
#include <array>
#include <iostream>
#include <set>
#include <vector>
using namespace std;
typedef long long ll;
#define endl '\n'
vector<array<int, 2>> movie;
multiset<int> memberFinTime;
const int FIN = 0, START = 1;
int main() {
  int n, k;
  cin >> n >> k;
  movie.resize(n);
  for (int i = 0; i < n; i++) {
    cin >> movie[i][START] >> movie[i][FIN];
  }
  sort(movie.begin(), movie.end());
  int ans = 0;
  for (int i = 0; i < k; i++)
    memberFinTime.insert(0);
  for (int i = 0; i < n; i++) {
    int currMovieStartTime = movie[i][START], currMovieFinTime = movie[i][FIN];
    auto it = memberFinTime.upper_bound(currMovieStartTime);
    if (it != memberFinTime.begin()) {
      it--;
      memberFinTime.erase(it);
      memberFinTime.insert(currMovieFinTime);
      ans++;
    }
  }
  cout << ans << endl;
  return 0;
}