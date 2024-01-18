#include <fstream>
#include <iostream>
#include <numeric>
#include <set>
#include <vector>

using std::cout;
using std::endl;
using std::vector;

/** Reverses [start, end] in the given vector in-place. */
template <typename T>
void reverse_segment(vector<T> &vec, int start, int end)
{
    while (start < end)
    {
        T temp = vec[start];
        vec[start] = vec[end];
        vec[end] = temp;

        start++;
        end--;
    }
}

int main()
{
    std::ifstream read("swap.in");
    int n, k;
    read >> n >> k;
    int a1, a2;
    int b1, b2;
    read >> a1 >> a2 >> b1 >> b2;

    vector<int> cows(n);
    // Assign the values 1, 2, 3... to the vector of cows
    iota(cows.begin(), cows.end(), 1);

    // Apply swaps until the cows repeat themselves
    std::set<vector<int>> visited{cows};
    while (true)
    {
        reverse_segment(cows, a1 - 1, a2 - 1);
        reverse_segment(cows, b1 - 1, b2 - 1);
        if (visited.count(cows))
        {
            break;
        }
        visited.insert(cows);
    }

    int cycle_len = visited.size();
    int swaps_left = k % cycle_len;
    for (int s = 0; s < swaps_left; s++)
    {
        reverse_segment(cows, a1 - 1, a2 - 1);
        reverse_segment(cows, b1 - 1, b2 - 1);
    }

    std::ofstream written("swap.out");
    for (int c : cows)
    {
        written << c << '\n';
    }
}