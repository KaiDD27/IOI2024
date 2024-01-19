#include <cmath>
#include <iostream>
#include <vector>

using namespace std;

struct ListNode {
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
  ListNode *reverseKGroup(ListNode *head, int k) {
    // Create a protective node, use its 'next' to point to the head of the
    // linked list
    ListNode *protect = new ListNode(0, head);
    // last is the end node of last group after reverse
    ListNode *last = protect;

    while (head != nullptr) {
      //    Grouping (move k-1 steps forward, find a group)，return stop
      ListNode *end = getEnd(head, k);
      if (end == nullptr)
        break; // not need to reverse
      ListNode *nextGroupHead = end->next;

      // Reverse Within Group
      reverseGroup(head, nextGroupHead);

      // Update the pointing relationship between each group and the previous
      // group, and the next group
      last->next = end;
      head->next = nextGroupHead;

      // move to next group
      last = head;
      head = nextGroupHead;
    }
    return protect->next;
  }

  // Return the node after moving k-1 steps
  // return nullptr if encounter nullptr
  ListNode *getEnd(ListNode *head, int k) {
    while (head != nullptr) {
      k--;
      if (k == 0)
        return head;
      head = head->next;
    }
    return nullptr;
  }

  // Reverse the linked list, stop at the node 'stop'
  // Reverse within group, do not handle the pointing and being pointed of the
  // two segments of the linked list
  void reverseGroup(ListNode *head, ListNode *stop) {
    ListNode *last = head;
    head = head->next;
    while (head != stop) {
      ListNode *nextHead;
      nextHead = head->next;
      head->next = last;
      last = head;
      head = nextHead;
    }
  }
};