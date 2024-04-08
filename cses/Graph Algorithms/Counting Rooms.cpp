#include <iostream>
#include <vector>
using namespace std;
using ll = long long;
#define endl "\n"
vector<vector<char>> grid;
vector<vector<bool>> visited;
int dx[4] = {-1, 0, 1, 0}; // 左上右下
int dy[4] = {0, -1, 0, 1};
void dfs(int y, int x) {
  visited[y][x] = true;
  for (int i = 0; i < 4; i++) {
    int newY = y + dy[i], newX = x + dx[i];
    if (grid[newY][newX] == '.' && visited[newY][newX] == false)
      dfs(newY, newX);
  }
}
int main() {
  ios::sync_with_stdio(false); // Fast I/O
  cin.tie(nullptr); // Not safe to use cin/cout & scanf/printf together
  int n, m;
  cin >> n >> m;
  grid.resize(n + 2, vector<char>(m + 2, '#'));
  visited.resize(n + 2, vector<bool>(m + 2, false));
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      cin >> grid[i][j];
    }
  }
  int numOfRooms = 0;
  for (int line = 1; line <= n; line++)
    for (int column = 1; column <= m; column++)
      if (grid[line][column] == '.' && visited[line][column] == false) {
        dfs(line, column);
        numOfRooms++;
      }
  cout << numOfRooms << endl;
  return 0;
}