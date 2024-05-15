#include <algorithm>
#include <array>
#include <cmath>
#include <deque>
#include <iostream>
#include <vector>
using namespace std;

int n, m;

struct Warrior {
  int id, L, R; // id: 战士的编号；L、R：战士的左右区间
};

// 自定义比较函数，用于按左端点排序
bool compareWarrior(const Warrior &a, const Warrior &b) { return a.L < b.L; }

vector<Warrior> w;
vector<vector<int>> go;
vector<int> res;

void init(int n2) { // 贪心 + 预计算倍增
  int nxt = 1;
  for (int i = 1; i <= n2; ++i) { // 用贪心求每个区间的下一个区间
    while (nxt <= n2 && w[nxt].L <= w[i].R)
      nxt++; // 每个区间的下一个是右端点最大的那个区间
    go[i][0] = nxt - 1; // 区间i的下一个区间
  }
  for (int i = 1; (1 << i) <= n; ++i) { // 倍增：i=1,2,4,8,... 共log(n)次
    for (int s = 1; s <= n2; ++s) {     // 每个区间后的第2^i个区间
      go[s][i] = go[go[s][i - 1]][i - 1];
    }
  }
}

void getans(int x) { // 从第x个战士出发
  int len = w[x].L + m, cur = x, ans = 1;
  for (int i = log2(n * 2); i >= 0; i--) { // 从最大的i开始找：2^i = N
    int pos = go[cur][i];
    if (pos && w[pos].R < len) {
      ans += 1 << i; // 累加跳过的区
      cur = pos;     // 从新位置继续开始
    }
  }
  res[w[x].id] = ans + 1;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  cin >> n >> m;

  // 动态调整数组大小
  w.resize(n * 2 + 1);
  go.resize(n * 2 + 1, vector<int>(20));
  res.resize(n + 1);

  for (int i = 1; i <= n; i++) {
    w[i].id = i; // 记录战士的顺序
    cin >> w[i].L >> w[i].R;
    if (w[i].R < w[i].L)
      w[i].R += m; // 把环变成链
  }
  sort(w.begin() + 1, w.begin() + n + 1, compareWarrior); // 按左端点排序

  for (int i = 1; i <= n; i++) { // 拆环加倍成一条链
    w[n + i] = w[i];
    w[n + i].L += m;
    w[n + i].R += m;
  }

  init(n * 2);

  for (int i = 1; i <= n; i++)
    getans(i); // 逐个计算每个战士
  for (int i = 1; i <= n; i++)
    cout << res[i] << " ";
  cout << endl;

  return 0;
}
