/*
http://www.usaco.org/index.php?page=viewproblem2&cpid=964
SAMPLE INPUT:
7
ABCDABC
SAMPLE OUTPUT:
4
*/

#include <algorithm>
#include <fstream>
#include <set>
#include <vector>

using namespace std;

int N = 0;

string strMailboxes;
int main(void) {
  ifstream fin("whereami.in");
  ofstream fout("whereami.out");
  fin >> N;
  fin >> strMailboxes;

  for (int k = 1; k <= N; k++) {
    set<string> setSubstrings;
    for (int i = k; i <= N; i++) {
      setSubstrings.insert(strMailboxes.substr(i - k, k));
    }

    if (setSubstrings.size() == N - k + 1) {
      fout << k << endl;
      break;
    }
  }
}