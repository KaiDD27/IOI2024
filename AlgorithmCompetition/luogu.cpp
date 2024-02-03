#include <iostream>
#include <queue>
#include <vector>
using namespace std;
const int INFN = 100005;
const int INFM = 305;
int groupId[INFN] = {-1};
vector<queue<int>> twoDQueue;

int main() {
  int n, m, T;
  cin >> n >> m;
  for (int i = 0; i < n; i++) {
    cin >> groupId[i];
  }

  for (int i = 1; i <= T; i++) {
    string strOp;
    int factorId;
    cin >> strOp >> factorId;
  }
}