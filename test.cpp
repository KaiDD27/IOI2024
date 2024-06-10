#include <algorithm>
#include <array>
#include <iostream>
#include <set>
#include <vector>
using namespace std;
using ll = long long;
#define endl "\n";

const int MOD = 1e9 + 7; // 模数，用于取模运算

const int MAX_GROUP = 125; // 最大组数

int n;                         // 块的数量
vector<char> c;                // 存储每个块的规则
vector<ll> groupId;            // 存储每个块所属的组ID
vector<vector<ll>> groups;     // 存储每个组中的块
vector<vector<ll>> illegalAdj; // 非法邻接表
vector<vector<ll>> groupDP;    // 每个组的动态规划表

int main() {
  cin >> n;             // 读取块的数量
  groupId.resize(n);    // 调整 group_id 的大小
  illegalAdj.resize(n); // 调整邻接表的大小
  c.resize(n);          // 调整规则数组的大小
  for (auto &ci : c)
    cin >> ci; // 读取每个块的规则

  int groupCnt = 0; // 组计数器
  for (int i = 0; i < n; i++) {
    char ci = c[i];
    if (ci == 's') {
      groupCnt++; // 每遇到一个 's' 规则，增加组计数器
    }
    groupId[i] = groupCnt; // 将当前块分配到当前组
    if (ci == 'a') {
      for (int j = i + 1; j < n; j++) {
        illegalAdj[j].push_back(
            i); // 添加非法路径'a' ：c[j]后面放c[i]就是非法的
      }
    } else if (ci == 'r') {
      for (int j = 0; j < i; j++) {
        illegalAdj[i].push_back(
            j); // 添加非法路径'r' ：c[i]后面放c[j]就是非法的
      }
    } else if (ci == 's') {
      for (int j = 0; j < i; j++) {
        illegalAdj[i].push_back(
            j); // 添加非法路径's' ：c[i]后面放c[j]就是非法的
      }
      for (int j = i + 1; j < n; j++) {
        illegalAdj[j].push_back(
            i); // 添加非法路径's' ：c[j]后面放c[i]就是非法的
      }
    }
  }
  groupCnt++;              // 增加组计数器
  groups.resize(groupCnt); // 调整组的大小
  groupDP.resize(groupCnt);
  for (int i = 0; i < n; i++) {
    groups[groupId[i]].push_back(i); // 将每个块添加到其所属的组中
  }
  ll ans = 1;
  for (int g = 0; g < groupCnt; g++) {
    int size = groups[g].size(); // 当前组的大小
    if (size == 0)
      continue;                   // 如果组为空，跳过
    groupDP[g].resize(1 << size); // 调整当前组的动态规划表的大小

    for (int mask = 0; mask < (1 << size); mask++) {
      if (__builtin_popcount(mask) == 1) {
        groupDP[g][mask] = 1; // 如果掩码中只有一个块，初始化为1
      } else {
        for (int i = 0; i < size; i++) {
          if (mask & (1 << i)) {
            // 先置为true
            bool valid = true;
            for (int j = 0; j < size; j++) {
              if (mask & (1 << j)) {
                // 看看j 是否存在通向 i 的非法路径，如果存在则说明i
                // 不能放在最后
                if (find(illegalAdj[groups[g][j]].begin(),
                         illegalAdj[groups[g][j]].end(),
                         groups[g][i]) != illegalAdj[groups[g][j]].end()) {
                  valid = false; // 如果存在不合法的边，标记为无效
                  break;
                }
              }
            }
            // 如果所有的j都可以放在i前面，则加上没有 i
            // 的排序方式的数量，然后把i放在最后就行了。
            if (valid) {
              groupDP[g][mask] = groupDP[g][mask] +
                                 groupDP[g][mask ^ (1 << i)]; // 更新动态规划表
            }
          }
        }
      }
    }
    ans *= groupDP[g][(1 << size) - 1];
    ans %= MOD;
  }
  cout << ans << endl; // 输出结果
  return 0;
}