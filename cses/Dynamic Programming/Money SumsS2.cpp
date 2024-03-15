#include <iostream>
#include <set>
#include <vector>

using namespace std;
using ll = long long;
#define endl '\n'
set<int> setSum;

int main() {
  ios::sync_with_stdio(false); // Fast I/O
  cin.tie(nullptr); // Not safe to use cin/cout & scanf/printf together
  int n;
  cin >> n;

  for (int i = 0; i < n; i++) {
    int xNum;
    cin >> xNum;

    if (!setSum.empty()) {
      vector<int> tmp(setSum.size());
      copy(setSum.begin(), setSum.end(), tmp.begin());
      for (auto ti : tmp) {
        setSum.insert(xNum + ti);
      }
    }
    setSum.insert(xNum);
  }
  cout << setSum.size() << endl;
  for (auto si : setSum)
    cout << si << " ";
  return 0;
}