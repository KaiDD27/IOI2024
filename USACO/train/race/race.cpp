#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;
int N, K;
vector<int> speeds;
int sum(int minVal, int maxVal)
{
    return (minVal + maxVal) * (maxVal - minVal + 1) / 2;
}

int GetShortestTime(int finishSpeed)
{
    int shortestTime = 0;
    int distance = 0;
    int maxSpeed = 1;

    for (maxSpeed = 1; maxSpeed <= finishSpeed; maxSpeed++)
    {
        if (sum(1, maxSpeed) >= K)
        {
            return maxSpeed;
        }
    }
    shortestTime = maxSpeed;
    distance = sum(1, maxSpeed);

    if (distance + finishSpeed >= K)
    {
        return ++shortestTime;
    }
    else if (distance + finishSpeed + 1 + finishSpeed >= K)
    {
        return shortestTime + 2;
    }

    int distanceA = distance;
    maxSpeed = finishSpeed + 2;
    distance = distanceA + finishSpeed + 1;
    shortestTime++;
    for (; maxSpeed <= 1000000000; maxSpeed++)
    {
        if (sum(1, maxSpeed) + sum(finishSpeed + 1, maxSpeed - 1) >= K)
        {
            maxSpeed--;
            break;
        }
    }

    distance = sum(1, maxSpeed - 1) + sum(finishSpeed + 1, maxSpeed - 1) + 1; // 加上最小冲刺距离和时间
    shortestTime = maxSpeed - 1 + maxSpeed - 1 - finishSpeed + 1;
    shortestTime = shortestTime + (K - distance) / maxSpeed;
    if ((K - distance) % maxSpeed > (finishSpeed - 1))
    {
        shortestTime++;
    }

    return shortestTime;
}
int main()
{
    ifstream fin("race.in");
    ofstream fout("race.out");
    fin >> K >> N;
    speeds.resize(N);
    for (int i = 0; i < N; i++)
    {
        fin >> speeds[i];
    }
    for (int i = 0; i < N; i++)
    {
        fout << GetShortestTime(speeds[i]) << endl;
    }
}