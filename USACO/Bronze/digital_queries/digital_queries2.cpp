#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

// Returns 10 to the power of "exp"
// Not using pow() because it can be inaccurate for large powers
ll pow10(int exp)
{
    ll product = 1;
    for (int i = 0; i < exp; i++)
    {
        product *= 10;
    }
    return product;
}

int main()
{
    int q;
    ll k;
    cin >> q;

    for (int i = 0; i < q; i++)
    {
        cin >> k;
        /*
         * Subtract k by sizes of groups until k becomes smaller than the size
         * of the current group. This produces the same effect as summing group
         * sizes until k becomes less than or equal to the sum. By the time the
         * while loop ends, k - 1 will equal j.
         */
        int n = 1;
        while (k > n * 9 * pow10(n - 1))
        {
            k -= n * 9 * pow10(n - 1);
            n++;
        }

        // The exact number the kth digit is in
        long num = (k - 1) / n + pow10(n - 1);
        // The location in num of the kth digit
        int loc = (int)((k - 1) % n);
        // Determine answer by converting num to string and indexing at loc
        cout << to_string(num)[loc] << endl;
    }
}