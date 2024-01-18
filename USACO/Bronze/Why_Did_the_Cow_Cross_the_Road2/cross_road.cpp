#include <algorithm>
#include <fstream>
#include <unordered_set>
#include <vector>
using namespace std;

int main(void)
{
  ifstream cin("circlecross.in");
  ofstream cout("circlecross.out");

  vector<char> strCircleCross(52);
  unordered_set<char> countPairs;
  for (auto &element : strCircleCross)
  {
    cin >> element;
  }

  int ans = 0;
  for (char c = 'A'; c <= 'Z'; c++)
  {
    int countC = 0;
    for (int i = 0; i < 52; i++)
    {
      if (strCircleCross[i] == c)
      {
        if (countC == 0)
        {
          ++countC;
          continue;
        }
        else
        {
          ans += countPairs.size();
          countPairs.clear();
          break;
        }
      }
      else if (countC == 1)
      {
        auto it = find(countPairs.begin(), countPairs.end(), strCircleCross[i]);
        if (it == countPairs.end())
        {
          countPairs.insert(strCircleCross[i]);
        }
        else
        {
          countPairs.erase(it);
        }
      }
    }
  }
  ans = ans / 2;
  cout << ans << endl;
  return 0;
}