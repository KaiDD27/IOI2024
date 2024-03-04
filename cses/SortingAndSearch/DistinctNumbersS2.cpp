#include <iostream>
#include <set>
using namespace std;
set<int> mSet;
int main(void) {
  int n = 0;
  cin >> n;
  for (int i = 0; i < n; i++) {
    int num;
    cin >> num;
    mSet.insert(num);
  }
  cout << mSet.size() << endl;
  return 0;
}