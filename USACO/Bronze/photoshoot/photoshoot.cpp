/*
http://www.usaco.org/index.php?page=viewproblem2&cpid=988
SAMPLE INPUT:
5
4 6 7 6
SAMPLE OUTPUT:
3 1 5 2 4
a
 produces b
 because 3+1=4
, 1+5=6
, 5+2=7
, and 2+4=6.
*/

#include <algorithm>
#include <fstream>
#include <vector>
using namespace std;

int main(void) {
  ifstream fin("photo.in");
  ofstream fout("photo.out");
  int N;
  fin >> N;
  vector<int> B(N - 1);
  for (auto &element : B) {
    fin >> element;
  }
  vector<int> int_Count(N + 1, 1);
  vector<int> aLine(N);

  for (int i = 1; i < B[0]; i++) {
    int iA = i;
    bool flag = false;
    for (auto &count : int_Count) {
      count = 1;
    }
    int_Count[iA]--;
    aLine[0] = iA;
    for (int j = 0; j < N - 1; j++) {
      iA = B[j] - iA;
      aLine[j + 1] = iA;
      if ((iA >= 1 && iA <= N && int_Count[iA] == 1))
        int_Count[iA]--;
      else
        break;
      if ((j == N - 2) && (int_Count[iA] == 0)) {
        flag = true;
      }
    }
    if (flag == true) {
      for (int j = 0; j < N; j++) {
        if (j == N - 1)
          fout << aLine[j];
        else
          fout << aLine[j] << ' ';
      }
      break;
    }
  }
  return 0;
}