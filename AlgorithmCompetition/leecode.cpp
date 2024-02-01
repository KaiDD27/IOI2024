#include <iostream>
#include <vector>
using namespace std;


 
class Solution {
public:
    struct ListNode {
        int val;
        ListNode *next;
        ListNode() : val(0), next(nullptr) {}
        ListNode(int x) : val(x), next(nullptr) {}
        ListNode(int x, ListNode *next) : val(x), next(next) {}
    };
    vector<int> reverseBookList(ListNode* head)
        {
      ListNode * prev = nullptr,*now = head,*next = head;
      while(now!=nullptr)
      {
        next = now->next;
        now->next = prev;
        prev = now;
        now = next;
      }
      head  = prev;
      vector<int> nodes;
      while(head!=nullptr){
        nodes.push_back(head->val);
        head = head->next;
      }
      return nodes;    
    }
};

int main()
{
    return 0;
}