#include <algorithm>
#include <iostream>

using namespace std;
int main() {
  string strDNA;
  cin >> strDNA;
  strDNA += "B";
  long long cnt = 1, ans = 1;
  for (int i = 1; i < strDNA.length(); i++) {
    if (strDNA[i] == strDNA[i - 1]) {
      cnt++;
    } else {
      ans = max(ans, cnt);
      cnt = 1;
    }
  }
  cout << ans << endl;
  return 0;
}