#include <algorithm>
#include <array>
#include <cstdlib>
#include <iostream>
#include <vector>
using namespace std;

int main() {
  int location;
  int min_distances[3];
  for (int i = 0; i < 3; ++i) {
    cin >> min_distances[i];
  }
  cin >> location;
  for (int i = 0; i < 3; ++i) {
    int remainder = location % min_distances[i];
    min_distances[i] = min(remainder, min_distances[i] - remainder);
  }
  sort(min_distances, min_distances + 3);
  cout << min_distances[0] << '\n';
  if (min_distances[0] == min_distances[1])
    cout << "can't make up my mind\n";
}