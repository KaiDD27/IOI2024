#include <iostream>
#include <vector>
#include <algorithm>

int main()
{
    int N;
    std::cin >> N;

    std::vector<char> S(N);
    for (int i = 0; i < N; ++i)
    {
        std::cin >> S[i];
    }

    if (std::count(S.begin(), S.end(), 'F') == N)
    {
        S[0] = 'E';
    }

    std::vector<int> positions;
    for (int i = 0; i < N; ++i)
    {
        if (S[i] != 'F')
        {
            positions.push_back(i);
        }
    }

    int ones = positions[0] + N - 1 - positions.back();
    int mn = 0, mx = 0;
    for (size_t i = 0; i < positions.size() - 1; ++i)
    {
        mn += ((positions[i + 1] - positions[i]) % 2) ^ (S[positions[i]] != S[positions[i + 1]]);
        mx += positions[i + 1] - positions[i] - (S[positions[i]] != S[positions[i + 1]]);
    }

    std::vector<int> ans;
    for (int i = mn; i <= ones + mx; i += 1 + (ones == 0))
    {
        ans.push_back(i);
    }

    std::cout << ans.size() << std::endl;
    for (const auto &level : ans)
    {
        std::cout << level << std::endl;
    }

    return 0;
}