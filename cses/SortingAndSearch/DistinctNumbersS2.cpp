#include <iostream>
#include <set> // Add this line to import the set library
#include <vector>
using namespace std;

int main(void) {
  int N = 0;
  cin >> N;
  vector<int> nums(N);
  for (int i = 0; i < N; i++) {
    cin >> nums[i];
  }
  set<int> s(nums.begin(), nums.end());
  cout << s.size() << endl;
  return 0;
}