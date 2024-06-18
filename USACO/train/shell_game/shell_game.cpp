#include <fstream>
#include <algorithm>
using namespace std;

int N,A[1000],B[1000],G[1000];
int num_correct(int starting_shell)
{
	int current_shell = starting_shell,correct =0;
	for(int i=0; i<N;i++)
	{
		if(A[i] == current_shell)
			current_shell = B[i];
		else if(B[i] == current_shell)
			current_shell = A[i];
		if(G[i] == current_shell)
			correct++;
	}
	return correct;
}

int main(void)
{	
	/* code */
	ifstream cin("shell.in");
	cin >> N;
	for(int i = 0;i<N;i++)
	{
		cin >> A[i] >> B[i] >> G[i];
	}


	int best = 0;
	for(int i =0; i < N ; i++)
	{
		best = max(best,num_correct(i));
	}
	ofstream cout ("shell.out");
	cout << best << "\n";
	return 0;
}