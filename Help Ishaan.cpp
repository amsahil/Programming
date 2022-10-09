//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
	int NthTerm(int N) {

		//base condition
		if (isPrime(N)) return 0;

		int i = 0;

		while (true)
		{
			if (isPrime(N - i) || isPrime(N + i))
			{
				break;
			}
			i++;
		}
		return i;
	}

	bool isPrime(int N)
	{
		if (N < 2) return false;

		for (int i = 2; i * i <= N; i++)
		{
			if (N % i == 0)
			{
				return false;
			}
		}
		return true;
	}







};

//{ Driver Code Starts.
int main() {
	int tc;
	cin >> tc;
	while (tc--) {
		int N;
		cin >> N;
		Solution obj;
		int ans = obj.NthTerm(N);
		cout << ans << "\n";
	}
	return 0;
}
// } Driver Code Ends