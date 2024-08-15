#include <algorithm>
#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;
using ll = long long; // 使用ll作为long long的别名
#define endl "\n"
const int MOD = 1e9 + 7; // 定义模数为1e9 + 7
int n, q;                // n是松果的数量，q是想象的场景数量
vector<ll> h, t,
    tSorted; // h存储每个松果的初始高度，t存储每个场景的投掷次数，tSorted是t的排序版本

int main() {
  cin >> n >> q;     // 从输入读取n和q
  h.resize(n + 1);   // 调整h的大小为n + 1
  t.resize(q);       // 调整t的大小为q
  tSorted.resize(q); // 调整tSorted的大小为q
  for (int i = 1; i <= n; i++)
    cin >> h[i]; // 读取每个松果的初始高度
  for (int i = 0; i < q; i++) {
    cin >> t[i];       // 读取每个场景的投掷次数
    tSorted[i] = t[i]; // 将t的值复制到tSorted
  }
  sort(h.begin(), h.end());             // 对h进行排序
  sort(tSorted.begin(), tSorted.end()); // 对tSorted进行排序
  unordered_map<ll, ll> answers;        // 存储每个场景的答案
  ll currSum = 0;                       // 当前的总高度
  ll currThrows = 0;                    // 当前的总投掷次数
  int qi = 0;                           // 当前处理的场景的索引
  for (int i = n; i > 0 && qi < q; i--) {
    int numPinecones = n - i + 1; // 当前可以投掷的松果数量
    ll numThrows = numPinecones * (h[i] - h[i - 1]); // 当前松果可以投掷的次数
    while (qi < q && tSorted[qi] < currThrows + numThrows) {
      ll extra = tSorted[qi] - currThrows;       // 额外的投掷次数
      ll fullLines = extra / numPinecones;       // 完整的投掷行数
      ll base = h[i] - fullLines;                // 基础高度
      ll remainingThrows = extra % numPinecones; // 剩余的投掷次数
      answers[tSorted[qi++]] =
          (currSum +
           numPinecones * ((h[i] + base + 1) * (h[i] - base) / 2) % MOD +
           remainingThrows * base % MOD) %
          MOD; // 计算当前场景的答案
    }
    currThrows += numThrows; // 更新总投掷次数
    currSum =
        (currSum + (numPinecones *
                    (((h[i] + h[i - 1] + 1) * (h[i] - h[i - 1]) / 2) % MOD)) %
                       MOD) %
        MOD; // 更新总高度
  }
  while (qi < q)
    answers[tSorted[qi++]] = currSum; // 对剩余的场景，答案为当前的总高度
  for (int i = 0; i < q; i++)
    cout << answers[t[i]] << '\n'; // 输出每个场景的答案
}