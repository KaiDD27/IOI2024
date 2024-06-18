#include <fstream>

using namespace std;

int evaluate(const string &num_in_base, int base)
{
    return (num_in_base[0] - '0') * base * base +
           (num_in_base[1] - '0') * base +
           (num_in_base[2] - '0');
}

int main()
{
    ifstream fin("whatbase.in");
    ofstream fout("whatbase.out");
    int MAXB = 15000;
    int T;
    fin >> T;
    for (int t = 0; t < T; t++)
    {
        string num_in_x, num_in_y;
        fin >> num_in_x >> num_in_y;
        int X = 10, Y = 10;
        while (X <= MAXB && Y < +MAXB)
        {
            int num_x = evaluate(num_in_x, X);
            int num_y = evaluate(num_in_y, Y);
            if (num_x == num_y)
            {
                fout << X << " " << Y << endl;
                break;
            }
            else if (num_x > num_y)
            {
                Y++;
            }
            else
            {
                X++;
            }
        }
    }
    return 0;
}