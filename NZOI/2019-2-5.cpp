#include <array>
#include <iostream>
#include <map>
#include <vector>

using namespace std;
using ll = long long;
#define endl "\n"
ll n, a, b, c, sumX, newDoubleMean;
map<int, int> mpX;
int main() {
  ios::sync_with_stdio(false); // Fast I/O
  cin.tie(nullptr); // Not safe to use cin/cout & scanf/printf together
  cin >> n >> a >> b >> c;
  if (a == b && b == c) {
    cout << "Possible" << endl;
    for (int i = 0; i < n; i++)
      cout << a << " ";
    return 0;
  }
  if (n == 1) {
    if (a == b && b == c) {
      cout << "Possible" << endl;
      cout << b << endl;
    } else {
      cout << "Impossible" << endl;
    }
    return 0;
  } else if (n == 3) {
    if (b != c)
      cout << "Impossible" << endl;
    else if (a * 3 - 2 * c < 1 || a * 3 - 2 * c > 1000000)
      cout << "Impossible" << endl;
    else {
      cout << "Possible" << endl;
      cout << a * 3 - 2 * c << " " << c << " " << c << endl;
    }
    return 0;
  }
  sumX = n * a;
  ll d = (n - 3) / 2;
  if (b == c) {
    ll ret = (sumX - (d - 1 + 3) * c) / (d + 1);
    ll remain = (sumX - (d - 1 + 3) * c) % (d + 1);
    if (ret >= 1 && (ret < 1000000 || (ret == 1000000 && remain == 0))) {
      cout << "Possible" << endl;
      for (int i = 0; i < d + 2; i++)
        cout << c << " ";
      for (int i = 0; i < d + 1 - remain; i++) {
        cout << ret << " ";
      }
      for (int i = 0; i < remain; i++) {
        cout << ret + 1 << " ";
      }
    } else
      cout << "Impossible" << endl;
    return 0;
  }

  if (b < c) {
    bool flag = false;
    for (int i = 2; i <= (n - 1) / 2; i++) {
      // 检测 a 会不会过大
      ll ret = ((n - 1) / 2 + 1) / (i - 1);
      ll remain = ((n - 1) / 2 + 1) % (i - 1);
      // 先减去左边(包含 b 点）最大的可能的sum
      ll minRightNumSum =
          (sumX - (b - ret + 1 + b) * (i - 1) / 2 - (b - ret) * remain);
      // 再看看大于 c 的数字取到最大值是否还是不够大
      ret = (((n - 1) / 2) - i) / (i - 1);
      remain = (((n - 1) / 2) - i) % (i - 1);
      if (ret > 1000000 - c || (ret == 1000000 - c && remain != 0))
        continue;
      if (minRightNumSum - c * i >
          ((1000000 + 1000000 - ret + 1) * (i - 1) / 2 +
           (1000000 - ret) * remain))
        continue;

      // 检测 a 会不会过小
      ret = ((n - 1) / 2 + 1 - i) / (i - 1);
      remain = ((n - 1) / 2 + 1 - i) % (i - 1);
      if (ret < c - b || (ret == c - b && remain == 0)) {
        ll maxLeftNum = (sumX - c * i - (b + ret - 1 + b) * (i - 1) / 2 -
                         remain * (b + ret)) /
                        ((n - 1) / 2);
        ll maxLeftNumRemain = (sumX - c * i - (b + ret - 1 + b) * (i - 1) / 2 -
                               remain * (b + ret)) %
                              ((n - 1) / 2);
        if (maxLeftNumRemain < 1)
          continue;
        else {
          flag = true;
          break;
        }
      }
    }
    if (flag == true)
      cout << "Possible" << endl;
    else
      cout << "Impossible" << endl;
    return 0;
  }
  return 0;
}