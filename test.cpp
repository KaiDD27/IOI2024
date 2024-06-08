#include <array>
#include <chrono>
#include <iostream>
#include <iterator>
#include <map>
#include <set>
#include <unordered_set>
#include <vector>
using namespace std;
using ll = long long;
#define endl "\n"
set<ll> columns;
map<ll, vector<ll>> rows;
int main() {
  ios::sync_with_stdio(false); // Fast I/O
  cin.tie(nullptr); // Not safe to use cin/cout & scanf/printf together
  ll r, c;
  cin >> r >> c;
  for (int i = 1; i <= c; i++) {
    columns.insert(i);
  }
  for (int i = 1; i <= r; i++) {
    vector<ll> row(c + 1);
    for (int j = 1; j <= c; j++) {
      cin >> row[j];
    }
    rows[i] = row;
  }

  ll lastColumn = 0;
  for (int i = 1; i <= c; i++) {
    if (rows.size() == 0) {
      for (auto ci : columns) {
        cout << ci << " asc" << endl;
      }
      return 0;
    }
    for (auto column : columns) {
      bool asc = true, desc = true;
      for (auto it = next(rows.begin()); it != rows.end(); it++) {
        if ((it->first == prev(it)->first + 1) &&
            (it->second[lastColumn] == prev(it)->second[lastColumn]) &&
            (it->second)[column] < (prev(it)->second)[column]) {
          asc = false;
          break;
        }
      }
      for (auto it = next(rows.begin()); it != rows.end(); it++) {
        if ((it->first == prev(it)->first + 1) &&
            (it->second[lastColumn] == prev(it)->second[lastColumn]) &&
            (it->second)[column] > (prev(it)->second)[column]) {
          desc = false;
          break;
        }
      }
      if (asc == true) {
        cout << column << " asc" << endl;
        columns.erase(columns.find(column));
        bool flagTie = false;
        for (auto it = rows.begin(); next(it) != rows.end();) {
          if (flagTie == true) {
          }

          if ((it->first == next(it)->first - 1) &&
              it->second[column] != next(it)->second[column]) {
            auto eraseIt = it;
            it++;
            rows.erase(eraseIt);
          } else {
            it++;
          }
        }
        lastColumn = column;
        break;
      } else if (desc == true) {
        cout << column << " desc" << endl;
        columns.erase(columns.find(column));
        for (auto it = next(rows.begin()); it != rows.end();) {
          if (it->second[column] != prev(it)->second[column]) {
            rows.erase(prev(it));
            it++;
          } else {
            it++;
            if (it != rows.end())
              it++;
          }
        }
        lastColumn = column;
        break;
      }
    }
  }
  return 0;
}