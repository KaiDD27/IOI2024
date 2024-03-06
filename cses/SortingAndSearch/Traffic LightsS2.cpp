#include <iostream>
#include <map>
#include <set>

using namespace std;
typedef long long ll;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  int x, n;
  set<int> setLights;
  map<int, int> mpDistance;
  cin >> x >> n;
  setLights.insert(0);
  setLights.insert(x);
  mpDistance[x] = 1;
  for (int i = 0; i < n; i++) {
    int num;
    cin >> num;
    auto it = setLights.insert(num).first;
    int currP = *it, nextP = *next(it), prevP = *prev(it);
    mpDistance[nextP - prevP]--;
    if (mpDistance[nextP - prevP] == 0) {
      mpDistance.erase(nextP - prevP);
    }
    mpDistance[nextP - currP]++;
    mpDistance[currP - prevP]++;
    cout << (prev(mpDistance.end()))->first << " ";
  }
  return 0;
}