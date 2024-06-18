#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;
int main(void)
{
	ifstream cin("speeding.in");
	int N=0,M=0,Max = 0,startLimitLength = 0,endLimitLength=0;
	cin >> N >> M ;
	vector<vector<int> > speedLimit(N,vector<int>(2)),Speed(M,vector<int>(2));
	for(int i = 0;i<N;i++)
	{
		cin >> speedLimit[i][0] >> speedLimit[i][1];
	}
	for(int i = 0;i<M;i++)
	{
		cin >> Speed[i][0] >> Speed[i][1];
	}
	for(int i = 0 ; i < N ; i++)
	{
		startLimitLength = endLimitLength;
		endLimitLength = startLimitLength + speedLimit[i][0];
		int startSpeedLength = 0,endSpeedLength =0;
		for(int p = 0;p< M;p++)
		{
			startSpeedLength = endSpeedLength;
			endSpeedLength = startSpeedLength + Speed[p][0];
			if((Speed[p][1]- speedLimit[i][1]) > Max)
			{
				if(!((startSpeedLength >= endLimitLength)|| (endSpeedLength <=startLimitLength)))
				{
					Max = Speed[p][1]- speedLimit[i][1];
				}
			}
		}
	}
	ofstream cout ("speeding.out");
	cout << Max << "\n";
	return 0;
}

