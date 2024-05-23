#include <array>
#include <iostream>
#include <vector>

using namespace std;
using ll = long long;
#define endl "\n"

int main() {
  ios::sync_with_stdio(false); // Fast I/O
  cin.tie(nullptr); // Not safe to use cin/cout & scanf/printf together
  bool flagHealthy = false;
  bool flagResow = false;
  for (int i = 0; i < 3; i++) {
    int n;
    cin >> n;
    int sum = 0;
    int resowReadingCnt = 0;
    for (int j = 0; j < n; j++) {
      int reading;
      cin >> reading;
      sum += reading;
      if (i == 0 && reading >= 25)
        resowReadingCnt++;
    }
    if (sum / n < 12)
      flagHealthy = true;
    if (i == 0) {
      if (resowReadingCnt == n / 2 && n % 2 == 0)
        flagResow = true;
      else if (resowReadingCnt > n / 2)
        flagResow = true;
    }
  }
  if (flagHealthy == true)
    cout << "healthy" << endl;
  else if (flagHealthy == false && flagResow == false)
    cout << "unhealthy" << endl;
  else
    cout << "resow" << endl;
  return 0;
}