#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void)
{
    ifstream fin("paint.in");
    ofstream fout("paint.out");
    int a, b, c, d, begin, end, distanceJohn, distanceBessie;
    fin >> a >> b >> c >> d;
    if (b <= c || d <= a)
    {
        distanceJohn = b - a;
        distanceBessie = d - c;
        fout << distanceJohn + distanceBessie << endl;
    }
    else
    {

        begin = min(a, c);
        end = max(b, d);
        fout << end - begin << endl;
    }

    return 0;
}