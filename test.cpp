#include <algorithm>
#include <cassert>
#include <iostream>
#include <map>
#include <numeric>
#include <set>
#include <vector>

using namespace std;
using ll = long long;
#define endl "\n"

// 生成最小或最大均值序列
vector<int> generate(int mode_freq, int p1, int p2, int direction, int n,
                     int median, int mode) {
  vector<int> sequence(mode_freq, mode);
  sequence.push_back(median);
  map<int, int> counts;
  for (int x : sequence)
    counts[x]++;

  // 取 n/2 个小于中位数的元素
  for (int x = 0; x < n / 2 - (mode < median ? mode_freq : 0); ++x) {
    while (counts[p1] >= mode_freq - 1)
      p1 += direction;
    counts[p1]++;
    sequence.push_back(p1);
  }

  // 取 n/2 个大于中位数的元素
  for (int x = 0; x < n / 2 - (mode > median ? mode_freq : 0); ++x) {
    while (counts[p2] >= mode_freq - 1)
      p2 += direction;
    counts[p2]++;
    sequence.push_back(p2);
  }

  assert(*min_element(sequence.begin(), sequence.end()) >= 1 &&
         *max_element(sequence.begin(), sequence.end()) <= 1000000);
  return sequence;
}

// 计算从 a 到 b 的数列和
int series_sum(int a, int b) {
  if (a > b)
    return series_sum(b, a);
  return b * (b + 1) / 2 - a * (a - 1) / 2;
}

// 计算最小或最大和
pair<int, int> calc(int area, int height, int mx, int start_pos, int mode) {
  int subtotal = 0;
  int width = area / height;
  int remainder = area % height;
  int end_pos = start_pos - width * mx + mx;

  if (start_pos * mx >= mode * mx && mode * mx >= end_pos * mx) {
    end_pos -= mx;
    subtotal -= mode * height;
  }

  if (width)
    subtotal += series_sum(start_pos, end_pos) * height;
  if (remainder && end_pos - mx == mode)
    end_pos -= mx;
  if (remainder && end_pos - mx != mode)
    subtotal += remainder * (end_pos - mx);

  return {subtotal, end_pos};
}

// 查找最小或最大和
int find_min_max(int mode_freq, int mx, int n, int median, int mode) {
  int total = mode * mode_freq;
  int height = mode_freq - 1;
  int area = n / 2;

  if (mode * mx > median * mx)
    area -= mode_freq;
  auto [subtotal, end_pos] =
      calc(area, height, mx, mx == 1 ? 1000000 : 1, mode);
  total += subtotal;

  area = n / 2 + 1;
  if (mode * mx < median * mx)
    area -= mode_freq;
  if (end_pos - mx == median) {
    total -= (end_pos - mx) * median;
    area += end_pos - mx;
  }
  total += calc(area, height, mx, median, mode).first;

  return total;
}

// 解决问题
void solve_average_problem(int n, int mean, int median, int mode) {
  if (mean == median && median == mode) {
    cout << "Possible" << endl;
    for (int i = 0; i < n; ++i)
      cout << mean << " ";
    return;
  }

  if (n == 1) {
    cout << "Impossible\n";
    return;
  }

  if (n == 3) {
    int x = n * mean - 2 * median;
    if (median != mode) {
      cout << "Impossible" << endl;
    } else if (x < 1 || x > 1000000) {
      cout << "Impossible" << endl;
    } else {
      cout << "Possible" << endl;
      cout << median << " " << median << " " << x << endl;
    }
    return;
  }

  ll sumX = n * mean;
  ll d = (n - 3) / 2;
  if (median == mode) {
    ll ret = (sumX - (d - 1 + 3) * mode) / (d + 1);
    ll remain = (sumX - (d - 1 + 3) * mode) % (d + 1);
    if (ret >= 1 && (ret < 1000000 || (ret == 1000000 && remain == 0))) {
      cout << "Possible" << endl;
      for (int i = 0; i < d + 2; i++)
        cout << mode << " ";
      for (int i = 0; i < d + 1 - remain; i++) {
        cout << ret << " ";
      }
      for (int i = 0; i < remain; i++) {
        cout << ret + 1 << " ";
      }
    } else
      cout << "Impossible" << endl;
    return;
  }

  for (int mode_freq = 2; mode_freq <= n / 2; ++mode_freq) {
    int height = mode_freq - 1;
    int right_spaces = (1000000 - median) * height + height - 1;
    int left_spaces = (median - 1) * height + height - 1;
    if (mode < median)
      left_spaces += 1;
    if (mode > median)
      right_spaces += 1;
    if (min(left_spaces, right_spaces) < n / 2)
      continue;

    int x = find_min_max(mode_freq, -1, n, median, mode);
    int y = find_min_max(mode_freq, 1, n, median, mode);
    if (x <= mean * n && mean * n <= y) {
      vector<int> sequence = generate(mode_freq, 1, median, 1, n, median, mode);
      sort(sequence.rbegin(), sequence.rend());
      map<int, int> counts;
      for (int x : sequence)
        counts[x]++;
      int total = accumulate(sequence.begin(), sequence.end(), 0);
      int p = 1000000;
      for (int i = 0; i < sequence.size(); ++i) {
        if (i == n / 2)
          p = median;
        if (sequence[i] == mode)
          continue;
        counts[sequence[i]]--;
        total -= sequence[i];
        while (counts[p] >= mode_freq - 1)
          p--;
        sequence[i] = min(p, mean * n - total);
        counts[sequence[i]]++;
        total += sequence[i];
      }
      cout << "Possible\n";
      for (int x : sequence)
        cout << x << " ";
      cout << "\n";
      return;
    }
  }

  cout << "Impossible\n";
}

int main() {
  int n, mean, median, mode;
  cin >> n >> mean >> median >> mode;
  solve_average_problem(n, mean, median, mode);
  return 0;
}
