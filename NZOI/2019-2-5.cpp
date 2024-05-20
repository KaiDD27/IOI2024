// 这道题，应该是题目的测试用例数据出错了，最多只能通过 35%
#include <algorithm>
#include <array>
#include <iostream>
#include <map>
#include <vector>

using namespace std;
using ll = long long;
#define endl "\n"
ll n, a, b, c, sumX;
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
  bool flag = false;
  // k代表 c 出现的次数
  for (int k = 2; k <= n / 2; k++) {
    // 个数超过了，就直接不用看了
    if (b < c) {
      if ((n / 2) / (k - 1) >= b ||
          (n / 2 - k) / (k - 1) >= (1000000 - b + 1 - 1))
        continue;
    } else {
      if ((n / 2 - k) / (k - 1) >= b - 1 ||
          (n / 2) / (k - 1) >= (1000000 - b + 1))
        continue;
    }
    // 计算 minSum
    int ret = (n / 2) / (k - 1);
    int remain = (n / 2) % (k - 1);
    int minSum = b + k * c;
    for (int i = 1; i <= ret; i++) {
      if (i == c)
        ret++;
      else
        minSum += i * (k - 1);
    }
    minSum += (ret + 1) * remain;
    if (ret + 1 == b) {
      if (n / 2 <= (k - 1 - remain - 1) * b)
        minSum += (n / 2) * b;
      else {
        ret = (n / 2 - (k - 1 - remain - 1)) / (k - 1);
        remain = (n / 2 - (k - 1 - remain - 1)) % (k - 1);
        for (int i = b + 1; i <= b + 1 + ret - 1; i++) {
          if (i == c)
            ret++;
          else
            minSum += i * (k - 1);
        }
        minSum += (b + 1 + ret - 1 + 1) * remain;
      }
    }
    ret = (n / 2 - (k - 2)) / (k - 1);
    remain = (n / 2 - (k - 2)) % (k - 1);
    for (int i = b + 1; i <= b + 1 + ret - 1; i++) {
      if (i == c)
        ret++;
      else
        minSum += i * (k - 1);
    }
    minSum += (b + 1 + ret - 1 + 1) * remain;

    // 计算 maxSum
    int maxSum = b + k * c;
    for (int i = 1000000; i >= (1000000 - ret + 1); i--) {
      if (i == c)
        ret++;
      else
        maxSum += i * (k - 1);
    }
    maxSum += (1000000 - ret + 1 - 1) * remain;
    if (1000000 - ret + 1 - 1 == b) {
      if (n / 2 <= (k - 1 - remain - 1) * b)
        maxSum += (n / 2) * b;
      else {
        ret = (n / 2 - (k - 1 - remain - 1)) / (k - 1);
        remain = (n / 2 - (k - 1 - remain - 1)) % (k - 1);
        for (int i = b - 1; i >= b - 1 - ret + 1; i--) {
          if (i == c)
            ret++;
          else
            maxSum += i * (k - 1);
        }
        maxSum += (b - 1 - ret + 1 - 1) * remain;
      }
    }
    ret = (n / 2 - (k - 2)) / (k - 1);
    remain = (n / 2 - (k - 2)) % (k - 1);
    for (int i = b - 1; i >= b - 1 - ret + 1; i--) {
      if (i == c)
        ret++;
      else
        maxSum += i * (k - 1);
    }
    maxSum += (b - 1 - ret + 1 - 1) * remain;

    if (sumX >= minSum && sumX <= maxSum) {
      flag = true;
      break;
    }
  }

  if (flag == true)
    cout << "Possible" << endl;
  else
    cout << "Impossible" << endl;
  return 0;
}