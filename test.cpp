#include <iostream>
#include <unordered_set>
#include <vector>
using namespace std;
int n, a[100000];
long long b[100000];
unordered_set<long long> conditions[100000], cantFriend;
bool formed[100000];
int main() {
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> a[i] >> b[i];
    for (long long j = 2 * a[i]; j < b[i]; j += a[i]) {
      conditions[i].insert(j);
    }
    cantFriend.insert(b[i]);
  }
  for (int i = 0; i < n; i++) {
    int minIdx = -1;
    for (int j = 0; j < n; j++) {
      if (formed[j])
        continue;
      if (conditions[j].size() > 0)
        continue;
      if (cantFriend.find(a[j]) != cantFriend.end())
        continue;
      if (minIdx == -1 || a[minIdx] > a[j]) {
        minIdx = j;
      }
    }
    cout << a[minIdx] << " ";
    formed[minIdx] = true;
    for (int i = 0; i < n; i++) {
      conditions[i].erase(a[minIdx]);
      conditions[i].erase(b[minIdx]);
    }
    cantFriend.erase(b[minIdx]);
  }
  cout << endl;
}