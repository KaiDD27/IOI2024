#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;

const int N = 3;
const int TURN_NUM = 100;
vector<int> O(N),M(N);

int main(void)
{
	ifstream cin("mixmilk.in");
	for(int i=0;i<N;i++)
	{
		cin >> O[i] >> M[i] ;		
	}
	for(int i = 0;i<TURN_NUM;i++)
	{
		int amt = min(M[i%N],O[(i+1)%N]-M[(i+1)%N]);
		M[i%N]=M[i%N]-amt;
		M[(i+1)%N]=M[(i+1)%N]+amt;
	}
	ofstream cout ("mixmilk.out");
	for(int i=0;i<N;i++)
	{
		cout << M[i] << "\n";
	}
	
	return 0;
}