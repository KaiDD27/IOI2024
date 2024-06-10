#include <algorithm>
#include <array>
#include <iostream>
#include <vector>
using namespace std;
using ll = long long;
#define endl "\n";

const int MOD = 1e9 + 7;     // 模数，用于取模运算
ll n;                        // 块的数量
vector<char> c;              // 存储每个块的规则
vector<vector<char>> groups; // 存储每个组中的块

ll groupWay(vector<char> group) {
  vector<ll> dp;           // 每个组的动态规划表
  int size = group.size(); // 当前组的大小
  if (size == 0)
    return 1;                    // 如果组为空，跳过
  vector<vector<ll>> illegalAdj; // 非法邻接表
  illegalAdj.resize(size);

  // 处理每一个组，组与组之间是完全独立的
  for (int i = 0; i < size; i++) {
    auto ci = group[i];
    // 建立非法路径
    if (ci == 'a') {
      for (int j = i + 1; j < size; j++) {
        illegalAdj[j].push_back(i); // 添加非法路径'a'：c[j]后面放c[i]就是非法的
      }
    } else if (ci == 'r') {
      for (int j = 0; j < i; j++) {
        illegalAdj[i].push_back(j); // 添加非法路径'r'：c[i]后面放c[j]就是非法的
      }
    } else if (ci == 's') {
      for (int j = 0; j < i; j++) {
        illegalAdj[i].push_back(j); // 添加非法路径's'：c[i]后面放c[j]就是非法的
      }
      for (int j = i + 1; j < size; j++) {
        illegalAdj[j].push_back(i); // 添加非法路径's'：c[j]后面放c[i]就是非法的
      }
    }
  }

  // 开始 DP，dp表示 mask 中的组合所有的ways
  dp.resize(1 << size); // 调整当前组的动态规划表的大小
  dp[0] = 1;            // dp初始化
  for (int mask = 0; mask < (1 << size); mask++) {
    for (int i = 0; i < size; i++) {
      if (mask & (1 << i)) {
        // 先置为true
        bool valid = true;
        for (int j = 0; j < size; j++) {
          if (mask & (1 << j)) {
            // 看看j是否存在通向i的非法路径，如果存在则说明i不能放在最后
            if (find(illegalAdj[j].begin(), illegalAdj[j].end(), i) !=
                illegalAdj[j].end()) {
              valid = false; // 如果存在不合法的边，标记为无效
              break;
            }
          }
        }
        // 如果所有的j都可以放在i前面，则加上没有i的排序方式的数量，然后把i放在最后就行了。
        if (valid) {
          dp[mask] = dp[mask] + dp[mask ^ (1 << i)]; // 更新动态规划表
        }
      }
    }
  }
  return dp[(1 << size) - 1];
}

int main() {
  cin >> n;    // 读取块的数量
  c.resize(n); // 调整规则数组的大小
  for (auto &ci : c) {
    cin >> ci; // 读取每个块的规则
  }
  groups.resize(1);
  for (int i = 0, iG = 0; i < n; i++) {
    char ci = c[i];
    if (ci == 's') {
      iG++; // 每遇到一个 's' 规则，增加组计数器
      groups.push_back({});
      continue;
    }
    groups[iG].push_back(ci); // 将每个块添加到其所属的组中
  }
  ll ans = 1;
  for (int iG = 0; iG < groups.size(); iG++) {
    ans *= groupWay(groups[iG]);
    ans %= MOD;
  }
  cout << ans << endl; // 输出结果
  return 0;
}