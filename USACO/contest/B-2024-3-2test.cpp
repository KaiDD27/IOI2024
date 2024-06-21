#include <cmath>
#include <iostream>
#include <vector>

using namespace std;

struct Point {
  int x, y;
};

double distance(Point a, Point b) { return abs(a.x - b.x) + abs(a.y - b.y); }

int main() {
  int N, P;
  cin >> N >> P;

  vector<Point> fence(P);
  for (int i = 0; i < P; i++) {
    cin >> fence[i].x >> fence[i].y;
  }

  double total_length = 0;
  for (int i = 0; i < P; i++) {
    total_length += distance(fence[i], fence[(i + 1) % P]);
  }

  for (int i = 0; i < N; i++) {
    Point start, end;
    cin >> start.x >> start.y >> end.x >> end.y;

    double dist_clockwise = 0;
    double dist_to_start = 0;
    bool start_found = false, end_found = false;

    for (int j = 0; j < P; j++) {
      Point curr = fence[j];
      Point next = fence[(j + 1) % P];

      if (!start_found && (curr.x == start.x && curr.y == start.y)) {
        start_found = true;
      }
      if (!end_found && (curr.x == end.x && curr.y == end.y)) {
        end_found = true;
      }

      double segment_length = distance(curr, next);

      if (start_found && !end_found) {
        dist_clockwise += segment_length;
      }
      if (!start_found) {
        dist_to_start += segment_length;
      }

      if (start.x == curr.x && start.y >= min(curr.y, next.y) &&
          start.y <= max(curr.y, next.y)) {
        start_found = true;
        dist_clockwise += abs(start.y - curr.y);
      }
      if (start.y == curr.y && start.x >= min(curr.x, next.x) &&
          start.x <= max(curr.x, next.x)) {
        start_found = true;
        dist_clockwise += abs(start.x - curr.x);
      }
      if (end.x == curr.x && end.y >= min(curr.y, next.y) &&
          end.y <= max(curr.y, next.y)) {
        end_found = true;
        dist_clockwise += abs(end.y - curr.y);
      }
      if (end.y == curr.y && end.x >= min(curr.x, next.x) &&
          end.x <= max(curr.x, next.x)) {
        end_found = true;
        dist_clockwise += abs(end.x - curr.x);
      }

      if (start_found && end_found)
        break;
    }

    double dist_counterclockwise = total_length - dist_clockwise;
    cout << (int)min(dist_clockwise, dist_counterclockwise) << endl;
  }

  return 0;
}