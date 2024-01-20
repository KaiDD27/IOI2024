#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

// from end to find ans using listNode->prev and ->next,and then delete the
// node;

int N = 0;

struct ListNode {
  long long val;
  int idx;
  ListNode *prev;
  ListNode *next;
};

// ListNode[rk[idx]],val=num[rk[idx]]
void createListNode(vector<ListNode *> &ptrNodes, const vector<int> &nums,
                    const vector<int> &rk) {
  ListNode *minNode = new ListNode();
  ListNode *maxNode = new ListNode();
  minNode->val = nums[rk[1]] - static_cast<long long>(3 * 1e9);
  maxNode->val = nums[rk[N]] + static_cast<long long>(3 * 1e9);

  ptrNodes[rk[1]] = new ListNode();
  ptrNodes[rk[1]]->val = nums[rk[1]];
  ptrNodes[rk[1]]->idx = rk[1];

  minNode->next = ptrNodes[rk[1]];
  ptrNodes[rk[1]]->prev = minNode;

  maxNode->prev = ptrNodes[rk[1]];
  ptrNodes[rk[1]]->next = maxNode;

  for (int i = 2; i <= N; i++) {
    ptrNodes[rk[i]] = new ListNode();
    ptrNodes[rk[i]]->val = nums[rk[i]];
    ptrNodes[rk[i]]->idx = rk[i];

    ptrNodes[rk[i]]->prev = ptrNodes[rk[i - 1]];
    ptrNodes[rk[i]]->next = ptrNodes[rk[i - 1]]->next;

    ptrNodes[rk[i - 1]]->next = ptrNodes[rk[i]];
    ptrNodes[rk[i]]->next->prev = ptrNodes[rk[i]];
  }
}

void deleteNode(ListNode *curr) {
  curr->prev->next = curr->next;
  curr->next->prev = curr->prev;
  delete curr;
}

void getMinValAndIdxOfNums(vector<ListNode *> &ptrNodes,
                           vector<long long> &minVal, vector<int> &P) {
  for (int i = N; i >= 2; i--) {
    long long preVal = ptrNodes[i]->prev->val;
    long long nextVal = ptrNodes[i]->next->val;
    if (ptrNodes[i]->val - preVal <= nextVal - ptrNodes[i]->val) {
      minVal[i] = ptrNodes[i]->val - preVal;
      P[i] = ptrNodes[i]->prev->idx;
    } else {
      minVal[i] = nextVal - ptrNodes[i]->val;
      P[i] = ptrNodes[i]->next->idx;
    }
    deleteNode(ptrNodes[i]);
  }
}

int main() {

  cin >> N;
  vector<int> nums(N + 1, 0);
  vector<int> rk(N + 1, 0);

  // make a rk[] to record the idx of  nums
  for (int i = 1; i <= N; i++) {
    cin >> nums[i];
    rk[i] = i;
  }

  // sort rk[] by nums[rk[]]
  sort(rk.begin() + 1, rk.end(),
       [&nums](int a, int b) { return nums[a] < nums[b]; });

  // create ListNode
  vector<ListNode *> ptrNodes(N + 1);
  createListNode(ptrNodes, nums, rk);

  // get the minVal and idx of nums
  vector<long long> minVal(N + 1);
  vector<int> P(N + 1);
  getMinValAndIdxOfNums(ptrNodes, minVal, P);

  for (int i = 2; i <= N; i++) {
    cout << minVal[i] << " " << P[i] << endl;
  }
}