#include <array>
#include <iostream>
#include <vector>

using namespace std;
using ll = long long;
#define endl "\n"
vector<ll> a;
vector<ll> ball;

int main() {
  ios::sync_with_stdio(false); // Fast I/O
  cin.tie(nullptr); // Not safe to use cin/cout & scanf/printf together
  int n;
  cin >> n;
  a.resize(n);
  for (auto &ai : a) {
    cin >> ai;
    ball.push_back(ai);
    while (1) {
      if (ball.size() <= 1)
        break;
      if (ball[ball.size() - 1] != ball[ball.size() - 2])
        break;
      else {
        ball.pop_back();
        ball.back() = ball.back() + 1;
      }
    }
  }

  cout << ball.size() << endl;
  return 0;
}