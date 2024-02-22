#include <iostream>
#include <utility>
#include <vector>

using namespace std;

vector<pair<int, int>> movDiskFromTo;
void hanoi(int num, int fromStack, int tmpStack, int toStack) {
  if (num == 1) {
    movDiskFromTo.push_back({fromStack, toStack});
    return;
  }
  hanoi(num - 1, fromStack, toStack, tmpStack);
  hanoi(1, fromStack, tmpStack, toStack);
  hanoi(num - 1, tmpStack, fromStack, toStack);

  return;
}
int main() {
  int n;
  cin >> n;
  hanoi(n, 1, 2, 3);
  cout << movDiskFromTo.size() << endl;
  for (auto fromTo : movDiskFromTo) {
    cout << fromTo.first << " " << fromTo.second << endl;
  }
  return 0;
}