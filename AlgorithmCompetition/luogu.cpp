#include <iostream>
#include <queue>
using namespace std;
const int INFN = 100005;
const int INFM = 305;
int groupId[INFN];
int output[INFN];
queue<int> queueArray[INFM];
queue<queue<int> *> twoDQueue;
int main() {
  int n, m, T;
  cin >> n >> m;
  for (int i = 0; i < n; i++) {
    cin >> groupId[i];
  }
  cin >> T;
  int cnt = 0;

  for (int i = 1; i <= T; i++) {
    string strOp;
    int factorId;
    cin >> strOp;
    if (strOp == "push") {
      cin >> factorId;
      if (queueArray[groupId[factorId]].empty())
        twoDQueue.push(&queueArray[groupId[factorId]]);
      queueArray[groupId[factorId]].push(factorId);
    }
    if (strOp == "pop") {

      output[cnt] = twoDQueue.front()->front();
      cnt++;
      twoDQueue.front()->pop();
      if (twoDQueue.front()->empty())
        twoDQueue.pop();
    }
  }

  for (int i = 0; i < cnt; i++) {
    cout << output[i] << endl;
  }
  return 0;
}