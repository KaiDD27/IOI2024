#include <iostream>

using namespace std;

int main() {
  int n;
  cin >> n;

  if (n % 4 == 0) {
    cout << "YES" << endl;
    cout << n / 2 << endl;
    for (int i = 1; i <= n; i = i + 4)
      cout << i << " " << i + 3 << " ";
    cout << endl << n / 2 << endl;
    for (int i = 2; i <= n; i = i + 4)
      cout << i << " " << i + 1 << " ";
    cout << endl;
  } else if (n % 4 == 3) {
    cout << "YES" << endl;
    cout << n / 2 + 1 << endl;
    cout << 1 << " " << 2 << " ";
    for (int i = 4; i <= n; i = i + 4)
      cout << i << " " << i + 3 << " ";
    cout << endl << n / 2 << endl;
    cout << 3 << " ";
    for (int i = 5; i <= n; i = i + 4)
      cout << i << " " << i + 1 << " ";
    cout << endl;
  } else {
    cout << "NO" << endl;
  }
  return 0;
}