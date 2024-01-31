#include <cstddef>
#include <iostream>
using namespace std;

struct Node {
  int data;
  Node *next;
};

int main() {
  int n, m;
  cin >> n >> m;
  Node *head, *prev, *node, *now;

  head = new Node;
  head->data = 1;
  head->next = nullptr;
  now = head;

  for (int i = 2; i <= n; i++) {
    node = new Node;
    node->data = i;
    node->next = nullptr;
    now->next = node;
    now = node;
  }
  now->next = head;
  //
}