#include <array>
#include <iostream>
#include <vector>

using namespace std;
using ll = long long;
#define endl "\n"
ll t;
vector<ll> ns;
vector<ll> ks;
vector<string> tCowsPreferred;
int main() {
  ios::sync_with_stdio(false); // Fast I/O
  cin.tie(nullptr); // Not safe to use cin/cout & scanf/printf together
  cin >> t;
  ns.resize(t);
  ks.resize(t);
  tCowsPreferred.resize(t);
  for (int ti = 0; ti < t; ti++) {
    cin >> ns[ti] >> ks[ti] >> tCowsPreferred[ti];
  }
  for (int ti = 0; ti < t; ti++) {
    ll n = ns[ti], k = ks[ti];
    string cowsPreferred = tCowsPreferred[ti];
    if (k == 0) {
      cout << n << endl;
      cout << cowsPreferred << endl;
      continue;
    }
    string strConfig;
    ll lastGDist = -1, lastHDist = -1, coverDistG = -1, coverDistH = -1;
    ll patchCnt = 0;
    for (auto chP : cowsPreferred) {
      if (k == lastGDist) {
        strConfig.push_back('G');
        patchCnt++;
        lastGDist = -1;
        coverDistG = k;
      } else if (k == lastHDist) {
        strConfig.push_back('H');
        patchCnt++;
        lastHDist = -1;
        coverDistH = k;
      } else {
        strConfig.push_back('.');
      }

      if (chP == 'G' && lastGDist == -1 && coverDistG < 0) {
        lastGDist = 0;
      }
      if (chP == 'H' && lastHDist == -1 && coverDistH < 0) {
        lastHDist = 0;
      }

      if (lastGDist != -1)
        lastGDist++;
      if (lastHDist != -1)
        lastHDist++;
      if (coverDistG != -1)
        coverDistG--;
      if (coverDistH != -1)
        coverDistH--;
    }
    for (auto it = strConfig.rbegin(); it != strConfig.rend(); it++) {
      if (lastGDist == -1 && lastHDist == -1)
        break;
      if (*it == '.') {
        if (lastGDist != -1) {
          *it = 'G';
          patchCnt++;
          lastGDist = -1;
        } else if (lastHDist != -1) {
          *it = 'H';
          patchCnt++;
          lastHDist = -1;
        }
      }
    }
    cout << patchCnt << endl;
    cout << strConfig << endl;
  }
  return 0;
}