#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>

using namespace std;

const int MAX_COORD = 500;
const int MAX_COST = 708;

struct City {
  int x, y;
};

int distance(const City &a, const City &b) {
  return ceil(sqrt(pow(a.x - b.x, 2) + pow(a.y - b.y, 2)));
}

int main() {
  int N, M;
  cin >> N >> M;

  vector<City> cities(N);
  for (int i = 0; i < N; i++) {
    cin >> cities[i].x >> cities[i].y;
  }

  vector<int> stops(M);
  for (int i = 0; i < M; i++) {
    cin >> stops[i];
  }

  vector<int> unreachable(N);
  for (int i = 0; i < N; i++) {
    unreachable[i] = i;
  }

  vector<int> answers(M);
  int money = 0;

  for (int i = M - 1; i >= 0; i--) {
    int current_city = stops[i];
    vector<int> new_unreachable;

    for (int city : unreachable) {
      if (city != current_city) {
        int cost = distance(cities[current_city], cities[city]);
        if (cost > money) {
          new_unreachable.push_back(city);
        }
      }
    }

    answers[i] = N - new_unreachable.size() - 1;
    unreachable = move(new_unreachable);

    if (i > 0) {
      money += distance(cities[stops[i]], cities[stops[i - 1]]);
      if (money >= MAX_COST) {
        fill(answers.begin(), answers.begin() + i, N - 1);
        break;
      }
    }
  }

  for (int i = 0; i < M; i++) {
    cout << answers[i] << (i == M - 1 ? '\n' : ' ');
  }

  return 0;
}