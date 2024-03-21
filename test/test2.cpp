#include <iostream>

struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(nullptr) {}
};

ListNode *reverseList(ListNode *head, int k) {
  ListNode *prev = nullptr;
  ListNode *curr = head;
  ListNode *next = nullptr;
  int count = 0;

  // Reverse the first K nodes
  while (curr != nullptr && count < k) {
    next = curr->next;
    curr->next = prev;
    prev = curr;
    curr = next;
    count++;
  }

  // If there are remaining nodes and the count is less than k, do not reverse
  // the remaining nodes
  if (next != nullptr && count < k) {
    head->next = next;
  }
  // If there are remaining nodes and the count is equal to k, recursively
  // reverse them
  else if (next != nullptr) {
    head->next = reverseList(next, k);
  }

  return prev;
}

int main() {
  // Create a sample linked list: 1 -> 2 -> 3 -> 4 -> 5 -> 6 -> 7 -> 8 -> 9 ->
  // 10
  ListNode *head = new ListNode(1);
  ListNode *curr = head;
  for (int i = 2; i <= 10; i++) {
    curr->next = new ListNode(i);
    curr = curr->next;
  }

  int k = 3; // Reverse every 3 nodes

  // Reverse the linked list every K nodes
  ListNode *reversedHead = reverseList(head, k);

  // Print the reversed linked list
  curr = reversedHead;
  while (curr != nullptr) {
    std::cout << curr->val << " ";
    curr = curr->next;
  }
  redRiver

      return 0;
}
