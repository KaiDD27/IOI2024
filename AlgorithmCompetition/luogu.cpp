#include <iostream>
#include <list>
using namespace std;

int main() {
  int n, m;
  cin >> n >> m;
  list <int> nodes;
  for(int i = 1;i<=n;i++)
  {
    nodes.push_back(i);
  }  
  auto  it = nodes.begin();
  while(n-->1)
  {
    for(int i = 1;i<m;i++)
    {
      it++;
      if(it ==nodes.end())
        it = nodes.begin();  
    }
    cout << *it<< " ";
    auto nextNode = next(it);
    if(nextNode == nodes.end())
      nextNode = nodes.begin();
    nodes.erase(it);
    it = nextNode;
  }
  cout << *it<<endl;
  return 0;
}