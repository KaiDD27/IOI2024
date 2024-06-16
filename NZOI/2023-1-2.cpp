#include <array>
#include <iostream>
#include <string>
#include <vector>

using namespace std;
using ll = long long;
#define endl "\n"
int n;
vector<int> ans;
void findDistinctRepdigits(ll num) {
  if (num == 0)
    return;
  if (num < 10) {
    ans.push_back(num);
    return;
  }
  string strNum = to_string(num);
  string strRepDigits = string(strNum.length(), strNum[0]);
  if (num - stoi(strRepDigits) < 0) {
    if (strNum[0] != '1') {
      strRepDigits = string(strNum.length(), strNum[0] - 1);
    } else {
      strRepDigits = string(strNum.length() - 1, '9');
    }
  }
  ans.push_back(stoi(strRepDigits));
  findDistinctRepdigits(num - stoi(strRepDigits));
}
int main() {
  ios::sync_with_stdio(false); // Fast I/O
  cin.tie(nullptr); // Not safe to use cin/cout & scanf/printf together
  cin >> n;
  findDistinctRepdigits(n);
  cout << ans.size() << endl;
  for (auto ai : ans)
    cout << ai << endl;
  return 0;
}