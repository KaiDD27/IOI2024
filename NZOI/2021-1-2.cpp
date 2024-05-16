#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main() {
  vector<string> n = {"2", "3",  "4", "5", "6", "7", "8",
                      "9", "10", "J", "Q", "K", "A"};
  vector<string> s = {"spades", "clubs", "diamonds", "hearts"};
  vector<string> sam(2);
  cin >> sam[0] >> sam[1];
  int p1 = search(n.begin(), n.end(), sam.end() - 1, sam.end()) - n.begin();
  int p2 = search(s.begin(), s.end(), sam.end() - 1, sam.end()) - s.begin();
  cout << (12 - p1) + (3 - p2) * 13 << endl;
}
