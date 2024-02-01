#include <iostream>
#include <list>
#include <vector>

using namespace std;

int main() {
  int N, M;
  cin >> N;

  vector<list<int>::iterator> pos(N + 1);
  vector<bool> erase(N + 1, false);
  list<int> lst;

  for (int i = 1; i <= N; i++) {
    lst.push_back(i);
    pos[i] = prev(lst.end());
  }

  for (int i = 2; i <= N; i++) {
    int target, prevOrNext;
    cin >> target >> prevOrNext;
    lst.erase(pos[i]);
    if (prevOrNext == 0) {
      lst.insert(pos[target], i);
    } else {
      auto nextPos = next(pos[target]);
      if (nextPos == lst.end()) {
        lst.push_back(i);
      } else {
        lst.insert(nextPos, i);
      }
    }
    pos[i] = prev(pos[target]);
  }

  cin >> M;

  while (M-- && !lst.empty()) {
    int deleteId;
    cin >> deleteId;
    if (erase[deleteId] != true)
      lst.erase(pos[deleteId]);
    erase[deleteId] = true;
  }

  for (int num : lst) {
    cout << num << " ";
  }

  return 0;
}