#include <array>
#include <iostream>
#include <map>
#include <set>
#include <utility>
#include <vector>

using namespace std;
using ll = long long;
#define endl "\n"
ll n;
set<ll> setFriendedNum;
set<pair<ll, ll>> setAandB, setTmpAandB;
map<ll, ll> mapBtoA;
vector<ll> ans;

void friendIt(ll b) {
  if (mapBtoA.count(b)) {
    ll a = mapBtoA[b];
    for (int m = 2; m < b / a; m++) {
      // 如果还没有被friend的话，则需要先friend
      if (setFriendedNum.count(a * m) == 0) {
        friendIt(a * m);
      }
    }
    ans.push_back(a);
    setFriendedNum.insert(a);
    setFriendedNum.insert(b);
    setTmpAandB.erase({a, b});
  } else {
    ll nb = setTmpAandB.lower_bound({b, 0})->second;
    if (setFriendedNum.count(nb) == 0) {
      friendIt(nb);
    }
  }
  return;
}

int main() {
  ios::sync_with_stdio(false); // Fast I/O
  cin.tie(nullptr); // Not safe to use cin/cout & scanf/printf together
  cin >> n;
  for (int i = 0; i < n; i++) {
    ll a, b;
    cin >> a >> b;
    setAandB.insert({a, b});
    mapBtoA[b] = a;
  }
  setTmpAandB = setAandB;
  for (auto it = setAandB.begin(); it != setAandB.end(); it++) {
    auto [a, b] = *it;
    // 已经被friend 了
    if (setFriendedNum.count(b) == 0)
      friendIt(b);
  }

  for (auto ai : ans)
    cout << ai << " ";
  cout << endl;
  return 0;
}