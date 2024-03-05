#include <iostream>
#include <vector>

using namespace std;
typedef long long ll;
#define endl '\n'

vector<int> a;

int main() {
  int rounds, n;
  cin >> n;
  a.resize(n + 1);
  rounds = n + 1;
  a[0] = 1;
  for (int i = 0; i < n; i++) {
    int x;
    cin >> x;
    rounds -= a[x - 1];
    a[x] = 1;
  }

  cout << rounds << endl;
  return 0;
}