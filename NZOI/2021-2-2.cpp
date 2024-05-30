#include <array>
#include <iostream>
#include <map>
#include <vector>

using namespace std;
using ll = long long;
#define endl "\n"
map<char, ll> mpCnt;
int main() {
  ios::sync_with_stdio(false); // Fast I/O
  cin.tie(nullptr); // Not safe to use cin/cout & scanf/printf together
  ll l;
  cin >> l;
  cin >> mpCnt['R'] >> mpCnt['P'] >> mpCnt['D'] >> mpCnt['G'];
  mpCnt['.'] = mpCnt['R'] + mpCnt['P'] + mpCnt['D'];
  ll sumCnt = mpCnt['.'] + mpCnt['G'];
  for (int i = 0; i < l; i++) {
    char chD;
    cin >> chD;
    mpCnt[chD]--;
    if (chD != 'R' || chD == 'P' || chD == 'D')
      mpCnt['.']--;
    if (mpCnt[chD] < 0 || mpCnt['.'] < 0) {
      cout << i << endl;
      cout << sumCnt - i << endl;
      return 0;
    }
  }
  cout << l << endl;
  cout << sumCnt - l << endl;
  return 0;
}