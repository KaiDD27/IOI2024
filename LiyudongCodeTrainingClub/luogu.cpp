#include <algorithm>
#include <fstream>
#include <iostream>
#include <stack>
#include <vector>
using namespace std;

int M, N;
int main() {
  long long ans = 0;
  stack<int> st;
  cin >> N >> M;
  vector<vector<char>> matrix(N + 2, vector<char>(M + 2));
  vector<int> h(M + 2), r(M + 2), l(M + 2);
  for (int n = 1; n <= N; n++)
    for (int m = 1; m <= M; m++) {
      cin >> matrix[n][m];
    }

  for (int n = 1; n <= N; n++) {
    for (int m = 1; m <= M; m++) {
      h[m] = matrix[n][m] == '*' ? 0 : h[m] + 1;
    }
    h[0] = 0;
    h[M + 1] = 0;
    for (int m = 1; m <= M + 1; m++) {
      while (!st.empty() && h[m] < h[st.top()]) {
        r[st.top()] = m;
        st.pop();
      }
      st.push(m);
    }
    while (!st.empty())
      st.pop();
    for (int m = M; m >= 0; m--) {
      while (!st.empty() && h[m] <= h[st.top()]) {
        l[st.top()] = m;
        st.pop();
      }
      st.push(m);
    }
    for (int m = 1; m <= M; m++) {
      ans += (m - l[m]) * (r[m] - m) * h[m];
    }
    //    cout << ans << endl;
  }

  cout << ans << endl;
  return 0;
}