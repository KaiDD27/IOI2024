#include <algorithm>
#include <iostream>
using namespace std;
typedef long long ll;
#define endl '\n'
vector<array<int, 2>> movie;
const int FIN = 0, START = 1;
int main() {
  int n;
  cin >> n;
  movie.resize(n);
  for (int i = 0; i < n; i++) {
    cin >> movie[i][START] >> movie[i][FIN];
  }
  sort(movie.begin(), movie.end());
  int ans = 0;
  for (int i = 0, finTime = 0; i < n; i++) {
    if (movie[i][START] >= finTime) {
      ans++;
      finTime = movie[i][FIN];
    }
  }
  cout << ans << endl;
  return 0;
}