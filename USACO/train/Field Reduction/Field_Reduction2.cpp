#include <cstdio>
#include <vector>
#include <algorithm>

#define NMAX 100000

int N;
long long x[NMAX];
long long y[NMAX];
#define infinite 1000000000

struct Analysis {
  long long area;
  std::vector<std::vector<int> > borders;
};

Analysis analyze(std::vector<int> indicesToSkip) {
  long long minX = infinite, minY = infinite, maxX = -infinite, maxY = -infinite;
  for (int i = 0; i < N; i++) {
    bool skip = false;
    for (int j = 0; j < indicesToSkip.size(); j++) {
      if (indicesToSkip[j] == i) {
	skip = true;
      }
    }

    if (skip) continue;

    minX = std::min(minX, x[i]);
    maxX = std::max(maxX, x[i]);
    minY = std::min(minY, y[i]);
    maxY = std::max(maxY, y[i]);
  }

  Analysis a;
  a.area = (maxX - minX) * (maxY - minY);

  std::vector<int> up, down, left, right;

  for (int i = 0; i < N; i++) {
    bool skip = false;
    for (int j = 0; j < indicesToSkip.size(); j++) {
      if (indicesToSkip[j] == i) {
	skip = true;
      }
    }

    if (skip) continue;

    if (x[i] == minX) left.push_back(i);
    if (x[i] == maxX) right.push_back(i);
    if (y[i] == minY) up.push_back(i);
    if (y[i] == maxY) down.push_back(i);
  } 

  if (up.size() <= 3) a.borders.push_back(up);
  if (down.size() <= 3) a.borders.push_back(down);
  if (left.size() <= 3) a.borders.push_back(left);
  if (right.size() <= 3) a.borders.push_back(right);

  return a;
}

int main() {
  freopen("reduce.in", "r", stdin);
  freopen("reduce.out", "w", stdout);
    
  scanf("%d", &N);
  for (int i = 0; i < N; i++) {
    scanf("%lld", &x[i]);
    scanf("%lld", &y[i]);
  }

  Analysis a = analyze(std::vector<int>());
  long long bestArea = a.area;

  for (std::vector<int> pointsOnBorder : a.borders) {
    Analysis smallerAnalysis = analyze(pointsOnBorder);
    bestArea = std::min(bestArea, smallerAnalysis.area);
    for (std::vector<int> pointsOnBorder2 : smallerAnalysis.borders) {
      if (pointsOnBorder2.size() + pointsOnBorder.size() <= 3) {
	for (int p : pointsOnBorder) {
	  pointsOnBorder2.push_back(p);
	}
	Analysis analysis3 = analyze(pointsOnBorder2);
	bestArea = std::min(bestArea, analysis3.area);
	for (std::vector<int> pointsOnBorder3 : analysis3.borders) {
	  if (pointsOnBorder2.size() + pointsOnBorder3.size() <= 3) {
	    for (int p : pointsOnBorder2) {
	      pointsOnBorder3.push_back(p);
	    }
	    Analysis analysis4 = analyze(pointsOnBorder3);
	    bestArea = std::min(bestArea, analysis4.area);
	  }
	}
      }
    }
  }

  printf("%lld\n", bestArea);
}