/* D12

Help Ishaan

P.S:- Ishaan has been given a task by his teacher. He needs to find the Nth term of a series.
    His teacher gives him some examples to help him out (Refer examples below).
    He is a bit weak in pattern searching so to help him his teacher told him that the Nth term is related to prime numbers.
    The Nth term is the difference of N and the closest prime number to N. Help him find the Nth term for a given N.


Example 1:
Input: N = 10
Output: 1
Explanation: Closest prime to 10 is 11.

Example 2:
Input: N = 7
Output: 0
Explanation: Closest prime to 7 is 7.

Constraints:
1 <= N <= 100000

Expected Time Complexity: O(N* √ N)
Expected Space Complexity: O(1)

*/


//--------------------------------------------------------------SOLUTION-----------------------------------------------

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