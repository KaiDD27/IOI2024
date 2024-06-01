#include <algorithm>
#include <array>
#include <iostream>
#include <iterator>
#include <set>
#include <vector>

using namespace std;
using ll = long long;
#define endl "\n"
vector<tuple<char, ll>> queryM;
vector<ll> cRank;
set<ll> stNoOffical;
set<ll> stNoOffical5000050050;
int main() {
  ios::sync_with_stdio(false); // Fast I/O
  cin.tie(nullptr); // Not safe to use cin/cout & scanf/printf together
  ll n, m;
  cin >> n >> m;
  queryM.resize(m);
  bool subtask5 = false;
  for (auto &[chM, idx] : queryM) {
    cin >> chM >> idx;
    if (chM == 'o' && idx > 50050 & m > 500)
      subtask5 = true;
  }
  if (subtask5 == true) {
    return 0;
  }
  if (m <= 500) {
    for (auto [chM, idx] : queryM) {
      if (chM == 't') {
        if (stNoOffical.count(idx))
          stNoOffical.erase(idx);
        else
          stNoOffical.insert(idx);
      }
      if (chM == 'o') {
        if (stNoOffical.count(idx))
          cout << "UNOFFICIAL" << endl;
        else {
          if (stNoOffical.empty())
            cout << idx << endl;
          else {
            auto it = stNoOffical.upper_bound(idx);
            cout << idx - distance(stNoOffical.begin(), it) << endl;
          }
        }
      }
    }
    return 0;
  }

  ll below50000Cnt = 0;
  for (auto [chM, idx] : queryM) {
    if (chM == 't') {
      if (idx < 50000) {
        if (stNoOffical.count(idx)) {
          stNoOffical.erase(idx);
          below50000Cnt--;
        } else {
          stNoOffical.insert(idx);
          below50000Cnt++;
        }
      } else if (idx <= 50050) {
        if (stNoOffical5000050050.count(idx)) {
          stNoOffical5000050050.erase(idx);
        } else {
          stNoOffical5000050050.insert(idx);
        }
      } else {
        break;
      }
    }
    if (chM == 'o') {
      if (stNoOffical.count(idx) || stNoOffical5000050050.count(idx))
        cout << "UNOFFICIAL" << endl;
      else {
        if (stNoOffical5000050050.empty())
          cout << idx - below50000Cnt << endl;
        else {
          auto it = stNoOffical5000050050.upper_bound(idx);
          cout << idx - below50000Cnt -
                      distance(stNoOffical5000050050.begin(), it)
               << endl;
        }
      }
    }
  }
  return 0;
}