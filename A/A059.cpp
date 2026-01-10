#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int Answer;

int main(int argc, char** argv)
{
	int T, test_case;

	cin >> T;
	for(test_case = 0; test_case  < T; test_case++)
	{

		Answer = 0;
		int subs;
		int counts;
		
		vector<int> a;
		
		cin >> subs;
		cin >> counts;
		
		for(int i = 0; i < subs; i++){
		    int tmp;
		    cin >> tmp;
		    a.push_back(tmp);
		}
		sort(a.begin(), a.end(), greater<int>());
		for(int i = 0; i < counts; i++){
            Answer += a[i];
		}
		// Print the answer to standard output(screen).
		cout << "Case #" << test_case+1 << endl;
		cout << Answer << endl;
	}

	return 0;//Your program should return 0 on normal termination.
}