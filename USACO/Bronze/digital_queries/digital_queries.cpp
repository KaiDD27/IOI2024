#include <vector>
#include <iostream>
#include <cmath>

using namespace std;
int Q;

long long pow10(int exp)
{
    long long product = 1;
    for (int i = 0; i < exp; i++)
    {
        product *= 10;
    }
    return product;
}
int main()
{
    cin >> Q;
    for (int q = 0; q < Q; q++)
    {
        unsigned long long K;
        cin >> K;
        char ans = ' ';
        int n = 1;

        while (K > 9 * n * pow10(n - 1))
        {
            K -= 9 * n * pow10(n - 1);
            n++;
        }
        unsigned long long num = (K - 1) / n + pow10(n - 1);
        string num_str = to_string(num);
        ans = num_str[(K - 1) % n];
        cout << ans << endl;
    }
    return 0;
}