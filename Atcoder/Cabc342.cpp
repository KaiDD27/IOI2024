#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;
using ll = long long;
#define endl "\n"
unordered_map<char, char> mpChar;
int main() {
  ios::sync_with_stdio(false); // Fast I/O
  cin.tie(nullptr); // Not safe to use cin/cout & scanf/printf together
  int N, Q;
  string S;
  cin >> N >> S >> Q;
  vector<pair<char, char>> cd(Q);
  for (char c = 'a'; c <= 'z'; c++) {
    mpChar[c] = c;
  }
  for (auto &cdi : cd) {
    cin >> cdi.first >> cdi.second;
    for (int i = 0; i < 26; i++) {
      if (mpChar['a' + i] == cdi.first)
        mpChar['a' + i] = cdi.second;
    }
  }
  for (int i = 0; i < S.length(); i++) {
    S[i] = mpChar[S[i]];
  }
  cout << S << endl;

  return 0;
}