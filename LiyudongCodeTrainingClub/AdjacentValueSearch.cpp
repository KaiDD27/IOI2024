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

void deleteNode(ListNode *curr) {
  curr->prev->next = curr->next;
  curr->next->prev = curr->prev;
  delete curr;
}

ListNode *addNode(ListNode *node, int idx, const vector<int> &nums) {
  ListNode *newNode = new ListNode();
  newNode->val = nums[idx];
  newNode->idx = idx;

  newNode->prev = node;
  newNode->next = node->next;

  node->next = newNode;
  newNode->next->prev = newNode;
  return newNode;
}

// ListNode[rk[idx]],val=num[rk[idx]
void createListNode(vector<ListNode *> &ptrNodes, const vector<int> nums,
                    const vector<int> &rk) {
  ListNode *minNode = new ListNode();
  ListNode *maxNode = new ListNode();
  minNode->val = nums[rk[1]] - static_cast<long long>(3 * 1e9);
  maxNode->val = nums[rk[N]] + static_cast<long long>(3 * 1e9);
  minNode->next = maxNode;
  maxNode->prev = minNode;

  for (int i = 1; i <= N; i++) {
    ptrNodes[rk[i]] = addNode(maxNode->prev, rk[i], nums);
  }
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

/**
 * The main function reads input values, creates a sorted index array,
 * creates a linked list, and calculates the minimum value and index
 * for each element in the array. Finally, it prints the minimum value
 * and index for each element (starting from the second element) in the array.
 */
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