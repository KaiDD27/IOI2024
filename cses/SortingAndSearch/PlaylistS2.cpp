#include <algorithm>
#include <iostream>
#include <map>
using namespace std;
typedef long long ll;
#define endl '\n'
map<int, int> mpSong;

int main() {
  int n, ans = 0;
  cin >> n;
  for (int i = 0, start = 0; i < n; i++) {
    int id;
    cin >> id;
    auto it = mpSong.find(id);
    if (it != mpSong.end() && mpSong[id] >= start) {
      start = mpSong[id] + 1;
    }
    mpSong[id] = i; // 此id的歌曲最后一次出现的序号i 存入map，key 为id。
    ans = max(ans, i - start + 1);
  }
  cout << ans << endl;
  return 0;
}
